#include "bits/stdc++.h"
using namespace std;

int l,n,k;
vector<int> a;

bool check(int m){
    int t=0;
    vector<int> aa(a);
    for(auto i=aa.begin();i!=aa.end()-1;i++){
        if(*(i+1)-*i>m) aa.insert(i+1,*i+m),t++;
    }
    for(auto x:aa) cout<<x<<" ";
    cout<<endl;
    if(t>=k) return 1;
    return 0;
}

int main(){
    cin>>l>>n>>k;
    a.resize(n);
    for(auto &i:a){
        cin>>i;
    }
    int s=0,e=l,ans=0;
    while(s<=e){
        int mid=s+(e-s)/2;
        cout<<mid<<endl;
        if(check(mid)){
            s=mid+1,ans=mid;
        }else{
            e=mid-1;
        }
    }
//    cout<<ans;
    return 0;
}
