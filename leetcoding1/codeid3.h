#ifndef CODEID3_H
#define CODEID3_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace CodeID3 {


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int retMaxLen = 0;
        int indexBegin = 0;
        int indexNext = 0;
        vector<int> vecHasShowChar(128, -1); // 已经出现的字符的位置
        for(indexNext = 0; indexNext < s.length(); ++indexNext)
        {
            char endChar = s[indexNext];
            if(vecHasShowChar[endChar] != -1)
            {
                // 说明当前字符出现过
                // 更新其实位置
                indexBegin = max(indexBegin, vecHasShowChar[s[indexNext]] + 1);
            }

            // 计算最大长度
            auto tempLen = indexNext - indexBegin + 1;
            retMaxLen = max(retMaxLen, tempLen);

            // 更新出现字符位置
            vecHasShowChar[s[indexNext]] = indexNext;
        }

        return retMaxLen;
    }

    int lengthOfLongestSubstring1(string s) {
        int retMaxLen = 0;
        int indexBegin = 0;
        int indexNext = 0;
        for(indexNext = 0; indexNext < s.length(); ++indexNext)
        {
            for (auto i = indexBegin;i <= indexNext; ++i)
            {
                auto begChar = s[i];
                auto endChar = s[indexNext];

                if((begChar == endChar) && (i != indexNext))
                {
                    indexBegin = i + 1;
                    continue;
                }
            }

            auto tempLen = indexNext - indexBegin + 1;
            retMaxLen = max(retMaxLen, tempLen);
        }

        return retMaxLen;
    }

    static void testLengthOfLongestSubstring()
    {
        Solution s;
        string testStr = "abba";
//        string testStr = "dvdf";
        cout << testStr <<  " max length: " << s.lengthOfLongestSubstring(testStr) << endl;

        testStr = "abcabcbb";
        cout << testStr <<  " max length: " << s.lengthOfLongestSubstring(testStr) << endl;

        testStr = "bbbbb";
        cout << testStr <<  " max length: " << s.lengthOfLongestSubstring(testStr) << endl;
    }

};

}

#endif // CODEID3_H
