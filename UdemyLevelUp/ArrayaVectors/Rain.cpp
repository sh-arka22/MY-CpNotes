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

int trappingRainWater(vector<int>heights){
	int n = heights.size();
	if(n<=2){
		return 0;
	}

	vector<int> left(n,0), right(n,0);
	left[0] = heights[0], right[n-1] = heights[n-1];

	for(int i=1;i<n;i++){
		left[i] = max(left[i-1],heights[i]);
	}
	for(int i=n-2;i>=0;i--){
		right[i] = max(right[i+1],heights[i]);
	}

	// water can only be stored from 1 to n-2 index
	int water = 0;
	for(int i=0;i<n;i++){
		water += min(left[i],right[i]) - heights[i];
	}

	return water;
}

int32_t main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	//START
	std::vector<int> arr = {4,2,0,3,2,5};
	cout<<trappingRainWater(arr)<<endl;

	return 0;
}