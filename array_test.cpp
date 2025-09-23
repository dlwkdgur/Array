#include <iostream>
using namespace std;

#include "Array.h"

int main() {
	Array<int> arr = Array<int>();
	arr.add(1);
	arr.list();
	cout << endl;
	int count = arr.size();
	cout << count << endl;
	arr.add(2);
	arr.list();
	cout << endl;
	arr.add(3);
	arr.list();
	cout << arr.pop() << endl;
	cout << endl;
	arr.list();

	cout << "arr[0] : "<< arr[0] << endl;

	Array<int> list = Array<int>(arr);
	list.list();

	cout << endl;
	Array<int> array = list;
	array.list();
	cout << endl;
	array.add(10);
	array.list();

	Array<int> asdf = { 10, 20, 30 };
	asdf.list();
	for (int value : asdf) {
		cout << "test" << value;
	}
	cout << endl;
	system("pause");
}