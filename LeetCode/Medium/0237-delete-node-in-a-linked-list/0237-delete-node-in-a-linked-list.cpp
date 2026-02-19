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
    void deleteNode(ListNode* node) {
    ListNode * temp = node -> next; //store the node next to the current node
       node -> val = temp-> val; //copy value of temp, into the current node(the node that has to be deleted)
       node-> next = node->next->next; //point next of current node to next of next node, ignore temp
       delete(temp); //delete temp, node that is next to the current node
    }
};

/*
so what we are basically doing is that we start with storing the pointer (address) of the current node's next node into temp, then we are copying the value of the node next to the given node into the given node, then we are pointing the next pointer of current node to the next to next node, and then at last we are deleting temp, since temp was the next node which we removed from the list and its value was already copied into the given node provided in the question.
*/