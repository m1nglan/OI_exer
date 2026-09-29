#include "bits/stdc++.h"
using namespace std;

int m,a[305][305]={-1};

void bfs(){


}

int main(){
    cin>>m;
    for(int i=1;i<=m;i++){
        int x,y,t;
        cin>>x>>y>>t;
        if(a[x][y]==-1||a[x][y]>t) a[x][y]=t;
        if(x>=0&&y>=0&&(a[x+1][y]==-1||a[x+1][y]>t)) a[x+1][y]=t;
        if(x>=0&&y>=0&&(a[x-1][y]==-1||a[x-1][y]>t)) a[x-1][y]=t;
        if(x>=0&&y>=0&&(a[x][y+1]==-1||a[x][y+1]>t)) a[x][y+1]=t;
        if(x>=0&&y>=0&&(a[x][y-1]==-1||a[x][y-1]>t)) a[x][y-1]=t;
    }
    if(a[0][0]==0){cout<<-1;return 0;}
    bfs();
    return 0;
}