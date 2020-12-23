#include "stdafx.h"

#define Swap(type,lParam,rParam)		\
do                                      \
{										\
	type temp = *lParam;				\
	*lParam = *rParam;					\
	*rParam = temp;						\
} while (0)


void QuickSortRecursive(int* pArray, int left, int right);


void QuickSort(int *pArray, int leftIndex, int rightIndex);



// Quick Sort 알고리즘의 배열 분할을 이해하는 함수입니다. 
void PartionArray(int* pArray, int arraySize);


void PrintQuickSortLogic(int* pArray, int arraySize, int pl, int pr, bool bSwapFlag = false);


int CompareOrder(int lParam, int rParam);

int wmain()
{
	_wsetlocale(LC_ALL, L"");

	int intArray[5] = { 3,10,7,9,8 };

	QuickSort(intArray, 0, 4);

	for (int index = 0; index < _countof(intArray); ++index)
	{
		wprintf_s(L"%d ", intArray[index]);
	}

	
	wprintf_s(L"\n");

	return 1;
}



int CompareOrder(int lParam, int rParam)
{
	// 오름, 내림 차순으로 변경하고 싶다면은 부등호를 반대로 바꾸면 된다.
	if (lParam > rParam)
	{
		return -1;
	}
	else if (lParam < rParam)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void QuickSortRecursive(int* pArray, int leftIndex, int rightIndex)
{
	// 디버깅용 변수
	int arraySize = rightIndex + 1;

	int pl = leftIndex;
	int pr = rightIndex;

	int pivot = pArray[(pl + pr) / 2];

	while (pl <= pr)
	{
		while (CompareOrder(pArray[pl],pivot) == -1)
		{
			PrintQuickSortLogic(pArray, arraySize, pl, pr);
			++pl;
		}

		while (CompareOrder(pArray[pr],pivot) == 1)
		{
			PrintQuickSortLogic(pArray, arraySize, pl, pr);
			--pr;
		}


		PrintQuickSortLogic(pArray, arraySize, pl, pr, true);
		Swap(int, &pArray[pl], &pArray[pr]);
		++pl;
		--pr;

		PrintQuickSortLogic(pArray, arraySize, pl, pr);
	}

	// pl 또는 pr이 pivot이 위치한 인덱스 직전에 멈춰 Swap 이 발생되어 서로 역전하는 순간이 있고
	// 발생될 수 있는 중간 그룹은 pl 과 pr 이 동일한 인덱스를 가리키는 상태에서 Swap이 발생되면 1개의 중간그룹이 발생된다.
	// pArray[pl-1], pArray[pr+1] 중간 그룹은 분할 대상에서 제외된다.

	if (leftIndex < pr)
	{
		QuickSortRecursive(pArray, leftIndex, pr);
	}

	if (rightIndex > pl)
	{
		QuickSortRecursive(pArray, pl, rightIndex);
	}
}




void QuickSort(int *pArray, int leftIndex, int rightIndex)
{
	// 디버깅용 변수
	int arraySize = rightIndex + 1;

	std::stack<int> indexStack;

	indexStack.push(rightIndex);

	indexStack.push(leftIndex);
	
	while (indexStack.empty() == false)
	{
		int pl = indexStack.top();
		indexStack.pop();
		leftIndex = pl;

		int pr = indexStack.top();
		indexStack.pop();
		rightIndex = pr;

		int pivot = pArray[(rightIndex + leftIndex) / 2];
		

		while (pl <= pr)
		{
			while (CompareOrder(pArray[pl],pivot) == -1)
			{
				PrintQuickSortLogic(pArray, arraySize, pl, pr);
				++pl;
			}

			while (CompareOrder(pArray[pr], pivot) == 1)
			{
				PrintQuickSortLogic(pArray, arraySize, pl, pr);
				--pr;
			}


			PrintQuickSortLogic(pArray, arraySize, pl, pr, true);
			Swap(int, &pArray[pl], &pArray[pr]);
			++pl;
			--pr;

			PrintQuickSortLogic(pArray, arraySize, pl, pr);
		}
		
		if (leftIndex < pr)
		{
			indexStack.push(pr);
			indexStack.push(leftIndex);
		}
		
		if (rightIndex > pl)
		{
			indexStack.push(rightIndex);
			indexStack.push(pl);
		}
	}
}


void PrintQuickSortLogic(int* pArray, int arraySize, int pl, int pr, bool bSwapFlag)
{
	wprintf_s(L"^ == pl, * == pr\n\n");

	for (int index = 0; index < arraySize; ++index)
	{
		if (index == pl && index == pr)
		{
			wprintf_s(L"< %d >", pArray[index]);
		}		
		else if (index == pl && pl >= 0)
		{
			if (bSwapFlag == true)
			{
				wprintf_s(L"(^%d) ", pArray[index]);
			}
			else
			{
				wprintf_s(L"[^%d] ", pArray[index]);
			}	
		}
		else if (index == pr && pr >= 0)
		{
			if (bSwapFlag == true)
			{
				wprintf_s(L"(*%d) ", pArray[index]);
			}
			else
			{
				wprintf_s(L"[*%d] ", pArray[index]);
			}
		}
		else if(pl >= 0 && pr >= 0)
		{
			wprintf_s(L"%d ", pArray[index]);
		}

	}
	_getwch();
	wprintf_s(L"\n\n");

}



void PartionArray(int* pArray, int arraySize)
{

	//int pivot = pArray[(arraySize - 1) / 2];

	int pivot = pArray[7];

	int pl = 0;

	int pr = arraySize - 1;

	while(pl <= pr)
	{	

		// pl 위치의 데이터가 pivot 보다 클 때 까지 반복문을 돈다.
		while (pArray[pl] < pivot)
		{
			++pl;
		}

		// pr 위치의 데이터가 pivot 보다 작을 때 까지 반복문을 돈다.
		while (pArray[pr] > pivot)
		{
			--pr;
		}

		Swap(int, &pArray[pl], &pArray[pr]);
		++pl;
		--pr;
	}

	// 왼쪽 그룹의 범위는 pArray[0] ~ pArray[pl-1] 까지이다.
	for (int index = 0; index <= pl - 1; ++index)
	{
		wprintf_s(L" %d ", pArray[index]);
	}
	wprintf_s(L"\n");
	wprintf_s(L"\n");


	for (int index = pr + 1; index <= pl - 1; ++index)
	{
		wprintf_s(L"피벗과 일치하는 그룹 : %d\n\n", pArray[index]);	
	}	
	
	// 오른쪽 그룹의 범위는 pArray[pr+1] ~ pArray[arraySize-1] 까지이다.
	for (int index = pr + 1; index < arraySize; ++index)
	{
		wprintf_s(L" %d ", pArray[index]);
	}

	wprintf_s(L"\n");
	wprintf_s(L"\n");
}