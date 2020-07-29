#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> findDuplicates(vector<int> &nums)
{
        vector<int> result;
        if (nums.size() == 0)
        {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                result.push_back(nums[i]);
                i++;
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
    vector<int> result = findDuplicates(nums);
    cout << "Duplicates :" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}
