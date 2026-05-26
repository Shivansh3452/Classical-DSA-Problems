#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll helper(ll a,ll b,ll m){
    ll ans=1;
    if(a==0&&b==0)
        return 1;
    while(b){
        if(b%2==1)
            ans=(ans*a)%(m);
        a=(a*a)%(m);
        b/=2;
    }
    return ans%(m);
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        ll temp=helper(b,c,mod-1);
        ll ans=helper(a,temp,mod);
        cout<<ans<<endl;
    }
    return 0;
}