#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

//���ݶ���
int n, d;
int* points;

/*��*/
void solve() {
	//��������
	cin >> n >> d;
	int total = 0;
	points = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> points[i];
	}
	sort(points, points + n);
	//����
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
	//���
	cout << total << endl;
	delete[] points;
}



int main() {
	solve();
	system("pause");//����Ҫ�����
	return 0;
}