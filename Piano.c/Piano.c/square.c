#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
void draw_basic_square(){
	unsigned char a = 0xa6, b[7], i;
	for (i = 1; i < 7; i++) b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]);
	printf("%c%c", a, b[4]);
	printf("\n");
	printf("%c%c", a, b[6]);
	printf("%c%c", a, b[5]);
	printf("\n");
}
void draw_square(int size){
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++) b[i] = 0xa0 + i;

	printf("%c%c", a,b[3]);
	for (i = 1; i <= size; i++)printf(" %c%c",a, b[1]);
	printf("%c%c\n",a, b[4]);

	for (i = 1; i <= size; i++) {
		printf("%c%c", a,b[2]);
		for (j = 1; j <= size; j++) printf("  ");
		printf("%c%c\n",a, b[2]);
	}

	printf("%c%c", a,b[6]);
	for (i = 1; i <= size; i++)printf(" %c%c", a,b[1]);
	printf("%c%c\n",a, b[5]);
}
int main() {
	int length = 0;
	printf("���簢�� �׸���\n\n");

	printf("���簢���� ����(�ִ� 37)�� �Է��ϰ� Enter : ");
	scanf("%d", &length);

	draw_square(length);

	return 0;
}