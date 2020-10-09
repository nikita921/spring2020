#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int scoreTypo(const string dictionary[], int n, string word)
{
    int counter = 0;
    int prevcounter = word.size();
    int index = 0;
    int check = 0;

    //check if n is not positive
    if (!(n > 0))
        return -1;
    //run through array
    for (int i = 0; i < n; i++)
    {
        index = 0;
        counter = 0;
        check = 0;
            
        //run through characters of word
        for (int j = 0; j < word.size(); j++)
        {
            //check for differences in words
            if (index < dictionary[i].size())
                if (dictionary[i].at(index) != word.at(j))
                {
                    counter++;
                    //check if letters are switched
                    if (j != word.size() - 1 && index != dictionary[i].size() - 1 && word.at(j) == dictionary[i].at(index + 1) && dictionary[i].at(index) == word.at(j + 1))
                    {
                        counter--;
                        check++;
                    }
                    //check if there is an extra letter
                    else if (j != word.size() - 1 && dictionary[i].at(index) == word.at(j + 1))
                        index--;
                    //check if one letter is removed
                    else if (index != dictionary[i].size() - 1 && dictionary[i].at(index + 1) == word.at(j))
                        j--;                       
                }
            index++;
        }

        if (check > 0 && counter == 1 && (word.size() - dictionary[i].size()) == 1)
            counter = 2;
        else if ((word.size() > dictionary[i].size()) && (word.size() - dictionary[i].size()) > 1)
            counter = 2;
        else if ((dictionary[i].size() > word.size()) && (dictionary[i].size() - word.size()) > 1)
            counter = 2;

        

        //return if there is an exact match and account for last letter
        if (counter == 0)
        {
            if (word.size() == dictionary[i].size())
                return 0;
            else
                counter = 1;
        }

        //find smallest number of typos
        if (counter < prevcounter)
            prevcounter = counter;
    }

    //one typo
    if (prevcounter == 1)
        return prevcounter;
    //more than one
    return 2;
}

int main()
{
    // Here are some tests.  You may add more if you wish.
    string dict1[6] = { "february", "pointer", "country", "forty", "conversation", "minuscule" };
    assert(scoreTypo(dict1, 0, "forty") == -1);
    assert(scoreTypo(dict1, 6, "forty") == 0);
    assert(scoreTypo(dict1, 6, "fourty") == 1);
    assert(scoreTypo(dict1, 6, "febuary") == 1);
    assert(scoreTypo(dict1, 6, "miniscule") == 1);
    assert(scoreTypo(dict1, 6, "poitnerr") == 2);
    assert(scoreTypo(dict1, 6, "conservation") == 2);
    assert(scoreTypo(dict1, 6, "cuontry") == 1);
    cout << "All tests succeeded" << endl;

}