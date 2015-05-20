
//https://www.hackerrank.com/challenges/find-digits

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std ; 

string num_to_str(int);
int str_to_num(char);


int main()
{
	int N = 0 ; 
	cin >> N ;
	int total[N] ;
	for(int i = 0 ; i < N ; i++ )
		total[i] = 0 ; 
    int count = N ; 
	while(count-- > 0  )
	{
		int num = 0 ; 
		cin >> num; 
		string num_str  = num_to_str(num) ;
		for(int i = 0 ; i < num_str.length() ; i++ ) 
		{
			int digit = str_to_num(num_str[i]) ; 
			if(digit == 0 )
				continue ; 
			if(num % digit == 0 )
				total[count]++ ; 
		}
		 
	}
    for(int i = N-1 ; i >= 0  ; i-- )
	   cout << total[i] << endl ;
	return 0 ; 
}



string num_to_str(int num)
{
	float digit = 0 ; 
	string digits ; 
	while(num >=1  ){
		digit = num % 10 ; 
		num /= 10 ; 
		digits.push_back(digit+'0') ; 
	}
	return digits; 
}


int str_to_num(char str)
{
	return str-'0' ; 
}



