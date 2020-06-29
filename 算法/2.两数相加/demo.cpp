#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		int num = l1->val + l2->val;
		ListNode* res = new ListNode(num % 10);
		res->next = new ListNode(num / 10);
		ListNode* p1 = l1->next;
		ListNode* p2 = l2->next;
		if (p1 == NULL && p2 == NULL)
		{
			if (res->next->val == 0) {
				res->next = NULL;
				return res;
			}
		}
		ListNode* p = res->next;
		while (true)
		{
			int var1 = 0;
			if (p1) {
				var1 = p1->val;
				p1 = p1->next;
			}

			int var2 = 0;
			if (p2) {
				var2 = p2->val;
				p2 = p2->next;
			}

			int num = p->val + var1 + var2;
			p->val = num % 10;
			p->next = new ListNode(num / 10);

			if (p1 == NULL && p2 == NULL)
			{
				if (p->next->val == 0) {
					p->next = NULL;
					return res;
				}
			}
			p = p->next;
		}
	}
};

void addNode(ListNode*& l, int num) {
	ListNode* a = new ListNode(num);
	a->next = l;
	l = a;
}

void coutNode(ListNode* l) {
	while (l)
	{
		cout << l->val;
		l = l->next;
	}
	cout << endl;
}

int main()
{
	ListNode* l1 = new ListNode(2);
	addNode(l1, 4);
	addNode(l1, 3);
	coutNode(l1);

	ListNode* l2 = new ListNode(5);
	addNode(l2, 6);
	addNode(l2, 4);
	coutNode(l2);

	Solution test = Solution();
	ListNode* res = test.addTwoNumbers(l1, l2);
	coutNode(res);


	l1 = new ListNode(0);
	coutNode(l1);

	l2 = new ListNode(0);
	coutNode(l2);

	test = Solution();
	res = test.addTwoNumbers(l1, l2);
	coutNode(res);
}



