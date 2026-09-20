#include "bits/stdc++.h"
using namespace std;

int s[5],a[5][90];

//法1 01背包-----------------------------------
int fdp(int s[],int n){
    int dp[10000]={0},W=s[0]/2;
    for(int i=1;i<=n;i++){
        for(int j=W;j>=s[i];j--){
            dp[j]=max(dp[j],dp[j-s[i]]+s[i]);
        }
    }
    return s[0]-dp[W];
}
int a1_dp(){
    int t=0;
    for(int i=1;i<=4;i++){
        t+=fdp(a[i],s[i]);
    }
    return t;
}


//法2 dfs--------------------------------------
int ans=0;
void dfs(int n,int a[],int w,int now,int i){
    if(now==w/2 && w%2==0){ ans=now; return; }
    if(now>w/2){if(now<ans)ans=now; return;}
    if(i>n) return;
    
        dfs(n,a,w,now+a[i],i+1);

        dfs(n,a,w,now,i+1);
}
bool cmp(int a,int b){ return a>b; }
int a2_dfs(){
    int t=0;
    for(int i=1;i<=4;i++){
        ans=INT_MAX;
        int w=a[i][0];
        sort(a[i]+1,a[i]+1+s[i],cmp);
        dfs(s[i],a[i],w,0,1);
        cout<<ans<<endl;
        t+=ans;
    }
    return t;
}

int main(){
    for(int i=1;i<=4;i++){
        cin>>s[i];
    }
    for(int i=1;i<=4;i++){
        int ta=0;
        for(int j=1;j<=s[i];j++){
            cin>>a[i][j],ta+=a[i][j];
        }
        a[i][0]=ta;
    }
    int a1=a1_dp(),a2=a2_dfs();
    cout<<"dp--> "<<a1<<endl;
    cout<<"dfs-> "<<a2<<endl;
    if(a1==a2)cout<<"samed";
    else cout<<"insamed";
    return 0;
}
