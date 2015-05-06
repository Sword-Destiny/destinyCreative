#include <iostream>
#include <algorithm>
using namespace std;

//数据定义
#define MAX_N 100
int memo[MAX_N + 1];
int m;

int fib(int n) {
	if (n <= 1) {
		return n;
	}
	else if (memo[n] != 0) {
		return memo[n];
	}
	else {
		memo[n] = fib(n - 1) + fib(n - 2);
		return memo[n];
	}
}

/*解*/
void solve() {
	cout << fib(m) << endl;
}



int main() {
	//输入数据
	cin >> m;
	solve();
	system("pause");//不必要的语句
	return 0;
}