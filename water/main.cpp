#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

//数据定义
int N, M;
char** fields;

void dfs(int x, int y) {
	if (fields[x][y] == 'W') {
		fields[x][y] = '.';
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (x + i >= 0 && x + i < N&&y + j >= 0 && y + j < M&&fields[x + i][y + j] == 'W') {
					dfs(x + i, y + j);
				}
			}
		}
	}
}

/*解*/
void solve() {
	//输入数据
	cin >> N >> M;
	fields = new char*[N];
	for (int i = 0; i < N; i++) {
		fields[i] = new char[M];
		getchar();
		for (int j = 0; j < M; j++) {
			fields[i][j] = getchar();
		}
	}
	//解题
	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (fields[i][j] == 'W') {
				dfs(i, j);
				num++;
			}
		}
	}
	cout << "水洼数量: " << num << endl;
	//析构
	for (int i = 0; i < N; i++) {
		delete[] fields[i];
	}
	delete[] fields;
}



int main() {
	solve();
	system("pause");//不必要的语句
	return 0;
}