const long long B = 100050007;
const long long M = 1000000009;

long long power(long long n, long long m)
{
    if (m == 0) return 1;
    long long x = power(n, m / 2);
    if (!(m & 1)) return (x * x) % M;
    else return (((x * x) % M) * n) % M;
}

long long h[MAX];
long long pB[MAX], invB[MAX];

void pInit() {
    pB[0] = 1;
    for (int i = 1; i < MAX; i++) {
        pB[i] = (pB[i-1] * B) % M;
    }

    invB[MAX-1] = power(pB[MAX-1], M-2);
    for (int i = MAX-2; i >= 0; i--) {
        invB[i] = (invB[i+1] * B) % M;
    }
}

void init(){
    int n = s.size();
    h[0] = s[0];
    for (int i = 1; i < n; i++) {
        h[i] = ((s[i] * pB[i]) % M + h[i-1]) % M;
    }
}

ll concat(ll h1, ll h2, ll n){
    ll ret = (h1 + (h2*pB[n])%M)%M;
    return ret;
}

ll getsubH( int i, int j){
    if(i > j)
        return 0;
    ll jh = h[j];
    ll ih = (i > 0)? h[i-1]: 0;
    ll subHash = ((jh + M - ih) * invB[i]) % M;
    return subHash;
}
