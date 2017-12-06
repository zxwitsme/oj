#include <stdio.h>
#include <string.h>

void solution(char *line)
{
	char stack_op[512], *tmp;
	int stack_num[512];
	char *saveptr;
	int i, p = 0;
	int num1, num2, num3;
	char op;

	num1 = atoi(strtok_r(line, " ", &saveptr));
	do {
		tmp = strtok_r(NULL, " ", &saveptr);
		if (tmp == NULL)
			break;
		op = *tmp;

		if (op == '*' || op == '/') {
			num2 = atoi(strtok_r(NULL, " ", &saveptr));
			if (op == '*')
				num1 *= num2;
			else if (op == '/') {
				if (num2 == 0) {
					printf("err\n");
					return;
				}
				num1 /= num2;
			}
		} else if (op == '+' || op == '-') {
			stack_num[p] = num1;
			stack_op[p] = op;
			p++;
			num1 = atoi(strtok_r(NULL, " ", &saveptr));
		}
	} while (1);

	if (p > 0)
		num2 = stack_num[0];
	else
		num2 = num1;
	for (i = 0; i < p; i ++) {
		if (i < p-1)
			num3 = stack_num[i+1];
		else 
			num3 = num1;
		op = stack_op[i];
		if (op == '+')
			num2 += num3;
		else if (op == '-')
			num2 -= num3;
	}

	printf("%d\n", num2);

}

int main()
{
	char line[1024];
	scanf("%[^\n]", line);
	solution(line);
}

