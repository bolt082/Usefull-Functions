//time complexity of algo O(V*E*E)

void augPath(int v, int minWeight){
	if(v == s)
	{
		f = minWeight;
		return;
	}
	else if(p.count(v)){
		augPath(p[v], min(minWeight, adMat[p[v]][v]));
		adMat[p[v]][v] -= f;
		adMat[v][p[v]] += f;
	}
}

int edmondKarp(){
	map<int, int> p;
	int f, s, t;

	while(true){
		f = 0;

		queue<int> q;
		map<int, int> depth;
		q.push(s);
		depth[s] = 0;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			if(u == t)
				break;
			for(int i = 0; i < adList[u]; ++i){
				int v = adList[u][i];
				if(adMat[u][v] > 0 && depth.find(v) != depth.end())
				{
					depth[v] = depth[u] + 1;
					q.push(v);
					p[v] = u;
				}
			}
		}
		if(augPath(t, INF));
		if(f == 0)
			break;
		maxFlow += f;
	}
	return maxFlow;
}