#include <iostream>
#include <algorithm>
using namespace std;
#include <string>
using std::string;
bool first;

bool dfs(int* a, int n, int i, int sum) {
	if (sum < 0) {
		return false;
	}
	else if (sum == 0) {
		return true;
	}
	if (i < n) {
		if (dfs(a, n, i + 1, sum - a[i])) {
			if (first) {
				cout << "{" << a[i];
				first = false;
			}
			else {
				cout << " + " << a[i];
			}
			return true;
		}
		return dfs(a, n, i + 1, sum);
	}
	return false;
}

//数据定义
int n;
int* a;
int sum;

void solve() {
	first = true;
	if (dfs(a, n, 0, sum)) {
		cout << " = " << sum << "} Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}

int main() {
	//输入数据
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> sum;
	solve();
	delete[] a;
	system("pause");//不必要的语句
	return 0;
}