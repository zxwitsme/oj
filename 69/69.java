    public static String solution(String line) {
        String[] s = line.split(";");
        String[] s1 = s[0].split(",");
        String[] s2 = s[1].split(",");
        int n = s1.length;
        int m = s2.length;
        int[] a = new int[n];
        int[] b = new int[m];
        for (int i = 0; i < n; i ++) {
            a[i] = Integer.parseInt(s1[i]);
        }
        for (int i = 0; i < m; i ++) {
            b[i] = Integer.parseInt(s2[i]);
        }
        Arrays.sort(a);
        Arrays.sort(b);

        int i = 0, j = 0, cnt = 0;
        while (i < n && j < m) {
            while (j < m && b[j] < a[i]) {
                j ++;
            }
            if (j < m && b[j] >= a[i]) {
                cnt ++;
            }
            i ++;
            j ++;
        }
        if (cnt > n / 2) {
            return "1";
        }
        return "0";
    }
