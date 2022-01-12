#include<iostream>
using namespace std;


int countOfDigits(int number)
{
	int count = 0;
	while (number > 0) {
		count++;
		number /= 10;
	}
	return count;
}
int pow(int basis, int stepen)
{
	int pow = 1;
	while (stepen > 0) {
		pow *= basis;
		stepen--;
	}
	return pow;
}
bool check(int number1, int number2)
{
	number1 /= 10;
	int countOfNumber2=countOfDigits(number2);
	while (number1 > 100) {
		int help = pow(10, countOfNumber2);
		int firstPart = number1 % help;
		if (firstPart == number2)
		{
			return true;
		}
		number1/=10;
	}

	return false;
}
int main()
{
	int N, K;
	cout << "N= "; cin >> N;
	cout << "K= "; cin >> K;

	if (check(N, K))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}