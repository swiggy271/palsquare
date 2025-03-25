/*
ID: stwiege1
TASK: palsquare
LANG: C++
*/

// NAME                    : Shuler Wiegerink
// GROUP                   : Hexadecimal
// LAST MODIFIED           : 25 March 2025
// PROBLEM ID              : USACO Milk
// PROBLEM DESCRIPTION     : Reads in a number containing a base, and outputs
//                           every number which the square of that number is            
//                           palindromic in the supplied base
// SOURCES I USED          : USACO website
// PEOPLE I HELPED         : 
// PEOPLE WHO HELPED ME    : Mr. Houtrouw

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
int base;

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
            fout << baseConvert(j, base) << " " << baseConvert(j * j, base) << endl;
        }
    }
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

    // calculates each number to save
    while (runningNum > 0 && a < 32)
    {
        powerTotal[a] = runningNum % base;
        runningNum /= base;
        a++;
    }
    a = 0;
    // formats powertotal array correctly, and translates double digit numbers to letters
    for(int j = 18; j >= 0; j--)
    {
        if((to_string(powerTotal[j]) == "0") && (writeZ == 0))
        {
            writeZ = 0;
        }
        else if(powerTotal[j] > 9)
        {
            g += alph[powerTotal[j] % 10];
            writeZ = 1;
        }
        else
        {
            g += to_string(powerTotal[j]);
            writeZ = 1;
        }
    }
    return g;
}

// checks if the string input is a palindrome
bool palindromeCheck(string b)
{
    bool isPal = 1;
    char check;

    // goes through the first half of the characters, and if the character
    // at the corresponding opposite end is the same, continue
    for(int q = 0; q < (b.length() / 2); q++)
    {
        check = b[q];
        if(b[(b.length() - q - 1)] != check)
        {
            isPal = 0;
            goto notPal;
        }
    }  
    notPal:
    return isPal;
}
