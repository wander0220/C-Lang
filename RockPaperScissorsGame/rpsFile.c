#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "rpstimes.h"
#include "rpsMoney.h"

#define FILE_NAME "gamefile.dat"
#define FILE_NAME_DEL "del gamefile.dat"

int DoYouWantToContinue() {
	FILE *fp;
	int cont;

	if (!AvailContinue()) return 0; //������ �����ϸ�

	puts("������ �̾ �Ͻðڽ��ϱ�?(Yes:1, No:0)");
	scanf("%d", &cont);

	if (cont == 0) return 0;

	fp = fopen(FILE_NAME, "rb"); //���� �б� ���
	if (fp == NULL) {
		puts("�̾ �� �����Ͱ� �������� �ʽ��ϴ�");
		return 0;
	}
	LoadGameTimesFromFile(fp); //���� �¸� ����
	LoadGameMoneyFormFIle(fp); //���� �Ӵ� ����
	fclose(fp);
	return 1;
}
int DoYouWantToStore() {
	FILE *fp;
	int cont;
	puts("���� ������ �����Ͻðڽ��ϱ�?(Yes:1, No:0)");
	scanf("%d", &cont);

	if (cont == 0) return 0;
	fp = fopen(FILE_NAME, "wb");//���� ���� ���
	StoreGameTimesFromFile(fp);
	StoreGameMoneyFromFile(fp);

	fclose(fp);
	return 1;
}
int AvailContinue() { // ������ �̾ �� �����Ͱ� �����ϸ�
	FILE *fp;
	fp = fopen(FILE_NAME, "rb"); //���� �б� ���
	if (fp == NULL) return 0;
	else {
		fclose(fp);
		return 1;
	}
}
void ClearContinueInfo() {
	FILE *fp;
	fp = fopen(FILE_NAME, "rb");

	if (fp != NULL) {
		fclose(fp);
		system(FILE_NAME_DEL);
	}
}