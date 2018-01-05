#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void solution(char *line)
{
	char *poker[6], *saveptr;
	int f[15], f1[15];
	int i, j;
	int m = 0, num_m = 0, start = 0, hole = 0, hole1 = 0;
	int tonghua = 1, shunzi = 1;
	char first_char;
 
	memset(f, 0, sizeof(f));
	memset(f1, 0, sizeof(f1));
	while (1) { 
		if (m == 0)
			poker[m] = strtok_r(line, ";", &saveptr);
		else    
			poker[m] = strtok_r(NULL, ";", &saveptr);
                         
		if (!poker[m])
			break;
		m++;
	}
	for (i = 0; i < 5; i++) {
		if (poker[i][0] != 'M')
			first_char = poker[i][0];
	}
	for (i = 0; i < 5; i++) {
		if (poker[i][0] != first_char && poker[i][0] != 'M')
			tonghua = 0;
	}


	for (i = 0; i < 5; i++) {
		if (poker[i][0] == 'M')
			num_m++;
		else {
			if(poker[i][1] == 'A') {
				f[14]++;
				f1[1]++;
				continue;
			}
			if (poker[i][1] >= '2' && poker[i][1] <= '9')
				m = poker[i][1] - '0';
			else if(poker[i][1] == '1')
				m = 10;
			else if(poker[i][1] == 'J')
				m = 11;
			else if(poker[i][1] == 'Q')
				m = 12;
			else if(poker[i][1] == 'K')
				m = 13;
			f[m]++;
			f1[m]++;

		}
	
	}

	for (i = 0; i < 15; i++) {
		if (start && i > j + 4)
			break;
		if (f[i] >= 1 && start == 0) {
			start = 1;
			j = i;
		}
		if (start == 1 && f[i] == 0)
			hole++;
	}

	if ((i - 1) < (j + 4))
		hole += j + 4 - (i - 1);

	for (i = 0, start = 0; i < 15; i++) {
		if (start && i > j + 4)
			break;
		if (f1[i] >= 1 && start == 0) {
			start = 1;
			j = i;
		}
		if (start == 1 && f1[i] == 0)
			hole1++;
	}
	if ((i - 1) < (j + 4))
		hole1 += j + 4 - (i - 1);

	if (hole > num_m && hole1 > num_m)
		shunzi = 0;

	if (tonghua&&shunzi)
		printf("Straight Flush\n");
	else if(tonghua)
		printf("Flush\n");
	else if(shunzi)
		printf("Straight\n");
	else
		printf("GG\n");

}
 
int main()
{
	char line[1024];
  
	scanf("%[^\n]", line);
 
	solution(line);
 
	return 0;
}
