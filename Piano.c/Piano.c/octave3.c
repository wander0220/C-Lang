#include <stdio.h>
#include <math.h>
#include <conio.h> 
#include <Windows.h>
void draw_check01(int column, int row) {
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[12];
	for (i = 1; i < 12; i++) b[i] = 0xa0 + i;

	printf("%c%c ", a, b[3]);
	for (i = 0; i<column - 1; i++)
		printf("%c%c %c%c ", a, b[1], a, b[8]);
	printf("%c%c %c%c", a, b[1], a, b[4]);
	printf("\n");

	for (i = 0; i < row - 1; i++) {
		for (j = 0; j < column + 1; j++) {
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
		printf("%c%c %c%c ", a, b[1], a, b[10]);
	printf("%c%c %c%c\n", a, b[1], a, b[5]);
}
void gotoxy(int x, int y) {
	COORD pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int clac_frequency(int octave, int inx) {
	double do_scale = 32.7032;
	double ratio = pow(2., 1 / 12.), temp;
	int i;

	temp = do_scale * pow(2, octave - 1);
	for (i = 0; i < inx; i++) {
		temp = (int)(temp + 0.5);
		temp *= ratio;
	}
	return (int)temp;
}
void practoce_piano() {
	int index[] = { 0,2,4,5,7,9,11,12 };
	int freq[8], code, i;

	for (i = 0; i < 8; i++)freq[i] = clac_frequency(4, index[i]);
	do {
		code = _getch();
		if ('1' <= code && code <= '8') {
			code -= 49;
			Beep(freq[code], 500);
		}
	} while (code != 27);
}
void main() {
	printf("1부터 8까지 숫자 키를 누르면 ");
	printf("각 음의 소리가 출력됨\n\n");
	printf("▷키↑: 한 옥타브 위로      ▷키↓: 한 옥타브 아래로\n");
	printf("▷키←: 음의 지연시간 짧게      ▷키→: 음의 지연시간 길게\n");
	
	draw_check01(8, 2);
	int num[8] = { 1,2,3,4,5,6,7,8 };
	int num2[8] = { 4,8,12,16,20,24,28,32 };

	for (int i = 0; i < 8; i++) {
		gotoxy(num2[i], 6);
		printf("%d", num[i]);
	}
	gotoxy(1, 2 * 3 + 4);
	printf("프로그램 종료 : Esc \n");
	practoce_piano();
}