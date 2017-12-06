#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void solution(char *line)
{
	int list[128];
	int i, j, k, l, m, n, c, t;
	int used;

	k = atoi(line);

	for (m = k+1; ;m++) {
		used = 0;
		c = 0;
		l = 0;
		memset(list, 0, 2 * k *sizeof(int));
		while (1) {
			t = 2*k-used;
			n = (m-l)%t;
			if (!n)
				n = t;
			for (i = 0, j = 0; i < 2 * k; i++) {
				if (!list[i]) {
					j++;
				}
				if (j == n)
					break;
			}
			if (j == n && i >= k) {
				list[i] = 1;
				for (l = 0; i < 2 * k; i++) {
					if (!list[i])
						l++;
				}
				used++;
				c++;
			} else
				break;
			if (c == k) {
				printf("%d\n", m);
				return;
			}
		}
	}
}


int main()
{
	char line[1024];

	scanf("%s", line);
	solution(line);

}

