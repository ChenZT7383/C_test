//���빦�ܣ�ͨ��һ������ǰ�������������������������
#include<iostream>
using namespace std;

struct NodeTree {
	int Key;
	NodeTree* LeftLeaf;
	NodeTree* RightLeaf;
};

//�ҵ�ָ��ֵ�������е�λ��
int FindNum(int *a,int Length,int num) {
	if (Length <= 0)return -1;
	for (int i = 0; i < Length; i++) {
		if (a[i] == num)return i;
	}
	return -1;
}

//˼���ǽ����⻮��Ϊ���������
NodeTree* CreateByPreAndInOrder(int *a, int *b, int Length) {

	NodeTree *Root = new NodeTree;
	Root->Key = a[0];
	int LeftLength = FindNum(b, Length, a[0]);//�����鳤��
	int RightLength = Length - LeftLength - 1;//�����鳤��

	if (LeftLength == 0) {
		Root->LeftLeaf = nullptr;
	}
	else{
		int *PreLeft = new int[LeftLength];
		int *InLeft = new int[LeftLength];
		memcpy(PreLeft, a + 1, LeftLength * sizeof(int));
		memcpy(InLeft, b, LeftLength * sizeof(int));
		Root->LeftLeaf = CreateByPreAndInOrder(PreLeft, InLeft, LeftLength);
		delete[] PreLeft;
		delete[] InLeft;
	}
	if (RightLength == 0) {
		Root->RightLeaf = nullptr;
	}
	else {
		int *InRight = new int[RightLength];	
		memcpy(InRight, b + LeftLength + 1, RightLength * sizeof(int));
		int *PreRight = new int[RightLength];	
		memcpy(PreRight, a + LeftLength + 1, RightLength * sizeof(int));
		Root->RightLeaf = CreateByPreAndInOrder(PreRight, InRight, RightLength);
		delete[] PreRight;
		delete[] InRight;
	}

	return Root;
}

void Print(NodeTree* a) {//������Ƿ�������ȷ
	if (a->LeftLeaf!=nullptr)
	{
		cout << a->Key << "�����ӽ����" << a->LeftLeaf->Key << endl << endl;
		Print(a->LeftLeaf);
	}
	else cout << a->Key << "û�����ӽ��" << endl << endl;

	if (a->RightLeaf!=nullptr)
	{
		cout << a->Key << "�����ӽ����" << a->RightLeaf->Key << endl << endl;
		Print(a->RightLeaf);
	}
	else cout << a->Key << "û�����ӽ��" << endl << endl;
}


int main() {
	int a[8] = { 1,2,4,7,3,5,6,8 };
	int b[8] = { 4,7,2,1,5,3,8,6 };
	NodeTree *Data = CreateByPreAndInOrder(a, b, 8);
	Print(Data);
	return 0;
}