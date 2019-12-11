#include<bits/stdc++.h>
using namespace std;

int *prefix_function(char *pattern)
{
    int m = strlen(pattern);
    int *pi=new int(m);
    *pi= -1;
    int k = -1;
    for (int j = 1; j < m; j++)
    {
        while (k > -1 && pattern[k + 1] != pattern[j])
        {
            k = *(pi+k);
        }
        if (pattern[k + 1] == pattern[j])
        {
            k = k + 1;
        }
        *(pi+j) = k;
    }
    for (int i = 0; i < m; i++)
    {
        cout << *(pi+i);
    }
    return pi;
}
void KMP_matcher(char *text,char *pattern)
{
    int n=strlen(text);
    int m=strlen(pattern);
    int *pi=new int(m);
    pi=prefix_function(pattern);
    
    int j=-1;//number of chars matched
    for(int i=0;i<n;i++)
    {
        while(j>=0 && pattern[j+1]!=text[i])
        {
            j=pi[j];//next char doesnot match
        }
        if(pattern[j+1]==text[i])
        {
            j=j+1;
        }
        if(j==m-1)
        {
            cout<<"Pattern found at position "<< i-m+2<<endl;
            j = pi[j];
        }
    }
}


int main()
{
    char text[30];
    char pattern[15];
    cout<<"Enter Text:"<<endl;
    cin>>text;
    cout<<"Enter Pattern:"<<endl;
    cin>>pattern;
    KMP_matcher(text,pattern);
    return 0;


}
