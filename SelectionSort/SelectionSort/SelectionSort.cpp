#include "stdafx.h"

#define Swap(type,lParam,rParam)        \
do                                      \
{                                       \
	type temp = *lParam;                \
	*lParam = *rParam;                  \
	*rParam = temp;                     \
} while (0)

void SelectionSort(int* pArray, int arraySize);

bool descendingOrder(int lParam, int rParam);

int wmain()
{

	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };

	SelectionSort(arr, _countof(arr));

	for (int index = 0; index < _countof(arr); ++index)
	{
		wprintf_s(L"%d ", arr[index]);
	}

	wprintf_s(L"\n");
}

bool descendingOrder(int lParam, int rParam)
{
	return lParam < rParam;
}

void SelectionSort(int* pArray, int arraySize)
{

	for (int index = 0; index < arraySize - 1; ++index)
	{
		for (int cmpIndex = index + 1; cmpIndex < arraySize; ++cmpIndex)
		{
			// pArray[inedx] 와 비교하면서 바꾸기를 시작하여 정렬되지 않은 요소들 중
			// 가장 작은 또는 가장 큰 값을 찾아 Swap 한다.
			if (descendingOrder(pArray[index], pArray[cmpIndex]) == true)
			{
				Swap(int, &pArray[index], &pArray[cmpIndex]);
			}
		}
	}
}