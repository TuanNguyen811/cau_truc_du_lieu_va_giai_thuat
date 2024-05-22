#include <iostream>
int x[100], n, k,m,dem = 0;
using namespace std;
void init(void) {
	cout << "Nhap n=";
	cin >> n;
	cout << "Nhap k=";
	cin >> k;
	cout << "Nhap m=";
	cin >> m;
	x[0] = 0;
}
void ketQua(void) {
	int sum = 0;
	for (int i = 1; i <= k; i++) {
		sum += x[i];
	}
	if (sum == m) {
		cout << "Ket qua buoc thu: " << ++dem << " : ";
		for (int i = 1; i <= k; i++) {
			cout << x[i] << " ";
		}
	}
	cout << endl;
}
void Try(int i) {
	for (int j = x[i-1]+1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k) {
			ketQua();
		}
		else Try(i + 1);
	}
}
int main() {
	init();
	Try(1);
	return 0;
}