//CSP - n queens

#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> ans;

void recur(int col, int n, vector<int> &row, vector<int> &left, vector<int> &right, vector<string> &path){
    //base condition
    if(col==n){
        //reached at end column- has all paths
        ans.push_back(path);
        return;
    }
    //logic
    for(int i=0; i<n; i++){
        if(!row[i] && !left[col+i] && !right[n-1+col-i]){
            row[i]=1;
            left[col+i]=1;
            right[n-1+col-i]=1;
            path[i][col]='Q';

            recur(col+1, n, row, left, right, path);

            path[i][col]='.';
            right[n-1+col-i]=0;
            left[col+i]=0;
            row[i]=0;
        }
    }
}

vector<vector<string>> solveQueens(int n){
    vector<string> path(n);
    string s(n, '.');
    for(int i=0; i<n; i++){
        path[i]=s;
    }
    vector<int> row(n);
    vector<int> left(2*n-1);
    vector<int> right(2*n-1);
    recur(0, n, row, left, right, path);
    return ans;
}

int main(){
    cout<<"Enter the n (to create n*n matrix) : ";
    int n;
    cin>>n;
    vector<vector<string>> result;
    result=solveQueens(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<result[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}