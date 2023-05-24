#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100001];

void dfs(int node, map<int, bool> &vis){
    vis[node] = true; // We visit that node, and do not want to visit this node again
    cout<<node<<" ";

    // Traverse in all the children of that node
    for(auto child : graph[node]){
        if(!vis[child]){ // If that child is not visited, call DFS on that child 
            dfs(child, vis);
        }
    }
}

void bfs(int node, map<int, bool> &visited, queue<int> &q){
    visited[node] = true; // We visit that node, and do not want to visit this node again
    cout<<node<<" ";

    q.pop();

    // Traverse in all the children of that node
    for(auto child : graph[node]){
        if(!visited[child]){ // If that child is not visited, call DFS on that child 
            visited[child] = true;
            q.push(child);
        }
    }
    
    if(q.size()){
        bfs(q.front(), visited, q); // Call BFS on node which is at front
    }
}



int main(){
    int v,e;
    cout << "Enter number of vertices :- ";
    cin >> v;
    cout << "Enter number of edges :- ";
    cin >> e;
    cout<<"Enter all the nodes :- ";
    vector<int> nodes(v);
    for(int i = 0;i < v;i++){
        cin>>nodes[i];
    }
    int src,dest;
    for(int i = 0;i < e;i++){
        cout << "Enter source :- ";
        cin >> src;
        cout << "Enter destination :- ";
        cin >> dest;
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }

    // The adjacency list is :-
    // for(int node = 1;node <= v;node++){
    //     if(!graph[node].size()){
    //         cout<<node<<" : "<<"No children\n";
    //     }
    //     else{
    //         cout<<node<<" : ";
    //         for(auto child : graph[node]){
    //             cout<<child<<" ";
    //         }
    //         cout<<"\n";
    //     }
    // }

    map<int, bool> vis;

    // DFS
    cout<<"Order of DFS call is :- \n";
    for(auto node : nodes){
        if(!vis[node]){ // If that node is not visited, call DFS on that node
            dfs(node, vis);
        }
    }
    cout<<"\n";
    // BFS
    cout<<"Order of BFS call is :- \n";
    queue<int> q;
    map<int, bool> visited;
    for(auto node : nodes){
        if(!visited[node]){
            q.push(node);
            bfs(node, visited, q);
        }
    }
    return 0;
}