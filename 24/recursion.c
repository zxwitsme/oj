#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void combine(int s[], int subset[], int n, int k, int m, int sum, int *hit)
{
	int i, j, sum_subset = 0;
	if (k == 0) {
		for(i = 0; i < m; i++)
			sum_subset += subset[i];
		if (sum_subset == sum/2)
			*hit = 1;
		return;
	}

	for (i = n; i >= k; i--) {
		subset[k-1] = s[i-1];
		combine(s, subset, i-1, k-1, m, sum, hit);
        }
}

void solution(char *line)
{
	int s[512];
	int subset[512];
	int n = 0;
	int i, sum = 0, hit = 0;

	while (1) {
		i = atoi(line);
		s[n++] = i;
		line = strstr(line, ",");
		if (!line)
			break;
		else
			line += 1;
	}

	for (i = 0; i < n; i++)
		sum += s[i];

	if (sum%2 != 0) {
		printf("false\n");
		return;
	}
	
	for (i = 1; i < n; i++) {
		combine(s,subset,n,i,i,sum,&hit);
		if (hit) {
			printf("true\n");
			return;
		}
	}

	printf("false\n");
}

int main()
{
	char line[1024];
	
	scanf("%[^\n]", line);
	solution(line);
}

