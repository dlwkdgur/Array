#pragma once
#include <iostream>

template <typename type>

class Array {
private:
	//배열을 추가하거나 삭제 할 떄 이전의 값을 가지고 있을 배열
	type* before;
	int count;
public :
	//배열 생성, 배열 사이즈 생성
	type* array;
	Array() {
		count = 0;
		array = new type[count];
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
		before = new type[count];
		for (int i = 0; i < count; i++) {//값을 대입함
			*(before + i) = *(array + i);
		}
		count++;
		array = new int[count];
		for (int i = 0; i < count - 1; i++) {
			*(array + i) = *(before + i);
		}
		array[count - 1] = value;
		delete[] before;
	}
	//벡터의 마지막 원소를 제거(크기가 1감소)
	type pop() {
		count--;
		return array[count];
	}

};