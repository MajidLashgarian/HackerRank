#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


string&  allToLower(string &);
bool isPangram(string &);


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

        string str ;
        getline(cin , str );
    str = allToLower(str);
        bool result = isPangram(str);
        if(result)
                cout << "pangram"  ;
        else
                cout << "not pangram" ;
    return 0;
} 



string& allToLower(string &str)
{
        for(int i = 0 ; i < str.size() ; i++ )
        {
                char &c = str[i];
                if(c >  'A' && c < 'Z')
                        c = c + 32;
        }
        return str ;
}




bool isPangram(string &str)
{
        vector<bool> alphabet ;
        alphabet.resize(24 , false );

        for(int i = 0 ; i <  str.size() ; i++ )
        {
                int asci = str[i] - 'a';
                if(asci <  0 || asci > 'z')
                        continue ;
                alphabet[asci] = true ;
        }

        for(int i = 0  ; i < alphabet.size() ; i++)
                if(!alphabet[i])
                        return false ;
        return true ;
}
