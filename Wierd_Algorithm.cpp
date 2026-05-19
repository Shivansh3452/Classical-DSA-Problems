#include<bits/stdc++.h>
using namespace std;

void helper(long long int n){
    while(n!=1){
        if(n%2==0){
            n/=2;
            if(n==1){
                cout<<n;
                return;
            }
            cout<<n<<" ";
        }
        else{
            if(n==1){
                cout<<n;
                return;
            }
            n=n*3+1;
            cout<<n<<" ";
        }
    }
}

int main(){
    long long int n;
    cin>>n;
    cout<<n<<" ";
    helper(n);
    return 0;
}