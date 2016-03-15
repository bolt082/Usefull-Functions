void dfs(int cur){
	if(!vis[cur]){
		vis[cur] = 1;
		for(int i = 0; i < ad[cur].size(); ++i){
			int tp = ad[cur][i];
			if(!vis[tp]){
				dfs(tp);
			}
		}
		topo.pb(tp);		
	}
}

//to obtain topological order reverse the topo vector!!

void bfs(int cur){
	queue<int> q;
	q.push(cur);
	map<int, int> depth;
	while(!q.empty()){
		int tp = q.front();
		q.pop();
		for(int i = 0; i < ad[tp].size(); ++i){
			int tx = ad[tp][cur];
			if(depth.find(tx) != depth.end()){
				depth[tx] = depth[tp] + 1;
				q.push(tx);
			}
		}
	}
}	