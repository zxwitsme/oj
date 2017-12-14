#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4096
void solution(char *line)
{
	unsigned short d[MAX], d1[MAX];
	char *a, *b;
	char *saveptr;
	int i, j, m, n, new, min;
 
	a = (char*)calloc(MAX, sizeof(char));
	b = (char*)calloc(MAX, sizeof(char));

	saveptr = strstr(line, ",");
	m = saveptr - line;
	strncpy(a, line, m);
	n = strlen(line) - m - 1;
	strncpy(b, saveptr + 1,  n);

	for (i = 0; i <= n; i++)
		d1[i] = i;

	for (i = 1; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			if (j == 0) {
				d[0] = i;
				continue;
			}
			min = d[j-1] + 1;
			new = d1[j] + 1;
			if (new < min)
				min = new;
			if (a[i-1] == b[j-1])
				new = d1[j-1];
			else
				new = d1[j-1] + 1;
			if (new < min)
				min = new;
			d[j] = min;
		}
		for (j = 0; j <= n; j++)
			d1[j] = d[j];
	}

	printf("%d\n", d[n]);
}
 
int main()
{
	char *line;
	char c;
	int m = 0;
  
	line = malloc(10240*sizeof(char));
#if 0
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

