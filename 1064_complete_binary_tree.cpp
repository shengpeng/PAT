#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e4 + 5;
int arr[N], t[N], n, cnt;
void inorder(int root){
	if(root > n) return ;
	inorder(2 * root);
	t[root] = arr[++ cnt];
	inorder(2 * root + 1);
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	inorder(1);
	for(int i = 1; i <= n; i ++){
		cout << t[i] << " \n"[i == n];
	}
	return 0;
}
