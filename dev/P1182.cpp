#include "bits/stdc++.h"
using namespace std;

int n,m;

bool check(vector<int> a,int x){
    auto p=a.begin();
    int t=0,tn=0;
    for(;p!=a.end();p++){
        if(tn+*p>x) t++,tn=*p;
        else tn+=*p;
    }
    if(tn!=0) t++;
//    cout<<"t-"<<t<<endl;
    if(t<=m) return 1;
    return 0;
}

int main(){
    cin>>n>>m;
    vector<int> a(n);
    int all=0;
    int maxn=0;
    for(auto &x:a){
        cin>>x;
        if(x>maxn) maxn=x;
        all+=x;
    }
    int s=maxn,e=all,ans;
    while(s<=e){
        int mid=s+(e-s)/2;
//        cout<<mid<<endl;
        if(check(a,mid)){
            e=mid-1,ans=mid;
        }else{
            s=mid+1;
        }
    }
    //42451 54421 555444321
    cout<<ans;
    return 0;
}