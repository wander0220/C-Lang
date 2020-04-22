#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
void draw_square(int size1,int size2) {
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++) b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]);
	for (i = 1; i <= size1; i++)printf(" %c%c", a, b[1]);
	printf("%c%c\n", a, b[4]);

	for (i = 1; i <= size2; i++) {
		printf("%c%c", a, b[2]);
		for (j = 1; j <= size1; j++) printf("  ");
		printf("%c%c\n", a, b[2]);
	}

	printf("%c%c", a, b[6]);
	for (i = 1; i <= size1; i++)printf(" %c%c", a, b[1]);
	printf("%c%c\n", a, b[5]);
}
int main() {
	int length1 = 0,length2=0;
	printf("직사각형 그리기(최대길이 37)\n\n");

	printf("직사각형 길이\n가 : ");
	scanf("%d", &length1);

	printf("직사각형 길이\n세 : ");
	scanf("%d", &length2);

	draw_square(length1,length2);

	return 0;
}