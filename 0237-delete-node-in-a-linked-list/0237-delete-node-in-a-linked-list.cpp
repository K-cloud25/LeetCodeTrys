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
        ListNode* temp = node->next;
        while( node->next != NULL && node->next->next != NULL ){
            node->val = temp->val;
            node = temp;
            temp = node->next;
        }
        node->val = temp->val;
        node->next = NULL;

    }
};