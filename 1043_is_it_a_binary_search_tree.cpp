#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e4 + 5;
int n;
struct node {
	int data;
	node * left, * right;
};
vector <int> origin, pre, preM, post, postM;

void insert(node * & root, int data){
	if(!root){
		root = new node;
		root -> data = data;
		root -> left = root -> right = NULL;
	}else{
		if(data < root -> data) insert(root -> left, data);
		else insert(root -> right, data);
	}
}

vector<int> & preTra(node * root, vector <int> & vec, bool m = 0){
	if(root){
		vec.push_back(root -> data);
		if(m){
			preTra(root -> right, vec, m);
			preTra(root -> left, vec, m);
		}else{
			preTra(root -> left, vec, m);
			preTra(root -> right, vec, m);
		}
	}
	return vec;
}

void postTra(node * root, vector <int> & vec, bool m = 0){
	if(root){
		if(m){
			postTra(root -> right, vec, m);
			postTra(root -> left, vec, m);
		}else{
			postTra(root -> left, vec, m);
			postTra(root -> right, vec, m);
		}
		vec.push_back(root -> data);
	}
}

int main(void)
{
	while(cin >> n){
		node * t = NULL;
		for(int i = 0; i < n; i ++){
			int tmp;
			cin >> tmp;
			origin.push_back(tmp);
			insert(t, tmp);
		}
		if(origin == preTra(t, pre)){
			cout << "YES" << endl;
			postTra(t, post);
			for(int i = 0; i < post.size(); i ++){
				cout << post[i] << " \n"[i + 1 == post.size()];
			}
		}else if(origin == preTra(t, preM, 1)){
			cout << "YES2" << endl;
			postTra(t, postM, 1);
			for(int i = 0; i < postM.size(); i ++){
				cout << postM[i] << " \n"[i + 1 == postM.size()];
			}
		}
		else cout << "NO" << endl;
		origin.clear();
		pre.clear();
		preM.clear();
		post.clear();
		postM.clear();
	}
	return 0;
}
