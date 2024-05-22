#include <iostream>
using namespace std;
int n, k, x[100],dem=0;
bool ok = true;
void init(void) {
	cout << "Nhap n="; 
	cin >> n;
	cout << "Nhap k=";
	cin >> k;
	for (int i = 1; i <= k; i++) {
		x[i] = i;
	}
}
void result(void) {
	cout << "Ket qua buoc " << ++dem << ":";
	for (int i = 1; i <= k; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}
void next_conbination(void) {
	int i = k;
	while (i>0&&x[i]==n-k+i)
	{
		i--;
	}
	if (i > 0) {
		x[i] = x[i] + 1;
		for (int j = i + 1; j <= k; j++) {
			x[j] = x[i] + j - i;
		}
	}
	else ok = false;
}
int main() {
	init();
	while (ok)
	{
		result();
		next_conbination();
	}
	system("PAUSE");
	return 0;
}