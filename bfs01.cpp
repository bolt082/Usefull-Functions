int bfs01(){
    deque< pair<int, int> > q;
    pair<int, int> curp;

    fori(i, 0, r){
        fori(j, 0, c){
            dist[i][j] = INT_MAX;
        }
    }
    q.push_back(mp(0, 0));
    dist[0][0] = 0;
    while(!q.empty()){
        curp = q.front();
        q.pop_front();
        //cout<<curp.F<<" "<<curp.S<<endl;
        if(curp.F > 0){
            int wt = 0;

            if(s[curp.F][curp.S] != s[curp.F-1][curp.S]){
                wt=1;
            }
            if(dist[curp.F-1][curp.S] > wt + dist[curp.F][curp.S]){
                dist[curp.F-1][curp.S] = wt + dist[curp.F][curp.S];
                if(wt){
                    q.push_back(mp(curp.F-1, curp.S));
                }
                else{
                    q.push_front(mp(curp.F-1, curp.S));
                }
            }
        }
        if(curp.S > 0){
            int wt = 0;
            if(s[curp.F][curp.S] != s[curp.F][curp.S-1]){
                wt=1;
            }
            if(dist[curp.F][curp.S-1] > wt + dist[curp.F][curp.S]){
                dist[curp.F][curp.S-1] = wt + dist[curp.F][curp.S];
                if(wt){
                    q.push_back(mp(curp.F, curp.S-1));
                }
                else{
                    q.push_front(mp(curp.F, curp.S-1));
                }
            }
        }
        if(curp.F < r-1){
            int wt = 0;

            if(s[curp.F][curp.S] != s[curp.F+1][curp.S]){
                wt=1;
            }
            if(dist[curp.F+1][curp.S] > wt + dist[curp.F][curp.S]){
                dist[curp.F+1][curp.S] = wt + dist[curp.F][curp.S];
                if(wt){
                    q.push_back(mp(curp.F+1, curp.S));
                }
                else{
                    q.push_front(mp(curp.F+1, curp.S));
                }
            }
        }
        if(curp.S < c-1){
            int wt = 0;

            if(s[curp.F][curp.S] != s[curp.F][curp.S+1]){
                wt=1;
            }
            if(dist[curp.F][curp.S+1] > wt + dist[curp.F][curp.S]){
                dist[curp.F][curp.S+1] = wt + dist[curp.F][curp.S];
                if(wt){
                    q.push_back(mp(curp.F, curp.S+1));
                }
                else{
                    q.push_front(mp(curp.F, curp.S+1));
                }
            }
        }
    }
    return dist[r-1][c-1];
}
