///*vector
//	�ڷḦ �迭ó�� ������ �����ҿ� ����Ŵ (���� X)
//	�������� ũ�� ����
//	<vector> ����� include
//	
//	vector<�ڷ� ����> �����̸�(�μ�, �ʱ�ȭ��); //�μ�, �ʱ�ȭ �� ���� ����
//	vector<�ڷ� ����> �����̸� = {�ʱ�ȭ �� ����Ʈ};
//	vector<�ڷ� ����> �����̸� {�ʱ�ȭ �� ����Ʈ};
//	
//	���� �Լ� : size(), empty(), front(), back(), push_back(), emplace_back(), pop_back(), clear()*/
//#include <iostream>
//#include <vector>
//
//using namespace std;
//void list(vector<int> v) {
//	for (int& value : v) {
//		cout << value << "\t";
//	}
//	cout << endl;
//}
//int main() {
//	vector<int> vt1 = { 1, 2, 3 };//�ʱ�ȭ �� ����Ʈ�� ��
//	cout << "vt 1 : ";
//	list(vt1);
//
//	vector<int> vt2(vt1);//vt1�� ���͸� vt2�� ���Ϳ� ������
//	cout << "vt 2 : ";
//	list(vt2);
//
//	int arr[] = { 10, 20, 30, 40 };
//	vector<int> vt3(begin(arr), end(arr));
//	cout << "vt 3 : ";
//	list(vt3);
//
//	cout << "�����Լ��� ����" << endl;
//
//	system("pause");
//	return 0;
//}

/*�ؾ� �� �͵�
�ϳ��� ������ ������ �и��ϴ� �Ű� (�ϴ� �밭�Ϸ��� - ���� ���� �͵��� ���� �س���)
�ϳ��� ���� CMake�� �ٲ㼭 ���� ���� �������� �� �ְ� ����� �ž�*/

/*void* (*fpMAlloc)(size_t);
void (*fpFree)(void*, size_t);
*/