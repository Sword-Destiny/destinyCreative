#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;


//数据定义
int coin[6];
int money[6] = { 1,5,10,50,100,500 };
int A;

/*解*/
void solve() {
	//输入数据
	cin >> A;
	for (int i = 0; i < 6; i++) {
		cin >> coin[i];
	}
	//解题
	int ans = 0;
	for (int i = 5; i >= 0; i--) {
		int num = A / money[i];
		int t = num > coin[i] ? coin[i] : num;
		ans += t;
		A -= t*money[i];
		if (A <= 0) {
			break;
		}
	}
	//析构
	cout << ans << endl;
}



int main() {
	solve();
	system("pause");//不必要的语句
	return 0;
}