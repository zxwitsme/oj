#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	int i, j, k, len;
	char *number, first_num = 1, result[1024], m = 0;

	number = strtok(line, ",");
	k = atoi(strtok(NULL, ","));

	len = strlen(number);
	if (len == k)
		printf("0\n");
	for (i = 0; i < strlen(number) - 1;) {
		if (m < k) {
			if(number[i] > number[i+1]) {
				for (j = i; j < strlen(number); j++)
					number[j] = number[j+1];
				i = 0;
				m++;
				continue;
			}

		} else
			break;

		i++;
	}

	number[len - k] = '\0';

	for (;;) {
		if(number[0] == '0' && strlen(number) != 1) {
			for (i = 0; i < strlen(number); i++)
				number[i] = number[i+1];
			continue;
		} else
			break;
	}

	printf("%s\n", number);
}

int main()
{
	char line[1024];

	scanf("%[^\n]", line);
	solution(line);
}

