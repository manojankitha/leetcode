/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = head, *curr = head;
        ListNode* prev=new ListNode();
        prev->next = head;
        ListNode * temp = prev;
        int l=0,i=1;
        while(dummy){
            l++;
            dummy = dummy->next;
        }
        
        while(i+n<=l){
            i++;
            prev = curr;
            curr = curr->next;
            
            
        }
       
        cout<<prev->next->val;
        cout<<curr->val;
       prev->next = curr->next;
        return temp->next;
        
        
    }
};