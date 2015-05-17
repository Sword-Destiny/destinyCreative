#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
#include <cmath>
#include <iomanip>
#include <queue>
#include <vector>
#include <functional>
//����������

using namespace std;

//���ݶ���
int n, *l;
priority_queue<int, vector<int>, greater<int> > q;

/*��*/
void solve() {
	//��������
	cin >> n;
	l = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> l[i];
		q.push(l[i]);
	}
	//����
	int ans = 0;
	while (q.size()>1) {
		int x = q.top();
		q.pop();
		int y = q.top();
		q.pop();
		ans = ans + x + y;
		q.push(x + y);
	}
	cout << ans << endl;
	//����
	delete[] l;
}



int main() {
	solve();
	system("pause");//����Ҫ�����
	return 0;
}