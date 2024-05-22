package ThuatToanSapXep;

public class BubbleSortHM {
    public static void bubbleSortHM(int[] a, int n) {
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (a[j] > a[j + 1]) {
                    HamCoBan.swap(a, j, j + 1);
                }
            }
        }
        System.out.println("Sap xep bang bubbleSortHM");
    }
}
