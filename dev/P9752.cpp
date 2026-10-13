#include "bits/stdc++.h"
using namespace std;

int n,s[9][5];
vector<string> a;

void add_item(int s[]){
    for(int i=0;i<5;i++){
        char c[5]="";
        for(int h=0;h<5;h++)
            c[h]=s[h]+'0';
        for(int j=1;j<10;j++){
            if(c[i]=='9') c[i]='0';
            else c[i]++;
            a.push_back(c);
        }
    }
    
    for(int i=0;i<4;i++){
        char c[5]="";
        for(int h=0;h<5;h++)
            c[h]=s[h]+'0';
        for(int j=1;j<10;j++){
            if(c[i]=='9') c[i]='0';
            else c[i]++;
            if(c[i+1]=='9') c[i+1]='0';
            else c[i+1]++;
            a.push_back(c);
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>s[i][j];
        }
    }
  //  if(n==1){cout<<81;return 0;}
    
    for(int i=0;i<n;i++){
        add_item(s[i]);
    }    
    sort(a.begin(),a.end());
    auto sp=a.begin();
    int t=0,tn=1;
    for(auto i=a.begin()+1;i!=a.end()+1;i++){
        if(i!=a.end()&&*i==*sp) tn++;
        else{
            if(tn==n) t++;
            tn=1,sp=i;
        }
    }
    cout<<t;
    return 0;
}