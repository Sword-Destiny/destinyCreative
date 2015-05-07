#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

//���ݶ���
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

/*��*/
void solve() {
	//��������
	cin >> N >> M;
	fields = new char*[N];
	for (int i = 0; i < N; i++) {
		fields[i] = new char[M];
		getchar();
		for (int j = 0; j < M; j++) {
			fields[i][j] = getchar();
		}
	}
	//����
	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (fields[i][j] == 'W') {
				dfs(i, j);
				num++;
			}
		}
	}
	cout << "ˮ������: " << num << endl;
	//����
	for (int i = 0; i < N; i++) {
		delete[] fields[i];
	}
	delete[] fields;
}



int main() {
	solve();
	system("pause");//����Ҫ�����
	return 0;
}