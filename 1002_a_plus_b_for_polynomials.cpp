#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1005;
double arr[MAXN];
int k, a, kk;
double b;

int main(void)
{
	cin >> k;
	for(int i = 0; i < k; i ++){
		cin >> a >> b;
		arr[a] = b;
	}
	cin >> k;
	for(int i = 0; i < k; i ++){
		cin >> a >> b;
		arr[a] += b;
	}
	for(int i = 0; i < MAXN; i ++){
		if(arr[i]) kk ++;
	}
	cout << kk;
	for(int i = MAXN - 1; i >= 0; i --){
		if(arr[i]) printf(" %d %.1lf", i, arr[i]);
	}
	cout << endl;
	return 0;
}
