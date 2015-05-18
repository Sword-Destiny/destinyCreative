#include <iostream>
#include <algorithm>
#include <iomanip>
//背包问题

using namespace std;

//数据定义
int n, *w, *v, W;

#define FAST

#ifndef FAST
//从第i个物品开始挑选总重小于等于j的部分
int rec(int i, int j) {
	int res;
	if (i == n) {
		//无剩余物品
		return 0;
	}
	else if (j < w[i]) {
		//不能选择第i个物品
		res = rec(i + 1, j);
	}
	else {
		//可以选择第i个物品，挑选和不调选的情况都试一下
		res = max(rec(i + 1, j), v[i] + rec(i + 1, j - w[i]));
	}
	return res;
}

/*解*/
void solve() {
	//输入数据
	cin >> n;
	w = new int[n];
	v = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	cin >> W;
	//解题
	int ans = 0;
	ans = rec(0, W);
	cout << ans << endl;
	//析构
	delete[] w;
	delete[] v;
}
#else
int **dp;

int rec1(int i, int j) {
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	int res;
	if (i == n) {
		res = 0;
	}
	else if (j < w[i]) {
		res = rec1(i + 1, j);
	}
	else {
		res = max(rec1(i + 1, j), v[i] + rec1(i + 1, j - w[i]));
	}
	dp[i][j] = res;
	return res;
}


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
			dp[i][j] = -1;
		}
	}
	//解题
	int ans = 0;
	ans = rec1(0, W);
	cout << ans << endl;
	//析构
	delete[] w;
	delete[] v;
	for (int i = 0; i < n + 1; i++) {
		delete[] dp[i];
	}
	delete[] dp;
}

#endif

int main() {
#ifndef FAST
	solve();
#else
	solve1();
#endif
#ifdef _WIN32
	system("pause");//不必要的语句
#endif
	return 0;
}