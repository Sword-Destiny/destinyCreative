#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;


//���ݶ���
int n;
int* s;
int* t;
#define INF 100000000

/*��:(O(n^2))*/
void solve() {
	//��������
	cin >> n;
	s = new int[n];
	t = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	//����
	int ans = 0;
	int current_time = 0;
	bool* select = new bool[n];
	for (int i = 0; i < n; i++) {
		select[i] = false;
	}
	for (int i = 0; i < n; i++) {
		int min_t = INF;
		int min_index = -1;
		for (int j = 0; j < n; j++) {
			if (!select[j] && s[j] >= current_time) {
				if (t[j] < min_t) {
					min_t = t[j];
					min_index = j;
				}
			}
		}
		if (min_index == -1) {
			break;
		}
		select[min_index] = true;
		current_time = t[min_index];
		ans++;
	}
	//����
	delete[] s;
	delete[] t;
	//���
	cout << ans << endl;
}



int main() {
	solve();
	system("pause");//����Ҫ�����
	return 0;
}