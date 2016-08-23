// Source : https://oj.leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
// Author : Hao Chen
// Date   : 2014-12-01

/*
 * Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
 * 
 * For example, Given s = “eceba”,
 * 
 * T is "ece" which its length is 3.
 */



#include <iostream>
#include <string>
using namespace std;


/*
 * Idea:
 *
 *    1) Using a map to count every char(s).
 *    2) Using a 'cnt' to count the current distinct chars.
 *    3) If `cnt > 2`, then go through the previous substring to decrease each char's count which stored in the map,
 *       if one of char's count decrease to zero, then the global distinct chars `cnt` decrease one.
 *       During the travel, maintain a pointer `start` to point the start position of sub-string.
 *
 * The following algorithm run-time complexity is O(n^2)
 *
 * This solution can be easy to extend to "find the length of longest substring with at most K distinct char(s)"
 */
int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            ++m[s[i]];
            while (m.size() > k) {
                if (--m[s[left]] == 0) m.erase(s[left]);
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;
}


int main(int argc, char** argv)
{
    string s = "eceba";
    if (argc>1){
        s = argv[1];
    }
    cout << s << " : " << lengthOfLongestSubstringTwoDistinct(s) << endl;

    return 0;
}
