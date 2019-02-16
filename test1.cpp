//创建链表，并且以顺序和倒序输出
#include<iostream>
#include<stack>
using namespace std;
struct ListNode {//链表数据结构
	int m_nKey;
	ListNode* m_pNext;
};

ListNode* NewList(int n) {//创建长度为n的链表
	ListNode *pHead=new ListNode;
	pHead->m_pNext = NULL;
	ListNode*p = pHead;
	for (int i = 0; i < n; i++) {
		ListNode* s = new ListNode;
		p->m_pNext = s;
		s->m_pNext = NULL;
		p = p->m_pNext;
	}
	return pHead;
}

void PrintList(ListNode* pHead) {//给定头指针倒序输出链表
	stack<ListNode*>nodes;//堆栈数据结构的定义
	ListNode* pNode = pHead->m_pNext;
	while (pNode != nullptr) {
		nodes.push(pNode);
		pNode = (*pNode).m_pNext;
	}
	while (!nodes.empty()) {
		cout << nodes.top()->m_nKey << endl;
		nodes.pop();
	}
}
int main() {
	ListNode* NumList = NewList(8);//新建长度为8的链表
	ListNode*p = NumList->m_pNext;
	for (int i = 1; i < 9; i++) {
		p->m_nKey = i;
		p = p->m_pNext;
	}
	p = NumList->m_pNext;
	while (p != nullptr){//顺序输出链表
		cout << p->m_nKey << endl;
		p = p->m_pNext;
	}
	cout << "----------------" << endl;
	PrintList(NumList);//递归倒序输出链表

	return 0;
}
