#include <iostream>
using namespace std;

int n, dem = 0, x[100];
bool Ok = true;
//ham khoi tao mang n chua xau dau tien [0,0,0,0..]
void init(void) {
    cout << "Nhap n=";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }
}
void result(void) {
    cout << "Ket qua buoc " << ++dem << " : ";
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}
void next_Bit_String(void) {
    int i = n;
    while (i > 0 && x[i] != 0) {
        x[i] = 0;
        i--;
    }
    if (i >0) {
        x[i] = 1;
    }
    else {
        Ok = false;
    }
}
int main() {
    init();
    while (Ok) {
        result();
        next_Bit_String();
    }
    system("PAUSE");
    return 0;
}