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
        int carry = 0;
        ListNode* ans = new ListNode(-1);
        ListNode* p = ans;
        while (l1 || l2) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            int val = sum % 10;
            carry = sum / 10;
            p->next = new ListNode(val);
            p = p->next;
        }
        if (carry)
            p->next = new ListNode(carry);
        
        ans = ans->next;
        return ans;
    }

private:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* curr = head->next;
        head->next = nullptr;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = head;
            head = curr;
            curr = next;
        }
        return head;
    }
};