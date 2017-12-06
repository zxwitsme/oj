#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

void solution(char *line)
{
	long s[16] = {1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2};
	long i, a, b, n;
	char line1[1024];

	if (strlen(line)<=8)
		n = atol(line);
	else {
		for(i=strlen(line)-8; ;i++) {
			line1[i - (strlen(line)-8)] = line[i];
			if(line[i]=='\0')
				break;
		}

		line[strlen(line)-8]='\0';

		printf("line %s\n", line1);
		printf("line1 %s\n", line1);

		a = atol(line);
		b = atol(line1);

		printf("a %ld\n", a);
		printf("b %ld\n", b);
		printf("%ld size:%ld\n", a*100000000 + b, sizeof(long));

		n = a*100000000 + b;
	}

	for (i = 1L; ;i++) {
		if (n - (i*(i-1L)/2L) <= i) {
			n -= i*(i-1L)/2L;
			printf("%ld %ld %ld\n", (n-1L)%16L, n-1L, s[(n-1L)%16L]);
			break;
		}
	}
}

int main()
{
	char line[1024];
	long a, b;
	
	a = 0x0fffffffff;
	b = 0x1000000000;

	printf("%lx\n",a+b);
	scanf("%[^\n]", line);

	solution(line);
}
