class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;
        ListNode* curr = head;

        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        while (count >= k) {
            curr = prevGroupEnd->next;
            ListNode* nextNode = curr->next;
            for (int i = 1; i < k; ++i) {
                curr->next = nextNode->next;
                nextNode->next = prevGroupEnd->next;
                prevGroupEnd->next = nextNode;
                nextNode = curr->next;
            }
            prevGroupEnd = curr;
            count -= k;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};