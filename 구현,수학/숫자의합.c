//11720 숫자의 합 (문자열)
#include <stdio.h>
#include <string.h>

int main(void) {
	int n;
	scanf("%d", &n);
	
	int temp = 0;
	int result= 0;
	char list[100];
	scanf("%s", list);


	for (int i = 0; i < strlen(list); i++) {
		temp = list[i] - '0';
		result += temp;
	}
	printf("%d", result);

	return 0;
}