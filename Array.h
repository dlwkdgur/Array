#pragma once
#include <iostream>
using namespace std;
template <typename type>

class Array {
private:
	int count;
public :
	//배열 생성, 배열 사이즈 생성
	type* array;
	Array() {
		count = 0;
		array = nullptr;
	}
	~Array() {
		delete[] array;
	}
	//메소드
	//원소의 수
	int size() { return count; }
	//현재 array가 비었냐
	bool empty() { return (count == 0); }
	//첫 번째 원소를 반환함
	type front() { return array[0]; }
	//마지막 원소를 반환함
	type back() { return array[count - 1]; }
	//원소들 나열
	void list() {
		for (int i = 0; i < count; i++) {
			cout << array[i] << "\t";
		}
		cout << endl;
	}
	//새 원소를 배열의 마지막 위치에 추가함(크기가 1증가함)
	void add(type value) {
		type* before = new type[count + 1];
		for (int i = 0; i < count; i++) {//값을 대입함
			*(before + i) = *(array + i);
		}
		count++;
		before[count - 1] = value;
		delete[] array;
		array = before;
	}
	//벡터의 마지막 원소를 제거(크기가 1감소)
	type pop() {
		if (empty()) throw out_of_range("Array is Empty");
		
		type value = array[count - 1];
		count--;
		type* before = new type[count];
		for (int i = 0; i < count; i++) {
			before[i] = array[i];
		}

		delete[] array;
		array = before;
		return value;
	}

	//[]연산자 오버로딩
	type& operator[] (int index) {
		if (index < 0 || index >= count) throw out_of_range("Index Out of Range");

		return array[index];
	}
	const type& operator[] (int index) const {
		if (index < 0 || index >= count) throw out_of_range("Index Out of Range");

		return array[index];
	}

};