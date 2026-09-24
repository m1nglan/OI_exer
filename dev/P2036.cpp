#include "bits/stdc++.h"
using namespace std;

int n;
int s[15],b[15];
int minn=INT_MAX;

void dfs(int m,int sn,int tn,int f){
    int t=abs(sn-tn);
    if(t<minn&&f!=0) minn=t;
    if(m>n) return;
    
    dfs(m+1,sn*s[m],tn+b[m],f+1);
    dfs(m+1,sn,tn,f);

}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i]>>b[i];
    }
    if(n==1){ cout<<abs(s[0]-b[0]); return 0; }
    dfs(0,1,0,0);
    cout<<minn;
    return 0;
}
