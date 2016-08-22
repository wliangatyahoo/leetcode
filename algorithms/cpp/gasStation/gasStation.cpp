// Source : https://oj.leetcode.com/problems/gas-station/
// Author : Hao Chen
// Date   : 2014-10-11

/********************************************************************************** 
* 
* There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
* 
* You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to 
* its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
* 
* Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
* 思路：

这题要想清楚不容易，尽管想清楚后代码写起来很简单。

I.  显然当gas[i]<cost[i]时，i不能作为起点。

II. 当对所有加油站求和：sum(gas[i] - cost[i]) <0时，无法环绕一圈。反之，则一定能环绕一圈。

问题是如果可以环绕一圈，如何找起点？

性质1. 对于任意一个加油站i，假如从i出发可以环绕一圈，则i一定可以到达任何一个加油站。显而易见。

性质2. 如果这样的i是唯一的，则必然不存在j!=i， 从j出发可以到达i。

反证法：如果存在这样的j，则必然存在j->i->i的路径，而这个路径会覆盖j->j一周的路径。那么j也将是一个符合条件的起点。与唯一解的限制条件矛盾。

性质3. 假如i是最后的解，则由1可知，从0 ~ i-1出发无法达到i。而从i出发可以到达i+1 ~ n-1。

结合以上三条性质，得出解决的思路：

0. 如果对所有加油站的sum(gas[i] - cost[i])<0，则无解。否则进入1。

1. 从0开始计算sum(gas[i] - cost[i])，当遇到i1使sum<0时，说明从0出发无法到达i1。根据性质1，0不是起始点。而由于从0出发已经到达了1 ~ i1-1。根据性质2，1 ~ i1-1一定不是正确的起始点。此时i1为起始点的候选。

2. 将sum清0，并从i1出发，假如又遇到i2使sum(gas[i] - cost[i]) < 0 时，说明i1出发无法绕一圈，更具性质1，排除i1。又因为i1+1 ~ i2-1都能从i1出发到达,。根据性质2，它们也必然不是起始点。此时i2为起始点的候选。

3. 以此类推，直到遇到ik，使从ik出发可以到达ik+1 ~ n-1。

其中步骤0可以合并到1~3的扫描中，一个pass来得到解。
* Note:
* The solution is guaranteed to be unique.
* 
*               
**********************************************************************************/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start = 0, netGasSum = 0, curGasSum = 0;
        for(int i=0; i<cost.size(); i++) {
            netGasSum += gas[i] - cost[i];
            curGasSum += gas[i] - cost[i];
            if(curGasSum<0) {
                start = i+1;
                curGasSum = 0;
            }
        } 
        if(netGasSum < 0) return -1;
        return start;
    }
};
