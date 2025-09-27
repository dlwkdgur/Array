#pragma once
#include <iostream>
#include <type_traits>
using namespace std;
template <typename type>

class Array {
private:
	int count;
	int capacity = 10;
	//�迭 ����, �迭 ������ ����
	type* array;

	void* (*fpMAlloc)(size_t);
	void (*fpFree)(void*, size_t);
public:

	//������
	Array();
	Array(int i);
	Array(const Array& other);
	Array(initializer_list<type> list);
	Array(void* (*fnMAlloc)(size_t), void (fnFree)(void*, size_t));

	//�Ҹ���
	~Array();

	//���� ���� ������
	Array& operator= (const Array& other);
	Array& operator= (initializer_list<type> list);

	//�޼ҵ�
	//������ ��
	int size();
	//���� array�� �����
	bool empty();
	//ù ��° ���Ҹ� ��ȯ��
	type front();
	//������ ���Ҹ� ��ȯ��
	type back();
	//���ҵ� ����
	void list();
	//�� ���Ҹ� �迭�� ������ ��ġ�� �߰���(ũ�Ⱑ 1������)
	void add(type value);
	//������ ������ ���Ҹ� ����(ũ�Ⱑ 1����)
	type pop();

	//[]������ �����ε�
	type& operator[] (int index);
	const type& operator[] (int index) const;

	//iteratorŸ�� ���� begin, end�޼ҵ�
	type* begin();
	type* end();

	const type* begin() const;
	const type* end() const;

};

#include "Array.ipp";