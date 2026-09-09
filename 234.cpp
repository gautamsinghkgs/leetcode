class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* prev = nullptr;

        while (slow != nullptr) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // Compare
        ListNode* p1 = head;
        ListNode* p2 = prev;

        while (p2 != nullptr) {
            if (p1->val != p2->val)
                return false;

            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};