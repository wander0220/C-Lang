#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
int count1=0, count2=0;
void move_arrow_key(char key, int *x, int *y, int x_m, int y_m) {
	switch (key) {//상 하 좌 우
	case 72:
		*y=*y-1;
		if (*y < 1)*y = 1;
		count1--;
		break;
	case 80:
		*y=*y+1;
		if (*y>y_m) *y = y_m;
		count1++;
		break;
	case 75:
		*x=*x-1;
		if (*x < 1) *x = 1;
		count2--;
		break;
	case 77:
		*x=*x+1;
		if (*x>x_m) *x = x_m;
		count2++;
		break;
	}
}
void gotoxy(int x, int y) {
	COORD Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void draw_rectangle(int c,int r) {

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
void draw_verticla_slide(int x, int y,int length,char *s) {
	gotoxy(x, 1);
	draw_rectangle(1, length);
	gotoxy(x+1,y+1);
	printf("%s", s);
}
void draw_horizontal_slide(int x, int y,int length,char *s) {
	gotoxy(1, y);
	draw_rectangle(length, 1);
	gotoxy(x+1, y+1);
	printf("%s", s);
}
int main() {
	//int col, row;
	char *slide = "■", key;
	int x = 1, y = 1;
	int h_slide_length, v_slide_length;// == col,row

	 /*printf("[SLIDE BAR]\n");
	   scanf("%d %d", &col, &row);
	   draw_rectangle(1, row);
	   draw_rectangle(col, 1);*/

	printf("슬라이드 바 표시 \n\n");
	printf("수직 슬라이드 바 입력 : ");
	scanf("%d", &v_slide_length);
	printf("슬라이드 바 표시 \n\n");
	printf("수평 슬라이드 바 입력 : ");
	scanf("%d", &h_slide_length);
	system("cls");

	do{
		draw_verticla_slide(1,y,v_slide_length,slide);
		draw_horizontal_slide(x, v_slide_length+3,h_slide_length,slide);
		key = _getch();
		move_arrow_key(key,&x,&y, h_slide_length*2-1 ,v_slide_length);
		/*gotoxy(5,1);
		printf("%d", count1);
		gotoxy(v_slide_length+2, h_slide_length);
		printf("%d", count2);*/
		
	}while (key!=27);

	return 0;
}