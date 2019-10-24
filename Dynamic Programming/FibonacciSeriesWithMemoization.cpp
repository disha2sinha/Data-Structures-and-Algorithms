#include<bits/stdc++.h>
using namespace std;
void initialization(int table[],int n){
    for (int i=0;i<n;i++)
    {
        table[i]=-1;
    }
}
int fibonacci(int table[],int n)
{
    if(table[n]==-1)
    {
        if(n<=1)
        {
            table[n]=n;
        }
        else
        {
            table[n]=table[n-1]+table[n-2];
        }
    }
    return table[n];
}

int main()
{
    int n;
    cout << "Enter The no. of terms:";
    cin >> n;
    int table[n];
    initialization(table,n);
    
    cout<<"Fibonacci Series:"<<"\n";
    for (int i=0;i<n;i++)
    {
        cout<<fibonacci(table,i)<<"\t";
    }
}