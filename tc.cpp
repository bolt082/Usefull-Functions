#include <bits/stdc++.h>
using namespace std;

int shortestLength(string a, string b, string c, string d){
    string s[4];
    s[0] = a;
    s[1] = b;
    s[2] = c;
    s[3] = d;
    int ans = 99999;
        string tp = "";
        for(int j = 0; j < 4; ++j){
            if((i&(1<<j))){
                if(tp.find(s[j]) == string::npos){
                    string tb = s[j];
                    if(tp.size() >= s[j].size()){
                        for(int k = s[j].size(); k >= 1; --k){
                            int n = tp.size();
                            string x = s[j].substr(0, k);
                            string y = tp.substr(n-k, k);
                            if(x == y)
                                tb = s[j].substr(k);
                        }
                    }
                    tp += tb;
                }
            }
        }
        int done = 1;
        for(int j = 0; j < 4; ++j){
            if(tp.find(s[j]) == string::npos){
                done = 0;
                break;
            }
        }
        if(done)
            ans = min(ans, (int)tp.size());
    return ans;
}
