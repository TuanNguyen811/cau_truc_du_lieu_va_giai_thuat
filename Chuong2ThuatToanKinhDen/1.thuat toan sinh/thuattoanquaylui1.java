import java.util.*;

import javax.naming.spi.DirStateFactory.Result;

public class thuattoanquaylui1 {
    int n, dem = 0;
    int[] A = new int[100];
    boolean[] chuaXet = new boolean[100];
    Scanner scanner = new Scanner(System.in);

    public void init() {
        System.out.println("Nhap n=");
        n = scanner.nextInt();
        for (int i = 1; i <= n; i++) {
            chuaXet[i] = true;
        }
    }

    public void result() {
        System.out.println("Ket Qua" + dem++ + ":");
        for (int i = 1; i <= n; i++) {
            System.out.print(A[i] + "  ");
        }
        System.out.println();
    }

    public void TRYYY(int i) {
        for (int j = 1; j <= n; j++) {
            if (chuaXet[j]) {
                A[i] = j;
                chuaXet[j] = false;
                if (i == n) {
                    result();
                } else {
                    TRYYY(i + 1);
                }
                chuaXet[j] = true;//
            }
        }

    }

    private static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public static void main(String[] args) {
        thuattoanquaylui1 bai1 = new thuattoanquaylui1();
        bai1.init();
        bai1.TRYYY(1);
    }
}