#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int findmax(int *f, int start, int end)
{
	int sum = 0;
	int max, first = 1;
	int i;

	for (i = start; i <= end; i++) {
		sum += f[i];
		if (first) {
			first = 0;
			max = sum;
		} else if (sum > max)
			max = sum;
		if (sum < 0)
			sum = 0;
	}
	return max;
}

int findmin(int *f, int start, int end)
{
	int sum = 0;
	int min, first = 1;
	int i;

	for (i = start; i <= end; i++) {
		sum += f[i];
		if (first) {
			first = 0;
			min = sum;
		} else if (sum < min)
			min = sum;
		if (sum > 0)
			sum = 0;
	}
	return min;
}

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

void solution(char *line)
{
	char *line_a, *saveptr;
	int max1, min1, max2, min2;
	int result = 0;
	int f[1024];
	int i, m = 0;
 
	memset(f, 0, sizeof(f));
	while (1) { 
		if (m == 0)
			line_a = strtok_r(line, ",", &saveptr);
		else    
			line_a = strtok_r(NULL, ",", &saveptr);
                         
		if (!line_a)
			break;

		f[m++] = atoi(line_a);
	}

	for (i = 0;  i < m - 1; i++) {
		max1 = findmax(f, 0, i);
		min1 = findmin(f, i+1, m - 1);
		max2 = findmax(f, i+1, m - 1);
		min2 = findmin(f, 0, i);
		result = max(max(abs(max2-min2), abs(max1-min1)), result);
	}

	printf("%d\n", result);
}
 
int main()
{
	char line[1024];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
