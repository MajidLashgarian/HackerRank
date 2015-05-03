#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int h = 0,
        v = 0,
        k = 0, 
        T;
    cin >> T ;
    
    while(T--)
    {
        cin >> k ;
        h = ceil(k/2.0f) ;  
        v = floor(k/2.0f) ; 
        cout << h*v  << endl ; 
        
    }
    
    
    return 0;
}
