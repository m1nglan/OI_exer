#include "bits/stdc++.h"
using namespace std;

int w, x, m;

bool check(double n){
    double wx=w;
    for(int i=1;i<=m;i++){
        double xn = wx*n;
        wx-= x-xn;
    }
    if(wx<=0) return 1;
    return 0;
}

int main(){
    cin>>w>>x>>m;

    int num=0;
    double s=0,e=3;
    while(num<100){
        double mid=s+(e-s)/2;
        if(check(mid)){
            s=mid;
        }else{
            e=mid;
        }
        num++;
    }
    printf("%.1f",s*100);
    return 0;
}