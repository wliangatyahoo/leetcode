// Source : https://oj.leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
// Author : Hao Chen
// Date   : 2014-12-01


/*
 * The API: int read4(char *buf) reads 4 characters at a time from a file.
 * 
 * The return value is the actual number of characters read. 
 * For example, it returns 3 if there is only 3 characters left in the file.
 * 
 * By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
 * 
 * Note:
 * The read function may be called multiple times.
 */


/*
 *  The key to solve this problem is: 
 *
 *    You have to buffer the extra data return from `read4()` API, which is for next call for `read()` .
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>

const char *p = "abcdefghijk";

// Forward declaration of the read4 API.
int read4(char *buf) {
    int s = 0;
    
    while (s < 4 && *p != '\0') {
        buf[s] = *p;
        p ++;
        s ++;
    }
    return s;
    
}

class Solution {
    int buf_offset, buf_size;
    char *buffer_read;
    
public:
    Solution ();
    
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int bytes_read_this_time = 0;
        bool eof = false;
        int length = 0;
        
        while (!eof && bytes_read_this_time < n) {
            if (buf_size == 0) {
                buf_size = read4(buffer_read);
                if (buf_size < 4) { eof = true; }
            }
            
            length = std::min(n - bytes_read_this_time, buf_size);
            strncpy(buf + bytes_read_this_time, buffer_read + buf_offset, length);
            buf[bytes_read_this_time + length] = '\0';
            
            buf_offset = (buf_offset + length) % 4;
            buf_size -= length;
            bytes_read_this_time += length;
        }
        
        return bytes_read_this_time;
    }
};

Solution::Solution () {
    buf_offset = 0;
    buf_size = 0;
    buffer_read = new char[4];
}

int main() {
    char buf[10];
    Solution sol;
    
    sol.read(buf, 3);
    sol.read(&buf[3], 4);
    printf("%s\n", buf);
    
    return 0;
}
