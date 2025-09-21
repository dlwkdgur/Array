#pragma once
#include <iostream>
using namespace std;
template <typename type>

class Array {
private:
	int count;
public :
	//�迭 ����, �迭 ������ ����
	type* array;
	Array() {
		count = 0;
		array = nullptr;
	}
	~Array() {
		delete[] array;
	}
	//�޼ҵ�
	//������ ��
	int size() { return count; }
	//���� array�� �����
	bool empty() { return (count == 0); }
	//ù ��° ���Ҹ� ��ȯ��
	type front() { return array[0]; }
	//������ ���Ҹ� ��ȯ��
	type back() { return array[count - 1]; }
	//���ҵ� ����
	void list() {
		for (int i = 0; i < count; i++) {
			cout << array[i] << "\t";
		}
		cout << endl;
	}
	//�� ���Ҹ� �迭�� ������ ��ġ�� �߰���(ũ�Ⱑ 1������)
	void add(type value) {
		type* before = new type[count + 1];
		for (int i = 0; i < count; i++) {//���� ������
			*(before + i) = *(array + i);
		}
		count++;
		before[count - 1] = value;
		delete[] array;
		array = before;
	}
	//������ ������ ���Ҹ� ����(ũ�Ⱑ 1����)
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

	//[]������ �����ε�
	type& operator[] (int index) {
		if (index < 0 || index >= count) throw out_of_range("Index Out of Range");

		return array[index];
	}
	const type& operator[] (int index) const {
		if (index < 0 || index >= count) throw out_of_range("Index Out of Range");

		return array[index];
	}

};