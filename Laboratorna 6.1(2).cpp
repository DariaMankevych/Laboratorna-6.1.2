// Laboratorna 6.1(2).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* a, const int n, const int Low, const int High, int i)
{
		a[i] = Low + rand() % (High - Low + 1);
		if (i < n - 1)
			Create(a, n, Low, High, i + 1);
}
void Print(int* a, const int n, int i)
{
		cout << setw(4) << a[i];
		if (i < n - 1)
			Print(a, n, i + 1);
	else
	cout << endl;
}
int Count(int* a, const int n, int i, int count)
{
		if (abs(a[i]) % 13 != 0 && abs(a[i]) % 2 != 0) 
			count++;
		if (i < n - 1)
			return Count(a, n, i + 1, count);
}
void Zero(int* a, const int n, int i) {
		if (abs(a[i]) % 13 != 0 && (a[i] % 2 != 0))
			a[i] = 0;
		if (i < n - 1)
			return Zero(a, n, i + 1);
}
int Sum(int* a, const int n, int i, int S) {
		if (abs(a[i]) % 13 != 0 && abs(a[i]) % 2 != 0)
			S += a[i];
		if (i < n - 1)
			return Sum(a, n, i + 1, S);
		else
	return S;
}
int main()
{
	srand((unsigned)time(NULL));

	const int n = 21;
	int a[n];

	int Low = 15;
	int High = 85;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);

	cout << "S = " << Sum(a, n, 0 , 0) << endl;
	cout << "Count = " << Count(a, n, 0 ,0 ) << endl;

	Zero(a, n, 0);
	Print(a, n, 0);
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
