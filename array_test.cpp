#include <iostream>
using namespace std;

#include "Array.h"

int main() {
	Array<int> arr = Array<int>();
	arr.add(1);
	arr.list();
	int count = arr.size();
	cout << count << endl;
	arr.add(2);
	arr.list();

	arr.add(3);
	arr.list();
	cout << arr.pop() << endl;

	arr.list();
}