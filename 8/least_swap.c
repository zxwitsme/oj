#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	int a, i, j, max = 0;
	int number[1024], least_swap = 0;

	memset(number, 0, 1024);
	while (1) {
		a = atoi(line);
		number[max++] = a;
		line = strstr(line, ",");
		if (line == NULL)
			break;
		else
			line++;
	}

	for (i = 0; i < max; i++) {
		for(j = i+1; j < max; j++) {
			if (number[i] > number[j])
				least_swap++;
		}
	}

	printf("%d\n", least_swap);
}

int main()
{
	char line[1024];

	scanf("%[^\n]", line);
	solution(line);
}

