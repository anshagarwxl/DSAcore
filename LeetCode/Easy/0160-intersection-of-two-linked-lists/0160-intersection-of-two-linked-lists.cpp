/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
        return NULL;
        ListNode * temp1 = headA;
        ListNode * temp2 = headB;
        while(temp1!=temp2){    
        //handles the case when both the headA and headB point to the same node itslef
        temp1 = (temp1==NULL) ? headB : temp1->next;
        temp2 = (temp2==NULL) ? headA : temp2->next;
        }
        return temp1;
    }
};
//start iterating 1 step at a time simulatenously with both temp1 and temp2 and stop them to the node previous to NULL, then once temp1 reaches last node before NULL, shift it to head2.
//DO the same for temp2, shifting temp2 to head1 once it reaches NULL.
//Keep shifting simulatenously, until they collide. 