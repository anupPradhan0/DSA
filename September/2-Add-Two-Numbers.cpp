// 2. Add Two Numbers


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;


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

    ListNode* add(ListNode* h1, ListNode* h2) {
        int carry = 0;
        ListNode* anshead = Null;
        ListNode* ans = Null;
        while (h1 != Null || h2 != Null || carry) {
            int sum = carry;
            if (h1 != Null) {
                sum += h1->val;
                h1 = h1->next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = add (l1,l2);

    }
};