bool val(int u){
	if(vis[u])
		return false;

	fori(i, 0, n){
		if(ad[u][i]){
			if(match[i] == -1){
				match[i] = u;
				return true;
			}
			else if(val(match[i])){
				match[i] = u;
			}
		}
	}
	return false;
}

int bpm(){
	int ret = 0;
	mem(match, -1);

	fori(i, 0, n){
		mem(vis, -1);
		ret += val(i);
	}
	return ret;
}
