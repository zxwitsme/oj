#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	int el[1024], temp;
	int result = 0;
	int a, n = 0;
	int i, j, p, q, x, repeat;
	int hit[32][3];

	memset(el, 0, 1024); 

	while (1) {
		a = atoi(line);
		el[n++] = a;
		line = strstr(line, ",");
		if (line == NULL)
			break;
		else
			line += 1;
	}

	for (i = 0; i < n; i++) {
		for (j = n -1; j > i; j--) {
			if (el[j] < el[j-1]) {
				temp = el[j-1];
				el[j-1] = el[j];
				el[j] = temp;
			}
		}
	}

	for (i = 0; i < n - 2; i++) {
		p = i + 1;
		q = n - 1;
		while (p < q) {
			if (el[i]+el[p]+el[q]==0) {
				repeat = 0;
				for (x = 0; x < result; x++) {
					if (hit[x][0] == el[i]
						&& hit[x][1] == el[p]
						&& hit[x][2] == el[q]) {
						repeat = 1;
						break;
					}
				}

				if (repeat == 0) {
					hit[result][0] = el[i];
					hit[result][1] = el[p];
					hit[result][2] = el[q];
					result++;
				}
				if (q > 0)
					q--;
				if (p < n - 1)
					p++;
			} else if (el[i]+el[p]+el[q]>0) {
				if (q > 0)
					q--;
			} else {
				if (p < n - 1)
					p++;
			}
		}
	}

	printf("%d\n", result);
}

int main()
{
	char line[1024];
	scanf("%[^\n]", line);
	solution(line);
}

