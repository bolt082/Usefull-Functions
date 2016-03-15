#include <bits/stdc++.h>
using namespace std;

#define V vector
#define pb push_back

template <class datatype> class Heap{
	public:
		V<datatype> max_heapify(V<datatype> a, int i, int hsize)
		{
			int l, r, lg;
			l = lchild(i);
			r = rchild(i);
			if(l <= hsize){
                if(a[l] > a[i])
                    lg = l;
                else
                    lg = i;
			}
			else
                lg = i;
			if(r <= hsize){
			    if(a[r] > a[lg])
                    lg = r;
			}
			if(lg == i)
			{
				return a;
			}
			swap(a[i], a[lg]);
			return max_heapify(a, lg, hsize);
		}
		V<datatype> min_heapify(V<datatype> a, int i, int hsize)
		{
			int l, r, lg;
			l = lchild(i);
			r = rchild(i);
			if(l <= hsize)
			{
				if(a[l] < a[i])
					lg = l;
				else
					lg = i;
			}
			else
				lg = i;
			if(r <= hsize)
			{
				if(a[r] < a[lg])
					lg = r;
			}
			if(lg == i)
				return a;
			swap(a[i], a[lg]);
			return min_heapify(a, lg, hsize);
		}
		V<datatype> build_heap(V<datatype> a, int k, int dc)
		{
		    int hsize = k, n = k;
		    for(int i = n/2; i >= 1; i--)
            {
            	if(dc == 1)
                	a = max_heapify(a, i, hsize);
                else
                	a = min_heapify(a, i, hsize);
            }
            return a;
		}
		inline int parent(int n)
		{
			return floor(n>>1);
		}
		inline int lchild(int n)
		{
			return n<<1;
		}
		inline int rchild(int n)
		{
			return (n<<1)+1;
		}
};

template <class datatype> class HeapSort{
    public:
    	V<datatype> do_work(V<datatype> a, int k, int dc)
    	{
    		Heap<datatype> hp;
    		a = hp.build_heap(a, k, dc);
    		int n = k, tp = k;
    		for(int i = k; i >= 2; i--)
    		{
    			swap(a[1], a[i]);
    			tp = i-1;
    			if(dc == 1)
    				a = hp.max_heapify(a, 1, tp);
    			else
    				a = hp.min_heapify(a, 1, tp);
    		}
    		return a;
    	}

};

int main()
{
	V<string> x(100);
	for(int i = 0; i < 100; i++)
        x[i] = " ";
	x[1] = "pratham";
	x[2] = "pandey";
	x[3] = "bhavook";
	x[4] = "khanna";
	x[5] = "sushil";
	x[6] = "dutt";
	x[7] = "g";
	x[8] = "h";
	x[9] = "i";
	x[10] = "j";
    HeapSort<string> hs;
    x = hs.do_work(x, 6, 2);
    for(int i = 1; i <= 6; i++)
    	cout<<x[i]<<" ";
    cout<<endl;
	return 0;
}
