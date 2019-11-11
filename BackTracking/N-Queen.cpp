#include<bits/stdc++.h>
using namespace std;
#define N 8
bool canbeplaced(int chessboard[N][N],int row,int col)
{
    int i,j;
    //same col
    for (int i=0;i<row;i++)
    {
        if(chessboard[i][col])
        return false;

    }
    //upper diagonal on left
    for( i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
    {
        if(chessboard[i][j])
            return false;
    }
    //upper diagonal on right
    for(i=row-1,j=col+1;i>=0&&j<N;i--,j++)
    {
        if (chessboard[i][j])
            return false;
    }
    return true;
}
bool N_Queen(int chessboard[N][N],int row)
{
    if (row>=N)
    {
        return true;
    }
    for(int i=0;i<N;i++)
    {
        if (canbeplaced(chessboard,row,i))
        {
            chessboard[row][i]=row+1;
            if(N_Queen(chessboard,row+1)){
                return true;
            }
            chessboard[row][i] = 0;
        }
    }

    return false;
}
void printSolution(int chessboard[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if (chessboard[i][j]==0)
            {
                cout<<chessboard[i][j]<<"\t";
            }
            else
            {
                cout<<"Q"<<chessboard[i][j]<<"\t";
            }
            
        }
        cout<<endl;
        cout<<endl;
    }
}
int main()
{
    int chessboard[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            chessboard[i][j]=0;
        }
    }
    if(N_Queen(chessboard,0)==false)
    {
        cout<<"Solution doesn't exist";
    }
    else
    {
        cout<<"Queens are placed as follows:"<<endl;
        cout<<endl;
        printSolution(chessboard);
        cout << endl;
    }
    return 0;
    
}
