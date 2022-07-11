//1157 단어공부 (문자열)
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	char str[1000001];
	scanf("%s", str);

	int list[26] = { 0, };
	int temp;
	int count;
	count = strlen(str);
	for (int i = 0; i < count; i++) {
		if (islower(str[i]))
			str[i] = toupper(str[i]);
		temp = str[i] - 'A';
		list[temp]++;
	}

	int max = 0;
	int flag = 0;
	temp = 0;
	for (int j = 0; j < 26; j++) {
		if (max < list[j]) {
			max = list[j];
			temp = j;
			flag = 0;
		}
		else if (max == list[j])
			flag = 1;
	}

	if (flag == 1) 
		printf("?\n");
	else
		printf("%c\n", temp + 65);

	return 0;
}