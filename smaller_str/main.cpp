#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;


//���ݶ���
string s;

/*��*/
void solve() {
	//��������
	cin >> s;
	int end_index = (int)s.length() - 1;
	int start_index = 0;
	//����
	string t;
	while (end_index >= start_index) {
		char left = s[start_index];
		char right = s[end_index];
		if (left < right) {
			start_index++;
			t += left;
		}
		else {
			end_index--;
			t += right;
		}
	}
	//���
	cout << t << endl;
}



int main() {
	solve();
	system("pause");//����Ҫ�����
	return 0;
}