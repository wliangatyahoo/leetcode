// Source : https://oj.leetcode.com/problems/dungeon-game/
// Author : Hao Chen
// Date   : 2015-01-16

/********************************************************************************** 
 * 
 * The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. 
 * The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned 
 * in the top-left room and must fight his way through the dungeon to rescue the princess. 
 *
 * The knight has an initial health point represented by a positive integer. 
 * If at any point his health point drops to 0 or below, he dies immediately. 
 *
 * Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; 
 * other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
 * In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step. 
 * 
 * Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
 * For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path 
 * RIGHT-> RIGHT -> DOWN -> DOWN.
 * 
 *   
 *   +------+------+------+
 *   |      |      |      |
 *   | -2(K)|  -3  |  3  |
 *   |      |      |      |
 *   +--------------------+
 *   |      |      |      |
 *   |  -5  | -10  |   1  |
 *   |      |      |      |
 *   +--------------------+
 *   |      |      |      |
 *   |  10  |  30  | -5(P)|
 *   |      |      |      |
 *   +------+------+------+
 *   
 * 
 * Notes:
 * 
 * The knight's health has no upper bound.
 * Any room can contain threats or power-ups, 
 * even the first room the knight enters and the bottom-right room where the princess is imprisoned.  
 * 
 * Credits:Special thanks to @stellari for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

class Solution {
    public:
        int calculateMinimumHP(vector<vector<int> > &dungeon) {
	        if (dungeon.size() == 0) return 0;
	        int row = dungeon.size();
	        int col = dungeon[0].size();
	        int dp[row][col] = {0};
	        dp[row-1][col-1] = max(1, 1-dungeon[row-1][col-1]);
	        for(int i=row-2; i >= 0; i—-) {
		        dp[i][col-1] = max(1, dp[i+1][col-1] - dungeon[i][col-1]);
	        }
	        for(int j=col-2; j >= 0; j—-) {
		        dp[row-1][j] = max(1, dp[row-1][j+1] - dungeon[row-1][j]);
	        }
	        for(int i = row-2; i>=0; i—-) {
		        for(int j = col-2; j>=0; j—-) {
			        dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1])-dungeon[i][j]);
		        }
	        }
	        return dp[0][0];
        }
};
