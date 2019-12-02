#include<bits/stdc++.h>
using namespace std;
class Item{
    public:
        double profit;
        double weight;
    public:
        Item(){
        }
};
bool compare(Item  obj1,Item obj2){
    double perunit1=obj1.profit/obj1.weight;
    double perunit2 = obj2.profit / obj2.weight;
    return perunit1>perunit2;
}
void knapsack(Item array[],int knapsack_size,int n)
{
    sort(array,array+n,compare);
    double solution[n];
    for(int i=0;i<n;i++)
    {
        solution[i]=0;
    }
    int u=knapsack_size;
    int i;
    for(i=0;i<n;i++)
    {
        if(array[i].weight>u)
            break;
        else
            solution[i]=1;
        u=u-array[i].weight;
    }
    if(i<n)
    {
        solution[i]=u/array[i].weight;
        double temp_p=array[i].profit;
        array[i].profit=solution[i]*temp_p;
        double temp_w = array[i].weight;
        array[i].weight = solution[i] * temp_w;
    }
    for(int i=0;i<n;i++)
    {
        if(solution[i]==0)
        {
            array[i].weight=0;
            array[i].profit=0;
        }
    }
    std::cout<<"Item Number"<<"\t"<<"Weight"<<"\t"<<"Profit"<<"\t"<<"Quantity Taken"<<endl;
    for(int i=0;i<n;i++)
    {
        std::cout<<i+1<<"\t\t"<<array[i].weight<<"\t"<<array[i].profit<<"\t"<<solution[i]<<endl;
    }
}
int main()
{
    int n;
    int knapsack_size;
    std::cout<<"Enter Number of Items:"<<endl;

    cin>>n;
    std::cout << "Enter Maximum Size of Knapsack:" << endl;
    cin>>knapsack_size;
    Item array[n];
    for(int i=0;i<n;i++)
    {
        std::cout<<"Enter Details of Item"<<i+1<<":"<<endl;
        std::cout<<"Enter weight:"<<endl;
        cin>>array[i].weight;
        std::cout << "Enter profit:" << endl;
        cin >> array[i].profit;
    }
    std::cout<<endl;
    std::cout<<"DETAILS OF ITEMS USED ARE SHOWN BELOW:"<<endl;
    std::cout<<endl;
    knapsack(array,knapsack_size,n);
    double total_profit=0.0;
    for(int i=0;i<n;i++)
    {
        total_profit+=array[i].profit;
    }
    cout<<"Maximum Profit: "<<total_profit;
    return 0;
}
