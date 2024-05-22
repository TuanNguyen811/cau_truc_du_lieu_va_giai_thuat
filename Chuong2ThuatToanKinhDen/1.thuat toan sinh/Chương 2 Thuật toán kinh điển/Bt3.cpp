#include <iostream>
int n, x[100],dem=0;
bool chuaXet[100];
using namespace std;
void init(void) {
	cout << "Nhap n=";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		chuaXet[i] = true;
	}
}
void ketQua(void) {
	cout << "Buoc dem thu: " << ++dem << ": ";
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
				ketQua();
			}
			else
			{
				Try(i + 1);
			}
			chuaXet[j] = true;
		}
		
	}
}
int main() {
	init();
	Try(1);
	return 0;
}

//kệ chứ chả liên quan gì luôn á, chả liên quản, không cần biết, lo cho mình còn chưa xong lo cho thiên hạ, làm gì hả cvo
//kệ chúc chả liên quan gì luân á chả liên uản gì luôn qá, nó lùn hơn mày cả cái đầu luôn á