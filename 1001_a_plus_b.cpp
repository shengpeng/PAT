#include <bits/stdc++.h>
#define inf (1<<29)
#define ll long long
using namespace std;
int a, b;
int main(void)
{
	cin >> a >> b;
	a += b;
	cout << (a < 0 ? "-" : "");
	a = abs(a);
	stack <char> s;
	int i = 0;
	while(a){
		i ++;
		int t = a % 10;
		s.push(t + '0');
		a /= 10;
		if(i % 3 == 0 && a)
			s.push(',');
	}
	if(s.empty()) cout << 0;
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return 0;
}
