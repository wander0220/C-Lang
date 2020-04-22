#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
int zero[20] = {
	1,1,1,1,
    1,0,0,1,
    1,0,0,1,
	1,0,0,1,
    1,1,1,1 
};
int one[20] = {
	0,0,0,1,
	0,0,0,1,
	0,0,0,1,
	0,0,0,1,
	0,0,0,1
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
void digit_print(int num[]) {
	for (int i = 0; i < 5; i++) {
		for (int j = i*4; j < i*4+4; j++) {
			if (num[j] == 1) printf("■");
			else printf("  ");
		}
		printf("\n");
	}
}
void number_check(int k) {
	switch (k%10){
	case 0: digit_print(zero); break;
	case 1: digit_print(one); break;
	case 2: digit_print(two); break; 
	case 3: digit_print(three); break;
	case 4: digit_print(four); break;
	case 5: digit_print(five); break;
	case 6: digit_print(six); break;
	case 7: digit_print(seven); break;
	case 8: digit_print(eight); break;
	case 9: digit_print(nine); break;
	}
}
int main() {
	int num;
	char ch;

	do {

		//system("cls");
		printf("< 디지털 숫자 출력 >\n");
		printf("0~9까지의 정수 중 한자리 만 입력\n");
		printf("숫자 입력 : ");
		scanf("%d", &num);

		printf("\n\n");

		number_check(num);
		printf("\n종료 : ESC\n\n");
		ch = getchar();

		system("cls");

	} while (ch!=27);
}