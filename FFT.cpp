#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1.0)

#define pb push_back

typedef complex<double> base;

class FFT{
	public:
		void fft(vector<base> &a, bool invert)
		{
			int n = (int)a.size();
			if(n == 1)
				return;
			vector<base> a0 (n/2),  a1 (n/2);
			for (int i=0, j=0; i<n; i+=2, ++j) {
				a0[j] = a[i];
				a1[j] = a[i+1];
			}
			fft (a0, invert);
			fft (a1, invert);
		 
			double ang = 2*PI/n * (invert ? -1 : 1);
			base w (1),  wn (cos(ang), sin(ang));
			for (int i=0; i<n/2; ++i) {
				a[i] = a0[i] + w * a1[i];
				a[i+n/2] = a0[i] - w * a1[i];
				if (invert)
					a[i] /= 2,  a[i+n/2] /= 2;
				w *= wn;
			}
		}
		void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
			vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
			size_t n = 1;
			while (n < max (a.size(), b.size()))  n <<= 1;
			n <<= 1;
			fa.resize (n),  fb.resize (n);
		 
			fft (fa, false),  fft (fb, false);
			for (size_t i=0; i<n; ++i)
				fa[i] *= fb[i];
			fft (fa, true);
		 
			res.resize (n);
			for (size_t i=0; i<n; ++i)
				res[i] = int (fa[i].real() + 0.5);
		}
};

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		string a, b;
		cin>>a>>b;
		if(a == "0" || b == "0")
		{
			cout<<"0\n";
			continue;
		}
		vector<int> ai;
		vector<int> bi;
		vector<int> res;
		for(int i = a.size()-1; i >= 0; --i)
		{
			ai.pb((a[i]-'0'));
		}
		for(int i = b.size()-1; i >= 0; --i)
		{
			bi.pb((b[i]-'0'));
		}
		FFT f;
		f.multiply(ai, bi, res);
		int carry=0;
		for(size_t i = 0; i < res.size(); i++)
		{
			res[i] += carry;
			carry = res[i]/10;
			res[i] %= 10;
		}
		int i = res.size()-1;
		while(res[i] == 0)
			i--;
		while(i >= 0)
		{
			cout<<res[i];
			--i;
		}
		cout<<endl;
	}
	return 0;
}
