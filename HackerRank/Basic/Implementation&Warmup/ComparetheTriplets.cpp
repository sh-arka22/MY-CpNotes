#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<utility>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
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

const int N = 200005;
//___________________________Arko banega red codder__________________________________


int32_t main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt",  "r",  stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	//START
	int n = 3;

	vector<int> a(n), b(n);
	for(int &it:a){
		cin>>it;
	}
	for(int &it:b){
		cin>>it;
	}
	int A=0, B=0;

	for(int i=0;i<n;i++){
		A += (a[i]>b[i]);
		B += (b[i]>a[i]);
	}

	cout<<A<<" "<<B;
	return 0;
}