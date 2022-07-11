//2941 크로아티아 알파벳 (문자열)
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[101];
	scanf("%s", str);

	int len = 0;
	len = strlen(str);

	int temp = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'c') {
			if (str[i + 1] == '=' || str[i + 1] == '-') {
				temp++;
				i++;
				continue;
			}
		}
		else if (str[i] == 'd') {
			if (str[i + 1] == 'z' && str[i + 2] == '=')
			{
				temp++;
				i += 2;
				continue;
			}
			else if (str[i + 1] == '-')
			{
				temp++;
				i++;
				continue;
			}
		}
		else if (str[i] == 'l') {
			if (str[i + 1] == 'j') {
				temp++;
				i++;
				continue;
			}
		}
		else if (str[i] == 'n') {
			if (str[i + 1] == 'j') {
				temp++;
				i++;
				continue;
			}
		}
		else if (str[i] == 's') {
			if (str[i + 1] == '=') {
				temp++;
				i++;
				continue;
			}
		}
		else if (str[i] == 'z') {
			if (str[i + 1] == '=') {
				temp++;
				i++;
				continue;
			}
		}
		temp++;
	}

	printf("%d", temp);

	return 0;
}