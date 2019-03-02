#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAXN = 505, INF = (1LL << 40);
ll c, n, sd, sp, m, sum, arr[MAXN], g[MAXN][MAXN], d[MAXN];
bool used[MAXN];
vector <ll> curPath, path;

void dijstra(){
	fill(d, d + n + 5, INF);
	d[0] = 0;
	while(1){
		ll v = -1;
		for(ll i = 0; i <= n; i ++)
			if(!used[i] && (v == -1 || d[v] > d[i])) v = i;
		if(v == -1) break;
		used[v] = 1;
		for(ll i = 0; i <= n; i ++)
			d[i] = min(d[i], d[v] + g[v][i]);
	}
}

ll cal(){
	ll rtn = 0, tmp;
	for(ll i = curPath.size() - 1; i >= 0; i --){
		tmp = arr[curPath[i]] - (c / 2);
		rtn += tmp;
		if(rtn > 0) rtn = 0;
	}
	return -rtn;
}

ll cal(vector<ll> vec, ll t){
	for(int i = vec.size() - 1; i >= 0; i --) t += arr[vec[i]];
	return t - vec.size() * (c / 2);
}

ll dfs(ll poll,ll dis){
	if(dis > sp) return 1;
	if(poll == sp && dis == sd){
		ll tmp = cal();
		if(path.size()){
			if(tmp < sum || (tmp == sum && cal(curPath, tmp) < cal(path, sum))){
				sum = tmp;
				path = curPath;
			}
		}
		else{
			path = curPath;
			sum = tmp;
		}
		return 2;
	}
	for(ll i = 1; i <= n; i ++){
		if(!used[i] && g[poll][i] < INF){
			used[i] = 1;
			curPath.push_back(i);
			dfs(i, dis + g[poll][i]);
			used[i] = 0;
			curPath.pop_back();
		}
	}
	return 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin >> c >> n >> sp >> m;
	for(ll i = 0; i <= n; i ++){
		for(ll j = 0; j <= n; j ++){
			g[i][j] = INF;
		}
	}
	for(ll i = 1; i <= n; i ++) cin >> arr[i];
	for(ll i = 0; i < m; i ++){
		ll x, y, z;
		cin >> x >> y >> z;
		g[y][x] = min(g[y][x], z);
		g[x][y] = g[y][x];
	}
	dijstra();
	sd = d[sp];
	fill(used, used + n + 1, false);
	used[0] = 1;
	dfs(0, 0);
	cout << sum << " 0->";
	for(ll i = 0; i < path.size(); i ++){
		cout << path[i] << (i + 1 == path.size() ? " " : "->");
		// sum += arr[path[i]];
	}
	cout << cal(path, sum) << endl;
	return 0;
}