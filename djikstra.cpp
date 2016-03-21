ll dist[MAX];

ll Dijkstra(int s){
    fori(i, 0, n){
        dist[i] = -1;
    }
    priority_queue< pair<ll, int> > pq;
    pq.push(mp(LLONG_MAX, 0));
    dist[0] = LLONG_MAX;
    pair<ll, int> cur;
    while(!pq.empty()){
        cur = pq.top();
        pq.pop();
        ll curS = cur.F;
        if(curS >= dist[cur.S]){
            for(int i = 0; i < ad[cur.S].size(); ++i){
                pair<int, ll> tp = ad[cur.S][i];
                if(dist[tp.F] < min(dist[cur.S], tp.S)){
                    dist[tp.F] = min(dist[cur.S], tp.S);
                    pq.push(mp(dist[tp.F], tp.F));
                }
            }
        }
    }
    //debug(i, n, dist);
    return dist[n-1];
}