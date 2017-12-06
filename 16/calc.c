#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	char *num[512], *op[512], *tmp;
	int even = 1;
	int i, j, n, p = 0, q = 0;
	char op1, op2, op3;
	int a1, a2, a3;

	num[p++] = strtok(line, " ");
	op[q++] = strtok(NULL, " ");
	do {
		tmp = strtok(NULL, " ");
		if (tmp == NULL) {
			break;
		}
		if (even)
			num[p++] = tmp;
		else
			op[q++] = tmp;
		even = !even;
	} while (1);

	n = p;
	p = 0;
	q = 0;

	a1 = 0;
	op1 = '+';
	while(p < n) {
		a2 = atoi(num[p++]);
		if (p < n)
			op2 = *(op[q++]);
		while(op2=='*' || op2=='/')  {
			a3 = atoi(num[p++]);
			if (p < n)
				op3 = *(op[q++]);
			if(op2=='*')
				a2 *= a3;  
			else if(op2=='/') {
				if (a3 == 0) {
					printf("err\n");
					return;
				} else
					a2 /= a3;
			}
			op2 = op3;
		}

		if(op1 == '+')
			a1 += a2;
		else if(op1 == '-')
			a1 -= a2; 
		op1 = op2;
	}

	printf("%d\n", a1);
}

int main()
{
	char line[1024];
	scanf("%[^\n]", line);
	solution(line);
}

