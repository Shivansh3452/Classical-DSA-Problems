#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;


int memo[101000];
    int helper(int i,int n,vector<int> &nums){
        if(i>=n)
            return 0;
        if(memo[i]!=-1)
            return memo[i];
        int steal=nums[i]+helper(i+2,n,nums);
        int skip=helper(i+1,n,nums);

        return memo[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(memo,-1,sizeof(memo));
        return helper(0,n,nums);
    }

int main(){
    int n;
    cin>>n;     //size of array
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans=rob(nums);
    cout<<ans<<endl;
    return 0;
}