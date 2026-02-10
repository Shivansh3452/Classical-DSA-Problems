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

/*
Bottom Up
int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> t(n+1);
        t[0]=0;
        t[1]=nums[0];
        for(int i=2;i<=n;i++){
            int steal=nums[i-1]+t[i-2];
            int skip=t[i-1];

            t[i]=max(steal,skip);
        }
        return t[n];
    }
*/

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
