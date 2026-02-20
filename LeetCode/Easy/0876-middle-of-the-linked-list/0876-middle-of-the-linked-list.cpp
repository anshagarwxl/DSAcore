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
    int getLength(ListNode* head){
        int count =0;
        ListNode*temp = head;
        while(temp!=NULL){
            count ++;
            temp = temp-> next;
        }
        return count;
    }
    ListNode* middleNode(ListNode* head) {
        int n = getLength(head);
        int mid = n/2;
        
        ListNode * temp = head;
       for(int i =0; i<mid;i++){
        temp = temp->next;
       }
       return temp;
    }
};