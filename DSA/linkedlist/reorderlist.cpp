/*
Question:
Reorder linked list:
L0 → L1 → L2 → ... → Ln
into:
L0 → Ln → L1 → Ln-1 → ...

Example:
1 → 2 → 3 → 4 → 5
becomes
1 → 5 → 2 → 4 → 3

Approach:
Har node ko index ke saath unordered_map mein store kiya.
Isse last node ko mpp[cnt] se directly access kar sakte hain.

cur → front se chalega
cnt → back se chalega

Har step mein:
cur → next
ko
cur → last → next
banana hai.

Isliye pehle cur->next ko nextt mein save kiya,
phir last node ko cur ke baad connect kiya.

cur = nextt;
cnt--;

Dono middle tak move karte hain.

mid = size / 2
aur
while (cnt > mid)
se middle par pahunchte hi loop stop.

End mein:
mpp[mid]->next = NULL;
taaki list properly terminate ho.

Complexity:
Time: O(n)
Space: O(n)
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        ListNode* cur = head;
        unordered_map<int, ListNode*> mpp;

        int cnt = -1;

        while (cur != NULL) {
            cnt++;
            mpp[cnt] = cur;
            cur = cur->next;
        }

        int size = cnt + 1;
        int mid = size / 2;

        cur = head;

        while (cnt > mid) {
            ListNode* nextt = cur->next;
            ListNode* last = mpp[cnt];

            cur->next = last;
            last->next = nextt;

            cur = nextt;
            cnt--;
        }

        mpp[mid]->next = NULL;
    }
};