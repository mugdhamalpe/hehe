//A* star - 8 puzzle game

#include <bits/stdc++.h>

using namespace std;
#define n 3

class Node{
    Node* parent;
    int mat[n][n];
    int x;
    int y;
    int level;
    int cost;

    friend class Solution;
};

class Solution{
    public:

    Node* newNode(int mat[n][n], int x, int y, int newX, int newY, int level, Node* child){
        Node* node=new Node;
        node->parent=child;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                node->mat[i][j]=mat[i][j]; //copy
            }
        }
        //swap
        swap(node->mat[x][y], node->mat[newX][newY]);
        //initializations
        node->cost=INT_MAX;
        node->level=level;
        node->x=newX;
        node->y=newY;

        return node;
    }

    int calculateCost(int initial[n][n], int final[n][n]){
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(initial[i][j] && initial[i][j]!=final[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }

    bool isSafe(int x, int y){
        if(x<0 || y<0 || x>=n || y>=n){
            return false;
        }
        return true;
    }

    void printMatrix(int mat[n][n]){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void printPath(Node* root){
        if(root==NULL){
            return;
        }
        printPath(root->parent);
        printMatrix(root->mat);
        cout<<endl;
    }

    struct comp{
        bool operator()(const Node* lhs, const Node* rhs)const{
            return (lhs->cost+lhs->level)>(rhs->cost, rhs->level);
        }
    };

    void solve(int initial[n][n], int x, int y, int final[n][n]){
        int row[]={-1, 0, 1, 0};
        int col[]={0, -1, 0, 1};

        priority_queue<Node*, vector<Node*>, comp> pq; //min heap

        Node* root=newNode(initial, x, y, x, y, 0, NULL);
        root->cost=calculateCost(initial, final);
        pq.push(root);

        while(!pq.empty()){
            Node* min=pq.top();
            pq.pop();

            if(min->cost==0){
                printPath(min);
                return;
            }

            for(int i=0; i<4; i++){
                if(isSafe(min->x+row[i], min->y+col[i])){
                    Node* child=newNode(min->mat, min->x, min->y, min->x+row[i], min->y+col[i], min->level+1, min);
                    child->cost=calculateCost(child->mat, final);
                    pq.push(child);
                }
            }
        }
    }
};


int main(){
    int initial[n][n]={
        {1,2,3},
        {0,4,6},
        {7,5,8}
    };
    int final[n][n]={
        {1,2,3},
        {4,5,6},
        {7,8,0}
    };
    int x=1, y=0;
    Solution s;
    s.solve(initial, x, y, final);
    return 0;
}