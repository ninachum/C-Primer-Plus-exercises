#include <iostream>
#include "classic1.h"

using namespace std;

void Bravo(const Cd & disk);

int main()
{
	{
		Cd c1("Beatles", "Capitol", 14, 35.5);
		Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
		Cd *pcd = &c1;

		cout << "��ü�� ���� ���:\n";
		c1.Report();
		c2.Report();

		cout << "��ü�� �����ϴ� Cd * ������ ���:\n";
		pcd->Report();
		pcd = &c2;
		pcd->Report();

		cout << "Cd ���� �Ű������� ����Ͽ� �Լ��� ȣ��:\n";
		Bravo(c1);
		Bravo(c2);

		cout << "���� �׽�Ʈ:\n";
		Classic copy;
		copy = c2;
		copy.Report();
	}
	cin.get();
	return 0;
}

void Bravo(const Cd & disk)
{
	disk.Report();
}