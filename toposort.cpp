#include <bits/stdc++.h>
using namespace std;
#define V vector<int>
#define pb push_back

V ad[10005];
V vx;
int visited[10005];

void dfs(V *ad, int u, V lst)
{
    visited[u] = 1;
    for(int i = 0; i < (int)ad[u].size(); i++)
    {
        if(!visited[i])
        {
            dfs(ad, i, lst);
        }
    }
    lst.pb(u);

}

V topological_sort(V *ad)
{
    vector<int> lst;

    for(V::iterator it = vx.begin(); it != vx.end(); it++)
    {
        if(!visited[*it])
        {
            dfs(ad, *it, lst);
        }
    }

    return lst;
}

int main()
{
    ad[]
	return 0;
}
