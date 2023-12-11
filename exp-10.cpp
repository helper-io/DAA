#include <bits/stdc++.h>
using namespace std;
int countt=0;

bool leftDiagonal[30]={0};
bool rightDiagonal[30]={0};
bool column[30]={0};

void print(int board[][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-----------------\n";
}

bool isValid(int board[][8],int row,int col){
    if(leftDiagonal[row-col+7]!=1&&rightDiagonal[row+col]!=1&&column[row]!=1)
    return true;
    return false;
}

void ninjaQueens(int board[][8],int currentColumn){
    if(currentColumn>=8)
    return;
    
    for(int i=0;i<8;i++){
        if(isValid(board,i,currentColumn)){
            board[i][currentColumn]=1;
            leftDiagonal[i-currentColumn+7]=rightDiagonal[i+currentColumn]=column[i]=1;
            if(currentColumn==7){
                print(board);
                countt++;
            }
            
            ninjaQueens(board,currentColumn+1);
           
            board[i][currentColumn]=0;
            leftDiagonal[i-currentColumn+7]=rightDiagonal[i+currentColumn]=column[i]=0;
        }
   
    }
}
int main() {
    
    
    int board[8][8]={{0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0}};
    ninjaQueens(board,0);
    
    cout<<countt<<endl;
    return 0;
}