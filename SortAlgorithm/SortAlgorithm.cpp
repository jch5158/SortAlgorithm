#include "stdafx.h"
#include "CSortHelper.h"

int main()
{
	int len;
	std::cin >> len;
	std::vector<int> arr;

	for (int i = 0; i < len; ++i)
	{
		int number;
		std::cin >> number;

		arr.push_back(number);
	}

	CSortHelper::MergeSort(0, arr.size() - 1, arr, [](const int a, const int b)->bool {return a < b; });
	for (int number : arr)
	{
		std::cout << number << "\n";
	}

	return 0;
}