// Problem Link - 
/* By Arkajyoti Saha */
#include<bits/stdc++.h>
using namespace std;

#define int   long long int
#define endl           "\n"
#define double long double
const int mod = 1e9 + 7;
const int N = 200005;

#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)

void file_i_o(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}


void primeSieve(vector<int>&sieve){
	//marking 0 and 1 as not prime number
	sieve[1] = sieve[0] = 0;

	//start marking all multiples of ith prime number that are not prime
	loop(i,2,N){
		if(sieve[i] == 1){ //means it is prime
			for(int j = i*i; j<=N; j = j+i){
				sieve[j] = 0; //marking that the number is not prime
			}
		}
	}
}


int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    
    vector<int>sieve(N,1);
    primeSieve(sieve);
    loop(i,0,100){
    	if(sieve[i]){
    		cout<<i<<endl;
    	}
    }
	
	
	
    
	return 0;
}







































