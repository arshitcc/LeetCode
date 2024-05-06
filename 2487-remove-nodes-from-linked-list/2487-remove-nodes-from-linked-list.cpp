class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = head;
        while(curr){
            Next = Next->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = rev(head);
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast){
            if(slow->val<=fast->val){
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }   
        slow->next = NULL;
        head = rev(head);
        return head;
    }
};