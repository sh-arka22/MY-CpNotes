// Problem Link - https://www.hackerrank.com/challenges/making-anagrams/problem?isFullScreen=true
/* By Arkajyoti Saha */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define int   long long int
#define endl           "\n"
#define double long double
const int mod = 1e9 + 7;
inline int power(int a, int b)
{
	int x = 1;
	while (b)
	{
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}

inline vector<string> tokenizer(string &str,char separator){
	istringstream ss(str);
	string token;
	vector<string>ans;
	while(getline(ss,token,separator)){
		ans.push_back(token);
	}
	return ans;
}

const int N = 200005;
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define printarg(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define printarr(arr)	for(auto it:arr) cout<<it<<" ";cout<<endl;	

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void file_i_o(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}





int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// file_i_o();
	// START //
    
    string s1, s2;
    cin>>s1>>s2;
    // printarg(s1,s2);
	
	vector<int>v1(26,0), v2(26,0);

	for(char it:s1){
		v1[it - 'a']++;
	}
	for(char it:s2){
		v2[it-'a']++;
	}

	for(char c:s1){
		int mini = min(v1[c-'a'],v2[c-'a']);

		v1[c-'a'] -= mini;
		v2[c-'a'] -= mini;
	}
	for(char c:s2){
		int mini = min(v1[c-'a'],v2[c-'a']);

		v1[c-'a'] -= mini;
		v2[c-'a'] -= mini;
	}



	int del = 0;

	for(int it:v1){
		del += it;
	}	
	for(int it:v2){
		del += it;
	}

	cout<<del<<endl;
    
	return 0;
}







































