// int, double 등 built-in type에는 constructor가 있으나 struct chaff와 같은 non built-in tyoe에는
// constructor가 없어 chaff *chaffs1 = new (buffer1) chaff[SIZE] { {"Nana", 3}, {"33", 1} }; 처럼
// 사용해도 초기화가 이루어지지 않는다.

#include <iostream>
#include <cstring>

const int SIZE = 2;

struct chaff
{
	char dross[20];
	int slag;
};

int main(void)
{
	char buffer1[512];
	char *buffer2 = new char[512];

	chaff *chaffs1 = new (buffer1) chaff[SIZE];
	chaff *chaffs2 = new (buffer2) chaff[SIZE];
	double *test = new (buffer1) double[SIZE] {0, 1};

	using std::strcpy;
	strcpy(chaffs1[0].dross, "hello, ");
	strcpy(chaffs1[1].dross, "world!");
	strcpy(chaffs2[0].dross, "hello, ");
	strcpy(chaffs2[1].dross, "world!");ㅁ
	chaffs1[0].slag = 0;
	chaffs1[1].slag = 1;
	chaffs2[0].slag = 0;
	chaffs2[1].slag = 1;


	return 0;
}
