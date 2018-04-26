#include <stdio.h>
#include <string.h>

int main()
{
	char a1 = 'x';
	char str[2];
	strcpy(str, "a");
	char c = 1 + '0';
	printf("%c\n",c );
	strcat(str,c);
	printf("%c\n",*str);
}
