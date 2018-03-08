#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quick_sort(int s[],int l,int r)
{
    if (l < r)
    {
        int i=l,j=r,x=s[l];
        while(i<j)
        {
            while(i<j && s[j]<=x)
                j--;
            if(i<j)
                s[i++]=s[j];

            while(i<j && s[i]>=x)
                i++;
            if(i<j)
                s[j--]=s[i];

        }

        s[i]=x;
        quick_sort(s,l,i-1);
        quick_sort(s,i+1,r);
    }
}

void solution(char *line)
{
	char *line_a, *saveptr;
	int a[1024], b[1024], c;
	int i, j, temp, m, n;
 
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));

	line_a = strtok_r(line, ";", &saveptr);
	m = 0;
	a[m++] = atoi(line_a);
	while (1) {
		line_a = strstr(line_a, ",");
		if (!line_a)
			break;
		line_a++;
		a[m++] = atoi(line_a);
	}

	c = m / 2 + 1;

	line_a = strtok_r(NULL, ";", &saveptr);
	n = 0;
	b[n++] = atoi(line_a);
	while (1) {
		line_a = strstr(line_a, ",");
		if (!line_a)
			break;
		line_a++;
		b[n++] = atoi(line_a);
	}

	quick_sort(a, 0, m-1);
	quick_sort(b, 0, n-1);

	j = m - c;
	b[n] = 0;
	n++;
	for (i = 0; i < n; i++) {
		while (b[i] < a[j]) {
			if (i <= j - (m - c)) {
				printf("0\n");
				return;
			} else
				j++;
		}
	}

	printf("1\n");
}
 
int main()
{
	char line[10240];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
