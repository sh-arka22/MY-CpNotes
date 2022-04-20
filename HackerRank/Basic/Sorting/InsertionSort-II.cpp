// Problem Link - 
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

void fun(vector<int>&arr, int n){
	int ele = arr[n-1];
	int i;
	for(i=n-2;i>=0;i--){
		if(arr[i]>ele){
			arr[i+1] = arr[i];
			// printarg(arr[i+1],arr[i]);
			// printarr(arr);
		}
		else{
			arr[i+1] = ele;
			// printarr(arr);
			break;
		}
	}
	if(arr[0]>ele){
		arr[0] = ele;
		// printarr(arr);
	}
	printarr(arr);
}



int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    
    
    int n;cin>>n;
    vector<int>arr(n);
    for(int &it:arr){
    	cin>>it;
    }
    int t = 1;
    while(t<=n){
    	fun(arr,t);
    	// printarr(arr);
    	t++;
    }
    
    
	return 0;
}



// 3 4 7 5 6 2 1
// 3 4 7 5 6 2 1
// 3 4 5 7 6 2 1
// 3 4 5 6 7 2 1
// 2 3 4 5 6 7 1
// 1 2 3 4 5 6 7



































