#include <iostream>
#include <string>
#include <cassert>
using namespace std;


// Return true if the argument is a two-uppercase-letter state code, or
// false otherwise.

bool isValidUppercaseStateCode(string stateCode)
{
	const string codes =
		"AL.AK.AZ.AR.CA.CO.CT.DE.DC.FL.GA.GU.HI.ID.IL.IN.IA.KS."
		"KY.LA.ME.MD.MA.MI.MN.MS.MO.MP.MT.NE.NV.NH.NJ.NM.NY.NC."
		"ND.OH.OK.OR.PA.PR.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
	return (stateCode.size() == 2 &&
		stateCode.find('.') == string::npos &&  // no '.' in stateCode
		codes.find(stateCode) != string::npos);  // match found
}

bool hasValidSyntax(string orders)
{
	string stateCode = "";
	int counter = 0;

	bool status = false;
	bool test = false;

	if (orders == "")
		return true;

	while (counter < orders.size())
	{
		//separate state code
		while (counter < orders.size() && !isdigit(orders.at(counter)))
		{
			orders.at(counter) = toupper(orders.at(counter));
			stateCode += orders.at(counter);
			counter++;
		}

		//check state code and following char
		if (isValidUppercaseStateCode(stateCode) && isdigit(orders.at(counter)))
		{
			status = true;
			counter++;
		}
		else
			return false;
		
		//find position of char after all numbers
		while (counter < orders.size() && isdigit(orders.at(counter)))
			counter++;

		//check for + or - at said position
		if (counter < orders.size() && ((orders.at(counter) == '+') || (orders.at(counter) == '-')))
			test = true;
		else
			return false;

		//reset stateCode and repeat
		stateCode = "";
		counter++;
	}

	if (test == true && status == true)
		return true;

	return false;
}

int countCases(string orders, char status, int& caseCount)
{
	//check if it is a valid order string
	if (!hasValidSyntax(orders))
		return 1;

	//check if the status is valid
	if ((status != '+') && (status != '-'))
		return 3;

	//check if it is an empty string
	if (orders == "")
		caseCount = 0;

	int posCounter = 0;
	int numCounter = 0;
	string number = "";
	
	//run through orders
	while (posCounter < orders.size())
	{
		//pass the state code
		while (posCounter < orders.size() && !isdigit(orders.at(posCounter)))
			posCounter++;

		//adds case numbers to string
		while (posCounter < orders.size() && isdigit(orders.at(posCounter)))
		{
			number += orders.at(posCounter);
			posCounter++;
		}

		//convert string to number
		int myint = stoi(number);
		
		//checks if case number is 0
		if (myint == 0)
			return 2;

		//adds cases if status matches
		if (orders.at(posCounter) == status)
		{
			numCounter += myint;
		}

		//moves on to next state order and resets string of case numbers
		posCounter++;
		number = "";
	}
	
	//set caseCount to total number of cases
	caseCount = numCounter;

	return 0;
}

int main()
{
	assert(hasValidSyntax("TX38-CA132+"));
	assert(!hasValidSyntax("MX38-CA132+"));
	int cases;
	cases = -999;    // so we can detect whether countCases sets cases
	assert(countCases("TX38-CA132+Ms6-nY290-UT006+MS8+CA15+", '+', cases) == 0 && cases == 161);
	cases = -999;    // so we can detect whether countCases leaves cases unchanged
	assert(countCases("TX38-CA132+", '%', cases) == 3 && cases == -999);
		cout << "All tests succeeded" << endl;

		cout << hasValidSyntax("CA009+");
	
}