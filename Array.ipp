//생성자
template <typename type>
Array<type>::Array() {
	count = 0;
	array = new type[capacity];
}
template <typename type>
Array<type>::Array(const Array& other) {
	count = other.count;
	capacity = other.capacity;
	array = new type[capacity];
	for (int i = 0; i < count; i++) {
		array[i] = other.array[i];
	}
}

//소멸자
template <typename type>
Array<type>::~Array() {
	delete[] array;
}

//복사 대입 연산자
template <typename type>
Array<type>& Array<type>:: operator= (const Array & other) {
	if (this == &other) return *this;
	delete[] array;
	count = other.count;
	capacity = other.capacity;
	array = new type[capacity];
	for (int i = 0; i < count; i++) {
		array[i] = other.array[i];
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
		type* before = new type[capacity];
		for (int i = 0; i < count; i++) {//값을 대입함
			*(before + i) = *(array + i);
		}
		before[count] = value;
		count++;
		delete[] array;
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