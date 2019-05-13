#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int gameNumOfTimes = 0;
static int youWinNumOfTimes = 0;

void StoreGameTimesFromFile(fp) {
	fwrite(&gameNumOfTimes, sizeof(int), 1, fp);
	fwrite(&youWinNumOfTimes, sizeof(int), 1, fp);
}
void LoadGameTimesFromFile(fp) {
	fread(&gameNumOfTimes, sizeof(int), 1, fp);
	fread(&youWinNumOfTimes, sizeof(int), 1, fp);
}

void IncreGameTimes(void){ //���� ���� �� ����
	gameNumOfTimes++;
}
int GetGameTimes(void){//���� ���� �� ��
	return gameNumOfTimes;
}
void IncreYouWinTimes(void){
	youWinNumOfTimes++;
}
int GetYouWinTimes(void){//���̸��� ���� ��� �� ��ȯ
	return youWinNumOfTimes;
}
int GetPercenOfVictory(void){ //���̸��� �·� ���
	if (gameNumOfTimes == 0)
		return 0;	
	
	return (double)youWinNumOfTimes / gameNumOfTimes * 100;
}
