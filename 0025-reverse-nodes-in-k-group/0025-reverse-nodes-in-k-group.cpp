class Solution {
public:
    ListNode* reverseKGroup(ListNode* h, int k) {
        ListNode d(0);
        d.next = h;
        ListNode *p = &d;

        while (1) {
            ListNode *q = p;
            for (int i = 0; i < k && q; i++) q = q->next;
            if (!q) break;

            ListNode *a = p->next;
            ListNode *b = a->next;

            for (int i = 1; i < k; i++) {
                a->next = b->next;
                b->next = p->next;
                p->next = b;
                b = a->next;
            }

            p = a;
        }

        return d.next;
    }
};