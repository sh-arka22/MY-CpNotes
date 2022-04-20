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

int highest_mountian(vector<int> arr){
	int n = arr.size();

	int largest = 0;

	for(int i=1;i<n-1;){
		if(arr[i]>=arr[i+1] and arr[i]>arr[i-1]){
			int cnt = 1;
			int j = i;

			while(j>=1 and arr[j]>arr[j-1]){
				j--;
				cnt++;
			}
			while(i<=n-2 and arr[i]>arr[i+1]){
				i++;
				cnt++;
			}
			largest = max(largest,cnt);
		}
		else{
			i++;
		}
	}
	return largest;
}


int32_t main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt",  "r",  stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	//START
	int net;
	cin>>net;
	int res = highest_mountian({5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4});
	cout<<res<<endl;
	cout<<net;

	return 0;
}