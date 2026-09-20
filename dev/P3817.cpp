#include <cstdio>
#include <iostream>
using namespace std;

long long n,x,a[100010],t;

int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        printf("%lld",&a[i]);
    }
    for(int i=2;i<=n;i++){
        while(a[i]+a[i-1]>x){
            a[i]--,t++;
        }
    }
    cout<<t;
}