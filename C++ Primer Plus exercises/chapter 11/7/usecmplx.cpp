#include <iostream>
#include "complex0.h"

using namespace std;

int main()
{
	Complex a(3.0, 4.0);
	Complex c;
	cout << "하나의 복소수를 입력하시오(q to exit) : \n";
	while (cin >> c) {
		cout << "c = " << c << '\n';
		cout << "공액복소수 = " << ~c << '\n';
		cout << "a = " << a << '\n';
		cout << "a + c = " << a + c << '\n';
		cout << "a - c = " << a - c << '\n';
		cout << "a * c = " << a * c << '\n';
		cout << "2 * c = " << 2 * c << '\n';
		cout << "하나의 복소수를 입력하시오(q to exit) : \n";
	}
	cout << "끝냅니다.\n";
	cin.get();
	cin.get();
	return 0;
}