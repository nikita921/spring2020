#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int firstDifference(const string a1[], int n1, const string a2[], int n2)
{
    int limit = 0;

    //check negatives and zeros

    if (n1 < 0)
        n1 = 0;

    if (n2 < 0)
        n2 = 0;

    if (n1 < n2)
        limit = n1;
    else
        limit = n2;

    //find first difference

    for (int i = 0; i < limit; i++) 
    {
        if (a1[i] != a2[i])
            return i;
    }

    return limit; 
}

bool isContainedIn(const string a1[], int n1, const string a2[], int n2)
{
    int k = 0;

    //check negatives and zeros

    if (n1 < 0)
        n1 = 0;

    if (n2 < 0)
        n2 = 0;

    if (n1 == 0)
        return true;

    if (n1 > n2)
        return false;

    //check contained elements
    for (int i = 0; i < n2; i++)
    {
        if ((k < n1) && (a1[k] == a2[i]))
            k++;    
    }

    //check if all elements were contained in the right order
    if (k  == n1)
        return true;

    return false;
}

int main()
{
    // Here are some tests that demonstrate what these functions do.  You may add
    // more if you wish.
    string colors[6] = { "pink", "blue", "white", "red", "black", "blue" };
    string hues[5] = { "pink", "blue", "white", "black", "green" };
    string tint[5] = { "yellow", "blue", "white", "black", "green" };
    assert(firstDifference(colors, 6, hues, 5) == 3);
    assert(firstDifference(colors, 4, hues, 5) == 3);
    assert(firstDifference(colors, 2, hues, 5) == 2);  // equal up to where a1 runs out
    assert(firstDifference(colors, 2, hues, 2) == 2);  // equal up to where both run out
    assert(firstDifference(colors, 5, hues, 1) == 1);  // equal up to where a2 runs out
    assert(firstDifference(colors, 5, hues, 0) == 0);  // equal up to where a2 runs out
    assert(firstDifference(colors, 5, tint, 0) == 0);  // equal up to where a2 runs out

    string little1[4] = { "blue", "white", "black", "blue" };
    assert(isContainedIn(little1, 4, colors, 6));
    string little2[2] = { "red", "white" };
    assert(!isContainedIn(little2, 2, colors, 6));
    string little3[3] = { "blue", "blue", "red" };
    assert(!isContainedIn(little3, 3, colors, 6));
    assert(isContainedIn(hues, 3, colors, 3));
    assert(!isContainedIn(hues, 3, colors, 2));
    assert(isContainedIn(hues, 0, tint, 5));
    assert(isContainedIn(hues, 0, tint, 0));
    cout << "All tests succeeded" << endl;

}