#include<bits/stdc++.h>
#include<string>
using namespace std;
int max(int x,int y)
{
    return (x>y)?x:y;
}
int LongestCommonSubsequence(string string1,string string2,int m,int n)
{
    int lcs[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0||j==0)
            {
                lcs[i][j]=0;
            }
            else if(string1.at(i-1)==string2.at(j-1))
            {
                lcs[i][j]=lcs[i-1][j-1]+1;
            }
            else
            {
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    int length= lcs[m - 1][n - 1];
    char sequence[length+1];
    int i=m-1;
    int j=n-1;
    while(i>0 && j>0)
    {
        if (string1.at(i - 1) == string2.at(j - 1))
        {
            sequence[length-1]=string1.at(i-1);
            i--;
            j--;
            length--;
        }
        else if(lcs[i-1][j]>lcs[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
        
        
    }
    cout<<"The Longest Common Subsequence of entered strings:"<<sequence<<"\n"; 
    return lcs[m-1][n-1];
}
int main()
{
    string string1;
    string string2;
    cout<<"Enter 1st String:\n";
    cin>>string1;
    cout<<"Enter 2nd String:\n";
    cin>>string2;
    int m=string1.size();
    int n=string2.size();
    int length=LongestCommonSubsequence(string1,string2,m,n);
    cout<<"So Length of Longest Common Subsequence:"<<length;
}