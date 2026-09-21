#include "bits/stdc++.h"
using namespace std;

int n,a,b,t=INT_MAX;
int k[210];
void dfs(int s,int tn){
    cout<<s<<"/"<<tn<<endl;
    if(b==s){ t=tn; return; }
    if(a==s&&tn!=0) return;
    if(s-k[s]>0) dfs(s-k[s],tn+1);
    if(s+k[s]<=n) dfs(s+k[s],tn+1);
}

int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }
    dfs(a,0);
    if(t==INT_MAX){ cout<<-1; return 0; }
    cout<<t;
    return 0;
}
