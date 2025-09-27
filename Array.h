#pragma once
#include <iostream>
#include <type_traits>
using namespace std;
template <typename type>

class Array {
private:
	int count;
	int capacity = 10;
	//배열 생성, 배열 사이즈 생성
	type* array;

	void* (*fpMAlloc)(size_t);
	void (*fpFree)(void*, size_t);
public:

	//생성자
	Array();
	Array(int i);
	Array(const Array& other);
	Array(initializer_list<type> list);
	Array(void* (*fnMAlloc)(size_t), void (fnFree)(void*, size_t));

	//소멸자
	~Array();

	//복사 대입 연산자
	Array& operator= (const Array& other);
	Array& operator= (initializer_list<type> list);

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

	//iterator타입 정의 begin, end메소드
	type* begin();
	type* end();

	const type* begin() const;
	const type* end() const;

};

#include "Array.ipp";