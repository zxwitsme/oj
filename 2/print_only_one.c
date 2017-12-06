#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	char *record;
	int max = 0;
	int a, size;

	size = 16;
	record = (char*)malloc(size * sizeof(char));
	memset(record, 0, size); 
	while (1) {
		a = atoi(line);
		if ((a + 1) > size) {
			record = (char*)realloc(record, (a+1)*sizeof(char));
			memset(record+size, 0, a+1-size); 
			size = a + 1;
		}
		record[a]++;
		if (a > max)
			max = a;
		line = strstr(line, " ");
		if (line == NULL)
			break;
		else
			line += 1;
	}

	for (a = 0; a < max + 1; a++) {
		if (record[a] == 1)
			printf("%d ", a);
	}
	printf("\n");
}

int main()
{
	char line[1024];
	scanf("%[^\n]", line);
	solution(line);
}

