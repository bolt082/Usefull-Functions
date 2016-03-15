//Love Sucks!!!

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define Sl(x) scanf("%lld",&x)
#define Su(x) scanf("%llu",&x)
#define all(v) v.begin(),v.end()
#define Sc(x) scanf("%d",&x)
#define P(x) printf("%d", x)
#define nl() printf("\n");
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define pps pair<ll,pll>
#define ppi pair<pii,int>
#define ppf pair<pll,ll>
#define psi pair<string,int>
#define pis pair<int,string>
#define F first
#define S second
#define MOD 1000000007
#define EPS 1e-9
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(int i=(s);i<(n);++i)
#define ford(i,s,n) for(int i=(n)-1;i>=(s);--i)
#define INF 8944674407370955161LL
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)
#define sync() ios_base::sync_with_stdio(0)

//double abs(double x) {if(x < 0) return -x; return x;}

int addmod(int v1, int v2) {
    int v3 = v1+v2;
    if(v3 >= MOD) v3 -= MOD;
    return v3;
}

#define MAX 1005
int s[MAX][MAX];
int n;
vector< pii > vp;
int vis[MAX][MAX];
int done[MAX][MAX];

int bfs(pii so)
{
    queue< pair<pii, int> > q;
    pair<pii, int> cur;
    q.push(mp(so, 0));
    mem(vis, 0);
    vis[so.F][so.S] = 1;
    mem(done, 0);
    while(!q.empty()){
        cur = q.front();
        q.pop();
        pii curp = cur.F;
        if(s[curp.F][curp.S] == 3){
            done[curp.F][curp.S] = cur.S;
        }
        if(curp.F > 0 && vis[curp.F-1][curp.S] == 0){
            q.push(mp(pii(curp.F-1, curp.S), cur.S+1));
            vis[curp.F-1][curp.S] = 1;
        }
        if(curp.S > 0 && vis[curp.F][curp.S-1] == 0){
            q.push(mp(pii(curp.F, curp.S-1), cur.S+1));
            vis[curp.F][curp.S-1] = 1;
        }
        if(curp.F < n-1 && vis[curp.F+1][curp.S] == 0){
            q.push(mp(pii(curp.F+1, curp.S), cur.S+1));
            vis[curp.F+1][curp.S] = 1;
        }
        if(curp.S < n-1 && vis[curp.F][curp.S+1] == 0){
            q.push(mp(pii(curp.F, curp.S+1), cur.S+1));
            vis[curp.F][curp.S+1] = 1;
        }
    }
    //cout<<so.F<<" "<<so.S<<endl;
    int ret = 8899999;
    fori(i, 0, n){
        fori(j, 0, n){
      //      cout<<done[i][j]<<" ";
            if(s[i][j] == 3){
                ret = min(ret, done[i][j]);
            }
        }
        //cout<<endl;
    }
    return ret;
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    Sc(t);
    while(t--){
        Sc(n);
        vp.clear();
        fori(i, 0, n){
            fori(j, 0, n){
                Sc(s[i][j]);
            }
        }
        fori(i, 0, n){
            fori(j, 0, n){
                if(s[i][j] == 1){
                    vp.pb(mp(i, j));
                }
            }
        }
        int ans = -1;
        fori(i, 0, vp.size()){
            ans = max(ans, bfs(vp[i]));
        }
        printf("%d\n", ans);
    }
    return 0;
}
