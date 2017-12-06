#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	int element[1024], t;
	int max = 0;
	int a, b, n = 0;
	char *line_element;
	int i, j;

	memset(element, 0, 1024); 

	line_element = strtok(line, " ");
	t = atoi(strtok(NULL, " "));

	while (1) {
		a = atoi(line_element);
		element[n++] = a;
		line_element = strstr(line_element, ",");
		if (line_element == NULL)
			break;
		else
			line_element += 1;
	}

	for (i = 0; i < n; i++) {
		if (element[i] == t) {
			printf("%d\n", i);
			return;
		}
	}

	printf("-1\n");
}

int main()
{
	char line[1024];
	scanf("%[^\n]", line);
	solution(line);
}

