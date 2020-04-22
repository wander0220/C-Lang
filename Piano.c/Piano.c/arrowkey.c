#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define X_MAX 79
#define Y_MAX 24
void gotoxy(int x,int y){
	COORD pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void move_arrow_key(char ch,int *x,int *y,int x_m,int y_m){
	switch (ch) {
		//╩С го аб ©Л
	case 72:
		*y--;
		if (*y < 1)*y = 1;
		break;
	case 80:
		y++;
		if (*y>y_m) *y = y_m;
		break;
	case 75:
		x--;
		if (*x < 1)*x = 1;
		break;
	case 77:
		x++;
	    if (*x>x_m) *x = x_m;
		break;
	}
}
int main(void) {
	char key;
	int x = 20, y = 3;
	do {
		gotoxy(x, y);
		printf("J");
		      key = _getch();
			  move_arrow_key(key, &x, &y, X_MAX, Y_MAX);
	} while (key != 27);
	return 0;
}