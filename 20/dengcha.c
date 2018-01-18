#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	short e[1024],f[1024][1024], f1[1024][1024];
	int count = 0;
	int a, n = 0;
	int i, j, k;

	memset(e, 0, sizeof(e)); 
	memset(f, 0, sizeof(f));
	memset(f1, 0, sizeof(f1));
	while (1) {
		a = atoi(line);
		e[n++] = a;
		line = strstr(line, " ");
		if (line == NULL)
			break;
		else
			line += 1;
	}

	for (i = 0; i < n; i++) {
		count += i+1;
		for (j = i-1; j >= 0; j--) {
			if (e[i] - e[j] >= 0) {
				k = e[i] - e[j];
				count += f[j][k];
				f[i][k] += f[j][k] + 1;
			} else {
				k = e[j] - e[i];
				count += f1[j][k];
				f1[i][k] += f1[j][k] + 1;
			}
		}
	}

	printf("%d\n", count - n);
}

int main()
{
	char line[1024];
	scanf("%[^\n]", line);
	solution(line);
}

