#include <stdio.h>
#include <Windows.h>
void gotoxy(int x, int y) {
	COORD Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int main() {
	gotoxy(3, 1);
	printf("jee");

	gotoxy(3, 10);
	printf("jung");

	gotoxy(20, 10);
	printf("eun");


	gotoxy(20, 1);
	printf("5단 구구단\n");
	for (int i = 1; i < 9; i++) {
		gotoxy(20, i + 1);
		printf("5 * %d = %d", i, i*5);
	}
	gotoxy(20, 13);
	printf("\n");

	return 0;
}