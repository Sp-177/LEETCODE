class Solution {
   public static int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == c && c == e) {
            if ((b < d && d < f) || (f < d && d < b)) return 2;
        } else if (b == d && d == f) {
            if ((a < c && c < e) || (e < c && c < a)) return 2;
        }

        boolean x1 = false;
        for (int i = c, j = d; i <= 8 && j <= 8; i++, j++) {
            if (i == e && j == f && !x1) return 1;
            if (i == a && j == b) x1 = true;
        }

        x1 = false;
        for (int i = c, j = d; i >= 0 && j >= 0; i--, j--) {
            if (i == e && j == f && !x1) return 1;
            if (i == a && j == b) x1 = true;
        }

        x1 = false;
        for (int i = c, j = d; i <= 8 && j >= 0; i++, j--) {
            if (i == e && j == f && !x1) return 1;
            if (i == a && j == b) x1 = true;
        }

        x1 = false;
        for (int i = c, j = d; i >= 0 && j <= 8; i--, j++) {
            if (i == e && j == f && !x1) return 1;
            if (i == a && j == b) x1 = true;
        }

        if (a != e && b != f) return 2;

        return 1;
    }
}