#include <bits/stdc++.h> 
using namespace std;

const int MAXN = 105;
int n, arr[MAXN], tArr[MAXN], partial[MAXN]; 

bool same(){
	for(int i = 1; i <= n; i ++){
		if(tArr[i] != partial[i]) return 0;
	}
	return 1;
}

bool same2(){
	for(int i = 1; i <= n; i ++){
		if(arr[i] != partial[i]) return 0;
	}
	return 1;
}

bool isort(){
	for(int i = 2; i <= n; i ++){
		sort(tArr + 1, tArr + i + 1);
		if(same()){
			sort(tArr + 1, tArr + i + 2);
			return 1;
		}
	}
	return 0;
}

void down(int low, int high){
	int i = low, j = 2 * i;
	while(j <= high){
		if(j + 1 <= high && arr[j + 1] > arr[j]){
			j ++;
		}
		if(arr[i] < arr[j]){
			swap(arr[i], arr[j]);
			i = j;
			j = 2 * i;
		}
		else{
			break;
		}
	}
}

void show(){
	cout << "++";
	for(int i = 1; i <= n; i ++){
		cout << arr[i] << " \n"[i == n];
	}
}

bool hsort(){
	for(int i = n / 2; i >= 1; i --){
		down(i, n);
	}
	for(int i = n; i > 1; i --){
		swap(arr[i], arr[1]);
		down(1, i - 1);
//		show();
		if(same2()) {
			swap(arr[i - 1], arr[1]);
			down(1, i - 2);
			return 1;
		}
	}
	return 0;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> arr[i];
		tArr[i] = arr[i];
	}
	for(int i = 1; i <= n; i ++){
		cin >> partial[i];
	}
	if(isort()){
		cout << "Insertion Sort" << endl;
		for(int i = 1; i <= n; i ++){
			cout << tArr[i] << " \n"[i == n];
		}
	}else{
		cout << "Heap Sort" << endl;
		hsort();
		for(int i = 1; i <= n; i ++){
			cout << arr[i] << " \n"[i == n];
		}
	}
	return 0;
}