#include "stdafx.h"

#define Swap(type,lParam,rParam)        \
do                                      \
{                                       \
	type temp = *lParam;                \
	*lParam = *rParam;                  \
	*rParam = temp;                     \
} while (0)



void SetHeapSubTree(int* pArray,int arraySize, int subRouteIndex);

void SetHeap(int* pArray, int arraySize);

void HeapSort(int* pArray, int arraySize);



void downHeap(int* pArray, int subRootIndex, int arraySize);

void HeapSort2(int* pArray, int arraySize);

int wmain()
{

	int pArray[] = { 17,6,5,8,8,4,0,3,2,1,15 };
	
	
	HeapSort2(pArray, _countof(pArray));


	for (int index = 0; index < _countof(pArray); ++index)
	{
		wprintf_s(L"%d ", pArray[index]);
	}


	wprintf_s(L"\n");
}



void SetHeapSubTree(int* pArray, int arraySize, int subRouteIndex)
{
	int temp = 0;

	//int lastIndex = arraySize - 1;
	
	for (;;)
	{
		int leftChildIndex = (subRouteIndex * 2) + 1;
		if (leftChildIndex >= arraySize)
		{
			break;
		}


		int rightChildIndex = (subRouteIndex * 2) + 2;

		if (rightChildIndex < arraySize)
		{
			if (pArray[leftChildIndex] > pArray[rightChildIndex])
			{
				if (pArray[leftChildIndex] > pArray[subRouteIndex])
				{
					temp = pArray[subRouteIndex];
					pArray[subRouteIndex] = pArray[leftChildIndex];
					pArray[leftChildIndex] = temp;

					// subRouteIndex를 변경하고 subtree를 검사한다.
					subRouteIndex = leftChildIndex;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (pArray[rightChildIndex] > pArray[subRouteIndex])
				{
					temp = pArray[subRouteIndex];
					pArray[subRouteIndex] = pArray[rightChildIndex];
					pArray[rightChildIndex] = temp;

					subRouteIndex = rightChildIndex;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			if (pArray[leftChildIndex] > pArray[subRouteIndex])
			{
				temp = pArray[subRouteIndex];
				pArray[subRouteIndex] = pArray[leftChildIndex];
				pArray[leftChildIndex] = temp;

				subRouteIndex = leftChildIndex;
			}
			else
			{
				break;
			}
		}
	}
}


// 짝수면은 왼쪽 노드, 홀수면은 오른쪽 노드
void SetHeap(int* pArray, int arraySize)
{
	int parentIndex = 0;

	int lastIndex = arraySize - 1;

	if (lastIndex % 2 == 0)
	{
		for (;;)
		{
			parentIndex = (lastIndex) / 2;

			SetHeapSubTree(pArray, arraySize, parentIndex);

			if (parentIndex == 0)
			{
				break;
			}

			lastIndex -= 2;
		}
	}
	else
	{
		for (;;)
		{
			parentIndex = (lastIndex - 1) / 2;

			SetHeapSubTree(pArray, arraySize, parentIndex);

			if (parentIndex == 0)
			{
				break;
			}

			lastIndex -= 2;
		}
	}
}


void HeapSort(int* pArray, int arraySize)
{
	int temp = 0;

	SetHeap(pArray, arraySize);

	for (arraySize; arraySize > 1; --arraySize)
	{	
		Swap(int, &pArray[arraySize - 1], &pArray[0]);

		SetHeapSubTree(pArray, arraySize - 1, 0);
	}

}


void downHeap(int* pArray, int subRootIndex, int arraySize)
{
	// 현재 부모의 데이터를 temp 에 보관해둔다.
	int temp = pArray[subRootIndex];

	int child = 0;
	int parnet = 0;

	// 자식을 가지는 부모 노드의 개수는 ( (arraySize-1) / 2 ) 이다.
	for (parnet = subRootIndex; parnet < arraySize / 2; parnet = child)
	{
		int childLeft = (parnet * 2) + 1;
		int childRight = childLeft + 1;

		if (childRight < arraySize && pArray[childRight] > pArray[childLeft])
		{
			child = childRight;
		}
		else
		{
			child = childLeft;
		}

		if (temp >= pArray[child])
		{
			break;
		}


		pArray[parnet] = pArray[child];
	}

	// 보관해둔 부모 노드의 데이터를 마지막에 넣어줘야 할 데이터 위치에 넣어준다. 
	pArray[parnet] = temp;
}


void HeapSort2(int* pArray, int arraySize)
{

	for (int subRootIndex = (arraySize-1) / 2; subRootIndex >= 0; --subRootIndex)
	{
		downHeap(pArray, subRootIndex, arraySize);
	}

	for (int index = arraySize - 1; index > 0; --index)
	{
		Swap(int, &pArray[0], &pArray[index]);

		// root 노드를 제거하고 마지막 인덱스의 노도를 루트 노르를 올림으로서 다시 힙 정렬을 해야한다.
		// 현재는 root를 제외하고 나머지 트리가 힙 규칙을 지키고 있는 상황이기 떄문에 root 를 기준으로
		// 다시 정렬만 해주면 된다.
		downHeap(pArray, 0, index);
	}

}
