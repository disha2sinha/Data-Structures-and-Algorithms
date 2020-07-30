#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int result;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i)
        {
            result = i;
            break;
        }
    }
    return result;
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
    int result = missingNumber(nums);
    cout << "Missing Number : " << result;
}
