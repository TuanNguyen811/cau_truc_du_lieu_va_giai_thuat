#include <iostream>
int n, x[100], dem = 0;

using namespace std;

void init(void) {
	cout << "Nhap n=";
	cin >> n;
}
void result(void) {
	cout << "Ket qua buoc " << ++dem << ":";
	for (int i = 1; i <= n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}
void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n) {
			result();
		}
		else
		{
			Try(i + 1);
		}
	}
}
int main() {
	init();
	Try(1);
	return 0;
}