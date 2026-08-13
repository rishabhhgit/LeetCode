class Solution {
public:
    //
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr) return NULL;
        ListNode*even=head->next;
        ListNode*odd=head;
        ListNode*evenStart=even;

        while(odd!=nullptr && even!=nullptr && even->next!=nullptr){
            odd->next=odd->next->next;
            even->next=even->next->next;
            
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenStart;
        return head;
    }
};