//1546 평균 (1차원 배열)
#include <stdio.h>

int main(void)
{
	int exam;
	scanf("%d", &exam);

	float score[1000];
	for (int i = 0; i < exam; i++) {
		scanf("%f", &score[i]);
	}
	int M = -1;

	for (int i = 0; i < exam; i++) {
		if (M < score[i])
			M = score[i];
	}

	float avg = 0;
	for (int i = 0; i < exam; i++) {
		score[i] = score[i] / M * 100;
		avg += score[i];
	}
	printf("%f\n", avg / exam);
	return 0;
}