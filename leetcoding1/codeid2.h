#ifndef CODEID2_H
#define CODEID2_H

#include <vector>
#include <iostream>
using namespace std;

namespace CodeID2 {
// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

void printList(ListNode* pList)
{
    auto p = pList;
    while (p) {
        cout<< p->val << (p->next ? " -> ":"");
        p = p->next;
    }
    cout << endl;
}

class Solution {
public:
    void createList(const vector<int>& inputVec, ListNode*& root)
    {
        ListNode* pPre = nullptr;
        for(auto index = 0; index < inputVec.size(); ++index)
        {
            auto pNode = new ListNode(inputVec[index]);
            if(!index)
            {
                root = pNode;
                pPre = root;
            }
            else
            {
                pPre->next = pNode;
                pPre = pNode;
            }
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(-1);
        int iAccerValue = 0;
        ListNode* pAdd1 = l1;
        ListNode* pAdd2 = l2;
        ListNode* p = root;

        while (pAdd1 || pAdd2 || iAccerValue) {
            auto iAddNumSum = 0;
            auto iAdd1 = 0;
            auto iAdd2 = 0;

            if(pAdd1)
            {
                iAdd1 = pAdd1 ? pAdd1->val : 0;
                pAdd1 = pAdd1->next;
            }

            if(pAdd2)
            {
                iAdd2 = pAdd2 ? pAdd2->val : 0;
                pAdd2 = pAdd2->next;
            }

            iAddNumSum = iAdd1 + iAdd2 + iAccerValue;
            auto pResNode1 = new ListNode(iAddNumSum % 10);
            iAccerValue = iAddNumSum / 10;

            p->next = pResNode1;
            p = pResNode1;
        }

        return root->next;
    }

    static void testAddTwoNumber()
    {
        Solution s;
        vector<int> addNum1 = {2,4,3};
        vector<int> addNum2 = {5,6,4};
//        vector<int> addNum1 = {1,8};
//        vector<int> addNum2 = {0};
//        vector<int> addNum1 = {5};
//        vector<int> addNum2 = {5};
        ListNode* listNum1 = nullptr;
        ListNode* listNum2 = nullptr;
        s.createList(addNum1, listNum1);
        s.createList(addNum2, listNum2);

        auto ret = s.addTwoNumbers(listNum1, listNum2);
        printList(ret);
    }
};
}
#endif // CODEID2_H
