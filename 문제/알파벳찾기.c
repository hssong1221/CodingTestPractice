//10890 알파벳 찾기 (문자열)
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[100];
	int list[26] = {0,};

	for (int i = 0; i < 26; i++) {
		list[i] = -1;
	}

	scanf("%s", str);
	int temp;
	for (int i = 0; i < strlen(str); i++) {
		temp = str[i] - 'a';
		if(list[temp] == -1)
			list[temp] = i;
	}
	
	for (int i = 0; i < 26; i++) {
		printf("%d ", list[i]);
	}

	return 0;
}