#include <iostream>
int n, x[100], dem = 0;
bool chuaXet[100];

using namespace std;
void init(void) {
	cout << "Nhap n=";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		chuaXet[i] = true;
	}
}
void result(void) {
	cout << "Ket qua buoc " << ++dem << ":";
	for (int i = 1; i <= n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}
void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (chuaXet[j]) {
			x[i] = j;
			chuaXet[j] = false;
			if (i == n) {
				result();
			}
			else {
				Try(i + 1);
			}
			chuaXet[j] = true;
		}
	}
}
int main() {
	init();
	Try(1);
	system("PAUSE");
	return 0;
}