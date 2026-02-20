#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int total=0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        total+=nums[i];
    }
    vector<bool> dp(total+1,false);
    dp[0]=true;     //0 always reachable
    for(int i=0;i<n;i++){
        for(int s=total;s>=nums[i];s--){
            if(dp[s-nums[i]])       //matlab bcha hua maal reachable h without this coin
                dp[s]=true;
        }
    }
    vector<int> ans;
    for(int s=1;s<=total;s++)
        if(dp[s])
            ans.push_back(s);

    cout<<ans.size();
    cout<<"\n";
    for(auto& a:ans)
        cout<<a<<" ";
    return 0;
}
