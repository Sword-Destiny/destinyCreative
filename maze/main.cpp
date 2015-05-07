#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

class point {
public:
	int x, y, value;
	point(const int& nx, const int& ny, const int& nv) :x(nx), y(ny), value(nv) {}
};

//数据定义
int N, M;
char** fields;
int sx, sy, ex, ey;
bool has_answer = false;
int min_path;

void bfs() {
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	queue<point> q;
	q.push(point(sx, sy, 0));
	fields[sx][sy] = '#';
	while (!q.empty()) {
		point p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (nx >= 0 && nx < N&&ny >= 0 && ny < M) {
				if (fields[nx][ny] == 'G') {
					has_answer = true;
					min_path = p.value + 1;
					return;
				}
				if (fields[nx][ny] != '#') {
					q.push(point(nx, ny, p.value + 1));
					fields[nx][ny] = '#';
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
			if (fields[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (fields[i][j] == 'G') {
				ex = i;
				ey = j;
			}
		}
	}
	//解题
	bfs();
	//析构
	for (int i = 0; i < N; i++) {
		delete[] fields[i];
	}
	delete[] fields;
	if (has_answer) {
		cout << "最短路径: " << min_path << endl;
	}
	else {
		cout << "No" << endl;
	}
}



int main() {
	solve();
	system("pause");//不必要的语句
	return 0;
}