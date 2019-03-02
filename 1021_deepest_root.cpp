#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e4 + 5;
int n, p[MAXN], d[MAXN];
bool used[MAXN], isAns[MAXN];
queue <int> q;
vector <int> G[MAXN], roots;

int find(int x){
	return x == p[x] ? x : p[x] = find(p[x]);
}
void unite(int x, int y){
	p[find(x)] = find(y);
}
int ok(){
	int rtn = 0;
	for(int i = 0; i < n; i ++)
		if(find(i) == i) rtn ++;
	return rtn;
}
int bfs(int s){
	int rtn = -1;
	fill(used, used + n, false);
	d[s] = 0;
	used[s] = 1;
	q.push(s);
	while(!q.empty()){
		int f = q.front();
		q.pop();
		for(int i = G[f].size() - 1; i >= 0; i --){
			int tmp = G[f][i];
			if(!used[tmp]){
				used[tmp] = 1;
				q.push(tmp);
				d[tmp] = d[f] + 1;
				rtn = max(rtn, d[tmp]);
			}
		}
	}
	return rtn;
}
void solve(){
	int t = bfs(0);
	for(int i = 0; i < n; i ++){
		if(t == d[i]){
			roots.push_back(i);
			isAns[i] = 1;
		}
	}
	t = bfs(roots[0]);
	for(int j = 0; j < n; j ++){
		if(d[j] == t && !isAns[j]){
			roots.push_back(j);
			isAns[j] = 1;
		}
	}
	sort(roots.begin(), roots.end());
	cout << roots[0] + 1 << endl;
	for(int i = 1; i < roots.size(); i ++){
		if(roots[i] != roots[i - 1])
		cout << 1 + roots[i] << endl;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	while(cin >> n){
		if(n == 1){
			cout << n << endl;
			return 0;
		}
		for(int i = 0; i < n; i ++){
			p[i] = i;
			G[i].clear();
		}
		for(int i = 1; i < n; i ++){
			int u, v;
			cin >> u >> v;
			u --, v --;
			unite(u, v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int tmp = ok();
		if(tmp == 1){
			solve();
		}else{
			cout << "Error: " << tmp << " components" << endl;
		}
		break;
	}
	return 0;
}
