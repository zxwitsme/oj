    private static String solution(String line) {
        int n = Integer.parseInt(line);
        int ans = 1, p = 1, i = 2, bef;
        int[] a = new int[n + 5];
        a[p] = 1;
        while (i <= n) {
            bef = a[i - 1];
            if (a[p] == 1) {
                if (bef == 1) {
                    a[i ++] = 2;
                } else {
                    a[i ++] = 1;
                    ans ++;
                }
            } else if (a[p] == 2) {
                if (bef == 1) {
                    a[i ++] = 1;
                    ans ++;
                    a[i ++] = 2;
                } else {
                    a[i ++] = 2;
                    if (i > n) {
                        break;
                    }
                    a[i ++] = 1;
                    ans ++;
                }
            }
            p ++;
        }
//        for (int j = 1; j <= n; j ++) {
//            System.out.print(a[j]);
//        }
//        System.out.println();
        return ans + "";
    }
