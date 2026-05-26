#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll helper(ll n,int k){
    if(n==1)
        return 1;
    if(k<=n/2)
        return 2*k;
    k-=n/2;
    if(n%2==0){
        int x=helper(n/2,k);
        return 2*x-1;
    }
    else{
        int x=helper(n/2+1,k);
        if(x==1)
            return n;
        else
            return 2*x-3;
    }
    return 1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll ans=helper(n,k);
        cout<<ans<<endl;
    }
    return 0;
}