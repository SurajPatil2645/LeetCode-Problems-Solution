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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first_critical = -1;
        int prev_critical = -1;
        int min_dist = INT_MAX;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;
        
        while (curr != nullptr && curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                if (first_critical == -1) {
                    first_critical = index;
                } else {
                    min_dist = min(min_dist, index - prev_critical);
                }
                prev_critical = index;
            }
            
            prev = curr;
            curr = curr->next;
            index++;
        }
        
        if (min_dist == INT_MAX) {
            return {-1, -1};
        }
        
        return {min_dist, prev_critical - first_critical};
    }
};