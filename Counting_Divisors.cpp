#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;(i*i)<=n;i++){
            if(n%i==0){
                ans++;
                if(i!=n/i)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}