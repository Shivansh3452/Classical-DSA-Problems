// Consider an n*n  grid whose squares may have traps. It is not allowed to move to a square with a trap.
// Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.
// Input
// The first input line has an integer n: the size of the grid.
// After this, there are n lines that describe the grid. Each line has n characters: . denotes an empty cell, and * denotes a trap.
// Output
// Print the number of paths modulo 10^9+7.
// Constraints

// 1<n<1000

// Example
// Input:
// 4
// ....
// .*..
// ...*
// *...

// Output:
// 3

#include<iostream>
#include<vector>
#include<cstring>
#define MOD 1000000007
using namespace std;

int t[1001][1001];
int helper(int i,int j,int n,vector<vector<char> > &mat){
    if(i>=n ||j>=n||mat[i][j]=='*')
        return 0;
    if(i==n-1 &&j==n-1)
        return 1;
    if(t[i][j]!=-1)
        return t[i][j];
    long long down=helper(i+1,j,n,mat);
    long long right=helper(i,j+1,n,mat);
    
    t[i][j]=(down+right)%MOD;
    return t[i][j];
}

int main(){
    int n;
    cin>>n;
    vector<vector<char> > mat(n,vector<char>(n));
    memset(t,-1,sizeof(t));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int ans=helper(0,0,n,mat);
    cout<<ans<<endl;
    return 0;
}