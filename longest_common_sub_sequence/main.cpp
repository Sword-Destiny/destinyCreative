#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
//背包问题

using namespace std;

//数据定义
string str1;
string str2;
int len1;
int len2;
int** dp;

int longest_common_sub_sequence(int i, int j) {
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (i == 0 || j == 0) {
		dp[i][j] = 0;
	}
	else {
		if (str1[i - 1] == str2[j - 1]) {
			dp[i][j] = longest_common_sub_sequence(i - 1, j - 1) + 1;
		}
		else {
			dp[i][j] = max(longest_common_sub_sequence(i - 1, j), longest_common_sub_sequence(i, j - 1));
		}
	}
	return dp[i][j];
}

//dynamic programming
void solve() {
	//输入数据
	cin >> str1 >> str2;
	len1 = (int)str1.length();
	len2 = (int)str2.length();
	dp = new int*[len1 + 1];
	for (int i = 0; i < len1 + 1; i++) {
		dp[i] = new int[len2 + 1];
		for (int j = 0; j < len2 + 1; j++) {
			dp[i][j] = -1;
		}
	}
	//解题
	cout << longest_common_sub_sequence(len1, len2) << endl;
	//析构
	for (int i = 0; i < len1+1; i++) {
		delete[] dp[i];
	}
	delete[] dp;
}


int main() {
	solve();
#ifdef _WIN32
	system("pause");//不必要的语句
#endif
	return 0;
}