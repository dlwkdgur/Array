int capacity_set(int count) {
	int capacity = 10;
	while (capacity < count) {
		capacity += capacity;
	}
	return capacity;
}
//������
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

//�Ҹ���
template <typename type>
Array<type>::~Array() {
	if (array) {
		if constexpr (!is_trivially_destructible<type> ::value) {//Ŭ���� Ÿ���� ��� ������ ȣ��
			for (int i = 0; i < count; i++) {
				array[i].~type();//�Ҹ��� ȣ��
			}
		}
		fpFree(array, sizeof(type) * capacity);
	}
}

//���� ���� ������
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

//�޼ҵ�
//������ ��
template <typename type>
int Array<type>:: size() { return count; }
//���� array�� �����
template <typename type>
bool Array<type>:: empty() { return (count == 0); }
//ù ��° ���Ҹ� ��ȯ��
template <typename type>
type Array<type>:: front() { return array[0]; }
//������ ���Ҹ� ��ȯ��
template <typename type>
type Array<type>:: back() { return array[count - 1]; }
//���ҵ� ����
template <typename type>
void Array<type>:: list() {
	for (int i = 0; i < count; i++) {
		cout << array[i] << "\t";
	}
	cout << endl;
}
//�� ���Ҹ� �迭�� ������ ��ġ�� �߰���(ũ�Ⱑ 1������)
template <typename type>
void Array<type>:: add(type value) {
	if (capacity == count) {//�迭�� ũ�⸦ �÷��� �ϴ� ���
		capacity += capacity;
		type* before = static_cast<type*>(fpMAlloc(sizeof(type) * capacity));
		for (int i = 0; i < count; i++) {//���� ������
			*(before + i) = *(array + i);
		}
		before[count] = value;
		count++;
		fpFree(array, sizeof(type) * capacity);
		array = before;
	}
	else {//�ø��� �ʾƵ� �Ǵ� ���
		array[count++] = value;
	}
	
}
//������ ������ ���Ҹ� ����(ũ�Ⱑ 1����)
template <typename type>
type Array<type>:: pop() {
	if (empty()) throw out_of_range("Array is Empty");
	
	count--;
	type value = array[count];
	
	return value;
}

//[]������ �����ε�
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