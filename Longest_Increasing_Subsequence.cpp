#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int t[2501][2501];
int helper(int n,vector<int> &nums,int i,int prev){
    if(i>=n)
        return 0;
    if(prev!=-1 && t[i][prev]!=-1)
        return t[i][prev];
    int take=0;
    if(prev==-1||nums[i]>nums[prev]){
        take=1+helper(n,nums,i+1,i);
    }
    int skip=helper(n,nums,i+1,prev);

    if(prev!=-1)
        t[i][prev]=max(take,skip);
    return max(take,skip);
}
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    memset(t,-1,sizeof(t));
    return helper(n,nums,0,-1);
}

// int lengthOfLIS(vector<int>& nums){
//         int n=nums.size();
//         vector<int> t(n,1);
//         int maxLIS=1;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<i;j++){
//                 if(nums[j]<nums[i]){
//                     t[i]=max(t[i],t[j]+1);
//                     maxLIS=max(maxLIS,t[i]);
//                 }
//             }
//         }
//         return maxLIS;
// } 

int main(){
    int n;
    cin>>n;     //size of array;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans=lengthOfLIS(nums);
    cout<<ans<<endl;

    return 0;
}