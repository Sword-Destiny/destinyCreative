#include <iostream>
#include <algorithm>
using namespace std;
#include "dfs_test.h"

//���ݶ���
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
	//��������
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> sum;
	solve();
	delete[] a;
	system("pause");//����Ҫ�����
	return 0;
}