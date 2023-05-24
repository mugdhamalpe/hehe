//assign 3 - selection sort

#include <bits/stdc++.h>

using namespace std;

void selection_sort(vector<int> &vec, int n){
    int min_idx=0;
    for(int i=0; i<n-1; i++){
        min_idx=i;
        for(int j=i+1; j<n; j++){
            if(vec[j]<vec[min_idx]){
                min_idx=j;
            }
        }
        if(min_idx!=i){
            swap(vec[min_idx], vec[i]);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    selection_sort(vec, n);
    cout<<"After sorting : "<<endl;
    for(int i=0; i<n; i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}