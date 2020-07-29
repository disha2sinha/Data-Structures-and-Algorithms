#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
void sortColors(vector<int> &nums)
{
    int left = 0;
    int mid = 0;
    int right = nums.size() - 1;
    while (mid <= right)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[left]);
            mid++;
            left++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[right]);
            right--;
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
    sortColors(nums);
    cout << "Duplicates :" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}
