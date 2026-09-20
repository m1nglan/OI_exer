#include "bits/stdc++.h"
using namespace std;

int l,n,m;
vector<int> a;

bool check(int f){
    int t=0;
    vector<int> aa(a);
    for(auto i=aa.begin()+1;i!=aa.end()-1;i++){
        if(i==aa.end()-2 && *(i+1)-*i<f){t++; break;}
        if(*i-*(i-1)<f) *i=*(i-1),t++;
    }
//    cout<<"t->"<<t<<endl;
    if(t<=m) return 1;
    return 0;
}

int main(){
    cin>>l>>n>>m;
    if(n==0) {cout<<l;return 0;}
    a.resize(n);
    for(auto &x:a) cin>>x;
    a.insert(a.begin(),0);
    a.push_back(l);

    int s=1,e=l,ans=0;
    while(s<=e){
        int mid=s+(e-s)/2;
//        cout<<mid<<endl;
        if(check(mid)) s=mid+1,ans=mid;
        else e=mid-1;
    }
    cout<<ans;
    return 0;
}

// 0 2 4 7 8
// 0 1 2 3 4 5