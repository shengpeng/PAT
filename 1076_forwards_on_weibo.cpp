#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1010;
int N, L;
int inque[maxn];
struct Node{
	int layer;
	vector<int>fans;
}arr[maxn];
queue<int>q;
int bfs(int s){
	int num=0;
	q.push(s);
	inque[s]=1;
	arr[s].layer=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		// 1 2 3 ... L 层都可以
		if(arr[u].layer>=1&&arr[u].layer<=L) num++;
		for(int i=0; i<arr[u].fans.size(); i++){
			int v=arr[u].fans[i];
			if(inque[v]==0 && arr[u].layer <= 2){
				q.push(v);
				inque[v]=1;
				// 确定没被访问过才能更改他的层数，否则可能会重复修改层数
				arr[v].layer=arr[u].layer+1;
			}
		}
	}
	return num;
}
int main(){
	int K, num, p, query;
	scanf("%d%d", &N, &L);
	for(int i=1; i<=N; i++){
		scanf("%d", &num);
		for(int j=1; j<=num; j++){
			scanf("%d", &p);
			arr[p].fans.push_back(i);
		}
	}
	scanf("%d", &K);
	for(int i=1; i<=K; i++){
		memset(inque, 0, sizeof(inque));
		scanf("%d", &query);
		int cnt=bfs(query);
		printf("%d\n", cnt);
	}
	return 0;
}