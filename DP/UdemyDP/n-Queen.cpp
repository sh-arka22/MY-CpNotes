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

void printBoard(int arr[][20],int n){
	for(int i=0;i<n;i++){
		loop(j,0,n-1){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

bool canPlace(int board[][20],int n,int x, int y){

	//column
	for(int k=0;k<x;k++){
		if(board[k][y]){
			return false;
		}
	}

	//left dai
	int i=x, j=y;

	while(i>=0 and j>=0){
		if(board[i][j]){
			return false;
		}
		i--, j--;
	}

	//right dia
	i = x, j=y;
	while(i>=0 and j<n){
		if(board[i][j]){
			return false;
		}
		i--,j++;
	}

	return true;
}

int solveNqueen(int board[][20],int n, int i){
	if(i==n){
		//print the board
		printBoard(board,n);
		return 1;
		// return true;
	}

	int ways = 0;

	for(int j=0;j<n;j++){
		// cheack wheather the current position is safe or not
		if(canPlace(board,n,i,j)){
			board[i][j] = 1;
			ways += solveNqueen(board,n,i+1);
			//backtrack that position
			board[i][j] = 0;
		}
	}
	return ways;
}



int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    
    
    
	int board[20][20] = {{0}};

	int n;
	cin>>n;

	int flag = solveNqueen(board,n,0);

	cout<<flag;
	
    
	return 0;
}







































