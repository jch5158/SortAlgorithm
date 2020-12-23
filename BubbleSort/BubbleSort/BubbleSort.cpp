#include "stdafx.h"

#define Swap(type, lParam, wParam)	\
do{									\
									\
	type t = *lParam;				\
	*lParam = *wParam;				\
	*wParam = t;					\
									\
} while (0)

class CDescendingOrder
{
public:

	bool operator()(const int num1,const int num2) const
	{
		return num1 < num2;
	}
};

void BubbleSort(int* pArray, int arraySize);

bool DescendingOrder(int lParam, int wParam);

//void Swap(int *pLparam, int *pWparam);

void PrintSortLogic(int* pArray,int arraySize, int lIndex, int rIndex);

int wmain()
{

	
	int arr[] = { 5,6,7,8,9,4,3,2,1 };

	BubbleSort(arr, _countof(arr));

	for (int index = 0; index < _countof(arr); ++index)
	{
		wprintf_s(L" %d ", arr[index]);
	}

	wprintf_s(L"\n");
}


void BubbleSort(int* pArray, int arraySize)
{
	// passCount는 배열의 길이에서 1를 뺀 값이다.
	int passCount = arraySize - 1;
	
	int count = 0;

	while(count < passCount)
	{	
		// 만약 한 번도 Swap이 발생되지 않았다면 로직상 count == passCount 가 돼서 while loop를 빠져나간다.
		int lastSwapIndex = 0;

		// 처음 비교 횟수는 배열의 길이의 -1 이며, 1 패스마다 비교하는 인덱스는 줄어든다.
		for (int index = 0; index < passCount - count; ++index)
		{		
			PrintSortLogic(pArray, arraySize, index, index + 1);

			if (DescendingOrder(pArray[index], pArray[index + 1]) == true)
			{
				Swap(int, &pArray[index], &pArray[index + 1]);
				
				lastSwapIndex = index;
			}
		}

		// 마지막으로 Swap 했을 때의 index를 기준으로 count 값을 계산한다.
		count = passCount - lastSwapIndex;
	}
}


//void BubbleSort(int* pArray, int arraySize)
//{
//	// passCount는 배열의 길이에서 1를 뺀 값이다.
//	int passCount = arraySize - 1;
//
//
//	for (int count = 0; count < passCount; ++count)
//	{
//		// 1 패스 때 한 번도 Swap이 호출되지 않았다면 모두 정렬된 상태이다.
//		bool bSwapFlag = false;
//
//		// 처음 비교 횟수는 배열의 길이의 -1 이며, 1 패스마다 비교하는 인덱스는 줄어든다.
//		for (int index = 0; index < passCount - count; ++index)
//		{
//			if (DescendingOrder(pArray[index], pArray[index + 1]) == true)
//			{
//				Swap(&pArray[index], &pArray[index + 1]);
//
//				bSwapFlag = true;
//			}
//		}
//
//		if (bSwapFlag == false)
//		{
//			break;
//		}
//	}
//}



void PrintSortLogic(int* pArray, int arraySize, int lIndex, int rIndex)
{
	for (int index = 0; index < arraySize; ++index)
	{
		if (index == lIndex || index == rIndex)
		{
			wprintf_s(L" [%d] ", pArray[index]);
		}
		else
		{
			wprintf_s(L" %d ", pArray[index]);
		}
	}

	wprintf_s(L"\n");

	wprintf_s(L"\n");

	_getwch();
}


bool DescendingOrder(int lParam, int wParam)
{
	return lParam < wParam;
}


//void Swap(int* pLparam, int* pWparam)
//{
//	int numBuffer = *pLparam;
//
//	*pLparam = *pWparam;
//
//	*pWparam = numBuffer;
//}













