#include <stdio.h>
#include <string.h>

void solution(char *line)
{
	int i, j, k, len;
	char *long_str, *short_str;

	short_str = strtok(line, " ");
	long_str = strtok(NULL, " ");

	len = strlen(long_str);
	for (i = 0; i < strlen(short_str); i++) {
		for (j = 0; j < len; j++) {
			if(short_str[i] == long_str[j]) {
				long_str[j] = ',';
				break;
			}
			if (j == (len -1)) {
				printf("false\n");
				return;
			}
		}
	}
	printf("true\n");
}

int main()
{
	char line[1024];

	scanf("%[^\n]", line);
	solution(line);
}

