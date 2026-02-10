#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int memo[101];
int helper(int i, int n, vector<int>& nums) {
    if (i > n)
        return 0;
    if (memo[i] != -1)
        return memo[i];
    int steal = nums[i] + helper(i + 2, n, nums);
    int skip = helper(i + 1, n, nums);
    return memo[i] = max(steal, skip);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];
    memset(memo, -1, sizeof(memo));
    int take_0th = helper(0, n - 2, nums);
    memset(memo, -1, sizeof(memo));
    int take_1th = helper(1, n - 1, nums);
    return max(take_0th, take_1th);
}

/*
Bottom Up Approach
int t[10000];
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        if (n == 2) 
            return max(nums[0], nums[1]);

        //case 1 when we take first house and thus not take the last house
        t[0]=0;
        t[1]=nums[0];
        for(int i=2;i<=n-1;i++){
            int skip=t[i-1];
            int take=nums[i-1]+t[i-2];
            t[i]=max(skip,take);
        }
        int result1=t[n-1];


        // case 2 when we do not take the first house
        t[0]=0;
        t[1]=0;
        for(int i=2;i<=n;i++){
            int skip=t[i-1];
            int take=nums[i-1]+t[i-2];
            t[i]=max(skip,take);
        }
        int result2=t[n];

        return max(result1,result2);
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
