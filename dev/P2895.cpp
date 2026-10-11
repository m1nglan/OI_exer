#include "bits/stdc++.h"
using namespace std;

int m,a[305][305],mint=INT_MAX;
bool ch[305][305];

struct xOy{
    int x;
    int y;
    int t;
};

void bfs(){
    queue<xOy> q;
    q.push({0,0,0});
    while(!q.empty()){
        xOy n=q.front();
        q.pop();
        int t=n.t,x=n.x,y=n.y;
        ch[x][y]=1;
        printf("%d|%d|%d|%d\n",x,y,t,a[x][y]);
        if(a[x][y]==-1){if(mint>t)mint=t;break;}
        if(x+1<=300&&(a[x+1][y]>t+1||a[x+1][y]==-1)&&!ch[x+1][y]) q.push({x+1,y,t+1});
        if(x-1>=0  &&(a[x-1][y]>t+1||a[x-1][y]==-1)&&!ch[x-1][y]) q.push({x-1,y,t+1});
        if(y+1<=300&&(a[x][y+1]>t+1||a[x][y+1]==-1)&&!ch[x][y+1]) q.push({x,y+1,t+1});
        if(y-1>=0  &&(a[x][y-1]>t+1||a[x][y-1]==-1)&&!ch[x][y-1]) q.push({x,y-1,t+1});
    }

}
#define PT_MAX 20
void print_map(){
    for(int i=0;i<PT_MAX;i++){
        for(int j=0;j<PT_MAX;j++){
            printf("%3d ",a[i][j]);
        }
        cout<<endl;
    }
}

int main(){
    memset(a,-1,sizeof(a));
    cin>>m;
    for(int i=1;i<=m;i++){
        int x,y,t;
        cin>>x>>y>>t;
        if(a[x][y]==-1||a[x][y]>t) a[x][y]=t;
        if(x+1<=300&&(a[x+1][y]==-1||a[x+1][y]>t)) a[x+1][y]=t;
        if(x-1>=0  &&(a[x-1][y]==-1||a[x-1][y]>t)) a[x-1][y]=t;
        if(y+1<=300&&(a[x][y+1]==-1||a[x][y+1]>t)) a[x][y+1]=t;
        if(y-1>=0  &&(a[x][y-1]==-1||a[x][y-1]>t)) a[x][y-1]=t;
    }
    print_map();
    if(a[0][0]==0){cout<<-1;return 0;}
    bfs();
    cout<<((mint==INT_MAX)?-1:mint);
    return 0;
}