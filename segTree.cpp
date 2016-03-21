//Simple max value segment tree
#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define ll long long

int n, l, r;
ll a[MAX];

struct node{
	int val;
};

node tree[4*MAX];
int lazy[4*MAX];

node createNode(ll val){
	node ret;
	//initialize node here

	return ret;
}

node merge(node l, node r){
	node ret;
	//merge procedure!!

	return ret;
}

void buildTree(int cur, int l, int r){
	if(l == r){
		tree[cur] = createNode(a[l]);
	}
	else{
		int m = (l+r)/2;
		buildTree(2*cur, l, m);
		buildTree(2*cur+1, m+1, r);
		tree[cur] = merge(tree[2*cur], tree[2*cur+1]);
	}
}

node query(int cur, int l, int r, int ql, int qr){
	if(ql == l && qr == r){
		return tree[cur];
	}
	else{
		int m = (l+r)/2;
		if(qr <= m){
			return query(2*cur, l, m, ql, qr);
		}
		else if(ql > m){
			return query(2*cur+1, m+1, r, ql, qr);
		}
		node lChild = query(2*cur, l, m, ql, m);
		node rChild = query(2*cur+1, m+1, r, m+1, qr);
		return merge(lChild, rChild);

	}
}

void update(int cur, int l, int r, int pos, int newVal){
	if(l == r && pos == l){
		tree[cur] = createNode(newVal);
	}
	else{
		int m = (l+r)/2;
		if(pos <= m){
			update(2*cur, l, m, pos, newVal);
		}
		else{
			update(2*cur+1, m+1, r, pos, newVal);
		}
		tree[cur] = merge(tree[2*cur], tree[2*cur+1]);
	}
}

void rUpdate(int cur, int a, int b, int i, int j, int value){
    if(lazy[cur] != 0) {
   		tree[cur].val += lazy[cur];

		if(a != b) {
			lazy[cur*2] += lazy[cur];
            lazy[cur*2+1] += lazy[cur];
		}

   		lazy[cur] = 0;
  	}

	if(a > b || a > j || b < i)
		return;

  	if(a >= i && b <= j) {
    		tree[cur].val = (j-i+1)*value;

		if(a != b) {
			lazy[cur*2] += (j-i+1)*value;
			lazy[cur*2+1] += (j-i+1)*value;
		}

        return;
	}

	rUpdate(cur*2, a, (a+b)/2, i, j, value);
	rUpdate(1+cur*2, 1+(a+b)/2, b, i, j, value);

	tree[cur].val = tree[cur*2].val+ tree[cur*2+1].val;

}

int main(){
    int q;
    cin>>n>>q;
	for(int i = 0; i < n; ++i){
		cin>>a[i];
	}
	buildTree(1, 0, n-1);

	while(q--){
	    int qt;
        cin>>qt>>l>>r;
        if(qt == 1){
            cout<<query(1, 0, n-1, l, r).val<<endl;
        }
        else{
            ll tp;
            cin>>tp;
            int cnt = getPop(tp);
            if(cnt != 1)
                cnt = 0;
            rUpdate(1, 0, n-1, l, r, cnt);
        }
	}
}
