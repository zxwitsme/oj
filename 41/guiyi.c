#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char* line)
{
	int n, m, i, s[16], t, h[10240];

	memset(h, 0, sizeof(h));
	n = atoi(line);

	t = 0;
	h[0] = n;
	while (1) {
		m = 0;
		while (n != 0) {
			s[m++] = n%10;
			n /= 10;
		}

		for (i = 0, n = 0; i < m; i++)
			n += s[i] * s[i];

		if (n == 1) {
			printf("true\n");
			return;
		}

		for (i = 0; i <= t + 1; i++) {
			if (n == h[i]) {
				printf("false\n");
				return;
			}
		}

		h[t] = n;
		t++;
	}
	
	printf("false\n");
	return;
}

int main()
{
	char line[1024];

	scanf("%s", line);

	solution(line);

	return 0;
}

