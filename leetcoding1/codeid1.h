#ifndef CODEID1_H
#define CODEID1_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

namespace CodeID1
{
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {

            vector<int> retIndex;
            for(auto i = 0; i < nums.size(); ++i)
            {
                for (auto j = i + 1; j < nums.size(); ++j)
                {
                    if(nums[i] + nums[j] == target)
                    {
                        retIndex.push_back(i);
                        retIndex.push_back(j);
                        break;
                    }
                }
            }

            return retIndex;
        }

        vector<int> twoSum2(vector<int>& nums, int target) {
            // 定义hash表
            map<int, int> mapOtherIndex;
            for (auto i = 0;i < nums.size(); ++i) {
                mapOtherIndex[nums[i]] = i;
            }
            vector<int> retIndex;
            for(auto i = 0; i < nums.size(); ++i)
            {
                auto anotherVal = target - nums[i];
                if(mapOtherIndex.find(anotherVal) != mapOtherIndex.end()
                        && i != mapOtherIndex[anotherVal])
                {
                    retIndex.push_back(i);
                    retIndex.push_back(mapOtherIndex[anotherVal]);
                    break;
                }
            }

            return retIndex;
        }

        vector<int> twoSum3(vector<int>& nums, int target) {
            // 定义hash表
            map<int, int> mapOtherIndex;
            vector<int> retIndex;
            for(auto i = 0; i < nums.size(); ++i)
            {
                auto anotherVal = target - nums[i];
                if(mapOtherIndex.find(anotherVal) != mapOtherIndex.end()
                        && i != mapOtherIndex[anotherVal])
                {
                    retIndex.push_back(mapOtherIndex[anotherVal]);
                    retIndex.push_back(i);
                    break;
                }

                mapOtherIndex.insert(std::map<int,int>::value_type(nums[i], i));
            }

            return retIndex;
        }

        static void testTwoSum()
        {
            Solution s;
            vector<int> testVec = {2, 7, 11, 15};
            auto ret = s.twoSum3(testVec, 9);

            for (auto i = 0; i < ret.size(); ++i) {
                cout << ret[i] << ' ';
            }
            cout << endl;
        }
    };

}
#endif // CODEID1_H
