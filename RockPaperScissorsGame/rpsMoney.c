#include <stdio.h>
#include <stdlib.h>

static int moneyCom;  // ��ǻ�� ���� �Ӵ�
static int moneyYou;  // ���̸� ���� �Ӵ�
static int gamblingTableMoney;

void StoreGameMoneyFromFile(fp) {
	fwrite(&moneyCom, sizeof(int), 1, fp);
	fwrite(&moneyYou, sizeof(int), 1, fp);
}
void LoadGameMoneyFormFIle(fp) {
	fread(&moneyCom, sizeof(int), 1, fp);
	fread(&moneyYou, sizeof(int), 1, fp);
}

void SetComMoney(int money){
	if (money < 0)	{// ������ �˸��� ���� �޽��� ��� ����.
		return;
	}
	moneyCom = money;
}

int GetCurrentComMoney(void){
	return moneyCom;
}

void SetYouMoney(int money){
	if (money < 0)	{// ������ �˸��� ���� �޽��� ��� ����.
		return;
	}
	moneyYou = money;
}

int GetCurrentYouMoney(void){
	return moneyYou;
}

void SetGamblingTableMoney(int money){
	if (money < 0)
		gamblingTableMoney = 0;
	else
		gamblingTableMoney = money;
}

void ComWinMoneyAccount(void){
	moneyYou -= gamblingTableMoney;
	moneyCom += gamblingTableMoney;
}

void YouWinMoneyAccount(void){
	moneyCom -= gamblingTableMoney;
	moneyYou += gamblingTableMoney;
}

int SetGamblingTableMoneyByGamer(int money){
	if (money > moneyYou)
		return 0;   // gamer ���� �ݾ� �ʰ�
	else if (money > moneyCom)
		return -1;  // com ���� �ݾ� �ʰ�

	SetGamblingTableMoney(money);
	return 1;  // ������ �Է�.
}