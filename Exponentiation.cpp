#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;


ll helper(ll a,ll b){
    ll ans=1;
    while(b){
        if(b%2==1)
            ans=(ans*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ans%mod;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        ll a,b;
        cin>>a>>b;
        cout<<helper(a,b)<<endl;
    }
    return 0;
}