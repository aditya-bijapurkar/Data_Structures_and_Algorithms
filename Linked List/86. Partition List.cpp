//  Link: https://leetcode.com/problems/partition-list/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left=new ListNode(-1);
        ListNode *right=new ListNode(-1);
        ListNode *l_ptr=left, *r_ptr=right;
        
        ListNode *curr=head;
        while(curr!=NULL){
            if(curr->val<x){
                l_ptr->next=curr;
                l_ptr=curr;
                curr=curr->next;
                l_ptr->next=NULL;
            }
            else{
                r_ptr->next=curr;
                r_ptr=curr;
                curr=curr->next;
                r_ptr->next=NULL;
            }
        }
        
        l_ptr->next=right->next;
        return left->next;
    }
};
