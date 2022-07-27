#pragma once

class CSortHelper
{
public:
	CSortHelper() = delete;
	~CSortHelper() = delete;
	CSortHelper(const CSortHelper&) = delete;
	CSortHelper& operator=(const CSortHelper&) = delete;

	static void QuickSort(const int left, const int right, std::vector<int>& arr, bool(*Cmp)(const int, const int));

	static void BubbleSort(std::vector<int>& arr, bool(*Cmp)(const int, const int));

	static void InsertionSort(std::vector<int>& arr, bool(*Cmp)(const int, const int));

	static void SelectionSrot(std::vector<int>& arr, bool(*Cmp)(const int, const int));

	static void MergeSort(const int low, const int high, std::vector<int>& arr, bool(*Cmp)(const int, const int));

private:

	static void Swap(int& left, int& right);

	static void Merge(int low, int mid, int high, std::vector<int>& arr, bool(*Cmp)(const int, const int));
};