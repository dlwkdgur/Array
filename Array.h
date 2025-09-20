typedef struct Node {//front now back
	Element data;
	struct Node* front;
	struct Node* back;

}Node;

Node* real = NULL;

//요소 e를 저장할 노드를 할당, 반환하는 함수
Node* alloc_node(Element e) {
	Node* now = (Node*)malloc(sizeof(Node));
	now->data = e;
	now->front = NULL;
	now->back = NULL;
	return now;
}

//노드 해제 함수
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

//크기
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

//요소를 추가하는 함수
void add(Element e) {
	Node* new_node = alloc_node(e);
	if (empty()) {// 맨 처음에 넣는 경우 -> new
		real = new_node;
		new_node->back = new_node;
		new_node->front = new_node;
	}
	else {//맨 처음에 넣는 경우가 아닌 경우  -> real new(back)
		new_node->back = real->back;
		new_node->front = real;
		real->back->front = new_node;
		real->back = new_node;
		real = new_node;
	}
}

//요소를 삭제하는 함수
Element remove_node() {//아무런 입력 없이 삭제하는 경우는 제일 뒤에를 삭제함
	if (empty()) {//삭제 할 것이 없음
		cout << "no remove" << endl;
		return (Element)0;
	}
	else {//삭제 할 것이 있음
		Node* now = real;
		if (real->front == real) {//요소가 하나 인 경우
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
Element remove_node(int index) {//삭제할 인덱스를 매개변수로 줌
	int cnt = size();
	if (0 <= index && index < cnt) {//삭제할 수 있는 경우
		if (cnt == 1 || index == cnt - 1) {//요소가 하나 있는 경우 또는 맨 뒤의 요소를 삭제하는 경우는 remove_node();함수로 처리 가능
			return remove_node();
		}
		else {//맨 처음부터 마지막 전까지의 경우
			int count = 0;//삭제할 노드 정하기
			Node* deleteNode = real->back;
			while (count != index) {
				deleteNode = deleteNode->back;
				count++;
			}
			cout << "삭제할 데이터 : " << deleteNode->data << endl;
			//삭제할 노드의 front와 back연결하기 (real은 건드릴 필요 없음)
			deleteNode->front->back = deleteNode->back;
			deleteNode->back->front = deleteNode->front;
			return free_node(deleteNode);
		}
	}
	else {//삭제할 수 없는 경우
		cout << "삭제할 수 없음" << endl;
		return (Element)0;
	}

}

//조회
void list() {
	if (empty()) {
		cout << "조회 할 것이 없음" << endl;
	}
	else {
		Node* start = real->back;
		for (Node* p = start; p != real; p = p->back) {
			cout << p->data << " ";
		}
		cout << real->data << endl;
	}

}