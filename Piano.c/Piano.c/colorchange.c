#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
int main(void) {
	char *text = "color 0c";
	system(text);

	printf("아무키나 누르면\n");
	printf("이전 색으로 도랑갑니다\n");
	_getch();
	system("color 87");
  //앞에 있는 숫자가 배경 뒤에있는거 글씨체

	return 0;
}