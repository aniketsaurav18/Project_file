#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int row,col;
    cin>>row>>col;
    cout<<endl;
    int a[row][col];
    vector<vector<int>>v;
    vector<int>temp;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>a[i][j];
            if(a[i][j]==0){
                temp.push_back(i);
                temp.push_back(j);
                v.push_back(temp);
                temp.clear();
            }
        }
    }
    for(int i=0;i<v.size();i++){
        for(int j=0;j<row;j++){
            a[v[i][0]][j]=0;
        }
        for(int j=0;j<row;j++){
            a[j][v[i][1]]=0;
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }






    return 0;
}