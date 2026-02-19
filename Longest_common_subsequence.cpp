#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;


int t[1001][1001];
int helper(int i,int j,int n,int m,vector<int>& nums1,vector<int>& nums2,vector<int>& common){
    if(i>=n||j>=m)
        return 0;
    if(t[i][j]!=-1)
        return t[i][j];
    if(nums1[i]==nums2[j]){
        return t[i][j]=1+helper(i+1,j+1,n,m,nums1,nums2,common);
    }
    return t[i][j]=max(helper(i,j+1,n,m,nums1,nums2,common)
        ,helper(i+1,j,n,m,nums1,nums2,common));
}

void reconstruct(int i,int j,int n,int m,vector<int>& nums1,vector<int>& nums2,vector<int>& common){
    if(i>=n||j>=m)
        return ;
    if(nums1[i]==nums2[j]){
        common.push_back(nums1[i]);
        reconstruct(i+1,j+1,n,m,nums1,nums2,common);
    }
    else if(helper(i+1,j,n,m,nums1,nums2,common)<helper(i,j+1,n,m,nums1,nums2,common))
        reconstruct(i,j+1,n,m,nums1,nums2,common);
    else 
        reconstruct(i+1,j,n,m,nums1,nums2,common);
}

int main(){
    memset(t,-1,sizeof(t));
    int n,m;
    cin>>n>>m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }
    vector<int> common;
    int ans=helper(0,0,n,m,nums1,nums2,common);
    cout<<ans<<endl;
    reconstruct(0,0,n,m,nums1,nums2,common);
    for(auto& num:common)
        cout<<num<<" ";
    return 0;
}