#include <iostream>
#include <algorithm>
using namespace std;

//���ݶ���
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

/*��*/
void solve() {
	cout << fib(m) << endl;
}



int main() {
	//��������
	cin >> m;
	solve();
	system("pause");//����Ҫ�����
	return 0;
}