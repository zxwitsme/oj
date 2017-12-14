#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4096
void solution(char *line)
{
	unsigned short **d;
	char *a, *b;
	char *saveptr;
	int i, j, m, n, new, min;
 
	d = (unsigned short **)calloc(MAX, sizeof(unsigned short*));
	for (i = 0; i < MAX; i++)
		d[i] = (unsigned short *)calloc(MAX, sizeof(unsigned short));

	a = (char*)calloc(MAX, sizeof(char));
	b = (char*)calloc(MAX, sizeof(char));

	saveptr = strstr(line, ",");
	m = saveptr - line;
	strncpy(a, line, m);
	n = strlen(line) - m - 1;
	strncpy(b, saveptr + 1,  n);

	for (i = 0; i <= m; i++)
		d[i][0] = i;
	for (j = 0; j <= n; j++)
		d[0][j] = j;

	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			min = d[i][j-1] + 1;
			new = d[i-1][j] + 1;
			if (new < min)
				min = new;
			if (a[i-1] == b[j-1])
				new = d[i-1][j-1];
			else
				new = d[i-1][j-1] + 1;
			if (new < min)
				min = new;
			d[i][j] = min;
			printf("d[%d][%d] %d\n", i, j, d[i][j]);
		}
	}

	printf("%d\n", d[m][n]);
}
 
int main()
{
	char *line;
	char c;
	int m = 0;
  
	line = malloc(10240*sizeof(char));
#if 1
	strcpy(line, "aabaabbbccabaacbaccacaaacccbcaaacbcaacbcacbacababccbbccbaabcbbbcbbcabcbbacabacaabbbbcbbcbbccccacaccaccabbaccacaaabccacaccacaabbbcbcbaacbbabccbbcaccccbcaabacccccbaacbabbcabcbbbccbccccccbbbbcaccccabbbaaccbccccacaababbbcbcbaabaacbbbbacbccbbacaccccbcbbcbacabbcacaacaacbcaacacbbaabbbaabaaacbcbbbcaaabbcaccbbacbaaabbabbccbaacbaabbacababaaabcaabbcbabcbbbbcbccbaabccccbbbbbacbccbacccaabaabbcbccaababccaaabbaacccaabbbcabbacbababbbbccaccbaabacaacccbabcaaaccaaccacaaacaaaaaabccaccbbbbcbbbbbacbccacccaacbaacbabcbcbcacacacbbcbcbabbaabbcbacaacaaccabcaabbaccbacabcbaabacbbbbbcbacabcabbccabacaabbaccbcccacabbcbbbabaacaaacaabcabccbcaaacccbcbacaacaccbbbaabaacbcaaaaccabaccaaabaababccaabcaccacaacacaaaaababbbabbccaaaabcaaacacaacbacbabcaccaabacbcccbaabcbaacbcbaacbaccabacbbcaccaccbaabacbbbbabbcbbcbcbcbcbbbcbbbcaaaccacaaabcaabcababbcaccaabbacacbbcaacbccaaabbbcaaabcbbbcaaccbccaabcbabcbcbbcbcaccabcbacbcaacacbccabbabbcbbbacaaccabaacabbbbbbbbaacbccacabbcbcaccaccbccccbacbbcabbcacbcabccccacbcaacbbbbbbacacacabbcccbcabbccbaacbaaabccaacbabbbabcaacccabaacbaccabbcacaabcabbbccaccaaabaabbbbbaacaaacbbbacbcababcbaabcbcbabaacbabccaaabbcacaccabaacabbccbacbacbbbbaacabbacbbccbbbcacbccbbabbbababccbabbcbbabccacbacbcabacaaccbcbacbbccbccbabbaaabbbacacbacaababcacacbcabacabcaaccabababccbacacbccccabacbabbaaaaabcccbbbbcabaccaabcbbcbababbcaccbbbabaabcaaaabaccaabcaabbcabbacabbbcccaaabbcbcbbbbcacacacaccbaaccabbbaaacaabacbcababbcbabcbbccaabaccccccccbbbbacbaccaccbbababccbbcaabbacbabaccaaabccaaaabbcaabcabcbccbaabcacacbacacbbababccaabababbabbaaccabbcbacccbcacbcccacacbbccacbabbbaaccabaaaccccbcbcbbacbabbcabaabbccbaaacbcacccccbaaacaaabcbcbbcbccababbbaccacacacbaabbbccabaaabbbcccaccccccabaaacaababbaabccccbcbbbabccaaaccbcabaabcaccacabccbcabcbbcacccbacabcbaaaabbbbabaaaaabbaaabbcaabaccbcbcbabacbbcbcacaaaccbbaccbccbacbcbbcbaaabaacbabcbcbbbcababbaacaacabcabcccbabbabbbbbabaacbaacaccbaaaaccacaaababacbacacbacccbaccbaacaaaccccbcaacbacaabbcbbcacabbabacbabaabaaaaccbbaacacccbcbabcaabcbccaabbcbacbacaacccccbabbbaacbcbbcbaccacacacacccabbaaaacaacbbcaaacbccabbacbbaaaacacccbbbccaabcabbcccccbabcbaacbabbbccabaacaabbcaaaacccbbcbacbbcacbacccacbcabacaacbbac,accacbbabbabbcccbcbaccbaabbabacbabaaaaaaccacbabbababccacccaccabcbaaccacbcacccccacbacaccccbcbaacabcbcacbcabbaaccbbabcccabbcbaccabacaaaaacbbccbbaacbaaababacaacbccaaacacbcbccaabbbbbbbcacaccbaacbbacbbbaaaabbabcacaccbbccaabcbcccccccabcbcbbccabbbcbbccccccababccbacbabaacccbabccbbacbabaccbbbbcaabbcaaabccbcbaaacaababbccccababbbaaacbccacccbaabcccbbaacbbcbabbbcbcbaabbabbcbbbcaccbacbaccbccbaabacbaabccababcbacbcacbacabbaababbbcccaacbcbbcacababaaacaccaaabbcaccaaccbbcacacbcbcaccacccabbbccccaacacacbabcacabcbcaabbacbabaccbccacbbaaacbbaababcbcabaabbabcabbbcacacccaccbcbccbbbbabaaaacaabacbbbbbbaaacccbcbaabcbbabcbcababcaabacacacbbbbaacacaabaccacbaabccbcbbcaaacaccacccbcaacbacbcbaababcbcaccabccbcbcbbaaacccbaaacaccaccbacbabcbcbaccaacaaaabaacbbbbbbaccbccccbacbbcbbccaccacbbcaacccbaccacbabbcabcbbcccbbaaaaacbcacccabcbcbbaccaabbaacbbccbbbaaabaaaaaaacabcbbaaaaaacabaaacccacbaaacbcabacbbaababcccbbbacaaaccbacbabccacabbabaabbcaaaaccaabbaacccbbbbbcbbcbcbabcacccbaabbbcabcaabacccbcbbbccbacababccbabababcabcbaccbaabcbaacccbbcaccacbabbcccbbbaaacabbbaabcaacbcabcccccacbcbacabccbcbcabababccccbcacacababaaaccaaccacaccacbbaacabacacabccabcabcbccbabbbcabcaaaccaaaabcaaacccabacbabcaaacbaabcaaccaaccccabbcccccaabacacbcabcacabbcbbbabaabbbabbacabaaaaaaacbaacccbbbcbbcabcccbbabaaacccabbbacbaabcacaababaabcaacbaccaccaabcccaabcbccabcbbbbcbbaaccccaaabbacbcacabccbccbabbacaabcabbbcbbccabbbabaababacaaaabacccaccbbbbbaabcacbcaaaabbabcaabcbbbbbbaaaaaaaabcbcbbccaacccbbabbbaccccbbabbaccbcbabaacaabacbbaaabccbccccbbaaaccaabcbbaabacaaaccbabacbcbabaaabbbbabacbaaabababbbcccccbbbcabbcbaaaacabcacaabbccaabcacabaabcccaaaccbbaccacabcaaacccabbababbbbcaabbccccbaaacabcccbbaacbbaccaacbbbabbbaaaaaccccbbbcacbbcbabacbcbaaccacbcbbbbbaabbacabbcacbbbcabcaccbcabbccbaaabcccaaccaabbacabcbaccacaaccacbcaaacababcabbabbabaacbbbacccaccbaacbaacacbaaababaccabcacacbabbaacbbbbccbcabbcbaccbbaccaccccbbbcbbaacaacbcaccccabbcaabbccabaaaaabcbbbcbccccbbbccaaccabaaaabbbbacabacaabacccbabaaabccabbaabccbbbcbabccbacacacacabbbabccccbccabccccacabbcbaacaabbbcaccaaacabcaaabccaabcabbacccbabcaaaabbcaaccbcacccaaccaabcacaacccacbbbcccccaccaaaaccbcaccacbcacacccbbbbccccbbacbacbccaacbaa");
#else
	while(1) {
		c = getchar();
		if (c == '\n')
			break;
		line[m++] = c;
	}
	line[m] = '\0';
#endif

	solution(line);
 
	return 0;
}

