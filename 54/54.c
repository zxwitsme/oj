#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	char *line_a, *saveptr;
	int f[1024], f_r[1024];
	int i, j, tmp, m = 0, count = 0;
 
	memset(f, 0, sizeof(f));
	memset(f_r, 0, sizeof(f_r));

	while (1) {
		if (m == 0)
			line_a = strtok_r(line, ",", &saveptr);
		else
			line_a = strtok_r(NULL, ",", &saveptr);
		if (!line_a)
			break;

		f[m] = atoi(line_a);
		m++;
	}

	for (i = 0; i < m; i++)
		f_r[i] = f[i];

	for (i = 0; i < m; i++) {
		for (j = m - 1; j > i; j--) {
			if (f_r[j-1] > f_r[j]) {
				tmp = f_r[j-1];
				f_r[j-1] = f_r[j];
				f_r[j] = tmp;
			}
		}
	}

	for (i = 0; i < m; i++) {
		if (f_r[i] != f[i])
			break;
		else
			count++;
	}

	for (i = m - 1; i >= 0; i--) {
		if (f_r[i] != f[i])
			break;
		else
			count++;
	}

	printf("%d\n", m - count);
}
 
int main()
{
	char line[10240];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
