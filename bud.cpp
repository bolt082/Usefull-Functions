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
#define sync() ios_base::sync_with_stdio(0)

ll abs(ll x) {if(x < 0) return -x; return x;}

int addmod(int v1, int v2) {
    int v3 = v1+v2;
    if(v3 >= MOD) v3 -= MOD;
    return v3;
}

#define MAX 65//maximum value of n goes here!!
int n;
string s[MAX];
int dp[MAX][2];


int main()
{
//   freopen("in2.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
    ll s, q;
    cin>>s>>q;
    map<ll, int> m;
    ll a;
    while(q--){
        cin>>a;
        ll gc = __gcd(a, s);
        if(m.find(gc) == m.end()){
            cout<<gc<<endl;
            m[gc]++;
        }
        else{
            cout<<"-1\n";
        }
    }
    return 0;
}



