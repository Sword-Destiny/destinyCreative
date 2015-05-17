#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
#include <cmath>
#include <iomanip>
#include <queue>
#include <vector>
#include <functional>
//霍夫曼编码

using namespace std;

//数据定义
int n, *l;
priority_queue<int, vector<int>, greater<int> > q;

/*解*/
void solve() {
	//输入数据
	cin >> n;
	l = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> l[i];
		q.push(l[i]);
	}
	//解题
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
	//析构
	delete[] l;
}



int main() {
	solve();
	system("pause");//不必要的语句
	return 0;
}