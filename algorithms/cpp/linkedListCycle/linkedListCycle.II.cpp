// Source : https://oj.leetcode.com/problems/linked-list-cycle-ii/
// Author : Hao Chen
// Date   : 2014-07-03

/********************************************************************************** 
* 
* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
* 
* Follow up:
* Can you solve it without using extra space?
* 
*               
**********************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
private:
    ListNode *p1, *p2;
public:
    bool hasCycle(ListNode *head) {
        
        if (head==NULL) return false;
        p1=head;
        p2=head;
        
        while (p1!=NULL && p2!=NULL){
            
            p1=p1->next;
            
            if (p2->next == NULL) return false;
            
            p2=p2->next->next;
            
            if (p1==p2) return true;
        }
        
        return false;
        
    }  
    
    /* 
     * So, the idea is:
     *   1) Using the cycle-chcking algorithm.
     *   2) Once p1 and p1 meet, then reset p1 to head, and move p1 & p2 synchronously
     *      until p1 and p2 meet again, that place is the cycle's start-point 
     */
    ListNode *detectCycle(ListNode *head) {
	    if (head == NULL || head->next == NULL) return false;

    	ListNode *fast = head, *slow = head;

	    while (fast != NULL && fast->next != NULL) {
		    fast = fast->next->next;
		    slow = slow->next;
		    if (fast == slow) {
			    slow = head;
			    while(slow != fast) {
				    slow = slow->next;
				    fast = fast->next;
				    if (slow == fast) {
					    return slow;
				    }
			    }
		    }
	    }

	    return NULL;
    }
};
