#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	int e[1024],f[1024][8192];
	int count = 0;
	int a, n = 0;
	int i, j, k;

	memset(e, 0, 1024); 
	memset(f, 0, sizeof(f)); 
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
			k = e[i]-e[j];
			if (k >= 8192) {
				printf("k so big: %d\n", k);
				return;
			}
			count += f[j][k];
			f[i][k] +=f[j][k]+1;
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

