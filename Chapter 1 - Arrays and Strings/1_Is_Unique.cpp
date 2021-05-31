/*
PROBLEM:
Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

SOLUTION LOGIC/IMPLEMENTATION:
Make a 256-element char array to store character counts, indexed by character.
If the count goes above 1, the string is not made of unique characters.
*/

#include <string>
#include <iostream>
using namespace std;

bool checkUnique(const string& s) {
    int freq[256] = {0};

    for (const char& c : s)
    {
        freq[c]++;
        if (freq[c] > 1) return false;
    }
    return true;
}

int main() {
    cout << checkUnique("hahaha") << endl;
    cout << checkUnique("abcdef") << endl;
    return 0;
}

//-----Notes/Improvements-----
/*
TIME COMPLEXITY: O(n)
Each character insertion into the array takes O(1) time. Since we iterate over every element of the string, the time
complexity is O(n).
If you add the string length check, you could also argue that the time complexity is O(1), since
the for loop will never iterate through more than 256 characters.

SPACE COMPLEXITY: O(1)
We use 256 bytes for the char array.

IMPROVEMENTS
- Ask if the string is an ASCII string or a Unicode string.
    Here I assumed the character set is ASCII. If Unicode handling was necessary, we'd need to increase the storage size and the algorithm would be much more complex.
    For ASCII, might be ok to assume 128 char instead of 256. Ask for clarification if needed
-  Use a bool array instead of a char array, since we just need to know if we've seen the character before or not.
    The second time you see the same char, you can immediately return false.
- Immediately return false if string is longer than 256 characters (i.e., if string length exceeds the number of unique characters in the alphabet).
- Can reduce space usage by a factor of eight by using a bit vector (come back to this later and implement).
- If we can't use additional data structures, we can compare every char of the string to every other char of the string.
    Time complexity is O(n^2) and space complexity is O(1).
 * /