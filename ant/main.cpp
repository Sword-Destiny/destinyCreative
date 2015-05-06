#include <iostream>
//�˽ⷨ������
using namespace std;

//���ݶ���
#define MAX_N 1000000
int l, n, x[MAX_N];

/*���⺯��*/
void solve() {
	int min = 0, max = 0;
	for (int i = 0; i < n; i++) {
		int least = l - x[i];
		if (x[i] < least) {
			min = x[i] > min ? x[i] : min;
			max = least > max ? least : max;
		}
		else {
			min = least > min ? least : min;
			max = x[i] > max ? x[i] : max;
		}
	}
	cout << "min=" << min << endl;
	cout << "max=" << max << endl;
}

int main() {
	//��������
	cin >> l >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	solve();
	system("pause");//����Ҫ�����
	return 0;
}