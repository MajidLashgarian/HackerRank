#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void getStrings(vector<string> &) ; 
bool isPalindroma(string &);
int processString(string &);
void copyStr(const string &, string & , const int &);

int main() {
	vector<string> input;
	vector<int> result ; 
	getStrings(input);
	for(auto str: input) 
	{
		int res = -2;
		int pos = -1 ;
		string tempStr = str ; 
		while(res < -1){
			res = processString(tempStr);
			if(res == -1)
				continue ; 
			pos++ ;
			copyStr(str , tempStr ,  pos);
		}   
		if(pos != -1 )
			result.push_back(pos) ;
		else 
			result.push_back(res) ; 
	}
	for(auto res : result)
		cout << res << endl ; 
    return 0;
}


void getStrings(vector<string>& input )
{
	int t = 0 ; 
	cin >> t;
	t++ ; 
	while(t--)
	{
		string temp_str ; 
		getline(cin , temp_str );
		if(!temp_str.size() ) 
			continue ; 
		input.push_back(temp_str);
	}
}



bool isPalindroma(string &str)
{
	int half = str.size()/2  ;
	bool isOdd = str.size()%2 != 0 ; 
	int s0 = 0 , e0 = half , s1 = isOdd ? half+1 : half  , e1 = str.size() ; 
	
	for(int i0 = s0 , i1 = s1 ; i0 < half ; i0++ , i1++ )
	{
		if(str[i0] != str[i1])
			return false ; 
	}

	return true ; 

}


int processString(string &str)
{
		bool res = isPalindroma(str);
		if(res)
			return -1 ;
		else 
			return -2 ; 
}

void copyStr(const string& src , string &dest ,const int &pos)
{
	dest = "" ; 
	for(int i = 0 ; i < src.size() ; i++)
	{
		if(pos == i )
			continue ; 
		dest.push_back(src[i]);
	}
} 
