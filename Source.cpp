#include <iostream>
using namespace std;

void lRoundShiftMas(int* source, int n, const int size)
{
	int buf = 0;
	for (int j = 0; j < n; j++)
	{
		buf = source[0];
		for (int i = 0; i < size; i++) 
		{
			if (size == i + 1) 
			{
				break;
			}
			source[i] = source[i + 1];
		}
		if (j + 1 > n) break;
		source[size - 1] = buf;
	}
	/*for (int i = 0; i < size; i++)
	{
		cout << source[i];
	}*/
}
bool CompareMas(int* a, int* b, int size)
{
	for (int i = 0; i < size; i++)
		if (a[i] != b[i]) return false;

	return true;
}
bool test(int* first1, int* first2)
{
	lRoundShiftMas(first1, 3, 5);
	return CompareMas(first1, first2, 5);
}
int main() 
{
	const int size = 5;
	int first1[size] = { 1, 2, 3, 4, 5 };
	int first2[size] = { 4, 5, 1, 2, 3 };
	int second1[size] = { 5, -4, 3, -2, 1 };
	int second2[size] = { 1, 5, -4, 3, -2 };
	int source[size] = { 1,2,3,4,5 };
	if (test(first1, first2)) cout << "Test ok";
	else cout << "Test not ok";
	if (test(second1, second2)) cout << "Test ok";
	else cout << "Test not ok";
}