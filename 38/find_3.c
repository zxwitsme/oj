#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	unsigned long i, j, n, c, r1;
	unsigned long r = 0, k = 10, done = 0;

	n = atol(line);

	while(1) {
		if (!n)
			break;
		c = n % k;
		if (c == 0) {
			k *= 10;
			continue;
		}
		if (c < 10) {
			for (i = 0; i <= c; i++) {
				if (i == 3)
					r++;
			}
		} else {
			j = 10;
			r1 = 1;
			i = c;
			while(1) {
				i /= 10;
				if (!i)
					break;
				if (i <= 10 && i >= 4) {
					r1 = i * r1 + j/2;
					break;
				} else if (i < 3) {
					r1 = i * r1;
					break;
				} else if (i == 3) {
					r1 = i * r1 + (done+1)/2;
					break;
				} else {
					r1 = 10 * r1 + j/2;
				}

				j *= 10;
			}
			r += r1;
		}

		n -= c;
		done += c;
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
