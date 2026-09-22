#include "bits/stdc++.h"
using namespace std;

int n,a,b,t=INT_MAX;
int k[210];
bool ch[210];
queue <pair<int,int>> qb;

void bfs(){
    qb.push(make_pair(a,0));
    while(!qb.empty()){
        pair<int,int> now;
        now=qb.front();
        qb.pop();
        int s=now.first;
        int tn=now.second;
        if(ch[s]) continue;
        ch[s]=1;
        if(s==b){ t=tn; break; }
        if(s-k[s]>0) qb.push(make_pair(s-k[s],tn+1));
        if(s+k[s]<=n) qb.push(make_pair(s+k[s],tn+1));
    }
}

int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }
    bfs();

    if(t==INT_MAX){ cout<<-1; return 0; }
    cout<<t;
    return 0;
}

/*
vector<int> dis(n + 1, -1);    // -1 = 没到过
queue<int> q;
dis[a] = 0; q.push(a);
while (!q.empty()) {
    int s = q.front(); q.pop();
    if (s == b) break;
    int nx[2] = {s - k[s], s + k[s]};
    for (int v : nx)
        if (v >= 1 && v <= n && dis[v] == -1) {   // 判重
            dis[v] = dis[s] + 1;
            q.push(v);
        }
}
cout << dis[b];    // 到不了自动输出 -1，不用特判！
*/