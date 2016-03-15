#include <bits/stdc++.h>
using namespace std;

#define V vector
#define pb push_back

template<class datatype> struct Edge{
    datatype src, dest;
    double weight;
};

template<class datatype> class Graph
{
    public:
        int v, e;
        V<datatype> vx;
        V< Edge<datatype> > eg;
        void setup(int v, int e)
        {
            this->v = v;
            this->e = e;
        }
};

class Djikstra{
	public:
		priority_queue<int> myq;
		V<int> ans;
	void initialize(Graph<int> g, int s)
	{
		ans.resize(10005);
		ans.clear();
		for(int i = 0; i < (int)g.vx.size(); i++)
		{
			ans[g.vx[i]] = INT_MAX;
			myq.push(g.vx[i]);
		}
		ans[s] = 0;
	}

	V<int> djikstra(Graph<int> g, int s)
	{
		initialize(g, s);
		V<int> ss;
		while(!myq.empty())
		{
			int u = myq.top();
			myq.pop();
			ss.pb(u);
			for(int i = 0; i < (int)g.eg.size(); i++)
			{
				if(ans[g.eg[i].dest] > ans[g.eg[i].src] + g.eg[i].weight)
				{
					ans[g.eg[i].dest] = ans[g.eg[i].src] + g.eg[i].weight;
				}
			}
		}
		for(int i = 0; i < (int)g.vx.size(); i++)
			cout<<ans[g.vx[i]]<<" ";
		cout<<endl;
		return ans;
	}
};

int main()
{
	Graph<int> g;
	g.setup(5, 10);
	Edge<int> ps;
	g.vx.pb(1);
    g.vx.pb(2);
    g.vx.pb(3);
    g.vx.pb(4);
    g.vx.pb(5);
    ps.src = 1;
    ps.dest = 2;
    ps.weight = 6;
    g.eg.pb(ps);
    ps.dest = 3;
    ps.weight = 7;
    g.eg.pb(ps);
    ps.src = 2;
    ps.dest = 4;
    ps.weight = 5;
    g.eg.pb(ps);
    ps.dest = 5;
    ps.weight = -4;
    g.eg.pb(ps);
    ps.dest = 3;
    ps.weight = 8;
    g.eg.pb(ps);
    ps.src = 3;
    ps.dest = 4;
    ps.weight = -3;
    g.eg.pb(ps);
    ps.dest = 5;
    ps.weight = 9;
    g.eg.pb(ps);
    ps.src = 4;
    ps.dest = 2;
    ps.weight = -2;
    g.eg.pb(ps);
    ps.src = 5;
    ps.dest = 4;
    ps.weight = 7;
    g.eg.pb(ps);
    ps.dest = 1;
    ps.weight = 2;
    g.eg.pb(ps);
    Djikstra d;
    d.djikstra(g, 1);
	return 0;
}
