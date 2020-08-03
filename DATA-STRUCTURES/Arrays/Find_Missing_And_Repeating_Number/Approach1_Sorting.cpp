#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void missingRepeatingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int result;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i-1]+1)
        {
            cout<<"Missing Number :"<<nums[i-1]+1<<endl;
        }
    }
    for(int i=0;i<nums.size()-1;i++)
    {
        if (nums[i]==nums[i+1])
        {
            cout << "Repeating Number:" <<nums[i]<<endl;
            break;
        }
    }
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
