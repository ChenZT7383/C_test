#include<iostream>
#include<stack>
using namespace std;
struct ListNode {//�������ݽṹ
	int m_nKey;
	ListNode* m_pNext;
};

ListNode* NewList(int n) {//��������Ϊn������
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

void PrintList(ListNode* pHead) {//����ͷָ�뵹���������
	stack<ListNode*>nodes;//��ջ���ݽṹ�Ķ���
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
	ListNode* NumList = NewList(8);//�½�����Ϊ8������
	ListNode*p = NumList->m_pNext;
	for (int i = 1; i < 9; i++) {
		p->m_nKey = i;
		p = p->m_pNext;
	}
	p = NumList->m_pNext;
	while (p != nullptr){//˳���������
		cout << p->m_nKey << endl;
		p = p->m_pNext;
	}
	cout << "----------------" << endl;
	PrintList(NumList);//�ݹ鵹���������

	return 0;
}