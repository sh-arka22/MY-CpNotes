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


int largestBand(vector<int> arr){
	int n = arr.size();

	unordered_set<int>st;
	for(int it:arr){
		st.insert(it);
	}
	int longest = 1;
	for(auto el:arr){
		int prev = el-1;
		if(st.find(prev) == st.end()){
			int start = prev+1;
			int cnt = 0;
			while(st.find(start) != st.end()){
				cout<<start<<" ";
				start++;
				cnt++;
			}
			longest = max(longest,cnt);
		}
		cout<<endl;
	}
	return longest;
}

int32_t main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	//START
	
	int ans = largestBand({1,9,3,0,18,5,2,4,10,7,12,6});
	cout<<ans<<endl;
	return 0;
}