#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<int> findDuplicates(vector<int> &nums)
{
    set<int> s1;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!s1.insert(nums[i]).second)
        {
            result.push_back(nums[i]);
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
