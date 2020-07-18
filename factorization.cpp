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

int factor_using_recursion(int x) {
	if (x == 1){
		return 1;
	}
	else {
		return x * factorUsingRecursion(x - 1);
	}
}

int factor_using_for(int x) {
	int result = 1;

	for ( int i=x; i>0; i-- ) {
		result *= i;	
	}	

	return result;
}

void clear_screen() {
	#ifdef OS_Windows
		system("cls");
	#else
		system("clear");
	#endif
}

void print_result(int x, int result, float diff, string method) {
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

	clear_screen();

	t_start = clock();
	int factorRecursion = factor_using_recursion(x);		
	t_end = clock();
	diff =  t_end - t_start;
	print_result(x, factorRecursion, diff, "recursion");	
	
	t_start = clock();
	int factorFor = factor_using_for(x);		
	t_end = clock();
	diff =  t_end - t_start;
	printResult(x, factorFor, diff, "for");
	
}
