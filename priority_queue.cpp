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
            	if(dc == 1){
                	a = max_heapify(a, i, hsize);
            	}
                else{
                	a = min_heapify(a, i, hsize);
                }
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

template<class datatype> class Priority_Queue{
    public:
        Heap<datatype> hp;
        V<datatype> data;
        int DC;
        V<datatype> build_pq(V<datatype> a, int dc)
        {
            cout<<a.size()<<endl;
            data = hp.build_heap(a, a.size()-1, dc);
            DC = dc;
            return data;
        }
        int front()
        {
            if(data.size() <= 0)
                return -1;
            return data[1];
        }
        int pop()
        {
            if(data.size() <= 0)
                return -1;
            datatype mx = data[1];
            if(DC == 1)
            {
                data = hp.max_heapify(data, 1, data.size());
            }
            else
            {
                data = hp.min_heapify(data, 1, data.size());
            }
            return mx;
        }
        V<datatype> inc_key(V<datatype> a, int i, datatype key)
        {
            if(DC == 1)
            {
                if(key < a[i])
                    return a;
                a[i] = key;
                while(i > 1 && a[hp.parent(i)] < a[i])
                {
                    swap(a[i], a[hp.parent(i)]);
                    i = hp.parent(i);
                }
                data = a;
                return a;
            }
            else
            {
                if(key > a[i])
                    return a;
                a[i] = key;
                while(i > 1 && a[hp.parent(i)] > a[i])
                {
                    swap(a[i], a[hp.parent(i)]);
                    i = hp.parent(i);
                }
                data = a;
                return a;
            }
        }
        V<datatype> Insert(V<datatype> a, datatype key)
        {
            int hsize = a.size();
            a.pb(_datatype(key));
            a = inc_key(a, hsize, key);
        }
        datatype __datatype(datatype key)
        {
            if(DC == 1)
            {
               return INT_MIN;
            }
            else
            {
                return INT_MAX;
            }
        }
};

int main()
{
    V<int> x;
    for(int i = 0; i <= 4; i++)
        x.pb(0);
    x[1] = 1;
    x[2] = 2;
    x[3] = 3;
    Priority_Queue<int> pq;
    x = pq.build_pq(x, 2);
    for(int i = 1; i < 4; i++)
        cout<<x[i]<<" ";
    cout<<endl;
    cout<<pq.front()<<endl;
	return 0;
}
