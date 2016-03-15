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

#define MAX 105
int dp[105][105*1000];
int n, m;
int a[MAX];

void rec(int sum){
    bool subset[sum+1][n+1];

    for (int i = 0; i <= n; i++)
      subset[0][i] = true;

    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;

     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= a[j-1])
           subset[i][j] = subset[i][j] || subset[i - a[j-1]][j-1];
       }
     }

     return subset[sum][n];
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    Sc(n);Sc(m);
    int sm = 0;
    fori(i, 0, n){
        Sc(a[i]);
        sm += a[i];
    }
    return 0;
}
