int dp[MAX][MAX];

int rec(int idx, int modSum){
    if(idx == n){
        if(modSum == 0 && seqCount)
            return 1;
        return 0;
    }
    if(dp[][] != -1)
        return dp[][];
    int ret = rec(idx+1, (modSum+a[idx])%m, 1) | rec(idx+1, modSum, seqCount);
    dp[][] = ret;
    return ret;
}
