#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
int main() {
	time_t now;

	struct tm *d;
	time(&now);

	now = time(NULL);

	d = localtime(&now);

	printf("���� ��¥�� �ð� : %s\n", asctime(localtime(&now)));
	printf("���� ��¥�� �ð� : %s\n", time(now));

	printf("���� ��¥ : %d�� %d�� %d�� \n", d->tm_year+1900,d->tm_mon+1,d->tm_mday);
	printf("���� ��¥ : %d�� %d�� %d�� \n", d->tm_hour*10000,d->tm_min*100,d->tm_sec);


}