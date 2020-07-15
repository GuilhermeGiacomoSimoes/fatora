#ifdef defined(__WIN32) || defined(WIN32)
	#define OS_Windows
#endif

#include<time.h>
#include<string>
#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int factorUsingRecursion(int x) {
	if (x == 1){
		return 1;
	}
	else {
		return x * factorUsingRecursion(x - 1);
	}
}

int factorUsingFor(int x) {
	int result = 1;

	for ( int i=x; i>0; i-- ) {
		result *= i;	
	}	

	return result;
}

void clearScreen() {
	#ifdef OS_Windows
		system("cls");
	#else
		system("clear");
	#endif
}

void printResult(int x, int result, float diff, string method) {
	cout << method << endl;
	cout << x << "! = " << result << endl;
	cout << "runtime: " << diff << " milliseconds" << endl;
	cout << endl;
}

int main() {
	int x;

	cout << ": ";
	cin >> x;

	float diff;
	clock_t t_start, t_end;

	clearScreen();

	t_start = clock();
	int factorRecursion = factorUsingRecursion(x);		
	t_end = clock();
	diff =  t_end - t_start;
	printResult(x, factorRecursion, diff, "recursion");	
	
	t_start = clock();
	int factorFor = factorUsingFor(x);		
	t_end = clock();
	diff =  t_end - t_start;
	printResult(x, factorFor, diff, "for");
	
}
