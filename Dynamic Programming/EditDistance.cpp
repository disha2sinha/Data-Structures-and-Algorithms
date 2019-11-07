#include<bits/stdc++.h>
using namespace std;

int EditDistance(string string1,string string2,int m,int n)
{
    int table[m+1][n+1];
    cout<<"Table:"<<"\n";

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if (i==0)
            {
                table[i][j]=j;
            }
            else if (j==0)
            {
                table[i][j]=i;
            }
            else if(string1.at(i-1)==string2.at(j-1))
            {
                table[i][j]=table[i-1][j-1];
            }
            else
            {
                table[i][j]=1+min(min(table[i][j-1],table[i-1][j]),table[i-1][j-1]);
            }
            cout<<table[i][j]<<"\t";
            
        }
        cout<<"\n";
    }
    int i=m;
    int j=n;
    cout<<"Operations to be performed on "<<string1<<"\n";
    while(i>0 && j>0)
    {
        if (string1.at(i-1)==string2.at(j-1))
        {
            i--;
            j--;
        }
        else if (table[i][j]==table[i-1][j-1]+1)
        {
            cout<<"Replaced "<<string1.at(i-1)<<" to "<<string2.at(j-1)<<"\n";
            i--;
            j--;
        }
        else if(table[i][j]==table[i][j-1]+1)
        {
            cout<<string2.at(j-1)<<" Added to "<<string1<<"\n";
            j--;
        }
        else if (table[i][j] == table[i-1][j] + 1)
        {
            cout<<string1.at(i-1)<<" deleted "<<"\n";
            i--;
        }
    }
    return table[m][n];
}
int main()
{
    string string1;
    string string2;
    cout << "Enter 1st String:\n";
    cin >> string1;
    cout << "Enter 2nd String:\n";
    cin >> string2;
    int m = string1.size();
    int n = string2.size();
    int length = EditDistance(string1, string2, m, n);
    cout << "No. of Operations required:" << length;
}