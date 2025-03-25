/*
ID: stwiege1
TASK: palsquare
LANG: C++
*/

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

// function declaration
string baseConvert(int number, int base);
bool palindromeCheck(string b);

// prepare files for input and output
ifstream fin ("palsquare.in");
ofstream fout ("palsquare.out");

// declare variables
int base, op[301], opSquare[301];

int main()
{
    // reads input file
    fin >> base;

    // repetition of main block of program, at size specified by problemm description
    for(int j = 1; j < 301; j++)
    {
        cout << j << endl;
        if(palindromeCheck(baseConvert(j * j, base)) == 1)
        {
            // op[j] = baseConvert(j, base);
            // opSquare[j] = baseConvert(pow(j, 2), base);
            fout << baseConvert(j, base) << " " << baseConvert(j * j, base) << endl;
            cout << "pal" << endl;
        }
    }

    // output
}

// base converter program
string baseConvert(int number, int base)
{
    int runningNum, a;
    int powerTotal[32] = {0};
    string g;
    string alph = "ABCDEFGHIJK";
    bool writeZ = 0;
    runningNum = number;
    a = 0;
    while (runningNum > 0 && a < 32)
    {
        powerTotal[a] = runningNum % base;
        // cout << "pa " << powerTotal[a] << endl;
        runningNum /= base;
        a++;
    }
    a = 0;
    for(int j = 10; j >= 0; j--)
    {
        // a += (powerTotal[j] * pow(10, j));
        // cout << powerTotal[j] << "* 10 ^ " << j << endl;
        // cout << "a " << a << endl;
        if((to_string(powerTotal[j]) == "0") && (writeZ == 0))
        {
            writeZ = 0;
            // cout << "p" << endl;
        }
        else if(powerTotal[j] > 9)
        {
            g += alph[powerTotal[j] % 10];
            writeZ = 1;
            // cout << "z" << alph[powerTotal[j] % 10] << endl;
        }
        else
        {
            g += to_string(powerTotal[j]);
            writeZ = 1;
            // cout << "z" << powerTotal[j] << to_string(powerTotal[j]) << endl;
        }
    }
    return g;
}

// checks if the string input is a palindrome
bool palindromeCheck(string b)
{
    bool isPal = 1;
    char check;
    for(int q = 0; q < (b.length() / 2); q++)
    {
        check = b[q];
        // cout << "q = " << q << endl << "check = " << check << endl;
        // cout << "important! " << b[(b.length() - q - 1)] << endl;
        if(b[(b.length() - q - 1)] != check)
        {
            // cout << "0 because " << b[(b.length() - q)] << "!= " << check << endl;
            isPal = 0;
            goto notPal;
        }
    }  
    notPal:
    return isPal;
}
