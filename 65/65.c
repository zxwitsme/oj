#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	long i, n, dp[128][2];

	memset(dp, 0, sizeof(dp));

	n = atol(line);

	dp[1][0] = 3;
	dp[1][1] = 0;

	for (i = 2; i <= n; i++) {
		dp[i][0] = dp[i-1][0] * 2 + dp[i-1][1] * 2;
		dp[i][1] = dp[i-1][0];
	}

	printf("%ld\n", dp[n][0] + dp[n][1]);

}

int main()
{
	char line[102400];

	scanf("%s", line);
	solution(line);

	return 0;
}

