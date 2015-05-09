#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;


//数据定义
string s;

/*解*/
void solve() {
	//输入数据
	cin >> s;
	int end_index = (int)s.length() - 1;
	int start_index = 0;
	//解题
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
	//结果
	cout << t << endl;
}



int main() {
	solve();
	system("pause");//不必要的语句
	return 0;
}