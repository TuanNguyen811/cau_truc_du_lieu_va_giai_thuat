package ThuatToanTimKiem;

import ThuatToanSapXep.HamCoBan;

public class TimKiemTuyenTinh {
    public static int timKiemTuyenTinh(int a[], int n, int x) {
        for (int i = 0; i < n; i++) {
            if (x == a[i]) {
                return i;
            }
        }
        return -1;
    }

}
