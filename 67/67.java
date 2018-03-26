    public static int[] a;
    public static int n;

    public static void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    public static boolean nextPermutation() {
        int pos1 = -1, pos2 = 0;
        for (int i = 1; i < n; i ++) {
            if (a[i] > a[i - 1]) {
                pos1 = i;
            }
        }
        if (pos1 == -1) {
            return false;
        }
        for (int i = n - 1; i >= pos1 - 1; i --) {
            if (a[i] > a[pos1 - 1]) {
                pos2 = i;
                break;
            }
        }
        swap(a, pos1 - 1, pos2);
        Arrays.sort(a, pos1, n);
        return true;
    }

    public static void appendAns(StringBuffer sb) {
        sb.append(a[0]);
        for (int i = 1; i < n; i ++) {
            sb.append("," + a[i]);
        }
        sb.append(";");
    }

    private static String solution(String line) {
        String[] s = line.split(",");
        n = s.length;
        if (n == 1) {
            return s[0];
        }
        a = new int[n];
        for (int i = 0; i < n; i ++) {
            a[i] = Integer.parseInt(s[i]);
        }
        Arrays.sort(a);
        StringBuffer sb = new StringBuffer("");
        appendAns(sb);
        while (nextPermutation()) {
            appendAns(sb);
        }
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }
