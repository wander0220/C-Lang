#include <stdio.h>
#include <math.h>
void print_frequency(int octave) {
	double do_scale = 32.7032;
	double ratio = pow(2., 1 / 12.), temp;
	int i;
	temp = do_scale * pow(2., (octave - 1));
	printf("\n%d��Ÿ�� : ", octave);
	for (i = 0;i < 12; i++) {
		printf("%5ld", (unsigned long)(temp + 0.5));
		temp*=ratio;
	}
	printf("\n");
}
int main() {
	char *scale[] = { "��","��#","��","��#","��",
		"��","��#","��","��#","��","��#","��","��" };
	int octave, i, count = 0;
	printf("����� ���ļ�\n\n����\t      ");
	for (i = 0; i < 12; i++) printf("%-5s", scale[i]);
	printf("\n");

	for (i = 0; i <= 70; i++) printf("-");
	for (octave = 1; octave < 7; octave++) {
		print_frequency(octave);
	}

}