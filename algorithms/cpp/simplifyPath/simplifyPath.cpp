// Source : https://oj.leetcode.com/problems/simplify-path/
// Author : Hao Chen
// Date   : 2014-10-09

/********************************************************************************** 
* 
* Given an absolute path for a file (Unix-style), simplify it.
* 
* For example,
* path = "/home/", => "/home"
* path = "/a/./b/../../c/", => "/c"
* 
* 
* Corner Cases:
* 
* Did you consider the case where path = "/../"?
* In this case, you should return "/".
* Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
* In this case, you should ignore redundant slashes and return "/home/foo".
* 
*               
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


string simplifyPath(string path) {

   stack<string> stk;
        while (!path.empty())
        {
            int id = path.find_first_of('/');
            string tem; //next file name
            if (id == -1) tem = path, path = "";
            else tem = path.substr(0, id), path = path.substr(id + 1);
            
            if (tem == "." || tem.size() == 0) continue; //current directory
            else if (tem == "..")    //previous directory
            {
                if (!stk.empty()) stk.pop();
            } //next directory
            else 
                stk.push(tem);

        }
       
        string ans;
        while (!stk.empty())
            ans = "/" + stk.top() + ans, stk.pop();
            
        return ans.empty() ? "/" : ans; //root only

        
}

int main(int argc, char** argv)
{
    string path("/a/./b/../../c/");
    if (argc > 1 ){
        path = argv[1];
    }

    cout << path << " : " << simplifyPath(path) << endl;
}
