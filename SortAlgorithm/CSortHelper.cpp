#include "stdafx.h"
#include "CSortHelper.h"

void CSortHelper::QuickSort(const int left, const int right, std::vector<int>& arr, bool(*Cmp)(const int, const int))
{
	if (left >= right)
		return;

	int tempL = left;
	int tempR = right;
	int pivot = arr[(left + right) / 2];

	while (tempL <= tempR)
	{
		while (Cmp(arr[tempL], pivot))
			++tempL;

		while (Cmp(pivot, arr[tempR]))
			--tempR;

		if (tempL <= tempR)
		{
			Swap(arr[tempL], arr[tempR]);

			++tempL;
			--tempR;
		}
	}

	QuickSort(left, tempR, arr, Cmp);
	QuickSort(tempL, right, arr, Cmp);

	return;
}

void CSortHelper::BubbleSort(std::vector<int>& arr, bool(*Cmp)(const int, const int))
{
	int len = arr.size();
	if (len <= 1)
		return;

	for (int i1 = len - 1; i1 > 0; --i1)
	{
		bool bSwap = false;
		int lastSwap = i1;

		for (int i2 = 0; i2 < i1; ++i2)
		{
			if (Cmp(arr[i2], arr[i2 + 1]) == false)
			{
				bSwap = true;
				lastSwap = i2 + 1;

				Swap(arr[i2], arr[i2 + 1]);
			}
		}

		if (bSwap == false)
			return;

		i1 = lastSwap;
	}

	return;
}

void CSortHelper::InsertionSort(std::vector<int>& arr, bool(*Cmp)(const int, const int))
{
	int len = arr.size();
	if (len <= 1)
		return;

	for (int i1 = 1; i1 < len; ++i1)
	{
		for (int i2 = i1 - 1; i2 >= 0; --i2)
		{
			if (Cmp(arr[i2], arr[i2 + 1]) == false)
			{
				Swap(arr[i2], arr[i2 + 1]);
			}
			else
			{
				break;
			}
		}
	}

	return;
}

void CSortHelper::SelectionSrot(std::vector<int>& arr, bool(*Cmp)(const int, const int))
{
	int len = arr.size();
	if (len <= 0)
		return;

	for (int i1 = 0; i1 < len - 1; ++i1)
	{
		int swapIdx = i1;

		for (int i2 = i1 + 1; i2 < len; ++i2)
		{
			if (Cmp(arr[i1], arr[i2]) == false)
			{
				swapIdx = i2;
			}
		}

		Swap(arr[i1], arr[swapIdx]);
	}

	return;
}

void CSortHelper::MergeSort(const int low, const int high, std::vector<int>& arr, bool(*Cmp)(const int, const int))
{
	if (low >= high)
		return;

	int mid = (low + high) / 2;

	MergeSort(low, mid, arr, Cmp);
	MergeSort(mid + 1, high, arr, Cmp);

	Merge(low, mid, high, arr, Cmp);

	return;
}

void CSortHelper::Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;

	return;
}

void CSortHelper::Merge(int low, int mid, int high, std::vector<int>& arr, bool(*Cmp)(const int, const int))
{
	std::vector<int> tempArr(arr.size());

	int pL = low;
	int pM = mid + 1;
	int tempIdx = 0;

	while (pL <= mid && pM <= high)
	{
		if (Cmp(arr[pL], arr[pM]) == true)
		{
			tempArr[tempIdx++] = arr[pL++];
		}
		else
		{
			tempArr[tempIdx++] = arr[pM++];
		}
	}

	while (pL <= mid)
	{
		tempArr[tempIdx++] = arr[pL++];
	}

	while (pM <= high)
	{
		tempArr[tempIdx++] = arr[pM++];
	}

	for (;;)
	{
		--tempIdx;

		// low 부터 채워나가기 위함
		arr[low + tempIdx] = tempArr[tempIdx];

		if (tempIdx == 0)
			break;
	}

	return;
}