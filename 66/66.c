#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	char d[102400];
	int i, j, m, n;
 
	memset(d, 0, sizeof(d));

	n = atoi(line);

	d[0] = 1;
	d[1] = 2;

	m = 1;
	i = 1;
	j = 1;

	for (i = 1; ; i++) {
		if (d[i] == 2) {
			if (i%2) {
				d[j++] = 2;
				d[j++] = 2;
			} else {
				d[j++] = 1;
				d[j++] = 1;
			}
		} else if (d[i] == 1) {
			if (i%2) {
				d[j++] = 2;
			} else {
				d[j++] = 1;
			}
		} else
			printf("couldn't reach here\n");

		if (!(i%2))
			m += d[i];

		if (j == n) {
			printf("%d\n", m);
			return;
		} else if (j == n + 1) {
			if (i%2)
				printf("%d\n", m);
			else
				printf("%d\n", m - 1);
			return;
		} else if (j > n + 1)
			printf("couldn't reach here\n");
	}
}
 
int main()
{
	char line[10240];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
