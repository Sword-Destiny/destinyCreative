#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

void test_priority_queue_max() {
	priority_queue<int, vector<int>, less<int> > q;
	for (int i = 0; i < 10; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
}

void test_priority_queue_min() {
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < 10; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
}