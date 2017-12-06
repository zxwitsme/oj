#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	int element[1024], result[1024], k;
	int max = 0;
	int a, b, n = 0;
	char *line_element;
	int i, j, hit, first = 0;

	memset(element, 0, 1024); 
	memset(result, 0, 1024); 

	line_element = strtok(line, " ");
	k = atoi(strtok(NULL, " "));

	while (1) {
		a = atoi(line_element);
		element[a]++;
		if (a + 1 > n)
			n = a + 1;
		line_element = strstr(line_element, ",");
		if (line_element == NULL)
			break;
		else
			line_element += 1;
	}

	for (i = 0; i < k; i++) {
		for (j = 0; j < n; j++) {
			if (element[j] > max) {
				hit = j;
				max = element[j];
			}
		}
		max = 0;
		element[hit] = 0;
		result[hit] = 1;
	}

	for (i = 0; i < n; i++) {
		if (result[i]) {
			if (first == 0) {
				first = 1;
				printf("%d", i);
			} else
				printf(",%d", i);
		}
	}
	printf("\n");

}

int main()
{
	char line[1024];
	scanf("%[^\n]", line);
	solution(line);
}

