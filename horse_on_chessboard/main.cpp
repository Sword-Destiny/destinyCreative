#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
#include <cmath>
#include <iomanip>
//马踏棋盘

using namespace std;

//数据定义
int m, n;
pair<int, int> start_point;
bool** chessboard;
list<pair<int, int>> path;
int total = 0;
class direction {
public:
	int nx, ny, num;
	direction() {}
	direction(int x, int y) :nx(x), ny(y), num(0) {}
	inline bool operator<(const direction& d) {
		return this->num < d.num;
	}
};

int xx[8] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int yy[8] = { 2, -2, 1, -1, 2, -2, 1, -1 };

bool solve_least() {
	if (total == m*n) {
		for (int i = 0; i < 8; i++) {
			if (path.front().first + xx[i] == path.back().first&&path.front().second + yy[i] == path.back().second) {
				return true;
			}
		}
		return false;
	}
	direction ds[8];
	for (int i = 0; i < 8; i++) {
		ds[i].nx = xx[i];
		ds[i].ny = yy[i];
		ds[i].num = 0;
		if (start_point.first + xx[i] < m&&start_point.second + yy[i] < n&&start_point.first + xx[i] >= 0 && start_point.second + yy[i] >= 0 && !chessboard[start_point.first + xx[i]][start_point.second + yy[i]]) {
			chessboard[start_point.first + xx[i]][start_point.second + yy[i]] = true;
			start_point.first += xx[i];
			start_point.second += yy[i];
			for (int j = 0; j < 8; j++) {
				if (start_point.first + xx[j] < m&&start_point.second + yy[j] < n&&start_point.first + xx[j] >= 0 && start_point.second + yy[j] >= 0 && !chessboard[start_point.first + xx[j]][start_point.second + yy[j]]) {
					ds[i].num++;
				}
			}
			start_point.first -= xx[i];
			start_point.second -= yy[i];
			chessboard[start_point.first + xx[i]][start_point.second + yy[i]] = false;
		}
	}
	sort(ds, ds + 8);
	for (int i = 0; i < 8; i++) {
		if (ds[i].num>0) {
			start_point.first += ds[i].nx;
			start_point.second += ds[i].ny;
			chessboard[start_point.first][start_point.second] = true;
			path.push_back(start_point);
			total++;
			if (solve_least()) {
				return true;
			}
			total--;
			path.pop_back();
			chessboard[start_point.first][start_point.second] = false;
			start_point.first -= ds[i].nx;
			start_point.second -= ds[i].ny;
		}
	}
	for (int i = 0; i < 8; i++) {
		if (ds[i].num == 0 && start_point.first + ds[i].nx < m&&start_point.second + ds[i].ny < n&&start_point.first + ds[i].nx >= 0 && start_point.second + ds[i].ny >= 0 && !chessboard[start_point.first + ds[i].nx][start_point.second + ds[i].ny]) {
			start_point.first += ds[i].nx;
			start_point.second += ds[i].ny;
			chessboard[start_point.first][start_point.second] = true;
			path.push_back(start_point);
			total++;
			if (solve_least()) {
				return true;
			}
			total--;
			path.pop_back();
			chessboard[start_point.first][start_point.second] = false;
			start_point.first -= ds[i].nx;
			start_point.second -= ds[i].ny;
		}
	}
	return false;
}

/*解*/
void solve() {
	//输入数据
	cin >> m >> n;
	int x, y;
	cin >> x >> y;
	start_point.first = x;
	start_point.second = y;
	chessboard = new bool*[m];
	for (int i = 0; i < m; i++) {
		chessboard[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			chessboard[i][j] = false;
		}
	}
	chessboard[start_point.first][start_point.second] = true;
	total++;
	path.push_front(start_point);
	//解题
	if (solve_least()) {
		cout << "Yes!" << endl;
		int** chess_path = new int*[m];
		for (int i = 0; i < m; i++) {
			chess_path[i] = new int[n];
		}
		int index = 1;
		while (!path.empty()) {
			chess_path[path.front().first][path.front().second] = index++;
			path.pop_front();
		}
		int length = (int)log10(m*n) + 1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << setw(length) << chess_path[i][j] << " ";
			}
			cout << endl;
			delete[] chess_path[i];
		}
		delete[] chess_path;
	}
	else {
		cout << "No!" << endl;
	}
	//析构
	for (int i = 0; i < m; i++) {
		delete[] chessboard[i];
	}
	delete[] chessboard;
}



int main() {
	solve();
	system("pause");//不必要的语句
	return 0;
}