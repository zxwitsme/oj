#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int min(int a, int b)
{
	if(a > b)
		return b;
	else
		return a;
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
	int sum = 0;
	int f[1024], dp[1024];
	int i, m = 0;
 
	memset(f, 0, sizeof(f));
	memset(dp, 0, sizeof(dp));
	while (1) { 
		if (m == 0)
			line_a = strtok_r(line, ",", &saveptr);
		else    
			line_a = strtok_r(NULL, ",", &saveptr);
                         
		if (!line_a)
			break;

		f[m++] = atoi(line_a);
	}

	if (m == 1 || m == 2) {
		printf("true\n");
		return;
	}

	for (i = 0; i < m; i++)
		sum += f[i];

	dp[m] = 0;
	dp[m-1] = f[m-1];
	dp[m-2] = f[m-1] + f[m-2];
	dp[m-3] = f[m-2] + f[m-3];

	for (i = m - 4; i >= 0; i--) {
		dp[i] = f[i] + min(dp[i+2], dp[i+3]);
		dp[i] = max(dp[i], f[i] + f[i+1] + min(dp[i+3], dp[i+4]));
	}

	if (dp[0] > sum - dp[0])
		printf("true\n");
	else
		printf("false\n");
}
 
int main()
{
	char line[1024];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
