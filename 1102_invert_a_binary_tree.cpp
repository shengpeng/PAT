#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 15;
int n, root;
struct node {
	int data, left, right;
}t[MAXN];

void invert(int root){
	if(root == -1) return ;
	swap(t[root].left, t[root].right);
	invert(t[root].left);
	invert(t[root]. right);
}

bool isSpace;
void level(int root){
	queue <int> q;
	q.push(root);
	while(!q.empty()){
		if(isSpace) cout << " ";
		if(!isSpace) isSpace = 1;
		root = q.front();
		cout << root;
		q.pop();
		if(t[root].left != -1)
			q.push(t[root].left);
		if(t[root].right != -1)
			q.push(t[root].right);
	}
}

void in(int root){
	if(root == -1) return ;
	in(t[root].left);
	if(isSpace) cout << " ";
	if(!isSpace) isSpace = 1;
	cout << root;
	in(t[root].right);
}

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i ++){
		root ^= i;
		t[i].left = t[i].right = -1;
		char a, b;
		scanf("%*c%c %c",&a, &b);
		if(a != '-') {
			t[i].left = a - '0';
			root ^= t[i].left;
		}
		if(b != '-') {
			t[i].right = b - '0';
			root ^= t[i].right;
		}
	}
	invert(root);
	level(root);cout << endl;
	isSpace = 0;
	in(root);cout << endl;
	return 0;
}
