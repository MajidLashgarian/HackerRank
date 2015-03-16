#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int calculateAllFairness(int *src , int &size , int &len );
int getUnfairness(int *dest , int &len  );


int main() {
    int N, K, unfairness = INT_MAX;
    cin >> N >> K;
    int list[N];
    for (int i=0; i<N; i++)
        cin >> list[i];
	vector<int> results ; 
	std::sort(list , list+N );
	unfairness = calculateAllFairness(list , N , K) ; 
    cout << unfairness << "\n";
    return 0;
}


int calculateAllFairness(int *src , int &size , int &len )
{
	int res[size];
	for(int start = 0 ; start < size  ; start++ )
	{
		int temp_src[len] ; 
		for(int i = start  , j = 0 ; i < start+len ; i++ , j++ )
		{
			int pos = i ; 
			if(pos >=size )
				pos = pos - size ; 
			temp_src[j] = src[pos]; 

		}
		int unf = getUnfairness(temp_src , len);
		res[start] = unf ; 
	}
	return *std::min_element(res , res+size) ; 
}

int getUnfairness(int *dest , int &len  )
{

	int max = *std::max_element(dest , dest+len);  
	int min = *std::min_element(dest , dest+len); 
	return max - min ; 
}



