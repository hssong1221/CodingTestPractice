//4344 평균은 넘겠지 (1차원 배열)
#include <stdio.h>

int main(void)
{
	int testcase;
	scanf("%d", &testcase);

	float num;
	int score[1000];
	float temp;
	float avg;
	float result;
	for (int i = 0; i < testcase; i++) {
		scanf("%f", &num);
		temp = 0;
		for (int k = 0; k < num; k++) {
			scanf("%d", &score[k]);
			temp += score[k];
		}
		avg = temp / num;
		temp = 0;
		for (int j = 0; j < num; j++) {
			if (score[j] > avg)
				temp++;
		}
		result = temp / num * 100;
		printf("%.3f%%\n", result);
	}

	return 0;
}