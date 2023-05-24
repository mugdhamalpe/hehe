
#include<bits/stdc++.h>

using namespace std;
#define inf 1e18

void printPath(int i, vector<int> &parent){
    if(i == parent[i]){ // Source mil gaya
        cout<<i<<" ";
        return;
    }
    printPath(parent[i], parent);
    cout<<i<<" ";
}

int main(){
    int v, e;
    cin>>v>>e;

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int,int>> adj[v+1];

    for(int i=0; i<e; i++){
        int u, v, x;
        cin>>u>>v>>x;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }

    vector<int> dist(v+1, INT_MAX);
    dist[1] = 0;
    pq.push(1);

    vector<int> parent(v+1);
    for(int i=1; i<=v; i++){
        parent[i] = i;
    }

    while(!pq.empty()){
        int node = pq.top();
        pq.pop();
        for(auto it : adj[node]){
            int child = it.first;
            int childDist = it.second;
            if(dist[child] > dist[node] + childDist){
                dist[child] = dist[node] + childDist;
                pq.push(child);
                parent[child] = node;
            }
        }
    }
    for(int i=1; i<=v; i++){
        cout<<"Path of "<<i<<"th node is:- ";
        printPath(i, parent);
        cout<<"\n";
    }

    return 0;
}
