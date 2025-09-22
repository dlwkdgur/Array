#pragma once
#include <iostream>
using namespace std;
template <typename type>

class Array {
private:
	int count;
	int capacity = 10;
	//배열 생성, 배열 사이즈 생성
	type* array;
public:

	//생성자
	Array();
	Array(const Array& other);

	//소멸자
	~Array();

	//복사 대입 연산자
	Array& operator= (const Array& other);

	//메소드
	//원소의 수
	int size();
	//현재 array가 비었냐
	bool empty();
	//첫 번째 원소를 반환함
	type front();
	//마지막 원소를 반환함
	type back();
	//원소들 나열
	void list();
	//새 원소를 배열의 마지막 위치에 추가함(크기가 1증가함)
	void add(type value);
	//벡터의 마지막 원소를 제거(크기가 1감소)
	type pop();

	//[]연산자 오버로딩
	type& operator[] (int index);
	const type& operator[] (int index) const;

};

#include "Array.ipp";