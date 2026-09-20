#include "bits/stdc++.h"
using namespace std;

int n,p;
double ta=0,tb=0;
vector<int> a;
vector<int> b;

bool check(double m){
    double pa=p*m; 
    for(int i=0;i<n;i++){
        if(a[i]*m<=b[i]) continue;
        pa-=a[i]*m-b[i];
    }
    if(pa>=0) return 1;
    return 0; 
}

int main(){
    cin>>n>>p;
    a.resize(n);
    b.resize(n);
    int maxn=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        ta+=a[i];
        tb+=b[i];
    }
    if(p>ta){cout<<-1;return 0;}
    int t=0;
    double s=0,e=1e10,ans=0;
    while(t<100){
        double mid=s+(e-s)/2;
        cout<<mid<<endl;
        if(check(mid)){
            s=mid,ans=mid;
        }else{
            e=mid;
        }
        t++;
    }
    cout<<ans;
    return 0;
}

/*
题意解释：
a->速度 b->存储
a1*t+a2*t+... = (a1+a2+...)*t = 总消耗
*/