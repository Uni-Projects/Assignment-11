#include <iostream>
#include <cassert>
#include <string>

using namespace std;

double power (double x, int n)
{
    assert (n >= 0);

    if (n == 0)
        return 1;
    if (n > 0)
        return x*power(x,n-1);
}

double power2 (double x, int n)
{

    assert (n >= 0);

    if (n == 0)
        return 1;
    if ((n % 2) == 0 && (n != 2))
        return power2(power2(x,n/2),2) ;

    return x*power2(x,n-1);
}

bool palindrome1 (string text, int i, int j)
{
    if ((text[i] == text[j]) && ((i==j+1)|| i==j) )
        return true;
    if (text[i] != text[j])
        return false;

    return palindrome1(text, i+1,j-1);
}

bool palindrome2 (string text, int i, int j)
{
    if ((text[i] == text[j]) || (text[i] == (text[j]+32)) || (text[i] == (text[j]-32)))
        {
            if((i==j+1)|| i==j)
             return true;
            else
             return palindrome2(text, i+1,j-1);
        }else return false;
        // A = a - 32 ;
}
bool palindrome3 (string text, int i, int j)
{
    //(' ','.', ',', ':', ';', '\'', '!', '?', '-');
    if (text[i] < 65)
        return palindrome3(text, i+1,j);
    if (text[j] < 65)
        return palindrome3(text, i,j-1);

    if ((text[i] == text[j]) || (text[i] == (text[j]+32)) || (text[i] == (text[j]-32)))
        {
          if((i==j+1)|| i==j)
             return true;
          else
             return palindrome3(text, i+1,j-1);
        }else
           return false;
}


int main()
{
    double a = 4;
    int b = 9;
    double res = 0;
    string c = "Madam, I'm Adam.";

    //res = power(a,b);

    //cout << res  << endl;

    res = power2(a,b);

    cout << res ;
    /*
    if (palindrome1(c,0,c.length()-1))
        cout << "palindrome!"<< endl;
        else cout << "nope!"<< endl;

    if (palindrome2(c,0,c.length()-1))
        cout << "palindrome!"<< endl;
        else cout << "nope!"<< endl;
    if (palindrome3(c,0,c.length()-1))
        cout << "palindrome!"<< endl;
        else cout << "nope!"<< endl;
    */

    return 0;
}
