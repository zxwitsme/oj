#include <stdio.h>
#include <stdlib.h>

void combine(int s[], int subset[], int n, int k, int m, int sum, int *hit)
{
	int i, j, sum_subset = 0;
	if (k == 0) {
		for(i = 0; i < m; i++) {
			//printf("subset[%d]: %d\n", i, subset[i]);
			sum_subset += subset[i];
		}
		//printf("sub_subset:%d\n", m);
		if (sum_subset == sum/2) {
			printf("###hit\n");
			for(i = 0; i < m; i++)
				printf("subset[%d]: %d\n", i, subset[i]);
			*hit = 1;
		}
		return;
	}

	for (i = n; i >= k; i--) {
		subset[k-1] = s[i-1];
		combine(s, subset, i-1, k-1, m, sum, hit);
        }
}

int main()
{
	//int s[] = {1,6,8,3,5,9};
	int s[] = {10,5,8,6,20,13,7,11};
	int subset[1024];
	int i, sum = 0, hit = 0;
	for (i = 0; i < sizeof(s)/sizeof(int); i++)
		sum += s[i];

	if (sum%2 != 0) {
		printf("false\n");
		return;
	}
	
	for (i = 1; i < sizeof(s)/sizeof(int); i++) {
	//for (i = 2; i <= 2; i++) {
		combine(s,subset,sizeof(s)/sizeof(int),i,i,sum,&hit);
		if (hit) {
			printf("true\n");
			return;
		}
	}

	printf("false\n");
}

