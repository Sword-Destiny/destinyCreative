#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

//数据定义
int n, d;
int* points;

/*解*/
void solve() {
	//输入数据
	cin >> n >> d;
	int total = 0;
	points = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> points[i];
	}
	sort(points, points + n);
	//解题
	int index = 0;
	while (index < n) {
		int i;
		int current = points[index] + d;
		for (i = index + 1; i < n; i++) {
			if (points[i] > current) {
				break;
			}
		}
		index = i - 1;
		total++;
		current = points[index] + d;
		for (i = index + 1; i < n; i++) {
			if (points[i] > current) {
				break;
			}
		}
		index = i;
	}
	//结果
	cout << total << endl;
	delete[] points;
}



int main() {
	solve();
	system("pause");//不必要的语句
	return 0;
}