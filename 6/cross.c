#include <stdio.h>
#include <string.h>

void solution(char *line)
{
	char *l, *m, *n;
	int i, j;

	l = strtok(line, ",");
	m = strtok(NULL, ",");
	n = strtok(NULL, ",");

	for (i = 0,j = 0; i < strlen(m); i++) {
		for (; j < strlen(n); j++) {
			if (n[j] == m[i]) {
				n[j] = ',';
				break;
			}
		}
	}

	for (i = 0, j = 0; i < strlen(n); i++) {
		if (n[i] == ',')
			continue;
		else if (n[i] != l[j++]) {
			printf("false\n");
			return;
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

