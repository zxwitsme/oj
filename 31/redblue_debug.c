#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	int a, b, n;
	int i, j, k, plus = 0, div2 = 0;
	int result[256][4096];

	memset(result, 0, sizeof(result));
	a = atoi(line);
	line = strstr(line, " ");
	line++;
	b = atoi(line);

	printf("%d %d\n", a, b);

	if (a > b) {
		printf("%d\n", a-b);
		return;
	}

	result[0][0] = a;
	for (i = 1; ;i++) {
		if (a > b) {
			printf("%d\n", a-b+plus+div2);
			return;
		}
		n = 1;
		for (j = 0; j < i; j++)
			n *= 2;
		printf("n %d\n", n);
		if (i > 12) {
			printf("too big! again\n");
			if (b%2) {
				div2 = b%2;
				b = (b+1)/2;
			} else
				b /= 2;
			plus++;
			i = 0;
			j = 0;
			continue;
		}

		for (j = 0; j < n; j+=2) {
			result[i][j] = 2 * result[i-1][j/2];
			result[i][j+1] = result[i-1][j/2] - 1;
			//printf("result[%d][%d] %d\n", i, j, result[i][j]);
			//printf("result[%d][%d] %d\n", i, j+1, result[i][j+1]);
			if (result[i][j] == b || result[i][j+1] == b) {
				printf("%d\n", i+plus+div2);
				return;
			}
		}
	}	
}

int main()
{
	char line[1024];
	
	scanf("%[^\n]", line);
	solution(line);

	return 0;
}

