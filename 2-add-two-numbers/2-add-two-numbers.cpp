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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root;
        ListNode* prev;
        int adder = 0;
        int iter = 0;
        while(l1 != NULL || l2 != NULL) {
            int x = 0, y = 0;
            if(l1) {
                x = l1->val;
            }
            if(l2) {
                y = l2->val;
            }
            int temp_sum = x + y + adder;
            ListNode* temp = new ListNode(temp_sum%10);
            if(iter) {
                prev->next = temp;
            }
            if(iter == 0) {
                root = temp;
                iter++;
            }
            adder = temp_sum / 10;
            if(l1) {
                l1 = l1->next;
            }
            if(l2) {
                l2 = l2->next;
            }
            
            prev = temp;
        }
        if(adder) {
            ListNode* temp = new ListNode(1);
            prev->next = temp;
        }
        return root;
    }
};