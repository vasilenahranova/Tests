#include<iostream>
using namespace std;

bool checkIfNumberIsNeighbour(int number)
{
	while (number > 10) {
		if ((number % 10) == (number / 10 % 10))
			return false;
		else
			number /= 10;
	}

	return true;
}

int main()
{
	int a,b;
	cout << "a= "; cin >>a;
	cout << "b= "; cin >> b;
	//validation
	while (a < 0 || b < 0) {
		cout << "Invalid values for a or b! Both numbers need to be positive! Try again!" << endl;
		cout << "a= "; cin >> a;
		cout << "b= "; cin >> b;
	}
	//with that check we ensure having a as the begining of the space and b as the end of the space
	if (a == b)
		cout << "This is invalid space of numbers!" << endl;
	if (a > b) {
		a = a + b;
		b = a - b;
		a = a - b;
	}

	int maxNumber = INT_MIN, minNumber = INT_MAX, length=0;
	//find the 'neighbour numbers' in the loop
	for (int i = a; i <= b; i++) {
		if (checkIfNumberIsNeighbour(i)) {
			length++;
			maxNumber = (i > maxNumber) ? i : maxNumber;
			minNumber = (i < minNumber) ? i : minNumber;
		}
	}
	if (length == 0)
		cout << "There is no adgusted numbers!" << endl;
	else
		cout << maxNumber - minNumber << endl;
	return 0;
}