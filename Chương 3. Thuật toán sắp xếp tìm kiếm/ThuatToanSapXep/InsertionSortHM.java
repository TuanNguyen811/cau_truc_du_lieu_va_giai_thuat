package ThuatToanSapXep;

public class InsertionSortHM {
    public static void insertionSortHM(int[] a, int n) {
        for (int i = 1; i < n; i++) {
            int key = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }
        System.out.println("Sap xep bang insertionSort");
    }

}
