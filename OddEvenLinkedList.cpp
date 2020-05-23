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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL || head->next==NULL){return head;}
        ListNode* head2 = head->next;
        ListNode* curr1 = head;
        ListNode* curr2 = head->next;
        
        while(curr1!=NULL){
            if(curr2==NULL){
                curr1->next=head2;
                break;
            }
            else if(curr2->next!=NULL){
                //cout<<curr1->val<<endl;
                curr1->next=curr2->next;
                curr2->next=curr1->next->next;
                curr1=curr1->next;
                curr2=curr2->next;
            }else{
                curr1->next=head2;
                curr2->next=NULL;
                break;
            }
        }
        return head;
        
    }
};
