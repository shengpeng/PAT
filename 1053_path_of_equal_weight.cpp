#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAXN = 105;
ll n, m, s, k, data[MAXN];
vector <ll> T[MAXN];
ll in(){
	string num; cin >> num;
	ll rtn = 0, i = 0;
	while(num[i] == '0' && i < num.size())
		i ++;
	while(i < num.size())
		rtn = rtn * 10 + num[i ++] - '0';
	return rtn;
}

vector <ll> path;

void dfs(ll p, ll curS){
	if(curS > s) return ;
	if(curS == s){
		if(!T[p].size()){
			for(ll i = 0; i < path.size(); i ++){
				cout << path[i] << " \n"[i + 1 == path.size()];
			}
		}
		return ;
	}
	for(ll i = 0; i < T[p].size(); i ++){
		path.push_back(data[T[p][i]]);
		dfs(T[p][i], curS + data[T[p][i]]);
		path.pop_back();
	}
}

bool cmp(ll a, ll b){
	return data[a] > data[b];
}

int main(void)
{
	cin >> n >> m >> s;
	for(ll i = 0; i < n; i ++) {
		cin >> data[i];
	}
	for(ll i = 0; i < m; i++) {
		ll id = in();
		cin >> k;
		T[id].resize(k);
		for(ll j = 0; j < k; j ++){
			T[id][j] = in();
		}
		sort(T[id].begin(), T[id].end(), cmp);
	}
	path = {data[0]};
	dfs(0, data[0]);
	return 0;
}