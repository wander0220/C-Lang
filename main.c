#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
void draw_rectangle(int r, int c) {

	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++) b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]);
	for (i = 1; i <= c; i++)printf(" %c%c", a, b[1]);
	printf("%c%c\n", a, b[4]);

	for (i = 1; i <= r; i++) {
		printf("%c%c", a, b[2]);
		for (j = 1; j <= c; j++) printf("  ");
		printf("%c%c\n", a, b[2]);
	}

	printf("%c%c", a, b[6]);
	for (i = 1; i <= c; i++)printf(" %c%c", a, b[1]);
	printf("%c%c\n", a, b[5]);
}
void gotoxy(int x, int y) {
	COORD Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void intro_game(void) {
	char start;
	printf("<<<��Ÿ�� ȭ���� ����>>>\n");
	printf("���� Ÿ�� �̵��ϸ鼭\n ��ǥ��(��)�� ���ߴ� ����!");
	printf("ȭ�� �߻� : �����̽� Ű\n\n");
	printf("������ �����Ϸ��� �ƹ� Ű�� �������� GO!\n");
	start = _getch();
}
void display_text(int count, int r_count) {
	
	gotoxy(45, 3);
	printf("ȭ�� �߻�� �����̽�Ű !");
	gotoxy(45, 5);
	printf("�� ���� ���� Ƚ�� : 10ȸ");
	gotoxy(45, 7);
	printf("��Ƚ�� : %d",count);
	gotoxy(45, 9);
	printf("������ : %d",r_count);

}
void horizontal_slide(int x, int y, char *c2) {
	gotoxy(x, y);
	printf("%s", c2);
	printf("\b");
	Sleep(100);
	printf("\b");
}
void game_control(int * r_c, int rnd) {
	int i = 1, k = 1, y;
	char *horse = "��", chr;
	do {
		i +=k;
		if (i > 38)
			k = -1;
		else if (i < 3)
			k = +1;
		horizontal_slide(i+1,21,horse);
	} while (!_kbhit());

	chr = _getch();
	y = 21;
	if (chr == 32) {//32���� �����̽� ��
		do {
			gotoxy(i, y);
			printf("��");
			y--;
			Sleep(70);
			printf("\b  ");
		} while (y>1);
	}
	if ((rnd - 1 <= i) && (i <= (rnd))) {
		gotoxy(rnd - 1, 2);
		printf("��");
		gotoxy(46, 13);
		printf("��������� ����~!~~!");
		Sleep(50);
		*r_c = *r_c + 1;
	}

	gotoxy(3, 23);
	printf("�ƹ�Ű�� ������ �������� ���� \n");
	chr = _getch();
}
int main() {
	int count = 0, rnd;
	int r_count = 0;
	char *target = "��";
	srand((unsigned int)time(NULL));
	int i = 0;
	    intro_game();
		do {
			system("cls");
			draw_rectangle(20, 20);
			rnd = rand() % 35 + 4;
			gotoxy(rnd, 2);
			printf("%s", target);
			count++;
			display_text(count, r_count);
			game_control(&r_count, rnd);
		} while (count < 10);

	return 0;
}