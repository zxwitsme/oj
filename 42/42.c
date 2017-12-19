#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	int min, n, t, i, j, s[100];
	unsigned char r[1000001];

	memset(s, 0, sizeof(s));
	memset(r, 0, sizeof(r));

	n = atoi(line);

	r[0] = 0;
	for (i = 0; i < 100; i++)
		s[i] = i * i * i;

	for (i = 1; i <= n; i++) {
		for (j = 1;  ; j++) {
			if (s[j] > i)
				break;
			if (j == 1)
				min = r[i-s[j]] + 1;
			else {
				t = r[i-s[j]] + 1;
				if (t < min)
					min = t;
			}
		}
		r[i] = min;
	}

	printf("%d\n", r[n]);
}

int main()
{
	char line[1024];

	scanf("%s", line);

	solution(line);

	return 0;
}


