package ThuatToanTimKiem;

import java.util.Scanner;
import ThuatToanSapXep.HamCoBan;

public class mmmain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = 0;
        int[] a = null;
        int luachon;
        do {
            System.out.println("1. Nhap mang");
            System.out.println("2. Xuat Mang");
            System.out.println("3. Thuat Toan tim kiem tuyen tinh");
            System.out.println("4. Thuat Toan tim kiem nhi phan");
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
                    int x;
                    System.out.println("gia tri can tim kiem: ");
                    x = scanner.nextInt();
                    int viTri = TimKiemTuyenTinh.timKiemTuyenTinh(a, n, x);

                    System.out.println("vi tri " + viTri);
                    break;
                }
                case 4: {
                    int x;
                    System.out.println("gia tri can tim kiem 2: ");
                    x = scanner.nextInt();
                    int viTri = TimKiemNhiPhan.timKiemNhiPhan(a, n, x);
                    System.out.println("vi tri " + viTri);
                    break;
                }
                default:
                    break;
            }
        } while (luachon != 0);
    }
}
