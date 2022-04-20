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

bool isSafe(int grid[][9],int i, int j, int no){
	loop(k,0,9-1){
		if(grid[k][j]==no or grid[i][k]==no){ // checks both rows and column
			return false;
		}
	}
	//check subgrid
	int sx = (i/3)*3;
	int sy = (j/3)*3;
	loop(x,sx,sx+3-1){
		loop(y,sy,sy+3-1){
			if(grid[x][y]==no){
				return false;
			}
		}
	}
	return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n){
	//base
	if(i==n){
		//print the solution
		loop(i,0,8){
			loop(j,0,8){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}
	if(j==n){
		return solveSudoku(mat,i+1,0,n);
	}
	if(mat[i][j] != 0){
		return solveSudoku(mat,i,j+1,n);
	}


	for(int no = 1;no<=9;no++){
		if(isSafe(mat,i,j,no)){
			mat[i][j] = no;
			bool faith = solveSudoku(mat,i,j+1,n);
			if(faith){
				return true;
			}
		}
	}
	//recur
	mat[i][j] = 0;
	return false;
}



int32_t main(int32_t argc, char const *argv[]) {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	file_i_o();
	// START //
    
    int n = 9;
    int grid[][9] = { { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
         { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
         { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
         { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
         { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
         { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
         { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
         { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
         { 7, 4, 5, 0, 8, 6, 3, 1, 0 } };
    
    bool ans = solveSudoku(grid,0,0,n);

    printarg(ans);
	
	
	
    
	return 0;
}







































