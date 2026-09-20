#include "bits/stdc++.h"
using namespace std;

int n,k;
vector<int> a;

bool check(int m){
    int t=0;
    for(auto x:a){
        while(x>=m) x-=m,t++;
    }
//    cout<<"t->"<<t<<endl;
    if(t>=k) return 1;
    return 0;
}

int main(){
    cin>>n>>k;
    a.resize(n);

    int minn=INT_MAX;
    for(auto &x:a){
        cin>>x;
        if(x<minn) minn=x;
    }
    
    int s=1,e=minn,ans=0;
    while(s<=e){
        int mid=s+(e-s)/2;
//        cout<<mid<<endl;
        if(check(mid)) s=mid+1,ans=mid;
        else e=mid-1;
    }
    cout<<ans;
    return 0;
}