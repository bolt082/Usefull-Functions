#include <bits/stdc++.h>
using namespace std;

#define c_size 26

struct node{
	int key, cur;
	node* next[c_size];
};

class Trie{
	public:
		node *root = NULL;
		
		//Trie Functions

		node* create()
		{
			node *ret = new node();
		    for(int x = 0;x < c_size;x++)
		        ret->next[x] = NULL;
		    ret->key = -1;
		    ret->cur = 0;
		    return ret;
		}

		void insert(string s)
		{
			int len = s.size();
		    int ind;
		    int lv = 0;
		    if(root == NULL)
		        root = create();
		    node *q = root; 
		 
		    for(;lv < len;lv++) {
		        ind = s[lv] - 'a';
		 		
		        if(q->next[ind] == NULL) {
		            q->next[ind] = create(); 
		        }
		     	q = q->next[ind];
		     	q->cur++;
		        
		       
		    }
		    q->key = lv;
		}
		int search(string s) {
		    node *q = root;
		    int len = s.size();
		 	int ch = 0;
		    int lv = 0;
		    for( ;lv < len; lv++) {
		        int ind = s[lv] - 'a';
		        if(q->cur !=  1)
		            q = q->next[ind];
		        else
		        {
		        	ch = 1;
		        	break;
		        }
		    }
		    if(s[lv] == '\0' && q->key != -1)
                    return q->key;
            return -1;
		}
		void destruct(node *root)
        {
            if (root == NULL)
                return;
            for (int i = 0; i < 26; i++) {
                destruct(root->next[i]);
            }
            free(root);
        }
        ~Trie()
        {
            destruct(root);
        }

};

int main()
{

	return 0;
}