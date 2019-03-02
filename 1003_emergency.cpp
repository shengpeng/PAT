#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505, INF = (1 << 29);
bool used[MAXN];
int g[MAXN][MAXN], d[MAXN], num[MAXN];
int n, m, s, t, cnt, men, sp;

void dijstra(){
	fill(d, d + n, INF);
	d[s] = 0;
	while(1){
	int v = -1;
	for(int i = 0; i < n; i ++){
		if(!used[i] && (v == -1 || d[v] > d[i])) v = i;
	}
	if(v == -1) break;
	used[v] = 1;
	for(int i = 0; i < n; i ++){
		d[i] = min(d[i], d[v] + g[v][i]);
	}
	}
}

void dfs(int v, int curDis, int curMen){
	if(curDis > sp) return ;
	if(v == t){
		if(curDis == sp){
			cnt ++;
			men = max(curMen, men);
		}
		return ;
	}
	for(int i = 0; i < n; i ++){
		if(!used[i] && g[v][i] < INF){
			used[i] = 1;
			dfs(i, curDis + g[v][i], curMen + num[i]);
			used[i] = 0;
		}
	}
}

int main(void){
	men = -1;
	cin >> n >> m >> s >> t;
	for(int i = 0; i < n; i ++){
		cin >> num[i];
		for(int j = 0; j < n; j ++)
			g[i][j] = INF;
	}
	for(int i = 0; i < m; i ++){
		int x, y;
		cin >> x >> y;
		cin >> g[x][y];
		g[y][x] = g[x][y];
	}
	dijstra();
	sp = d[t];
	memset(used, 0, sizeof used);
	dfs(s, 0, num[s]);
	cout << cnt << " " << men << '\n';
	return 0;
}
