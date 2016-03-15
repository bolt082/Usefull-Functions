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

#define MAX 100005//maximum value of n goes here!!
ll a, b;
void matmult(long long  a[][2],long long  b[][2],long long c[][2])//multiply matrix a and b. put result in c
{
    int i,j,k;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            c[i][j]=0;
            for(k=0;k<2;k++)
            {
                c[i][j]+=(a[i][k]*b[k][j]);
                c[i][j]=c[i][j]%MOD;
                if(c[i][j] < 0)
                    c[i][j] += MOD;
            }
        }
    }

}
void matpow(long long Z[][2],int n,long long ans[][2])
//find ( Z^n )% M and return result in ans
{

    long long temp[2][2];
    ans[0][0]=1;
    ans[1][0]=0;
    ans[0][1]=0;
    ans[1][1]=1;
    int i,j;
    while(n>0)
    {
        if(n&1)
        {
            matmult(ans,Z,temp);
            for(i=0;i<2;i++)
                for(j=0;j<2;j++)
                    ans[i][j]=temp[i][j];
        }
        matmult(Z,Z,temp);
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                Z[i][j]=temp[i][j];


        n=n/2;
    }
    return;

}
long long fin(long long n)
{
    long long fib;
    if(n>2)
    {
        long long int Z[2][2]={{1,-1},{1,0}},result[2][2];//modify matrix a[][] for other recurrence relations
        matpow(Z,n-2,result);
        fib=((result[0][0]*b)%MOD + (result[0][1]*a)%MOD)%MOD;
        if(fib < 0)
            fib += MOD;//final multiplication of Z^(n-2) with the initial terms of the series
    }
    else
    {
        if(n == 1)
            return a;
        else
            return b;
    }

    return fib;
}

int main()
{
    int t;
    Sc(t);
    while(t--){
        ll n;
        Sl(a);
        Sl(b);
        Sl(n);
        if(a < 0)
            a += MOD;
        if(b < 0)
            b += MOD;
        //n--;
        printf("%lld\n", fin(n));
    }
}



