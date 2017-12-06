#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{ 
	int i, n, r;

	n = atoi(line);

	for (i = 1, r = 0; i <= n; i++) {
		if (n%i == 0 && n/i-(i-1) > 0)
			r++;
	}
	printf("%d\n", r); 
}   

int main()
{
	char a[1024];
	scanf("%s", a);
	solution(a);
	return 0;
}

