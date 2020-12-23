#include "stdafx.h"

#define Swap(type,lParam,rParam)        \
do                                      \
{                                       \
	type temp = *lParam;                \
	*lParam = *rParam;                  \
	*rParam = temp;                     \
} while (0)


bool AscendingOrder(int lParam, int rParam);

void InsertionSort(int* pArray, int arraySize);

int wmain()
{

	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };

	InsertionSort(arr, _countof(arr));

	for (int index = 0; index < _countof(arr); ++index)
	{
		wprintf_s(L"%d ", arr[index]);
	}

	wprintf_s(L"\n");
}


bool AscendingOrder(int lParam, int rParam)
{
	return lParam < rParam;
}

void InsertionSort(int* pArray, int arraySize)
{
	int temp = 0;

	for (int index = 1; index < arraySize; ++index)
	{
		temp = pArray[index];

		for (int cmpIndex = index - 1; cmpIndex >= 0; --cmpIndex)
		{
			// 조건에 맞으면 temp 데이터를 삽입하기 위해 pArray[cmpIndex+1] 에 pArray[cmpIndex] 데이터를 넣는다.
			
			if (AscendingOrder(temp, pArray[cmpIndex]) == true)
			{
				pArray[cmpIndex + 1] = pArray[cmpIndex];

			}
			else
			{
				// 앞 인덱스들은 이미 정렬이 다 되었기 때문에 추가적인 확인이 필요없다. 
				pArray[cmpIndex + 1] = temp;
				break;
			}
		}
	}
}