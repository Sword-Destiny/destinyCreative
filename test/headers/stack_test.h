#pragma once
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void test_stack() {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}