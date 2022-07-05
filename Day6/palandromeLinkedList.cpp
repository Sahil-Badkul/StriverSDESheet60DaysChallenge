
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int num;
    node *next;
    node(int val)
    {
        num = val;
        next = NULL;
    }
};

void insertNode(node *head, int val)
{
    node *newNode = new node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}

node *reverse(node *head)
{
    node *curr, *next, *prev;
    curr = head, prev = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(node *head)
{
    node *slow = head, *fast = head;
    node *dummy = head;
    // step1. find middle
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // step 2. reverse after mid
    slow = reverse(slow);
    // check for palindrome
    while (slow)
    {
        if (slow->num != dummy->num)
            return false;
        slow = slow->next;
        dummy = dummy->next;
    }
    return true;
}
int main()
{
    node *head = NULL;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 2);
    insertNode(head, 1);
    isPalindrome(head) ? cout << "True" : cout << "False";
    return 0;
}