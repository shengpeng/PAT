#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1005;
int n, m, k, u, v, cnt;
bool g[MAXN][MAXN], used[MAXN];

void dfs(int s){
	used[s] = 1;
	for(int i = 0; i < n; i ++){
		if(!used[i] && g[s][i]){
			dfs(i);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i ++){
		cin >> u >> v;
		u --, v --;
		g[v][u] = g[u][v] = 1;
	}
	for(int i = 0; i < k; i ++){
		cin >> u;
		u --;
		cnt = -1;
		for(int j = 0; j < n; j ++) used[j] = 0;
		used[u] = 1;
		for(int j = 0; j < n; j ++){
			if(!used[j]){
				dfs(j);
				cnt ++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
