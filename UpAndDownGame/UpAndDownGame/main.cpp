#include "stdafx.h"

Node* rootNode = nullptr;
int TargetNumber = 0;
int Count = 5;

int main()
{
	cout << "�� �ٿ� ������ �����մϴ� ! ( ���� 0 ~ 100 )" << endl;

	cout << "��� : " << Count << endl;

	srand(time(NULL));

	TargetNumber = rand() % 101;

	rootNode = InsertNode(rootNode, TargetNumber);

	while (Count--)
	{
		int selNum = 0;

		cin >> selNum;
		
		Node* targetNode = SearchNode(rootNode, selNum);

		if(targetNode != nullptr)
		{
			cout << "�����Դϴ�! (���� : " << rootNode->key << ")\n";
			break;
		}
		else
		{
			if (selNum != rootNode->key && Count == 0)
			{
				InsertNode(rootNode, selNum);
				cout << "Ʋ�Ƚ��ϴ�..\n";
			}
			else if (selNum > rootNode->key)
			{
				InsertNode(rootNode, selNum);
				cout << "DOWN!\n";
			}
			else if (selNum < rootNode->key)
			{
				InsertNode(rootNode, selNum);
				cout << "UP!\n";
			}
		}
		
	}

	cout << "���� ��ȸ : "; PrintPreorder(rootNode); cout << endl;
	cout << "���� ��ȸ : "; PrintInorder(rootNode); cout << endl;
	cout << "���� ��ȸ : "; PrintPostorder(rootNode); cout << endl;
	
	return 0;
}