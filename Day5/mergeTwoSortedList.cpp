#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* node = new ListNode(0);
        ListNode* temp = node;
        while(list1 && list2){
            if(!list1){
                temp->next = list2;
                temp = temp->next;
            }else if(!list2){
                temp->next = list1;
                temp = temp->next;
            }else if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }else{
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }
        if(list1) temp->next = list1;
        if(list2) temp->next = list2;
        return node->next;
    }
};

int main()
{
    Solution obj;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(8);
    ListNode *head2 = new ListNode(3);
    head->next = new ListNode(4);
    head->next->next = new ListNode(9);
    head = obj.mergeTwoLists(head, head2);
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;
}