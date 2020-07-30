#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int missingNumber(vector<int> &nums)
{
    int expected = nums.size() * (nums.size() + 1) / 2;
    int actual = 0;
    for (int num : nums)
        actual += num;
    return expected- actual;
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
