#include "rps.h"
#include "rpstimes.h"
#include "rpsMoney.h"
#include "rpsFile.h"

int main(void){
	int com;
	int you;

	int youMoney;
	int tableMoney;
	int ret;

	if (!DoYouWantToContinue())	{
		puts("-----���� ���� �� ���� ����-----");
		puts("");

		SetComMoney(5000);

		fputs("�� ����� ���� �Ӵ� �Է� : ", stdout);
		scanf("%d", &youMoney);
		if (youMoney <= 0)
		{
			puts("����ġ ���� �Է����� ���α׷��� �����մϴ�.");
			return -1;
		}
		SetYouMoney(youMoney);
	}
	printf("�� ����� ���� �Ӵ�: %d \n", GetCurrentYouMoney());
	printf("�� ��ǻ�� ���� �Ӵ�: %d \n\n", GetCurrentComMoney());

	while (1)
	{
		puts("�� �ǵ� ����!��");
		fputs("�� �ǵ� �Է�: ", stdout);
		scanf("%d", &tableMoney);
		puts("");

		ret = SetGamblingTableMoneyByGamer(tableMoney);
		if (ret == 0 || ret == -1)  // �ǵ� �Է� ����!
		{
			if (ret == 0) // ����� ���� �ݾ� �ʰ�
			{
				puts("�����ϰ� �ִ� �ݾ� ������ �ż���!");
				printf("�� ����� ���� ���� �Ӵ�: %d \n", GetCurrentYouMoney());
			}
			else // ��ǻ�� ���� �ݾ� �ʰ�
			{
				puts("��ǻ�� ���� �ݾ� �ʰ��Դϴ�!");
				printf("�� ��ǻ���� ���� ���� �Ӵ�: %d \n", GetCurrentComMoney());
			}
			continue;
		}

		puts("���������� ��  �� ����������");
		com = ChoiceOfCom();
		you = ChoiceOfMe();
		puts("");

		if (you == EXIT)	break;

		puts("���������� ��  �� ����������");
		WhoIsWinner(com, you);

		fputs("�� ��ǻ���� ����: ", stdout);
		ShowRSP(com);
		puts("");

		fputs("�� ����� ����: ", stdout);
		ShowRSP(you);
		puts("");

		printf("---> �·� : %d %% \n\n", GetPercenOfVictory());
		printf("�� ����� �Ӵ�: %d \n", GetCurrentYouMoney());
		printf("�� ��ǻ�� �Ӵ�: %d \n\n", GetCurrentComMoney());

		if (GetCurrentComMoney() <= 0 || GetCurrentYouMoney() <= 0)
			break;
	}
	puts("���������� �� �� �� �� ����������");
	printf("�����·� : %d %% \n", GetPercenOfVictory());

	if (GetCurrentComMoney() != 0 && GetCurrentYouMoney() != 0)
		DoYouWantToStore();  // ���ӳ��� ����.
	else
		ClearContinueInfo();

	puts("Thank You~ See you Again~~~!");
	puts("");

	return 0;
}