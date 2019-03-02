#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXK = 33;
int k;
struct p{int e;int level;};
vector <p> levelTra;
int post[MAXK], in[MAXK];

void findRoot(int il, int ir, int pl, int pr, int le){//findRoot(0, k, 0, k, 0);
	if(il >= ir) return ;
	levelTra.push_back({post[pr - 1], le});
	int p, ls;
	for(p = il; p < ir; p ++)
		if(in[p] == post[pr - 1])
			break;
	ls = p - il;
	findRoot(il, p, pl, pl + ls, le + 1);
	findRoot(p + 1, ir, pl + ls, pr - 1, le + 1);
}

// void findRoot(int pl, int pr, int il, int ir, int le){// findRoot(0, k - 1, 0, k - 1, 0);
// 	if(pl > pr) return ;
// 	levelTra.push_back({post[pr], le});
// 	int k = il;
// 	for(; k <= ir; k ++)
// 		if(in[k] == post[pr])
// 			break;
// 	int numl = k - il;
// 	findRoot(pl, pl + numl - 1, il, k - 1, le + 1);
// 	findRoot(pl + numl, pr - 1, k + 1, ir, le + 1);
// }

int main(void)
{
	ios::sync_with_stdio(false);
	cin >> k;
	for(int i = 0; i < k; i ++) cin >> post[i];
	for(int i = 0; i < k; i ++) cin >> in[i];
	// findRoot(0, k - 1, 0, k - 1, 0);
	findRoot(0, k, 0, k, 0);
	for(int i = levelTra.size() - 1; i >= 0; i --){
		for(int j = 0; j < i; j ++){
			if(levelTra[j].level > levelTra[j + 1].level){
				swap(levelTra[j], levelTra[j + 1]);
			}
		}
	}
	for(int i = 0; i < levelTra.size(); i ++){
		cout << levelTra[i].e << " \n"[i + 1 == levelTra.size()];
	}
	return 0;
}
