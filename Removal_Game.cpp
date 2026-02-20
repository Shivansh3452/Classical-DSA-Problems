#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;

long long dp[5001][5001];
long long helper(int i,int j,vector<int>& nums){
    if(i==j)
        return nums[i];
    if(j-i==1)
        return max(nums[i],nums[j]);
    if(dp[i][j]!=LLONG_MIN)
        return dp[i][j];
    return dp[i][j]=max((long long)nums[i]+min(helper(i+2,j,nums),helper(i+1,j-1,nums)),
                (long long)nums[j]+min(helper(i,j-2,nums),helper(i+1,j-1,nums)));
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    for(auto& row : dp)
        fill(row, row+n, LLONG_MIN);
    cout<<helper(0,n-1,nums)<<endl;
    return 0;
}