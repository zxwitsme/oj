    private static String solution(String line) {
        String[] s = line.split(",");
        int n = s.length;
        int[] a = new int[n];
        for (int i = 0; i < n; i ++) {
            a[i] = Integer.parseInt(s[i]);
        }
        int[] bit = new int[32];
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < 32; j ++) {
                bit[j] += (1 << j) & a[i];
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i ++) {
            if (bit[i] % 3 != 0) {
                ans |= (1 << i);
            }
        }
        return ans + "";
    }
