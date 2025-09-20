typedef struct Node {//front now back
	Element data;
	struct Node* front;
	struct Node* back;

}Node;

Node* real = NULL;

//��� e�� ������ ��带 �Ҵ�, ��ȯ�ϴ� �Լ�
Node* alloc_node(Element e) {
	Node* now = (Node*)malloc(sizeof(Node));
	now->data = e;
	now->front = NULL;
	now->back = NULL;
	return now;
}

//��� ���� �Լ�
Element free_node(Node* p) {
	Element data = p->data;
	free(p);
	return data;
}


bool empty() {
	return (real == NULL);
}
void init() {
	real = NULL;
}

//ũ��
int size() {
	int count = 0;
	if (empty()) {
		return count;
	}
	else {
		count++;
		Node* start = real->back;
		for (Node* p = start; p != real; p = p->back) {
			count++;
		}
		return count;
	}
}

//��Ҹ� �߰��ϴ� �Լ�
void add(Element e) {
	Node* new_node = alloc_node(e);
	if (empty()) {// �� ó���� �ִ� ��� -> new
		real = new_node;
		new_node->back = new_node;
		new_node->front = new_node;
	}
	else {//�� ó���� �ִ� ��찡 �ƴ� ���  -> real new(back)
		new_node->back = real->back;
		new_node->front = real;
		real->back->front = new_node;
		real->back = new_node;
		real = new_node;
	}
}

//��Ҹ� �����ϴ� �Լ�
Element remove_node() {//�ƹ��� �Է� ���� �����ϴ� ���� ���� �ڿ��� ������
	if (empty()) {//���� �� ���� ����
		cout << "no remove" << endl;
		return (Element)0;
	}
	else {//���� �� ���� ����
		Node* now = real;
		if (real->front == real) {//��Ұ� �ϳ� �� ���
			real = NULL;
		}
		else {//front now back now->back->back
			now->front->back = now->back;
			now->back->front = now->front;
			real = now->front;
		}
		return free_node(now);

	}
}
Element remove_node(int index) {//������ �ε����� �Ű������� ��
	int cnt = size();
	if (0 <= index && index < cnt) {//������ �� �ִ� ���
		if (cnt == 1 || index == cnt - 1) {//��Ұ� �ϳ� �ִ� ��� �Ǵ� �� ���� ��Ҹ� �����ϴ� ���� remove_node();�Լ��� ó�� ����
			return remove_node();
		}
		else {//�� ó������ ������ �������� ���
			int count = 0;//������ ��� ���ϱ�
			Node* deleteNode = real->back;
			while (count != index) {
				deleteNode = deleteNode->back;
				count++;
			}
			cout << "������ ������ : " << deleteNode->data << endl;
			//������ ����� front�� back�����ϱ� (real�� �ǵ帱 �ʿ� ����)
			deleteNode->front->back = deleteNode->back;
			deleteNode->back->front = deleteNode->front;
			return free_node(deleteNode);
		}
	}
	else {//������ �� ���� ���
		cout << "������ �� ����" << endl;
		return (Element)0;
	}

}

//��ȸ
void list() {
	if (empty()) {
		cout << "��ȸ �� ���� ����" << endl;
	}
	else {
		Node* start = real->back;
		for (Node* p = start; p != real; p = p->back) {
			cout << p->data << " ";
		}
		cout << real->data << endl;
	}

}