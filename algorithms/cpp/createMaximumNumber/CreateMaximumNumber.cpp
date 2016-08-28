// Source : https://leetcode.com/problems/create-maximum-number/
// Author : Hao Chen
// Date   : 2016-01-21

/*************************************************************************************** 
 *
 * Given two arrays of length m and n with digits 0-9 representing two numbers.
 *     Create the maximum number of length k  from digits of the two. The relative 
 * order of the digits
 *     from the same array must be preserved. Return an array of the k digits. You 
 * should try to optimize your time and space complexity.
 * 
 *     Example 1:
 * 
 *     nums1 = [3, 4, 6, 5]
 *     nums2 = [9, 1, 2, 5, 8, 3]
 *     k = 5
 *     return [9, 8, 6, 5, 3]
 * 
 *     Example 2:
 * 
 *     nums1 = [6, 7]
 *     nums2 = [6, 0, 4]
 *     k = 5
 *     return [6, 7, 6, 0, 4]
 * 
 *     Example 3:
 * 
 *     nums1 = [3, 9]
 *     nums2 = [8, 9]
 *     k = 3
 *     return [9, 8, 9]
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/



/*
 * Solution
 * --------
 * 
 * 1) We split the `K` to two parts : `i` & `k-i`  0<= i <= k
 * 
 * 2) Find the max number for both arrays with giving the length `i` and `k-i`
 *      - sub1 = FindMaxNumber(num1, len=i);
 *      - sub2 = FindMaxNumber(num2, len=k-i);
 *    Here, we need use stack-way to solve find the max number.
 * 
 * 3) Merge two arrays 
 *      - solution = Merge(sub1, sub2);
 *    Here, we need be careful if a two number are same which one we need to take.  For examples: 
 *      [6,7]
 *      [6,0,4]
 *      5
 *      
 *      [2,5,6,4,4,0]
 *      [7,3,8,0,6,5,7,6,2]
 *      15
 * 
 * 4) compare with the last solution
 *     - result = max(result, solution); 
 * 
 * 
 */


class Solution {
public:
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> ans(k, 0);
		for (int i = max(0, k - (int)nums2.size()); i <= min(k, (int)nums1.size()); i++) {
			vector<int> res1 = get_max_sub_array(nums1, i);
			vector<int> res2 = get_max_sub_array(nums2, k - i);
			vector<int> res(k, 0);
			int pos1 = 0, pos2 = 0, tpos = 0;
			while (pos1 < res1.size() || pos2 < res2.size()) {
				res[tpos++] = greater(res1, pos1, res2, pos2) ? res1[pos1++] : res2[pos2++];
			}
			if (!greater(ans, 0, res, 0))
				ans = res;
		}
		return ans;
	}
 
	bool greater(const vector<int> & a, int start1, const vector<int> &b, int start2) {
		for (; start1 < a.size() && start2 < b.size(); start1++, start2++) {
			if (a[start1] > b[start2]) return true;
			if (a[start1] < b[start2]) return false;
		}
		return start1 != a.size();
	}
 
	vector<int> get_max_sub_array(const vector<int> &nums, const int& k) {
		vector<int> res(k,0);
		int len = 0 , n = nums.size();
		for (int i = 0; i < n; i++) {
			while (len && len + n - i > k && nums[i] > res[len - 1])
				len--;
			if (len < k)
				res[len++] = nums[i];
		}
		return res;
	}
    
};
