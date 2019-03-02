#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e4 + 5;
int n, m, root;
int pre[N], in[N];
struct node {
	int left, right;
}t[N];

int create(int il, int ir, int pl, int pr){
	if(il >= ir) return -1;
	int k, ls;
	for(k = il; k < ir; k ++){
		if(pre[pl] == in[k]){
			break;
		}
	}
	ls = k - il;
	t[pre[pl]].left = create(il, k, pl + 1, pl + 1 + ls);
	t[pre[pl]].right = create(k + 1, ir, pl + 1 + ls, pr);
	return pre[pl];
}

int main(void)
{
	cin >> m >> n;
	for(int i = 0; i < n; i ++){
		cin >> pre[i];
		in[i] = -- pre[i];
	}
	sort(in, in + n);
	root = create(0, n, 0, n);
	for(int i = 0; i < n; i ++){
		printf("%d %d %d\n",i, t[i].left, t[i].right);
	}
	return 0;
}
