package ThuatToanSapXep;

public class SelectionSortHM {
    public static void selectionSort(int a[], int n) {
        int min_idx;
        for (int i = 0; i < n - 1; i++) {
            min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[min_idx]) {
                    min_idx = j;
                }
            }
            HamCoBan.swap(a, i, min_idx);
        }
        System.out.println("Sap xep bang selectionSort");
    }
}