#include <iostream>
#include <vector>
using namespace std;
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[abs(nums[i]) - 1] < 0)
        {
            result.push_back(abs(nums[i]));
        }
        else
        {
            nums[abs(nums[i]) - 1] = nums[abs(nums[i]) - 1] * (-1);
        }
    }
    return result;
}
int main()
{
    vector<int> nums;
    int N;
    cout<<"Enter number of elements: "<<endl;
    cin>>N;
    int element;
    for(int i=0;i<N;i++)
    {
        cout << "Enter element: " << endl;
        cin>>element;
        nums.push_back(element);
    }
    vector<int> result=findDuplicates(nums);
    cout<<"Duplicates :"<<endl;
    for (int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
}
