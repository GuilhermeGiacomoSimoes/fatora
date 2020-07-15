#ifdef defined(__WIN32) || defined(WIN32)
	#define OS_Windows
#endif

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int fatora(int x) {
	if (x == 1){
		return 1;
	}
	else {
		return x * fatora(x - 1);
	}
}

int main() {
	int x;

	cout << ": ";
	cin >> x;

	#ifdef OS_Windows
		system("cls");
	#else
		system("clear");
	#endif

	cout << x << "! = " << fatora(x) << endl;
}
