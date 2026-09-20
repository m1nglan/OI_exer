#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n,s,y[100010],a,b,t;

int main(){
    cin>>n>>s>>a>>b;
    int l=a+b,j=0;
    for(int i=1;i<=n;i++){
        int xn,yn;
        cin>>xn>>yn;
        if(xn<=l) y[j++]=yn;
    }
    j--;
    sort(y,y+j);
    for(int i=0;s>=0;i++){
        if(s-y[i]<0) break;
        t++,s-=y[i];
    }
    cout<<t;
}