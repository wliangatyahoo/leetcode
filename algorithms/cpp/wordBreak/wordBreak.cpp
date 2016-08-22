// Source : https://oj.leetcode.com/problems/word-break/
// Author : Hao Chen
// Date   : 2014-07-01

/********************************************************************************** 
* 
* Given a string s and a dictionary of words dict, determine if s can be segmented 
* into a space-separated sequence of one or more dictionary words.
* 
* For example, given
* s = "leetcode",
* dict = ["leet", "code"].
* 
* Return true because "leetcode" can be segmented as "leet code".
* 
*               
**********************************************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool wordBreak(string s, set<string> &dict) {

	  vector<bool> match(s.size()+1, false);
	  match[0] = true; //initial state so we can move forward
	  for (int i = 0; i<s.size(); ++i)
	  {
	       if (match[i]) {
	        for (const auto &x:dict) {
	           int end = x.size() + i;
	           if (end <= s.length() && (s.substr(i, x.size()) == x)) {
                    match[end] = true;
	          }
	       }
	    }
	  }
	  return match[s.size()];
}


int main()
{
    string s; 
    set<string> dict;

    s = "a";
    dict.insert("a");
    cout << wordBreak(s, dict) << endl;
    
    dict.clear();
    s = "dogs";
    string d[]={"dog","s","gs"};
    dict.insert(d, d+3);
    cout << wordBreak(s, dict) << endl;

    return 0;
}
