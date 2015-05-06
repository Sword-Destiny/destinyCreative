#include <iostream>
#include <algorithm>

using namespace std;

//数据定义
#define MAX_N 100
int n, a[MAX_N];

/*一般解法:此解法非最优*/
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

/*返回数组a中小于data的最大的数的索引,O(n*n*n)*/
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

/*更优的算法:非最优,O(n*n*log(n))*/
void solve1() {
	int answer = 0;
	sort(a, a + n);
	//从小到大搜索可能的最大值(不合适)
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

/*更优的算法:可选的最优解法,O(n*log(n))*/
void solve2() {
	sort(a, a + n);
	//从大到小搜索可能的最大值
	for (int i = n - 3; i >= 0; i--) {
		if (a[i] + a[i + 1] > a[i + 2]) {
			cout << (a[i] + a[i + 1] + a[i + 2]) << endl;
			return;
		}
	}
	cout << 0 << endl;
}

int main() {
	//输入数据
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	solve2();
	system("pause");//不必要的语句
	return 0;
}