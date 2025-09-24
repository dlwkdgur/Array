///*vector
//	자료를 배열처럼 연속적 기억장소에 기억시킴 (연결 X)
//	동적으로 크기 변형
//	<vector> 헤더를 include
//	
//	vector<자료 유형> 벡터이름(인수, 초기화값); //인수, 초기화 값 생략 가능
//	vector<자료 유형> 벡터이름 = {초기화 값 리스트};
//	vector<자료 유형> 벡터이름 {초기화 값 리스트};
//	
//	관련 함수 : size(), empty(), front(), back(), push_back(), emplace_back(), pop_back(), clear()*/
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
//	vector<int> vt1 = { 1, 2, 3 };//초기화 값 리스트를 줌
//	cout << "vt 1 : ";
//	list(vt1);
//
//	vector<int> vt2(vt1);//vt1의 벡터를 vt2의 벡터에 복사함
//	cout << "vt 2 : ";
//	list(vt2);
//
//	int arr[] = { 10, 20, 30, 40 };
//	vector<int> vt3(begin(arr), end(arr));
//	cout << "vt 3 : ";
//	list(vt3);
//
//	cout << "관련함수들 공부" << endl;
//
//	system("pause");
//	return 0;
//}

/*해야 될 것들
하나는 구현과 선언을 분리하는 거고 (일단 대강완료함 - 생각 나는 것들은 구현 해놓음)
하나는 저걸 CMake로 바꿔서 내가 저걸 컴파일할 수 있게 만드는 거야*/

/*void* (*fpMAlloc)(size_t);
void (*fpFree)(void*, size_t);
*/