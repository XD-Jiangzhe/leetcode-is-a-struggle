/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {

        vector<Interval> result;

        if(intervals.empty())
        {
            result.push_back(newInterval);
            return result;
        }
        bool isInsert = false;
        int length  = intervals.size();
        for(int i=0; i<length; ++i)
        {
            if(result.empty())
               {
                   if(hasTheSame(intervals[i], newInterval))
                    {
                        isInsert = !isInsert;
                        auto temp = merge(intervals[i], newInterval);
                        result.push_back(temp);
                    }
                    else if(intervals[i].start<newInterval.start)
                        result.push_back(intervals[i]);
                        else {
                            result.push_back(newInterval);
                            result.push_back(intervals[i]);
                            isInsert = !isInsert;
                        }
                    
               }
            else 
            {
                auto& backOfInterval = result.back();
                if(!isInsert)
                {
                    if(hasTheSame(newInterval, intervals[i]))
                    {
                        auto temp = merge(newInterval, intervals[i]);
                        isInsert =!isInsert;
                        result.push_back(temp);
                    }
                    else 
                    {
                        if(newInterval.start < intervals[i].start)
                        {
                            result.push_back(newInterval);
                            result.push_back(intervals[i]);
                            isInsert = !isInsert;
                        }
                        else 
                            result.push_back(intervals[i]);
                    }
                    
                }
                else 
                {
                    if(hasTheSame(backOfInterval, intervals[i]))
                    {
                        backOfInterval = merge(backOfInterval, intervals[i]);
                    }
                    else 
                        result.push_back(intervals[i]);
                }
            }
        }
        if(!isInsert)
        {
            result.push_back(newInterval);
        }
        return result;

    }

    bool hasTheSame(Interval& first, Interval& second)
    {
        if(first.start<=second.end && second.start <=first.end)
            return true;
        else 
            return false;
    }

    Interval merge(Interval& first, Interval& second)
    {
        int min_start = min(first.start, second.start);
        int max_end = max(first.end, second.end);
        return Interval(min_start, max_end);
    }
};

int main()
{
    vector<Interval> intervals{{1,2},{3,5},{6,7},{8,10},{12,16}};
    Interval newInterval{4,9};
    
    Solution a;
    auto re = a.insert(intervals, newInterval);
    for(auto const& i: re)
    {
        cout<<i.start<<" "<<i.end<<endl;
    }
    return 0;
}