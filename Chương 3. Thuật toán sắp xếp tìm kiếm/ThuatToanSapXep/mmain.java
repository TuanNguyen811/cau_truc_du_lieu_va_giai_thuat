package ThuatToanSapXep;

import java.util.*;

public class mmain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = 0;
        int[] a = null;
        int luachon;
        do {
            System.out.println("1. Nhap mang");
            System.out.println("2. Xuat Mang");
            System.out.println("3. Thuat Toan SelectionSort");
            System.out.println("4. Thuat Toan insertionSortHM");
            System.out.println("5. Thuat Toan bubbleSortHM ");
            System.out.println("6. Thuat Toan NC ");
            System.out.println("7. Thuat Toan ");
            System.out.println("8. Thuat Toan ");

            System.out.println("0. Thoat");
            luachon = scanner.nextInt();
            switch (luachon) {
                case 1: {
                    a = HamCoBan.nhapMang();
                    n = a.length;
                    break;
                }
                case 2: {
                    HamCoBan.xuatMang(a);
                    break;
                }
                case 3: {
                    if (a != null) {
                        SelectionSortHM.selectionSort(a, n);
                        System.out.println("Mang da duoc sap xep!");
                    } else {
                        System.out.println("mang rong");
                    }
                    break;
                }
                case 4: {
                    if (a != null) {
                        InsertionSortHM.insertionSortHM(a, n);
                        System.out.println("Mang da duoc sap xep!");
                    } else {
                        System.out.println("mang rong");
                    }
                    break;
                }
                case 5: {
                    if (a != null) {
                        BubbleSortHM.bubbleSortHM(a, n);
                        System.out.println("Mang da duoc sap xep!");
                    } else {
                        System.out.println("mang rong");
                    }
                    break;
                }
                case 6: {
                    if (a != null) {
                        Quick_Sort.quick_Sort(a, 0, n);
                        System.out.println("Mang da duoc sap xep!");
                    } else {
                        System.out.println("mang rong");
                    }
                    break;
                }
                default:
                    break;
            }
        } while (luachon != 0);
    }
}
