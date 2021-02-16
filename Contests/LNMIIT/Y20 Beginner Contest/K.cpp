#include <iostream>
#include <string>
using namespace std;

struct LinkedListNode
{
    LinkedListNode(): val(0), next(nullptr){};
    LinkedListNode(int x): val(x), next(nullptr){};
    int val;
    LinkedListNode *next;
};

int main()
{
    int n = 0;
    string s;
    cin >> n >> s;
    LinkedListNode *temp1 = new LinkedListNode(1), *temp2 = temp1;
    LinkedListNode *head = temp1;
    for(int i = 1; i < n; i++)
    {
        if(s[i - 1] == 'r')
        {
            LinkedListNode *curr = new LinkedListNode(i + 1);
            LinkedListNode *actual_temp = temp1->next;
            temp1->next = curr;
            curr->next = actual_temp;
            if(i != 1)
            {
                temp2 = temp1;
            }
            temp1 = curr;
        }
        else
        {
            LinkedListNode *curr = new LinkedListNode(i + 1);
            if(temp1 == temp2)
            {
                curr->next = temp1;
                head = curr;
                temp1 = curr;
                temp2 = curr;
            }
            else
            {
                temp2->next = curr;
                curr->next = temp1;
                temp1 = curr;
            }
        }
    }
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}