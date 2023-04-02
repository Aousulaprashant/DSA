#include "bits/stdc++.h"
using namespace std;
bool notclash(vector<vector<char>>& board,int n,int i,int j,char num){
    for(int k=0;k<n;j++){
        if(board[i][k]==num)return false;
        if(board[k][j]==num)return false;
     }    
            int s=sqrt(n);
            int sr=i-i%s;
            int sc=j-j%s;
            for(int r=sr;r<sr+s;r++)
            {
                for(int c=sc;c<sc+s;c++)
                {
                    if(board[r][c]==num)return false;
                }
            }
            return true;
}

int main(){
    
}