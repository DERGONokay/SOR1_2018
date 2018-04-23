#include <stdio.h>

void* f1 (char[2]* a)
{
	printf("grupo_%c",a);
}
int main()
{
	char a = 'a';
	char b = 'b';
	char[2] c = {&a,&b};
	f1(&c);
}
