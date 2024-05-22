#include <iostream>
int n,k, x[100], dem = 0;
using namespace std;

void init(void) {
	cout << "Nhap n=";
	cin >> n;
	 cout << "Nhap k=";
	cin >> k;
	x[0] = 0;
}
void result(void) {
	cout << "Ket qua buoc thu " << ++dem << ":";
	for (int i = 1; i <= k; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}
void Tryyy(int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k) {
			result();
		}
		else
		{
			Tryyy(i + 1);
		}
	}
}
int main() {
	init();
	Tryyy(1);
	return 0;
}