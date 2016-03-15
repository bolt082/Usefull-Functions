int tree[MAX];

int get(int idx){
	int s = 0;
	while(idx > 0){
		s += tree[idx];
		idx -= (idx & -idx);
	}
	return s;
}

void update(int idx, int v){
	while(idx < MAX){
		tree[idx] += v;
		idx += (idx & -idx);
	}
}