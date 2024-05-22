package ThuatToanTimKiem;

public class TimKiemNhiPhan {
    public static int timKiemNhiPhan(int a[], int n, int x) {
        int L = 0;
        int R = n - 1;
        int M = (L + R) / 2;
        while (L <= R) {
            if (x > a[M]) {
                L = M + 1;
            } else if (x < a[M]) {
                R = M - 1;
            } else {// x=a[m]
                return M;
            }
            M = (L + R) / 2;
        }
        return -1;
    }
}
