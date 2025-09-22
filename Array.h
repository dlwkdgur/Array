#pragma once
#include <iostream>
using namespace std;
template <typename type>

class Array {
private:
	int count;
	int capacity = 10;
	//�迭 ����, �迭 ������ ����
	type* array;
public:

	//������
	Array();
	Array(const Array& other);

	//�Ҹ���
	~Array();

	//���� ���� ������
	Array& operator= (const Array& other);

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

};

#include "Array.ipp";