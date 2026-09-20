#include "bits/stdc++.h"
using namespace std;

int n,maxn;
string a[21],tans;
char s;
int ch[21];


bool check(string &nans,string ans,string a){
    string f;
    for(int i=0;i<a.size()-1;i++){
        f+=a[i];
    //    cout<<f<<endl;
        int pos=ans.find(f,ans.size()-i-1);
        if(pos!=-1){
            
            string add;
            for(auto j=a.begin()+i+1;j!=a.end();j++) add+=*j;
            nans=ans+add;
            return 1;
        }
    }
    return 0;
}

void dfs(int w,string ans){
    //cout<<ans<<endl;
    int t=ans.size();
    if(t>maxn) maxn=t,tans=ans;   
    for(int i=1;i<=n;i++){
    //    cout<<w<<endl;
        if(w==1){
        //    cout<<a[i][0]<<endl;
            if(a[i][0]!=s) continue;
            ans=a[i],ch[i]=1;
            dfs(w+1,ans);
            ans="",ch[i]=0;
        }else{
            if(ch[i]==2) continue;
            string nans;
            if(!check(nans,ans,a[i])) continue;
            ch[i]+=1;
            dfs(w+1,nans);
            ch[i]-=1;
        }
    }

}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>s;
    dfs(1,"");
    cout<<maxn;

    return 0;
}

//atoucheatactactouchoose
//atoucheatactactouchoose