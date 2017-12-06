#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solution(char *line)
{
	char record[1024];
	int conti[1024];
	int max = 0;
	int a, b, size = 1;

	memset(record, 0, 1024); 
	memset(conti, 0, 1024); 
	while (1) {
		a = atoi(line);
		//printf("%d\n", a);
		record[a]++;
		if (a > max)
			max = a;
		line = strstr(line, ",");
		if (line == NULL)
			break;
		else
			line += 1;
	}

	for (a=0; a<max+1;) {
		if ((record[a]==0) || (record[a+1]==0)) {
			//printf("a:%d ignore\n", a);
			a++;
			continue;
		}
		for(b=a;b<max+1;b++) {
			//printf("a:%d b:%d record[b]:%d\n", a, b, record[b]);
			if (record[b]) {
				//printf("conti[a]:%d\n", conti[a]);
				conti[a]++;
				if (conti[a] > size)
					size = conti[a];
			} else
				break;
			//printf("a:%d b:%d conti[a]:%d\n", a, b, conti[a]);
		}
		//printf("size %d conti[a] %d\n", size, conti[a]);
		
		if(b>a+1)
			a = b;
		else
			a++;
	}
	printf("%d\n", size);
}

int main()
{
	char line[1024];
	scanf("%[^\n]", line);
	solution(line);
}

