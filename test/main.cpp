#include <iostream>
#include <algorithm>
using namespace std;

#include "./headers/stack_test.h"
#include "./headers/queue_test.h"
#include "./headers/priority_queue_test.h"
//���ݶ���


/*��*/
void solve() {
	test_priority_queue_max();
	test_priority_queue_min();
	test_stack();
	test_queue();
}



int main() {
	//��������
	
	solve();
	system("pause");//����Ҫ�����
	return 0;
}