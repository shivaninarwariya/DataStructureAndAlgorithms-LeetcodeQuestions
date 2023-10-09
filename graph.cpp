#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
vector<int>g[N];
bool vis[N];
//DFS TRAVERSAL
void Dfs(int vertex){
    vis[vertex]=true;
    cout<<"DFS traversal of graph is :"<<vertex<<" ";
    for(int child:g[vertex]){
        if(vis[child])continue;
        Dfs(child);
    }
}
//BFS
vector<int> bfsOfGroup(int v,vector<int>adj[]){
    int n;
    int vis[n]={0};
    vis[0]=1;
    queue<int>q;
    q.push(0); vector<int>bfs;
    while(!q.empty()){
     int node=q.front();
     q.pop();
     bfs.push_back(node);
     for(auto it:adj[node]){
        if(!vis[it]){
            vis[it]=1;
            q.push(it);
        }
     }
   }
   return bfs;
}

int main(){
    int n,m;
    cout<<"enter the value of vertices :";cin>>n;
    cout<<"enter the value of edges :";cin>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    //FINDING NUMBER OF CONNECTED COMPONENT IN GRAPH 
    int ct=0;
    for(int i=0;i<n;i++){
      if(vis[i])continue;
      Dfs(i);
      ct++;
    }
    cout<<"number of count of connected component in graph :"<<ct<<" ";
}
