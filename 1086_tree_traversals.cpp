#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 33;
int n;
vector <int> pre, in;
stack <int> s;
struct node {
	int data;
	node * left, * right;
	node(int data){
		this -> data = data;
	}
};

node * create(int il, int ir, int pl, int pr){
	if(il >= ir) return NULL;
	node * root = new node(pre[pl]);
	int m = il, ls;
	for(; m < ir; m ++){
		if(in[m] == pre[pl]){
			break;
		}
	}
	ls = m - il;
	root -> left = create(il, m, pl + 1, pl + 1 + ls);
	root -> right = create(m + 1, ir, pl + 1 + ls, pr);
	return root;
}

bool isSpace;
void postOrder(node * root){
	if(!root) return ;
	postOrder(root -> left);
	postOrder(root -> right);
	if(isSpace) cout << " ";
	if(!isSpace) isSpace = 1;
	cout << root -> data;
}

int main(void)
{
	cin >> n;
	string op;
	int num;
	for(int i = 0; i < 2 * n; i ++){
		cin >> op;
		if(op == "Pop"){
			in.push_back(s.top());
			s.pop();
		}else{
			cin >> num;
			pre.push_back(num);
			s.push(num);
		}
	}
	node * root = create(0, n, 0, n);
	postOrder(root);
	cout << endl;
	return 0;
}
