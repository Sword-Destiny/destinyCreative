#pragma once
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void test_queue() {
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}