#include <iostream>
#include "complex0.h"

using namespace std;

int main()
{
	Complex a(3.0, 4.0);
	Complex c;
	cout << "�ϳ��� ���Ҽ��� �Է��Ͻÿ�(q to exit) : \n";
	while (cin >> c) {
		cout << "c = " << c << '\n';
		cout << "���׺��Ҽ� = " << ~c << '\n';
		cout << "a = " << a << '\n';
		cout << "a + c = " << a + c << '\n';
		cout << "a - c = " << a - c << '\n';
		cout << "a * c = " << a * c << '\n';
		cout << "2 * c = " << 2 * c << '\n';
		cout << "�ϳ��� ���Ҽ��� �Է��Ͻÿ�(q to exit) : \n";
	}
	cout << "�����ϴ�.\n";
	cin.get();
	cin.get();
	return 0;
}