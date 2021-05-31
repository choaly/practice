
#include <string>
#include <iostream>

using namespace std;

//-----My first attempt-----
bool isPermOfPalindrome(string s) {
    int freq[256] = {0};

    for (int i=0; i < s.length(); i++)
    {
        freq[s[i]]++;
    }

    if (s.length() % 2 == 0) //if string length is even
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (freq[c] % 2 == 1) return false; //if a char's freq is odd, return false
        }
        return true;
    }
    else //else if (s.length() % 2 == 1)
    {
        int numCharWithOddFrq = 0;
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (freq[c] % 2 == 1)
            {
                numCharWithOddFrq++;
            }
        }
        
        if (numCharWithOddFrq <= 1) return true;
        return false;
    }
}

//-----Notes/Improvements-----
/*SOLUTION LOGIC: A palindrome is a string that's the same forwards and backwards. This means that there are 2 cases in which
                  a string can be a permutation of a palindrome:
                    - if the string has an even length: the string must have an even number of all chars (so that half
                      the chars are on one side of the string and half are on the other side)
                    - if the string has an odd length: the string must have an odd number of exactly one char, and an even number of all
                      other chars


(FIRST ATTEMPT) IMPLEMENTATION:
            Create a 256-element int array to store character counts.
            Iterate through the string, counting the frequency of each character.
            If string length is even:
                If any of the character frequencies are odd, then return false (string is not a permutation of a palindrome).
                Otherwise, return true.
            Else if string length is odd:
                Count the number of characters with odd frequencies. If there's more than 1 char with an odd frequency, return false.
                Otherwise, return true.


IMPROVEMENT 1: I split my code into two cases (even string length and odd string length), but didn't need to.
               Reasoning:
               An "even" string can't have an odd number of exactly one char, otherwise it wouldn't be an even-length string
               (an odd num + many even nums = an odd num).
               An "odd" string can't have all chars with even counts (sum of evens is even).
               So to cover both the odd and even cases, it's sufficient to say that, to be a permutation of a palindrome, a string can
               have at most one char that is odd.

IMPROVEMENT 2: I forgot to account for casing and non-letter characters in the given string (which can be ignored) smh.
               Also, the array can be size 128 instead of 256.
                    The standard ASCII table (7-bit character code) contains only 128 values. It is the extended ASCII chart that has 256 values.
                    Most of the extended ASCII codes (character code 128-255) aren't present on the QWERTY keyboard. This problem only looks at
                    alphabetic characters, which are included in the standard ASCII characters (0-127).

TIME COMPLEXITY:
O(n), since we iterate through the whole string (length n) and then iterate through 26 chars (a-z), which is a constant num of iterations.

SPACE COMPLEXITY:
O(1). Only need space for a 256-element (or 128-element) array and an integer to hold the odd count.

IMPROVEMENT 3: use a bit vector (come back this later)
*/


//-----Improved Implementation-----
bool isPermOfPalindrome2(const string& s) {
    int freq[256] = {0};
    int odd_count = 0; //originally numCharWithOddFrq

    for (int i=0; i < s.length(); i++)         //for (const char& c : s)
    {                                          
        if ( isalpha(s[i]) )                        //if (isalpha(c))
        {                                               
            freq[ tolower(s[i]) ]++;                    //freq[tolower(c)]++;
        }
        
    }

    for (char c = 'a'; c <= 'z'; c++)
    {
        if (freq[c] % 2 == 1)
        {
            odd_count++;
        }
    }
    
    return odd_count <= 1;
    // if (numCharWithOddFrq <= 1) return true;
    // return false;
}



int main() {
    //testing first attempt implementation
    // string str("tactcoa");
    // cout << "Is the string \"" << str << "\" a permutation of a palindrome? "
    //      << "(1 for true, 0 for false): ";
    // cout << isPermOfPalindrome(str) << endl; //should return true (tacocat!)

    // string str1("chocopie");
    // cout << "Is the string \"" << str1 << "\" a permutation of a palindrome? "
    //      << "(1 for true, 0 for false): ";
    // cout << isPermOfPalindrome(str1) << endl; //should return false

    // string str2("abacbc");
    // cout << "Is the string \"" << str2 << "\" a permutation of a palindrome? "
    //      << "(1 for true, 0 for false): ";
    // cout << isPermOfPalindrome(str2) << endl; //should return true (abccba)



    //testing improved implementation
    string str("tactcoa");
    cout << "Is the string \"" << str << "\" a permutation of a palindrome? "
         << "(1 for true, 0 for false): ";
    cout << isPermOfPalindrome2(str) << endl; //should return true (tacocat!)

    string str1("Chocopie");
    cout << "Is the string \"" << str1 << "\" a permutation of a palindrome? "
         << "(1 for true, 0 for false): ";
    cout << isPermOfPalindrome2(str1) << endl; //should return false

    string str2("A bacbc");
    cout << "Is the string \"" << str2 << "\" a permutation of a palindrome? "
         << "(1 for true, 0 for false): ";
    cout << isPermOfPalindrome2(str2) << endl; //should return true (abccba)


    return 0;
}