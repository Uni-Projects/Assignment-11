#include <iostream>
#include <cassert>
#include <string>

using namespace std;

// Part 1.2
double power(double x, int n)
{
    // PRE:
    assert(n >= 0);
    // POST: returns the result of a given
    // number x to the power of given  n ( n >= 0 ) .
    if(n == 0)
        return 1;
    else
        return(x * power(x, n - 1));
}

// Part 1.2
double power2 (double x, int n)
{
    // PRE:
    assert (n >= 0);
    //POST: return the result of a given number x to the power of given n ( n >= 0 ).
    // The algorithm has been modified in relation to the previous exercise to reduce recursive function calls.
    // Run-time complexity of the new function is O(N/2).
    if (n == 0)
        return 1;
    if ((n % 2) == 0 && (n != 2))
        return power2(power2(x,n/2),2) ;

    return x*power2(x,n-1);
}

// Part 2.1
bool palindrome1 (string text, int i , int j)
{
    // PRE:
    assert(text.length() > 0);
    // POST: returns true when text is a palindrome, false when it is not.
    if(text[i] == text[j] && (i == j + 1 || i == j))
        return true;
    if(text[i] != text[j])
        return false;
    return palindrome1(text, i + 1, j - 1);
}

// Part 2.2
bool palindrome2(string text, int i, int j)
{
    // PRE:
    assert(text.length() > 0);
    // POST: returns true when text is a palindrome. This version is not case sensitive, i.e. a == A. Returns false if
    // if it is not a palindrome.
    if((text[i] == text[j]) || (text[i] + 32 == text[j]) || (text[i] - 32 == text[j]))
    {
        if((i == j + 1) || (i == j))
            return true;
        return palindrome2(text, i + 1, j - 1);
    }
    else
        return false;
}

// Part 2.3
bool palindrome3 (string text, int i, int j)
{
    //PRE:
    assert(text.length() > 0);
    // POST: Return true when text is a palindrome, additionally to the previous parts spaces
    // and punctuation marks will be omitted.
    // (' ','.', ',', ':', ';', '\'', '!', '?', '-')
    if (text[i] < 65)
        return palindrome3(text, i + 1, j);

    if (text[j] < 65)
        return palindrome3(text, i, j - 1);

    if ((text[i] == text[j]) || (text[i] == (text[j] + 32)) || (text[i] == (text[j] - 32)))
    {
        if((i == j + 1)|| i == j)
            return true;
        else
            return palindrome3(text, i + 1, j - 1);
    }
    else
        return false;
}

// Part 3
bool match_chars(string chars, int i, string source, int j) {
    // PRE:
    assert(chars.length() > 0 && source.length() >= chars.length());
    // POST: returns true if the whole character sequence of chars appears in
    // the given string, in the particular order. There may be different
    // characters in between.
    if(i == chars.length())
        return true;
    if(j == source.length())// && !(i < chars.length())
        return false;
    if(chars[i] == source[j])
        return(match_chars(chars, i + 1, source, j + 1));
    else
        return(match_chars(chars, i, source, j + 1));
}

int main()
{
    int i = 0;
    int j = 4;
    double x = 4;
    int n = 5;
    string source = "otto";
    string chars = "abc";

    /*if(match_chars(chars, i, source, j))
        cout << "true";
    else
        cout<< "false";*/

    return 0;
}