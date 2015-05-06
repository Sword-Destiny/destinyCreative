#include <iostream>
#include <algorithm>

using namespace std;

//���ݶ���
#define MAX_N 100
int n, a[MAX_N];

/*һ��ⷨ:�˽ⷨ������*/
void solve() {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (a[i] + a[j]>a[k] && a[j] + a[k]>a[i] && a[k] + a[i]>a[j]) {
					int l = a[i] + a[j] + a[k];
					if (l > answer) {
						answer = l;
					}
				}
			}
		}
	}
	cout << answer << endl;
}

/*��������a��С��data��������������,O(n*n*n)*/
int index_of(int* arr, int low, int high, int data) {
	int mid = -1;
	while (high >= low) {
		mid = (low + high) / 2;
		if (arr[mid] == data) {
			break;
		}
		if (arr[mid] < data) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return low <= high ? mid - 1 : high;
}

/*���ŵ��㷨:������,O(n*n*log(n))*/
void solve1() {
	int answer = 0;
	sort(a, a + n);
	//��С�����������ܵ����ֵ(������)
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int val = a[i] + a[j];
			int index = index_of(a, j, n - 1, val);
			if (index > j) {
				int l = a[index] + val;
				if (l > answer) {
					answer = l;
				}
			}
		}
	}
	cout << answer << endl;
}

/*���ŵ��㷨:��ѡ�����Žⷨ,O(n*log(n))*/
void solve2() {
	sort(a, a + n);
	//�Ӵ�С�������ܵ����ֵ
	for (int i = n - 3; i >= 0; i--) {
		if (a[i] + a[i + 1] > a[i + 2]) {
			cout << (a[i] + a[i + 1] + a[i + 2]) << endl;
			return;
		}
	}
	cout << 0 << endl;
}

int main() {
	//��������
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	solve2();
	system("pause");//����Ҫ�����
	return 0;
}