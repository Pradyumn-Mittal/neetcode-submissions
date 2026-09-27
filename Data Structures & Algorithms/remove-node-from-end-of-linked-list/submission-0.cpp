class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast n nodes ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Keep a gap of n nodes
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        slow->next = slow->next->next;

        return dummy.next;
    }
};