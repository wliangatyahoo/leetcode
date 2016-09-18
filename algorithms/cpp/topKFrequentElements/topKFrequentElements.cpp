// Source : https://leetcode.com/problems/top-k-frequent-elements/
// Author : Calinescu Valentin
// Date   : 2016-05-02

/*************************************************************************************** 
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the 
 * array's size.
 * 
 ***************************************************************************************/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i])==m.end()) {
                m[nums[i]] = 1;
            } else {
                m[nums[i]]++;
            }
        }
        int maxF = 0;
        for (auto it:m) {
            maxF = max(maxF, it.second);
        }
        vector<vector<int>> list(maxF);
        for (auto it:m) {
            list[it.second-1].push_back(it.first);
        }
        vector<int>result;
        for (int i = maxF-1; i >= 0; i--) {
            if (list[i].size()>0) {
                for (int j = 0; j < list[i].size();j++) {
                    result.push_back(list[i][j]);
                    if (result.size() >= k) {
                        return result;
                    }
                }
            }
        }
        return result;
    }
};
