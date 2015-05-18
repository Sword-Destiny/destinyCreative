#include <iostream>
#include <algorithm>
#include <iomanip>
//��������

using namespace std;

//���ݶ���
int n, *w, *v, W;

#define FAST

#ifndef FAST
//�ӵ�i����Ʒ��ʼ��ѡ����С�ڵ���j�Ĳ���
int rec(int i, int j) {
	int res;
	if (i == n) {
		//��ʣ����Ʒ
		return 0;
	}
	else if (j < w[i]) {
		//����ѡ���i����Ʒ
		res = rec(i + 1, j);
	}
	else {
		//����ѡ���i����Ʒ����ѡ�Ͳ���ѡ���������һ��
		res = max(rec(i + 1, j), v[i] + rec(i + 1, j - w[i]));
	}
	return res;
}

/*��*/
void solve() {
	//��������
	cin >> n;
	w = new int[n];
	v = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	cin >> W;
	//����
	int ans = 0;
	ans = rec(0, W);
	cout << ans << endl;
	//����
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
	//��������
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
	//����
	int ans = 0;
	ans = rec1(0, W);
	cout << ans << endl;
	//����
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
	system("pause");//����Ҫ�����
#endif
	return 0;
}