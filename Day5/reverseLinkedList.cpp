#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        /*
        ListNode* prev = NULL, *next = NULL, *curr = head;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
        */
        if (!head || !head->next)
            return head;
        ListNode *newNode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newNode;
    }
};
int main()
{
    Solution obj;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head = obj.reverseList(head);
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;
}