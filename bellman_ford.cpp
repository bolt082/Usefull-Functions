#include <bits/stdc++.h>
using namespace std;

#define V vector
#define pb push_back

struct Edge{
    int src, dest;
    double weight;
};

class Graph
{
    public:
        int v, e;
        V<int> vx;
        V<Edge> eg;
        void setup(int v, int e)
        {
            this->v = v;
            this->e = e;
        }
        //~Graph();
};

V<int> Initialize(Graph g, int s)
{
    V<int> r;
    r.resize(10005);
    r.clear();
    for(int i = 0; i < (int)g.vx.size(); i++)
    {
        r[g.vx[i]] = INT_MAX;
    }
    r[s] = 0;
    return r;
}

bool Bellman_Ford(Graph g, int s)
{
    V<int> sd = Initialize(g, s);
    for(int k = 0; k < (int)g.vx.size(); k++)
    {
        for(int i = 0; i < (int)g.eg.size(); i++)
        {
            int src, dest;
            double w;
            src = g.eg[i].src;
            dest = g.eg[i].dest;
            w = g.eg[i].weight;
            if(sd[dest] > sd[src] + w)
                sd[dest] = sd[src] + w;
        }
    }
    for(int i = 0; i < (int)g.eg.size(); i++)
    {
        int src, dest;
        double w;
        src = g.eg[i].src;
        dest = g.eg[i].dest;
        w = g.eg[i].weight;
        if(sd[dest] > sd[src] + w)
        {
            return false;
        }
    }
    for(int i = 0; i < (int)g.vx.size(); i++)
        cout<<sd[g.vx[i]]<<" ";
    cout<<endl;
    return true;
}

int main()
{
    Graph g;
    g.setup(5, 10);
    g.vx.pb(1);
    g.vx.pb(2);
    g.vx.pb(3);
    g.vx.pb(4);
    g.vx.pb(5);
    Edge ps;
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
    //for(int i = 0; i < (int)g.eg.size(); i++)
     //   cout<<g.eg[i].src<<" "<<g.eg[i].dest<<" "<<g.eg[i].weight<<endl;
    cout<<Bellman_Ford(g, 1)<<endl;
    return 0;
}
