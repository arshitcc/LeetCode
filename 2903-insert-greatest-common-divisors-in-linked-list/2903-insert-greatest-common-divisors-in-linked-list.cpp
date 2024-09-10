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

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* temp = head;
        while(temp and temp->next){
            int val = gcd(temp->val, temp->next->val);
            ListNode* x = new ListNode(val);
            x->next = temp->next;
            temp->next = x;
            temp = temp->next->next;
        }

        return head;
    }
};