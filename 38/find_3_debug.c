#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	unsigned long t[16];
	unsigned long i, j, m, n, c;
	unsigned long r1 = 0, r = 0, k = 10, done = 0;

	memset(t, 0, sizeof(t));

	n = atol(line);

	while(1) {
		printf("n %lu\n", n);
		if (!n)
			break;
		c = n % k;
		printf("c %lu\n", c);
		if (c == 0) {
			k *= 10;
			continue;
		}
		if (c < 10) {
			for (i = 0; i <= c; i++) {
				if (i == 3)
					r++;
			}
			printf("r %lu\n", r);
		} else {
			j = 10;
			r1 = 1;
			m = c;
			while(1) {
				m /= 10;
				printf("m %lu\n", m);
				if (!m)
					break;
				if (m <= 10 && m >= 4) {
					r1 = m * r1 + j/2;
					printf("#m %lu r1 %lu\n", m, r1);
					break;
				} else if (m < 3) {
					r1 = m * r1;
					printf("##m %lu r1 %lu\n", m, r1);
					break;
				} else if (m == 3) {
					r1 = m * r1 + (done+1)/2;
					printf("###m %lu r1 %lu done %lu\n", m, r1, done);
					break;
				} else {
					r1 = 10 * r1 + j/2;
					printf("m %lu r1 %lu\n", m, r1);
				}

				j *= 10;
			}
			r += r1;
			printf("#r %lu\n", r);
		}

		n -= c;
		done += c;
		printf("done %lu\n", done);
		k *= 10;
	}

	printf("%lu\n", r);
}
 
int main()
{
	char line[1024];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
