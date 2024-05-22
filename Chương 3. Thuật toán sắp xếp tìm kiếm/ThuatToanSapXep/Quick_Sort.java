package ThuatToanSapXep;

//Thuat toan chia de tri
public class Quick_Sort {
    public static int partition(int a[], int l, int h) {
        int x = a[h];// x la chot
        int i = l - 1;// i lay vi tri nho hon l
        for (int j = 1; j <= h - 1; j++) {
            if (a[j] <= x) {
                i++;
                HamCoBan.swap(a, i, j);
            }
        }
        HamCoBan.swap(a, i + 1, h);
        return (i + 1);
    }

    public static void quick_Sort(int a[], int l, int h) {
        if (l < h) {
            int p = partition(a, l, h);
            quick_Sort(a, l, h - 1);
            quick_Sort(a, p + 1, h);
        }
        System.out.println("Thuat toan quick_Sort");
        ;
    }

}
