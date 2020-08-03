#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void missingRepeatingNumber(vector<int> &nums)
{
    int xor_result=0;
    int x=0;
    int y=0;
    for (int i=0;i<nums.size();i++)
    {
        xor_result=xor_result^nums[i];
    }
    for (int i=1;i<=nums.size();i++)
    {
        xor_result=xor_result^i;
    }
    int set_bit= xor_result & ~(xor_result - 1);
    for (int i=0;i<nums.size();i++)
    {
        if (nums[i] & set_bit !=0)
            x = x ^ nums[i];
        else
        {
            y = y ^ nums[i];
        }   
    }
    for (int i = 1; i <= nums.size(); i++)
    {
        if (i & set_bit != 0)
            x = x ^ i;
        else
        {
            y = y ^ i;
        }
    }
    cout<<"Missing Number :"<<x<<endl;
    cout << "Repeating Number :" << y << endl;
}
int main()
{
    vector<int> nums;
    int N;
    cout << "Enter number of elements: " << endl;
    cin >> N;
    int element;
    for (int i = 0; i < N; i++)
    {
        cout << "Enter element: " << endl;
        cin >> element;
        nums.push_back(element);
    }
    missingRepeatingNumber(nums);
}
