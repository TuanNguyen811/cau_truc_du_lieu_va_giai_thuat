package ThuatToanSapXep;

import java.util.*;

public class HamCoBan {
    public static Scanner scanner = new Scanner(System.in);

    public static void swap(int[] a, int x, int y) {
        int temp = a[x];
        a[x] = a[y];
        a[y] = temp;
    }

    public static int[] nhapMang() {
        System.out.print("Nhap so luon mang: ");
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("[" + i + "]= ");
            a[i] = scanner.nextInt();
        }
        System.out.println("Nhap mang thanh cong!");
        return a;
    }

    public static void xuatMang(int a[]) {
        for (int i : a) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}