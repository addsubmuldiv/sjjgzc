#include <stdio.h>
int main(void)
{
	char a, b;
	scanf("%c", &a);
	printf("%c", a);
	scanf(" %c", &b);  //scanf��ȡ�ַ�("c%")��
	printf("%c", b);
	system("pause");
	return 0;
}