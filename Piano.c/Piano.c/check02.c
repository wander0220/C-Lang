#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
void draw_check01(int column, int row) {
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[12];
	for (i = 1; i < 12; i++) b[i] = 0xa0 + i;

	printf("%c%c ", a, b[3]);
	for (i = 0; i<column - 1; i++)
		printf("%c%c %c%c ",a,b[1], a, b[8]);
	printf("%c%c %c%c", a, b[1], a, b[4]);
	printf("\n");

	for (i = 0; i < row - 1; i++) {
		for (j = 0; j < column+1 ; j++) {
			printf("%c%c ", a, b[2]);
			printf("  ");
		}
		printf("\n");

		printf("%c%c ", a, b[7]);
		for (j = 0; j < column - 1; j++)
			printf("%c%c %c%c ", a, b[1], a, b[11]);
		printf("%c%c %c%c\n", a, b[1], a, b[9]);

	}
	for (j = 0; j < column + 1; j++) {
		printf("%c%c ", a, b[2]);
		printf("  ");
	}
	printf("\n");

	printf("%c%c ", a, b[6]);
	for (i = 0; i < column - 1; i++)
		printf("%c%c %c%c ", a, b[1],  a, b[10]);
	printf("%c%c %c%c\n", a, b[1], a, b[5]);
}
void gotoxy(int x,int y){
	COORD pos = { x-1,y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int main() {
	int row, column;

	printf("< 바둑판 그리기 >\n\n");
	printf("가 : ");
	scanf("%d", &column);
	printf("세 : ");
	scanf("%d", &row);

	draw_check01(column, row);
	gotoxy(3, 6);
	printf("히");
	gotoxy(5, 8);
	printf("⊙");
	gotoxy(3, 10);
	printf("⊙");
	gotoxy(1, row*3+4);

	return 0;
}