// #include<iostream>
// #include<vector>
// #include<cstring>
// #include<climits>
// #define MOD 1000000007
// using namespace std;

// int t[1000001];

// long long helper(int n,int x,vector<int> nums){
//     if(x==0)
//         return 1;
//     if(x<0)
//         return 0;
//     if(t[x]!=-1)
//         return t[x];
//     long long  ways=0;
//     for(int i=0;i<n;i++){
//         ways=(ways+helper(n,x-nums[i],nums))%MOD;
//     }
//     t[x]=ways;
//     return ways;
// }

// int main(){
//     int n,x;
//     cin>>n>>x;
//     vector<int> nums(n);
//     memset(t,-1,sizeof(t));
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     long long ans=helper(n,x,nums);
//     cout<<ans<<endl;
//     return 0;
// }


#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#define MOD 1000000007
using namespace std;

int t[1000001];

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    memset(t,0,sizeof(t));
    t[0]=1;
    
    for(int i=1;i<=x;i++){
        long long ways=0;
        for(int j=0;j<n;j++){
            if(i-nums[j]>=0){
                ways=(ways+t[i-nums[j]])%MOD;
            }
        }
        t[i]=ways;
    }
    
    cout<<t[x]<<endl;
    return 0;
}