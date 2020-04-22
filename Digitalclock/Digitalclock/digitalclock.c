#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
int zero[20] = {
	1,1,1,1,
	1,0,0,1,
	1,0,0,1,
	1,0,0,1,
	1,1,1,1
};
int one[20] = {
	0,0,1,0,
	0,1,1,0,
	0,0,1,0,
	0,0,1,0,
	0,1,1,1
};
int two[20] = {
	1,1,1,1,
	0,0,0,1,
	1,1,1,1,
	1,0,0,0,
	1,1,1,1
};
int three[20] = {
	1,1,1,1,
	0,0,0,1,
	1,1,1,1,
	0,0,0,1,
	1,1,1,1
};
int four[20] = {
	1,0,1,0,
	1,0,1,0,
	1,1,1,1,
	0,0,1,0,
	0,0,1,0
};
int five[20] = {
	1,1,1,1,
	1,0,0,0,
	1,1,1,1,
	0,0,0,1,
	1,1,1,1
};
int six[20] = {
	1,1,1,1,
	1,0,0,0,
	1,1,1,1,
	1,0,0,1,
	1,1,1,1
};
int seven[20] = {
	1,1,1,1,
	0,0,0,1,
	0,0,0,1,
	0,0,0,1,
	0,0,0,1
};
int eight[20] = {
	1,1,1,1,
	1,0,0,1,
	1,1,1,1,
	1,0,0,1,
	1,1,1,1
};
int nine[20] = {
	1,1,1,1,
	1,0,0,1,
	1,1,1,1,
	0,0,0,1,
	0,0,0,1
};
void digit_print(int num[],int line) {
		for(int j=line*4;j<line*4+4;j++){
			if (num[j] == 1) printf("■");
			else printf("  ");
		}
		printf("  ");

}
void number_check(int k,int line) {
	if (k >= 1) {
		number_check(k / 10, line);
		switch (k % 10) {
		case 0: digit_print(zero,line); break;
		case 1: digit_print(one,line); break;
		case 2: digit_print(two,line); break;
		case 3: digit_print(three,line); break;
		case 4: digit_print(four,line); break;
		case 5: digit_print(five,line); break;
		case 6: digit_print(six,line); break;
		case 7: digit_print(seven,line); break;
		case 8: digit_print(eight,line); break;
		case 9: digit_print(nine,line); break;
		}
	}
}
long time_to_number() {
	long ptime;
	time_t current;
	struct tm *d;
	int hour, min, sec;
	current = time(NULL);
	d = localtime(&current);

	hour = d->tm_hour * 10000;
	min = d->tm_min * 100;
	sec=(d->tm_sec);
	
	ptime = hour + min + sec;
	return ptime;
}
void gotoxy(int x, int y) {
	COORD Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void dot_print(int hour) {
	if (hour < 100000) {//0:00:00
		for (int i = 0; i < 2; i++) {
			gotoxy(9 + i * 15, 4);
			printf("■");
			gotoxy(9 + i * 15, 6);
			printf("■");
		}
	}

	else {//00:00:00
		for (int i = 0; i < 2; i++) {
			gotoxy(19 + i * 20, 4);
			printf("■");
			gotoxy(19 + i * 20, 6);
			printf("■");
		}
		
	}
}
int main() {
	int num;
	long time_number;//시간 계산 넘기는 어쩌구
		//system("cls");
		printf("< 디지털 숫자 출력 - 현재 시간 출력 >\n");
		printf("아무키나 누르면 현재 시간을 보여줍니다.\n");
	    _getch();
		//system("cls");

		while (!_kbhit()) {
			Sleep(1000);
			system("cls");
			gotoxy(1, 3);
			
			time_number = time_to_number();

			for (int line = 0; line < 5; line++) {
				number_check(time_number, line);
				printf("\n");
			}
			dot_print(time_number);
			
			//printf("\n종료 : ESC\n\n");
		}
		
		return 0;
}