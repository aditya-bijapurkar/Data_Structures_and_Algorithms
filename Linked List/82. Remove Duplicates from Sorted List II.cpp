//  Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        ListNode *ans=new ListNode(-1), *temp=ans;
        ListNode *curr=head;
        
        while(curr!=NULL){
            if((curr->next==NULL) || (curr->next!=NULL && curr->val!=curr->next->val)){
                temp->next=new ListNode(curr->val);
                temp=temp->next;
                curr=curr->next;
            }
            else{
                while(curr->next!=NULL && curr->val==curr->next->val){
                    curr=curr->next;
                }
                curr=curr->next;
            }
        }
        
        return ans->next;
    }
};
