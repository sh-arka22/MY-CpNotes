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

bool outOfOrder(vector<int>&arr, int i){
	int ele = arr[i];
	int n = arr.size();
	if(i==0){
		return ele>arr[i+1];
	}
	if(i==n-1){
		return ele<arr[i-1];
	}
	return ele > arr[i+1] or ele < arr[i-1];
}

pair<int,int> subarraySort(vector<int>&arr){

	int smallest = INT_MAX; //smallest ele that i sout of order
	int largest = INT_MIN; //largest ele that is out of order

	for(int i = 0;i <arr.size(); i++){
		int ele = arr[i];
		if(outOfOrder(arr,i)){
			smallest = min(smallest,ele);
			largest = max(largest,ele);
		}
	}

	//finding the right index where smallest and largest should be
	if(smallest == INT_MAX)
		return {-1,-1};

	int left = 0;
	while(smallest >= arr[left]){
		left ++;
	}

	int right = arr.size()-1;
	while(largest <= arr[right]){
		right--;
	}
	return {left,right};
}

int32_t main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt",  "r",  stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	//START
	vector<int> arr = {1,2,3,4,5,8,6,7,9,10,11};
	auto p = subarraySort(arr);
	cout<< p.first<<" and "<<p.second;

	return 0;
}