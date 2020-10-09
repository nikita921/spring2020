#include <iostream>
#include <string>
using namespace std;

int main()
{
	//first take in all inputs and assign variables
	cout << "Name: ";
	string name;
	getline(cin, name);

	cout << "Taxable income: ";
	double income;
	cin >> income;
	cin.ignore(10000, '\n');

	cout << "Occupation: ";
	string occupation;
	getline(cin, occupation);

	cout << "Number of children: ";
	int children;
	cin >> children;

	//set precision to two numbers after decimal
	cout.setf(ios::fixed);
	cout.precision(2);

	//find tax reduction
	double taxReduction = 0.0;
	if (income < 120000)
		taxReduction = 200.0 * children;

	//find first taxable amount
	double firstTier = 0.0;
	if (income < 50000)		//check if income is less than 50000
		firstTier = income * 0.04;
	else
		firstTier = 2000;

	//find second and third taxable amount
	double secondTier = 0.0;
	double thirdTier = 0.0;
	
		//tax for engineers
	if (occupation == "engineer")
	{
		if (income > 120000)
		{
			secondTier = 3500;
			thirdTier = (income - 120000) * 0.09;
		}
		else if (income > 50000)
			secondTier = (income - 50000) * 0.05;	//isolates amount between 50000 and 120000
	}
		//tax for other occupations
	else
	{
		if (income > 120000)
		{
			secondTier = 4200;
			thirdTier = (income - 120000) * 0.09;
		}
		else if (income > 50000)
			secondTier = (income - 50000) * 0.06;
	}

	//calculate total tax and make sure it is nonnegative
	double tax = firstTier + secondTier + thirdTier;
	double totalTax;
	if (taxReduction > tax)
		totalTax = 0.0;
	else
		totalTax = tax - taxReduction;
	
	//add line with three hyphens
	cout << "---" << endl;

	//check for input errors and give final result
	if (name == "")
		cout << "You must enter a name" << endl;
	else if (income < 0)
		cout << "The taxable income must be nonnegative" << endl;
	else if (occupation == "")
		cout << "You must enter an occupation" << endl;
	else if (children < 0)
		cout << "The number of children must be nonnegative" << endl;
	else
		cout << name << " would pay $" << totalTax << endl;

}