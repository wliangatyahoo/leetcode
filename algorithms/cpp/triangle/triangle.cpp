// Source : https://oj.leetcode.com/problems/triangle/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 
* Given a triangle, find the minimum path sum from top to bottom. 
* Each step you may move to adjacent numbers on the row below.
* 
* For example, given the following triangle
* 
* [
*      [2],
*     [3,4],
*    [6,5,7],
*   [4,1,8,3]
* ]
* 
* The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
* 
* Note:
* Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
* 
*               
**********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (!triangle.size()) return 0;
        int maxval=triangle[0][0];
        
        for (int row = 1; row < triangle.size(); ++row) {
            maxval = INT_MAX;
            for (int i = row; i >= 0; i--) {
                if (i == 0 ) {
                    triangle[row][i] += triangle[row-1][i];
                } else if (i == row) {
                    triangle[row][i] += triangle[row-1][i-1];
                } else {
                    triangle[row][i] += min(triangle[row-1][i-1], triangle[row-1][i]);
                }
                maxval = min(maxval, triangle[row][i]);
            }
        }
        
        return maxval;
    }
private:
    inline int min(int x, int y, int z){
        int n = x<y?x:y;
        return (n<z?n:z);
    }
};


int main()
{
    vector< vector<int> > v;
    vector<int> i;
    i.push_back(-1);
    v.push_back(i);
    
    i.clear();
    i.push_back(2);
    i.push_back(3);
    v.push_back(i);

    i.clear();
    i.push_back(1);
    i.push_back(-1);
    i.push_back(-3);
    v.push_back(i);

    Solution s;
    cout << s.minimumTotal(v) << endl;;
    
    v.clear();
    i.clear();
    i.push_back(-1);
    v.push_back(i);
    
    i.clear();
    i.push_back(3);
    i.push_back(2);
    v.push_back(i);

    i.clear();
    i.push_back(-3);
    i.push_back(1);
    i.push_back(-1);
    v.push_back(i);
    cout << s.minimumTotal(v) << endl;;

    return 0;
}
