#include <iostream>

using namespace std;

//template

//함수 템플릿
template <typename T>
T add(T a, T b) {
	return a + b;
}

/*위와 같다
int add(int a, int b) {
	return a + b;
}

int add(float a, float b) {
	return a + b;
}
*/




int main() {

	int ret = add<int>(20, 30);
	double fret = add<double>(2.3, 3.3);
	string str1 = "monster";
	string str2 = "is World";
	string str = add(str1, str2);

	cout << str << endl;

	return 0;
}