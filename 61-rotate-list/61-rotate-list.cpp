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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* traversal = head;
        if(k==0){
            return head;
        }
        if (head==NULL){
            return NULL;
        }
        int n = 1;
        while(traversal->next!=NULL){
            n++;
            traversal = traversal->next;
        }
        
     
        traversal->next = head;
        
        ListNode * seq = head;
        for(int i = 1;i<n-((k)%n);i++){
            seq = seq->next;
        }
        head = seq->next;
        seq->next = NULL;
        
         
        return head;
       
        
    }
};