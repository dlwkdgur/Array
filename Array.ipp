//������
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

//�Ҹ���
template <typename type>
Array<type>::~Array() {
	delete[] array;
}

//���� ���� ������
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
		type* before = new type[capacity];
		for (int i = 0; i < count; i++) {//���� ������
			*(before + i) = *(array + i);
		}
		before[count] = value;
		count++;
		delete[] array;
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