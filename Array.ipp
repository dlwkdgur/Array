int capacity_set(int count) {
	int capacity = 10;
	while (capacity < count) {
		capacity += capacity;
	}
	return capacity;
}
//생성자
template <typename type>
Array<type>::Array() {
	count = 0;
	fpMAlloc = malloc;
	fpFree = [](void* p, size_t) {free(p); };
	array = static_cast<type*>(fpMAlloc(sizeof(type) * capacity));
}
template <typename type>
Array<type>::Array(int i) {
	count = i;
	capacity = capacity_set(count);
	fpMAlloc = malloc;
	fpFree = [](void* p, size_t) {free(p); };
	array = static_cast<type*>(fpMAlloc(sizeof(type) * capacity));
}
template <typename type>
Array<type>::Array(const Array& other) {
	count = other.count;
	capacity = other.capacity;
	fpMAlloc = other.fpMAlloc;
	fpFree = other.fpFree;
	array = static_cast<type*>(fpMAlloc(sizeof(type) * capacity));
	for (int i = 0; i < count; i++) {
		array[i] = other.array[i];
	}
}
template<typename type>
Array<type>::Array(initializer_list<type> list) {
	count = list.size();
	capacity = capacity_set(count);
	fpMAlloc = malloc;
	fpFree = [](void* p, size_t) {free(p); };
	array = static_cast<type*>(fpMAlloc(sizeof(type) * capacity));
	int i = 0;
	for (type value : list) {
		array[i++] = value;
	}
}
template<typename type>
Array<type>::Array(void* (*fnMAlloc)(size_t), void (*fnFree)(void*, size_t)) {
	count = 0;
	fpMAlloc = fnMAlloc;
	fpFree = fnFree;
	array = static_cast<type*>(fpMAlloc(sizeof(type) * capacity));
}

//소멸자
template <typename type>
Array<type>::~Array() {
	if (array) {
		if constexpr (!is_trivially_destructible<type> ::value) {//클래스 타입을 경우 생성자 호출
			for (int i = 0; i < count; i++) {
				array[i].~type();//소멸자 호출
			}
		}
		fpFree(array, sizeof(type) * capacity);
	}
}

//복사 대입 연산자
template <typename type>
Array<type>& Array<type>:: operator= (const Array & other) {
	if (this == &other) return *this;
	fpFree(array, sizeof(type) * capacity);
	count = other.count;
	capacity = other.capacity;
	fpMAlloc = other.fpMAlloc;
	fpFree = other.fpFree;
	array = static_cast<type*>(fpMAlloc(sizeof(type)) * capacity);
	for (int i = 0; i < count; i++) {
		array[i] = other.array[i];
	}

	return *this;
}
template<typename type>
Array<type>& Array<type>:: operator= (initializer_list<type> list) {
	fpFree(array, sizeof(type) * capacity);
	count = list.size();
	capacity = capacity_set(count);
	array = static_cast<type*>(fpMAlloc(sizeof(type)) * capacity);
	int i = 0;
	for (type value : list) {
		array[i++] = value;
	}
	return *this;
}

//메소드
//원소의 수
template <typename type>
int Array<type>:: size() { return count; }
//현재 array가 비었냐
template <typename type>
bool Array<type>:: empty() { return (count == 0); }
//첫 번째 원소를 반환함
template <typename type>
type Array<type>:: front() { return array[0]; }
//마지막 원소를 반환함
template <typename type>
type Array<type>:: back() { return array[count - 1]; }
//원소들 나열
template <typename type>
void Array<type>:: list() {
	for (int i = 0; i < count; i++) {
		cout << array[i] << "\t";
	}
	cout << endl;
}
//새 원소를 배열의 마지막 위치에 추가함(크기가 1증가함)
template <typename type>
void Array<type>:: add(type value) {
	if (capacity == count) {//배열의 크기를 늘려야 하는 경우
		capacity += capacity;
		type* before = static_cast<type*>(fpMAlloc(sizeof(type) * capacity));
		for (int i = 0; i < count; i++) {//값을 대입함
			*(before + i) = *(array + i);
		}
		before[count] = value;
		count++;
		fpFree(array, sizeof(type) * capacity);
		array = before;
	}
	else {//늘리지 않아도 되는 경우
		array[count++] = value;
	}
	
}
//벡터의 마지막 원소를 제거(크기가 1감소)
template <typename type>
type Array<type>:: pop() {
	if (empty()) throw out_of_range("Array is Empty");
	
	count--;
	type value = array[count];
	
	return value;
}

//[]연산자 오버로딩
template <typename type>
type& Array<type>:: operator[] (int index) {
	if (index < 0 || index >= count) throw out_of_range("Index Out of Range");

	return array[index];
}
template <typename type>
const type& Array<type>:: operator[] (int index) const {
	if (index < 0 || index >= count) throw out_of_range("Index Out of Range");

	return array[index];
}

template<typename type>
type* Array<type>::begin() { return array; }
template<typename type>
type* Array<type>::end() { return array + count; }

template<typename type>
const type* Array<type>::begin() const { return array; }
template<typename type>
const type* Array<type>::end() const { return array + count; }