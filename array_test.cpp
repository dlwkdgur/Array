#include <iostream>
using namespace std;

typedef int Element;
#include "array.h";

int main() {
	init();
	add(1);
	add(10);
	add(100);
	add(101);
	list();
	int count = size();
	cout << count << endl;
	remove_node();
	list();

	add(200);
	add(300);
	list();

	remove_node(4);
	list();

	remove_node(2);
	list();
}