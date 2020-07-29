#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
void sortColors(vector<int> &nums)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            count0++;
        else if (nums[i] == 1)
            count1++;
        else
            count2++;
    }
    int i = 0;
    while (count0 > 0)
    {
        nums[i] = 0;
        i++;
        count0--;
    }
    while (count1 > 0)
    {
        nums[i] = 1;
        i++;
        count1--;
    }
    while (count2 > 0)
    {
        nums[i] = 2;
        i++;
        count2--;
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
