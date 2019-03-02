#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, x, y, sum;

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> y;
		if(y > x)
			sum += (y - x) * 6;
		else if(y < x)
			sum += (x - y) * 4;
		swap(x, y);
	}
	cout << sum + n * 5 << endl;
	return 0;
}
