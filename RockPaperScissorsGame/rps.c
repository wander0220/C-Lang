#include "rps.h"
#include "rpstimes.h"
#include "rpsMoney.h"
#include <time.h>
int ChoiceOfCom(void){  // 1~3 ������ ���� ���� ��ȯ
	srand((unsigned int)time(NULL));
	return rand() % 3 + 1;
}

int ChoiceOfMe(void) {
	int choice;
	fputs("����(1) ����(2) ��(3) ����(0) ����? ", stdout);
	scanf("%d", &choice);
	return choice;
}

void WhoIsWinner(int com, int you) {
	int outcome = you - com;
	IncreGameTimes();

	switch (outcome){
	case 0:      /* ��� ��� */
		puts("�����ϴ�.");		
		return;
	case 1: case -2:    /* ���� �̱� ��� */
		puts("����� �����Դϴ�.");
		IncreYouWinTimes();
		YouWinMoneyAccount();
		return;
	}
	puts("��ǻ�Ͱ� �����̱���!");
	ComWinMoneyAccount();
}

void ShowRSP(int rsp){ //����� ���� ���ڿ�(����, ����, ��) ���
	switch (rsp){
	case SCISSORS:
		fputs("����", stdout);
		break;
	case ROCK:
		fputs("����", stdout);
		break;
	case PAPER:
		fputs("��", stdout);
		break;
	}
}