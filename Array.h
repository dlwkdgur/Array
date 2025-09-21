#pragma once
#include <iostream>

template <typename type>

class Array {
private:
	//�迭�� �߰��ϰų� ���� �� �� ������ ���� ������ ���� �迭
	type* before;
	int count;
public :
	//�迭 ����, �迭 ������ ����
	type* array;
	Array() {
		count = 0;
		array = new type[count];
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
		before = new type[count];
		for (int i = 0; i < count; i++) {//���� ������
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
	//������ ������ ���Ҹ� ����(ũ�Ⱑ 1����)
	type pop() {
		count--;
		return array[count];
	}

};