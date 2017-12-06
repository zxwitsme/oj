#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{ 
	unsigned int i, n, r;

	n = atoi(line);

	for (i = 0, r = 0; i < 32; i++) {
		r *= 2;
		r += n%2;
		n /= 2;
	}

	printf("%u\n", r); 
}   

int main()
{
	char a[1024];
	scanf("%s", a);
	solution(a);
	return 0;
}

