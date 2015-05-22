#include <iostream>
#include <algorithm>
#include <iomanip>
//完全背包问题

using namespace std;

//数据定义
int n, *w, *v, W;
int **dp;

//dynamic programming
void solve1() {
	//输入数据
	cin >> n;
	w = new int[n];
	v = new int[n];
	dp = new int *[n + 1];

	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	cin >> W;
	for (int i = 0; i < n + 1; i++) {
		dp[i] = new int[W + 1];
		for (int j = 0; j < W + 1; j++) {
			dp[i][j] = 0;
		}
	}
	//解题
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= W; j++) {
			if (j < w[i]) {
				dp[i + 1][j] = dp[i][j];
			}
			else {
				dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
			}
		}
	}
	cout << dp[n][W] << endl;
	//析构
	delete[] w;
	delete[] v;
	for (int i = 0; i < n + 1; i++) {
		delete[] dp[i];
	}
	delete[] dp;
}


int main() {
	solve1();
#ifdef _WIN32
	system("pause");//不必要的语句
#endif
	return 0;
}