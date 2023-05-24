//asign 3 - dijkstra's algo

#include <bits/stdc++.h>

using namespace std;

void printParent(int i, vector<int> &parent){
    if(parent[i]==i){
        cout<<i<<" ";
        return;
    }
    printParent(parent[i], parent);
    cout<<i<<" ";
    // cout<<endl;
}

int main(){
    cout<<"Enter no of vertices : ";
    int v; 
    cin>>v;
    cout<<"Enter no of edges : ";
    int e;
    cin>>e;
    vector<pair<int, int>> adj[v+1];
    for(int i=0; i<e; i++){
        int u, v, x;
        cout<<"Enter source : ";
        cin>>u;
        cout<<"Enter destination : ";
        cin>>v;
        cout<<"Enter weight : ";
        cin>>x;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }
    vector<int> parent(v+1);
    for(int i=1; i<=v; i++){
        parent[i]=i;
    }

    priority_queue<int, vector<int>, greater<>> pq;
    vector<int> dist(v+1, INT_MAX);
    dist[1]=0;
    pq.push(1);

    while(!pq.empty()){
        int node=pq.top();
        pq.pop();
        for(auto it: adj[node]){
            int child=it.first;
            int childDist=it.second;
            if(dist[child]>dist[node]+childDist){
                dist[child]=dist[node]+childDist;
                pq.push(child);
                parent[child]=node;
            }
        }
    }

    for(int i=1; i<=v; i++){
        cout<<"Path of "<<i<<"th node is : ";
        printParent(i, parent);
        cout<<endl;
    }
    
    return 0;
}