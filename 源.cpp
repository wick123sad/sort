#include<iostream>
using namespace std;
#include<time.h>
#include<stdlib.h>
void QuickSort(int* a, int s, int t)
{
	if (s > t)return;
	int i = s, j = t;
	int tmp = a[s];
	while (i != j)
	{
		while (i < j && a[j] >= tmp)
			j--;
		while (i < j && a[i] <= tmp)
			i++;
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	a[s] = a[i];
	a[i] = tmp;
	QuickSort(a, s, i - 1);
	QuickSort(a, i + 1, t);
}

void BubbleSort(int* arr,int n)//将较小的数逐渐浮出数组的前端
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = n-1; j > i; j--)
		{
			if (arr[j] < arr[j-1])
			{
				int t = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = t;
			}
		}
	}
}

void ShellSort(int* arr, int n)
{
	int d = n / 2;
	while (d > 0) 
	{
		for (int i = d; i < n; i++)
		{
			if (arr[i] < arr[i - d])
			{
				int tmp = arr[i];
				int j = i - d;
				while (j >= 0 && arr[j] > tmp)
				{
					arr[j + d] = arr[j];
					j = j - d;
				}
				arr[j + d] = tmp;
			}
		}
		d = d / 2;
	}
}

void Disp(int* arr,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) <<' ';
	}
}

int main()
{
	int arr[] = { 6,8,7,9,0,1,3,2,4,5 };
	//BubbleSort(arr,10);
	ShellSort(arr,sizeof(arr)/sizeof(arr[0]));
	Disp(arr,sizeof(arr) / sizeof(arr[0]));
	return 0;
}