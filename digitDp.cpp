int dp[10][100][100];

int rec(int idx, int sumEv, int sumOdd, int lo, string &x){
    if(idx == n){
        return (sumEv-sumOdd == 1);
    }
    if(lo && dp[idx][sumEv][sumOdd] != -1)
        return dp[idx][sumEv][sumOdd];
    ll ret = 0;
    int lim = (x[idx]-'0');
    if(lo)
        lim = 9;
    for(int d = 0; d <= lim; ++d){
        if((n-idx)%2 == 1){
            ret += rec(idx+1, sumEv, sumOdd+d, (lo || (d < (x[idx] - '0'))), x);
        }
        else{
            ret += rec(idx+1, sumEv+d, sumOdd, (lo || (d < (x[idx] - '0'))), x);
        }
    }
    dp[idx][sumEv][sumOdd] = ret;
    return ret;
}

int solve(string x){
    n = x.size();
    mem(dp, -1);
    return rec(0, 0, 0, 0, x);
}

int checkProp(string l){
    if(l.size() == 1)
        return 0;
    int e = 0, o = 0;
    for(int i = l.size()-1; i >= 0; --i){
        if((l.size()-i)%2){
            o+=(l[i]-'0');
        }
        else{
            e += (l[i]-'0');
        }
    }
    return (e-o == 1);
}

ans = solve(r) - solve(l) + checkProp(l);
