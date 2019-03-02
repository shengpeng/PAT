#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1005;
int ok, u, v, n, m, k, space, g[MAXN][MAXN], arr[MAXN], indeg[MAXN];
inline void copy(){
	for(int i = 0; i < MAXN; i ++)
		indeg[i] = arr[i];
}

int main(void)
{
	cin >> n >> m;
	for(int i = 0; i < m; i ++){
		cin >> u >> v;
		g[u][v] = 1;
		arr[v] ++;
	}
	cin >> m;
	for(int i = 0; i < m; i ++){
		copy();
		ok = 1;
		for(int j = 0; j < n; j ++){
			cin >> v;
			if(ok){
				if(!indeg[v])
					for(int k = 1; k <= n; k ++){
						if(g[v][k]) indeg[k] --;
					}
				else
					ok = 0;
			}
		}
		if(ok) continue;
		if(!space)
			space = 1;
		else
			cout << " ";
		cout << i;
	}
	cout << '\n';
	return 0;
}
