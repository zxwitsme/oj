#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 600000
int log_calc(long i)
{
	if (i <= 0)
		return 0;
	if(i < 10 && i >= 1)
		return 0;
	else if (i < 100 && i >= 10)
		return 1;
	else if (i < 1000 && i >= 100)
		return 2;
	else if (i < 10000 && i >= 1000)
		return 3;
	else if (i < 100000 && i >= 10000)
		return 4;
	else if (i < 1000000 && i >= 100000)
		return 5;
	else if (i < 10000000 && i >= 1000000)
		return 6;
	else if (i < 100000000 && i >= 10000000)
		return 7;
	else if (i < 1000000000 && i >= 100000000)
		return 8;
	else if (i < 10000000000 && i >= 1000000000)
		return 9;
	else if (i < 100000000000L && i >= 10000000000)
		return 10;
	else if (i < 1000000000000L && i >= 100000000000L)
		return 11;
	else if (i < 10000000000000L && i >= 1000000000000L)
		return 12;
	else if (i < 100000000000000L && i >= 10000000000000L)
		return 13;
	else if (i < 1000000000000000L && i >= 10000000000000L)
		return 14;
	else if (i < 10000000000000000L && i >= 100000000000000L)
		return 15;
}

/*because atol function doesn't work, so we use 2 atoi to combile long type*/
void solution(char *line)
{
	long a, b;
	char line1[1024];
   	long i, j, m = 0, n, t = 1;
	long f1, f2;
	long s[NUM];

	if (strlen(line)<=8)
		n = atol(line);
	else {
		for(i=strlen(line)-8; ;i++) {
			line1[i - (strlen(line)-8)] = line[i];
			if(line[i]=='\0')
				break;
		}

		line[strlen(line)-8]='\0';

		a = atol(line);
		b = atol(line1);

		n = a*100000000 + b;
	}

	f1=1;
	s[1]=1;
	for(i=2;i<NUM;i++){
		f2=f1+log_calc(i)+1;
		s[i]=s[i-1]+f2;
		f1 = f2;
	}

	i = 1;
	while(s[i]<n) {
        	i++;
		if (i >= NUM) {
			printf("out of range\n");
			break;
		}
	}
    	n-=s[i-1];
	for(i=1;m<n;i++)
		m+=(int)log_calc(i)+1;
	for(j=0;j<m-n;j++)
		t *= 10;
	m=(i-1)/t%10;
	printf("%ld\n", m);
}

int main()
{
	char line[1024];
	
	scanf("%[^\n]", line);
	solution(line);
}
