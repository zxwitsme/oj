#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution (char *line)
{
	char a[512], b[512], *c;
	int s = 0;
	int i, m = 0, n = 0, m1, hit;
	int z = 0;

	for (i = 0; i < 512; i++) {
		if (line[i] == '-') {
			hit = i;
			printf("hit:%d\n",hit);
			s = 1;
		}
		else if (line[i] >= '0' && line[i] <= '9') {
			if (!s)
				a[m++] = line[i];
			else
				b[n++] = line[i];
		} else if (line[i] != ' ')
			break;
	}
	m--;
	n--;

	m1 = m;
	printf("m1:%d\n", m1);

	for (; m >= 0; n--, m--) {
		if (n >= 0) {
			a[m] = a[m] - b[n] + '0';
		}
	//	else
	//		a[m] = a[m];
		if (a[m] < '0')	{
			a[m] = a[m] + 10;
			a[m - 1]--;
		}
	}
	while (a[z] == '0')
		z++;
	c=a+z;
	*(c+m1+1) = '\0';
	printf("%s\n", c);

	//for (i = z; i <= m1; i++)
	//	printf ("%c", a[i]);
}

int
main ()
{
  char line[1024];
  scanf ("%[^\n]", line);
  solution (line);
}
