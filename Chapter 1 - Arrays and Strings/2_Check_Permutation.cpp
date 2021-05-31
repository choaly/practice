
/*
PROBLEM:
Given two strings, write a method to decide if one is a permutation of the other.

SOLUTION LOGIC: A string is a permutation of another if both strings have the same character frequencies.
*/

//-----My attempt-----
#include <string>
#include <iostream>
using namespace std;

bool isPermutation(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) return false;

    int freq[256] = {0};

    for (char c : s1)
    {
        freq[c]++;
    }

    for (char c : s2)
    {
        freq[c]--;
        if (freq[c] < 0) return false;
    }

    return true;
}


//-----Notes/Improvements-----
/*
IMPLEMENTATION:
Check if the two strings are equal length. This will improve average-case time complexity.
Create a 256-element int array to store character frequencies.
Iterate through string 1, incrementing the frequency of each character.
Iterate through string 2, decrementing the frequency of each character.
Terminate early and return false if a frequency ever turns negative (that means s2 has a higher frequency of some char than s1).
If we don't terminate early, then the array must be all zeroes. This is b/c the strings are the same lengths and we incremented
the same number of times we decremented. The array can't have any positive values if it doesn't have any negative values.
So return true

WHY YOU CAN USE CHARS FOR ARRAY INDICES (eg freq[c]):
The char data type is an integral type, meaning the underlying value is stored as an integer. The integer stored by a char variable
is interpreted as an ASCII character. eg. char myVariable = 'a' really stores the ASCII value of 'a' (97).
However, the ostream operators are overloaded to deal with char; instead of displaying 97 in
    cout << myVariable;
they display the ASCII representation of the char, i.e., 'a'.

NOTES:
- Should have asked if the permutation comparison is case sensitive (e.g., is God a permutation of dog?) and if whitespace
  is significant. Book assumes that the comparison is case sensitive and whitespace is significant
  (so, "God    " is different from "dog").
- For the freq array, making the size 128 would have been assuming that the character set was ASCII.
  Always ask about the size of the character set (should be 256 if strings could include characters in the extended ASCII table).

TIME COMPLEXITY:
O(n), since we iterate through the strings (length n)

SPACE COMPLEXITY:
O(1). Only need space for a 256-element (or 128-element) array
*/


int main() {
	cout << isPermutation("hello", "ohell") << endl; // true
	cout << isPermutation("red", "blue") << endl; //false
	cout << isPermutation("@ppl3", "pp3l@") << endl; //true
	return 0;
}

//g++ -std=c++11 2_Check_Permutation.cpp -o 2_Check_Permutation
