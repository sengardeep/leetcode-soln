class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        // Find the middle
        int count = 0;
        ListNode* ptr = head;

        while (ptr) {
            ptr = ptr->next;
            count++;
        }

        count = (count + 1) / 2;

        ListNode* prev = nullptr;
        ptr = head;

        while (count--) {
            prev = ptr;
            ptr = ptr->next;
        }

        // Split the list
        prev->next = nullptr;

        // Reverse second half
        ListNode* curr = nullptr;

        while (ptr) {
            ListNode* next = ptr->next;
            ptr->next = curr;
            curr = ptr;
            ptr = next;
        }

        // Merge
        ListNode* p1 = head;
        ListNode* p2 = curr;

        while (p2) {
            ListNode* n1 = p1->next;
            ListNode* n2 = p2->next;

            p1->next = p2;
            p2->next = n1;

            p1 = n1;
            p2 = n2;
        }
    }
};