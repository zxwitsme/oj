#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *s, int i, int j)
{
    int tmp;
    tmp= s[i];
    s[i] = s[j];
    s[j] = tmp;
}

void permutation(int s[], int n, int e, int q, int lr[][2], int *max)
{
	int i, j, r;
	if (n > e) {
		//for (i = 0; i < n; i++)
		//	printf("%d ", s[i]);
		//printf("\n");
		r = 0;
		for (i = 0; i < q; i++)
			for (j = lr[i][0] - 1; j < lr[i][1]; j++)
				r += s[j];
		if (r > *max)
			*max = r;
		return;
	}

	for (i = n; i <= e; i++) {
		//printf("swap i %d n %d\n", i, n);
		swap(s, n, i); 
		permutation(s, n+1, e, q, lr, max);
		//printf("#swap i %d n %d\n", i, n);
		swap(s, n, i); 
	}
}

void solution(char *line)
{
        char *line_a, *line_lr, *saveptr;
	int s[32], lr[512][2];
        int i, j, tmp, max = 0;
        int q = 0, m = 0, n = 0;

        memset(s, 0, sizeof(s));
        memset(lr, 0, sizeof(lr));

        n = atoi(strtok_r(line, ";", &saveptr));
	printf("n %d\n", n);
	q = atoi(strtok_r(NULL, ";", &saveptr));
	printf("q %d\n", q);
        line_a = strtok_r(NULL, ";", &saveptr);
        while (1) {
                i = atoi(line_a);
		printf("s[%d] %d\n", n, i);
                s[m++] = i;
                line_a = strstr(line_a, " ");
                if (!line_a)
                        break;
                else
                        line_a += 1;
        }
	for (i = 0; i < q; i++) {
		line_lr = strtok_r(NULL, ";", &saveptr);
		m = 0;
		while (1) {
			j = atoi(line_lr);
			printf("lr[%d][%d] %d\n", i, n, j);
			lr[i][m++] = j;
			line_lr = strstr(line_lr, " ");
			if (!line_lr)
				break;
			else
				line_lr += 1;
		}
	}

	permutation(s, 0, n - 1, q, lr, &max);

	printf("%d\n", max);
}

void combination(int s[], int subset[], int n, int k, int m)
{
	int i;
	if (k == 0) {
		for(i = 0; i < m; i++)
			printf("%d ", subset[i]);
		printf("\n");
		return;
	}

	for (i = n; i >= k; i--) {
		subset[k-1] = s[i-1];
		printf("set s[%d] to subset[%d] %d\n", i-1, k-1, s[i-1]);
		combination(s, subset, i-1, k-1, m);
        }
}

int main()
{
	char line[1024];

	scanf("%[^\n]", line);

	solution(line);

}

