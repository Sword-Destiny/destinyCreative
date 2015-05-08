#pragma once
#include <string>
using std::string;
bool first;

bool dfs(int* a, int n, int i, int sum) {
	if (sum == 0) {
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