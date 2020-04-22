#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
void draw_check01(int column,int row) {
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[12];
	for (i = 1; i < 12; i++) b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]);
	for(i=0;i<column-1;i++)
		printf("%c%c ", a, b[8]);
	printf("%c%c\n", a, b[4]);

	for (i = 0; i < row-1; i++) {
		printf("%c%c", a, b[7]);
		for (j = 0; j < column-1; j++)
			printf("%c%c ",a,b[11]);
		printf("%c%c\n", a, b[9]);
	}

	printf("%c%c", a, b[6]);
	for (i = 0; i < column-1; i++)
		printf("%c%c ", a, b[10]);
	printf("%c%c\n", a, b[5]);
}
int main() {
	int row, column;

	printf("< 바둑판 그리기 >\n\n");
	printf("가 : ");
	scanf("%d", &column);
	printf("세 : ");
	scanf("%d", &row);

	draw_check01(column, row);
	
	return 0;
}