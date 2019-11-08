#include<bits/stdc++.h>
using namespace std;
int bracket[100][100];
void PrintBrackets(int i,int j,int n,int bracket[][100],char &matrix)
{
    if(i==j)
    {
        cout<<matrix++;
        return;
    }
    cout<<"(";
    PrintBrackets(i,bracket[i][j],n,bracket,matrix);
    PrintBrackets(bracket[i][j]+1,j, n, bracket, matrix);
    cout<<")";
}
int ChainMatrix(int p[],int n)
{
    int m[n][n];
    for(int i=1;i<=n;i++)
    {
        m[i][i]=0;
    }
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            m[i][j]=36575;
            for (int k=i;k<=j-1;k++)
            {
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    bracket[i][j]=k;
                }            
            }
        }
    }
    char matrix = 'A';
    cout << "Optimal Parenthization:";
    PrintBrackets(1, n, n, bracket, matrix);

    return m[1][n];
}
int main()
{
    int n;
    cout<<"Enter number of matrix:";
    cin>>n;
    int p[n+1];
    for(int i=0;i<n+1;i++)
    {
        if(i<n)
        {
            cout<<"Enter row of "<<i+1<<"th matrix:";
            cin>>p[i];
        }
        else
        {
            cout<<"Enter column of "<<i<<"th matrix:";
            cin>>p[i];
        }
    }
    int operations=ChainMatrix(p,n);
    cout<<endl;
    cout<<"The Number Of Multiplications required:"<<operations;
}