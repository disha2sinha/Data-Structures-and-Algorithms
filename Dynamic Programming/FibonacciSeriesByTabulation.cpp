#include<bits/stdc++.h>
using namespace std;
void fibonacci(int n)
{
    int table[n+1];
    table[0]=0;
    table[1]=1;
    cout<<table[0]<<"\t"<<table[1]<<"\t";
    for(int i=2;i<n;i++)
    {
        table[i]=table[i-1]+table[i-2];
        cout<<table[i]<<"\t";
    }
}

int main()
{
    int n;
    cout << "Enter The no. of terms:";
    cin >> n;
    cout<<"Fibonacci Series:"<<"\n";
    fibonacci(n);
}