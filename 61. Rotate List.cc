/*
Given a list, rotate the list to the right by k places, where k is non-negative.


Example:

Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <string>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     ListNode(){}
};

typedef ListNode* Node;
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head)   return head;

        int len = 1;
        ListNode* newH, *tail;
        newH = tail=head;
        while(tail->next)
        {
            tail = tail->next;
            ++len;
        }
        tail->next = head;      //这里将 头尾连在一起，然后旋转
        if(k %= len)
        {
            for(auto i=0; i<len-k; ++i)
                tail = tail->next;
        }
        newH = tail->next;
        tail->next = nullptr;
        return newH;
    }

};
void build(Node* head, int val)
{
    if(*head == nullptr)
    {
        *head = new ListNode();
        (*head)->val = val;
        (*head)->next = nullptr;
    }
    else
    {
        auto pNode = *head;
        while(pNode->next)
        {
            pNode = pNode->next;
        }
        Node newNode = new ListNode();
        newNode->val = val;
        newNode->next = nullptr;

        pNode->next = newNode;
    }
}

void printAllNode(Node* head)
{
    auto curNode = *head;
    while(curNode)
    {
       std::cout<<curNode->val<<" ";
        curNode = curNode->next;
    }
    std::cout<<"\n";
}

void deleteAllNode(Node* head)
{
    if(*head == nullptr||head == nullptr)
        return;
    
    auto curNode = *head;

    while(curNode !=nullptr)
    {
        auto nextNode = curNode->next;
        
        delete curNode;
        curNode = nextNode;
    }

    *head = nullptr;
}

int main()
{
    ListNode* head = nullptr;
    for(int i=0;i<3; ++i)
        build(&head, i);

    Solution a;
    auto  newhead = a.rotateRight(head, 10);

    printAllNode(&newhead);
}

