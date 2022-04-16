#include <iostream>
using namespace std;
void odd()
{
	int number;
	int sum = 0;
	for (int n = 1; n <= 10; n++)
	{
		cout << "Enter numbers" << endl;
		cin >> number;
	}
		while (number % 2 != 0)
		{
			sum = sum + number;
		}
		cout << "The sum of odd numbers is " << sum << endl;
}
void main()
{
	odd();
}