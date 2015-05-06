#include <iostream>
#include <algorithm>
using namespace std;

#include "./headers/stack_test.h"
#include "./headers/queue_test.h"
#include "./headers/priority_queue_test.h"
//数据定义


/*解*/
void solve() {
	test_priority_queue_max();
	test_priority_queue_min();
	test_stack();
	test_queue();
}



int main() {
	//输入数据
	
	solve();
	system("pause");//不必要的语句
	return 0;
}