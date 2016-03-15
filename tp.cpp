//Love Sucks!!!

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define Sl(x) scanf("%lld",&x)
#define Su(x) scanf("%llu",&x)
#define all(v) v.begin(),v.end()
#define Sc(x) scanf("%d",&x)
#define P(x) printf("%d", x)
#define nl() printf("\n");
#define F first
#define S second
#define pii pair<int, int>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(int i=(s);i<(n);++i)
#define ford(i,s,n) for(int i=(n)-1;i>=(s);--i)
#define INF 8944674407370955161LL
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)
//#define sync() ios_base::sync_with_stdio(0)

ll abs(ll x) {if(x < 0) return -x; return x;}

int addmod(int v1, int v2) {
    int v3 = v1+v2;
    if(v3 >= MOD) v3 -= MOD;
    return v3;
}

#define MAX 500005//maximum value of n goes here!!
int n, m, q;
vector< pii > roads;
ll pop[MAX];

ll par[MAX], rnk[MAX];
ll tree[4*MAX];

void build_tree(int cur, int l, int r){
    if(l == r){
        tree[cur] = rnk[l];
    }
    else{
        int m = (l+r)/2;
        build_tree(2*cur, l, m);
        build_tree(2*cur + 1, m+1, r);
        tree[cur] = max(tree[2*cur], tree[2*cur+1]);
    }
}

ll query(int cur, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr)
        return tree[cur];
    int m = (l+r)/2;
    if (qr <= m)
        return query(cur*2, l, m, ql, qr);
    if (ql > m)
        return query(cur*2+1, m+1, r, ql, qr);
    return max(query(cur*2, l, m, ql, m), query(cur*2+1, m+1, r, m+1, qr));
}

void update(int cur, int l, int r, int pos, ll new_val) {
    if (l == r)
        tree[cur] = new_val;
    else {
        int m = (l + r) / 2;
        if (pos <= m)
            update(2*cur, l, m, pos, new_val);
        else
            update(2*cur+1, m+1, r, pos, new_val);
        tree[cur] = max(tree[2*cur], tree[2*cur+1]);
    }
}

void make_set(int n)
{
    for(int i = 0; i < n; i++)
    {
        rnk[i] = pop[i];
        par[i] = i;
    }
}
int find(int i)
{
    if(par[i] != i)
        par[i] = find(par[i]);
    return par[i];
}
void Union(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);
    if(xroot == yroot)
        return;
    par[xroot] = yroot;
    rnk[yroot] += rnk[xroot];
    update(1, 0, n-1, xroot, -999999999);
    update(1, 0, n-1, yroot, rnk[yroot]);
}

char qt[MAX];
vector< pii > qs;
int mrk[MAX];
vector<int> upd[MAX];
ll ans[MAX];
int main()
{
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
    int t;
    t=1;
    while(t--)
    {
        Sc(n);Sc(m);Sc(q);
        roads.resize(m);
        fori(i, 0, n){
            upd[i].clear();
            mrk[i] = 0;
            Sl(pop[i]);
            upd[i].pb(pop[i]);
        }
        fori(i, 0, m){
            int a, b;
            Sc(a);Sc(b);
            a--,b--;
            roads[i] = mp(a, b);
        }
        char c;
        qs.resize(q);
        fori(i, 0, q){
            cin>>c;
            qt[i] = c;
            ll x;
            int tp;
            if(c == 'D'){
                scanf("%d", &tp);
                tp--;
                mrk[tp] = 1;
                qs[i] = mp(roads[tp].F, roads[tp].S);
            }
            else{
                scanf("%d%lld", &tp, &x);
                tp--;
                pop[tp] = x;
                upd[tp].pb(x);
                qs[i] = mp(tp, (int)x);
            }
        }
        make_set(n);
        build_tree(1, 0, n-1);
        //debug(i, n, pop);
        fori(i, 0, m){
            if(mrk[i] == 0){
                Union(roads[i].F, roads[i].S);
            }
        }
        for(int i = q-1; i >= 0; --i){
            ans[i] = query(1, 0, n-1, 0, n-1);
            if(qt[i] == 'P'){
                int xroot = find(qs[i].F);
                int tx = qs[i].F;
                upd[tx].pop_back();
                rnk[xroot] -= pop[tx];
                rnk[xroot] += upd[tx].back();
                pop[tx] = upd[tx].back();
                update(1, 0, n-1, xroot, rnk[xroot]);
            }
            else{
                Union(qs[i].F, qs[i].S);
            }
        }
        fori(i, 0, q){
            printf("%lld\n", ans[i]);
        }
    }
    return 0;
}



