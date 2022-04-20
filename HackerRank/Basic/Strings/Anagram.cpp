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


void solve(){
	string str;
	cin>>str;

	int n=str.size();
	if(n%2 != 0){
		cout<<-1<<endl;
		return;
	}

	vector<int>str1(26,0), str2(26,0);

	bool flag = true;
	int i = 0, j = n-1;
	while(flag){
		str1[str[i]-'a']++;
		str2[str[j]-'a']++;
		i++;
		j--;
		if(i == j or i>j){
			flag = false;
		}
	}
	for(i=0;i<n/2;i++){
		int mini = min(str2[str[i]-'a'],str1[str[i]-'a']);
		str1[str[i]-'a'] -= mini;
		str2[str[i]-'a'] -= mini;
	}
	for(i=n/2+1;i<n;i++){
		int mini = min(str2[str[i]-'a'],str1[str[i]-'a']);
		str1[str[i]-'a'] -= mini;
		str2[str[i]-'a'] -= mini;
	}
	int cnt = 0;
	for(auto it:str1){
		cnt += it;
	}

	cout<<cnt<<endl;
}


int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// file_i_o();
	// START //
    
    
    int t;cin>>t;

    while(t--){
    	solve();
    }
	
	
	
    
	return 0;
}







































