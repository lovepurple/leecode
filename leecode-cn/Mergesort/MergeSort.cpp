/*
	归并排序算法，非常典型的分治思想
*/
#include <iostream>

using namespace std;

void mergeSort(int* arr, int arrayLength);


void merge(int* arr, int leftIndex, int rightIndex)
{
	int i = leftIndex;
	int j = rightIndex;

	int mid = leftIndex + (j - i) / 2;
	int tempIndex = 0;
	int* pTempArray = new int[j + 1 - i];

	while (i <= mid && j <= rightIndex)
	{
		if (arr[i] < arr[j])
		{
			pTempArray[tempIndex++] = arr[i];
			i++;
		}
		else
		{
			pTempArray[tempIndex++] = arr[j];
			j++;
		}
	}

	while (i <= mid)
	{
		pTempArray[tempIndex++] = arr[i];
		i++;
	}

	while (j <= rightIndex)
	{
		pTempArray[tempIndex++] = arr[j];
		j++;
	}

	tempIndex = 0;
	for (int i = leftIndex; i <= rightIndex; ++i)
		arr[i] = pTempArray[tempIndex++];

	delete pTempArray;
}

void sort(int* arr, int leftIndex, int rightIndex)
{
	if (leftIndex < rightIndex)
	{
		int mid = leftIndex + (rightIndex - leftIndex) / 2;
		sort(arr, leftIndex, mid);
		sort(arr, mid + 1, rightIndex);
		merge(arr, leftIndex, rightIndex);
	}
}



int main()
{
	int arr[] = { 25,1,5,8,6,33,4,7,9 };

	mergeSort(arr, 9);

	std::cout << "AfterSort:" << std::endl;
	for (int i = 0; i <= 9; ++i)
	{
		std::cout << arr[i] << ",";
	}

	return 0;
}


void mergeSort(int* arr, int arrayLength)
{
	sort(arr, 0, arrayLength - 1);

}