#include "stdafx.h"

Node* rootNode = nullptr;
int TargetNumber = 0;
int Count = 5;

int main()
{
	cout << "업 다운 게임을 시작합니다 ! ( 범위 0 ~ 100 )" << endl;

	cout << "목숨 : " << Count << endl;

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
			cout << "정답입니다! (정답 : " << rootNode->key << ")\n";
			break;
		}
		else
		{
			if (selNum != rootNode->key && Count == 0)
			{
				InsertNode(rootNode, selNum);
				cout << "틀렸습니다..\n";
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

	cout << "전위 순회 : "; PrintPreorder(rootNode); cout << endl;
	cout << "중위 순회 : "; PrintInorder(rootNode); cout << endl;
	cout << "후위 순회 : "; PrintPostorder(rootNode); cout << endl;
	
	return 0;
}