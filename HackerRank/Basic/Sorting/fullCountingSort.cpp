#include <cstdio>
#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

int num;
vector<int> cnt[101];
string name[MAX];
int val[MAX];
int order[MAX];

int main(){
    cin >> num;
    int stop = num/2;
    int temp1;
    string temp2;
    for(int x = 0;x<num;x++){
        cin >> temp1 >> temp2;
        val[x] = temp1;
        name[x] = temp2;
        cnt[temp1].push_back(x);
    }
    for(int x = 0;x<100;x++){
        for(vector<int>::iterator it = cnt[x].begin();it!=cnt[x].end();++it){
            if((*it)<stop) cout << "- ";
            else cout << name[*it] << " ";
        }
    }

    return 0;
}