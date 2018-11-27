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

double power_v2 (double x, int n)
{
    assert (n >= 0);

    if (n == 0)
        return 1;
    if ((n % 2) == 0)
        return power_v2(power_v2(x,n/2),2);
        else if (n > 0)
            return x*power_v2(x,n-1);
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

}
 // A = a - 32 ;
int main()
{
    double a = 4;
    int b = 24;
    double res = 0;
    string c = "otoiotO";

    //res = power(a,b);

    //cout << res  << endl;

    //res = power_v2(a,b);

    //cout << res ;

    if (palindrome1(c,0,c.length()-1))
        cout << "palindrome!"<<endl;
        else cout << "nope!"<<endl;

    if (palindrome2(c,0,c.length()-1))
        cout << "palindrome!"<<endl;
        else cout << "nope!"<<endl;


    return 0;
}
