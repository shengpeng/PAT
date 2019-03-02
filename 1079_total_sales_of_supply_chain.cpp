#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e5 + 5;
vector <int> t[MAXN];
int n, goods[MAXN];
double rate, price, sum;

void dfs(int p, int l){
	if(goods[p] != -1){
		sum += price * goods[p] * pow(rate, l);
		return ;
	}
	for(int i = t[p].size() - 1; i >= 0; i --){
		dfs(t[p][i], l + 1);
	}
}

int main(void)
{
	cin >> n >> price >> rate;
	rate = 1 + rate / 100.0;
	for(int i = 0; i < n; i ++){
		int k, num; cin >> k;
		if(k){
			for(int j = 0; j < k; j ++){
				cin >> num;
				t[i].push_back(num);
			}
			goods[i] = -1;
		}
		else{
			cin >> num;
			goods[i] = num;
		}
	}
	dfs(0, 0);
	printf("%.1lf\n", sum);
	return 0;
}
