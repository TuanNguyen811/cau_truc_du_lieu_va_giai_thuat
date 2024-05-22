package ThuatToanSapXep;

// thi thuat toan nay su dung phuong phap chia de quy de tri
public class Merge_Sort {

    public static void merge(int a[], int l, int m, int r) {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;
        int[] L = new int[n1];
        int[] R = new int[n2];
        // chung ta tao ra 2 mamg co kich thuoc lua trai va lua phai cua mang chinh
        for (i = 0; i < n1; i++) {
            L[i] = a[l + i];
        }
        for (j = 0; j < n2; j++) {
            R[j] = a[m + 1 + j];
        }
        // chuyen gia tri vao 2 mang theo thu tu mang a

        i = 0;
        j = 0;
        k = l; // Sửa đổi kết quả của biến k
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                a[k] = L[i];
                i++;
            } else {
                a[k] = R[j];
                j++;
            }
            k++;
        }
        // tu mang R va L truyen nguoc lai mang A theo thu tu nho vao truoc lon vao sau
        while (i < n1) {
            a[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            a[k] = R[j];
            j++;
            k++;
        }
        // con lai thi truyen vao thoi
    }

    public static void merge_Sort(int a[], int l, int r) {
        if (l < r) {
            int m = (l + r) / 2; // Sửa đổi cách tính m
            merge_Sort(a, l, m);
            merge_Sort(a, m + 1, r);
            merge(a, l, m, r);
        }
    }

    public static void main(String[] args) {
        int[] a = { 38, 27, 43, 3, 9, 82, 10 };
        merge_Sort(a, 0, 6); // Đã sửa đổi giá trị của r
        HamCoBan.xuatMang(a);
    }
}
