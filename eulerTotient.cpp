vector<int> primeFac(int n){
	vector<int> ret;
	int idx = 0;

	while(n != 1 && prime[idx]*prime[idx] <= n){
		int done = 0;
		while(n%prime[idx] == 0){
			n /= prime[idx];
			if(done == 0){ // uncomment to get all factors
				ret.push_back(prime[idx]);
				done = 1;
			}
		}
		++idx;
	}
	if(n != 1)
		ret.push_back(n);

	return ret;
}

int phi(int n){
	vector<int> primeFactor = primeFac(n);
	int ret = n;

	for(int i = 0; i < primeFactor.size(); ++i){
		ret = ret - ret/primeFactor[i];
	}

	return ret;
}