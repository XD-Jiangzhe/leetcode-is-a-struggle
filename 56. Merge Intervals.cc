/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
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
    vector<Interval> merge(vector<Interval>& intervals) {

        vector<Interval> result;
        sort(intervals.begin(), intervals.end(), [](Interval first, Interval second){return first.start < second.start;});
        for(int i=0; i<intervals.size(); ++i)
        {
            if(result.empty())
            {
                result.push_back(intervals[i]);         
            }    
            else 
            {
                Interval& backOFIntervals = result.back();
                if(intervals[i].start <=backOFIntervals.end)
                {
                    if(backOFIntervals.end <=intervals[i].end)
                    {
                        backOFIntervals.end = intervals[i].end;
                    }
                }
                else 
                {
                    result.push_back(intervals[i]);
                }
            }
        }
        return result;
    }
};

int main()
{

    Solution a;
    vector<Interval> temp={{1,3},{2,6},{8,10},{15,18}};
    auto re = a.merge(temp);
    for(auto const& i: re)
        cout<<i.start<<endl;

    return 0;
}