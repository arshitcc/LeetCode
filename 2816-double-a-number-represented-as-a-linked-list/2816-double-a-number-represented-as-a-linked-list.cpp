class Solution {
public:
    ListNode* revLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = head->next;
        while(Next){
            curr->next = prev;
            prev = curr;
            curr = Next;
            Next = Next->next;
        }
        curr->next = prev;
        return curr;
    }

    ListNode* doubleIt(ListNode* head) {
        head = revLL(head);

        int carry = 0;
        ListNode* temp = head;
        ListNode* prev;
        
        while(temp){
            prev = temp;
            int x = temp->val;
            temp->val = (x*2 +carry)%10;
            carry = (x*2 +carry)/10;
            temp = temp->next;
        }

        if(carry!=0){
            ListNode* node = new ListNode(carry);
            prev->next = node;
        }
        return revLL(head);  
    }
};