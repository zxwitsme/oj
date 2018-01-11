#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int judge1(int x, int y, int s[][9])  
{  
	int i;

	for (i = 0; i < 9; i++) {
		if ((s[i][y] == s[x][y]) && (i != x))
			return 0;
		if ((s[x][i] == s[x][y]) && (i != y))
			return 0;
	}

	return 1;
}

int judge2(int x, int y, int s[][9])  
{
	int m, n, i, j;

	m = x / 3;
	n = y / 3;

	for (i = m * 3; i < m * 3 + 3; i++) {
		for(j = n * 3; j < n * 3 + 3; j++) {
			if (s[i][j] == s[x][y] && !(i==x && j==y))
				return 0;
		}
	}

	return 1;
}

void solution(char *line)
{
	char *line_a, *saveptr;
	int s[9][9], tmp[9];
	int i, j, m = 0;
 
	memset(s, 0, sizeof(s));
	memset(tmp, 0, sizeof(tmp));
	while (1) {
		if (m == 0)
			line_a = strtok_r(line, " ", &saveptr);
		else
			line_a = strtok_r(NULL, " ", &saveptr);
		if (!line_a)
			break;

		for(i = 0; i < 9; i++) {
			if (i != 0) {
				if (*line_a == '-')
					tmp[i] = 0;
				else
					tmp[i] = atoi(line_a);
				line_a = strstr(line_a, ",");
				if (!line_a)
					break;
				line_a++;
			}
			if (*line_a == '-')
				tmp[i] = 0;
			else
				tmp[i] = atoi(line_a);
		}
		
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				s[(m / 3) * 3 + i][(m % 3) * 3 + j] = tmp[i*3+j];

		m++;
	}

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (s[i][j] != 0) {
				if (!judge1(i, j, s)) {
					printf("false\n");
					return;
				}
				if (!judge2(i, j, s)) {
					printf("false\n");
					return;
				}
			}
		}
	}

	printf("true\n");
}
 
int main()
{
	char line[10240];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
