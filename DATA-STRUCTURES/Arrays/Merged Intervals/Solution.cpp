#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>> merge(vector<pair<int,int>>& intervals) {
    vector<pair<int,int>> mergedIntervals;
    if (intervals.size()==0)
    {
        return mergedIntervals;
    }
    sort(intervals.begin(),intervals.end());
    pair<int,int> tempintervals=intervals[0];
    for (auto interval : intervals)
    {
        if(interval.first<=tempintervals.second)
        {
            tempintervals.second=max(interval.second,tempintervals.second);
        }
        else
        {
            mergedIntervals.push_back(tempintervals);
            tempintervals=interval;
        }
    }
    mergedIntervals.push_back(tempintervals);
    return mergedIntervals;
        
}
int main()
{
    vector<pair<int,int>> Intervals;
    pair<int,int> interval;
    int N;
    cout<<"Enter number of intervals:"<<endl;
    cin>>N;
    for (int i=0;i<N;i++)
    {
        cout<<"Enter interval:"<<endl;
        cin>>interval.first>>interval.second;
        Intervals.push_back(interval);
    }
    vector<pair<int,int>> mergedIntervals = merge(Intervals);
    for (auto it : mergedIntervals)
    {
        cout<<it.first<<","<<it.second<<endl;
    }

}
