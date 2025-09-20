

#include <iostream>
using namespace std;


void merge(int arr[], int left, int mid, int right, bool &isSorted)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
            isSorted = false;
        }
    }


    while (i < n1) arr[k++] = L[i++];
    while (j < n2)
    {
        arr[k++] = R[j++];
        isSorted = false;
    }
}


void mergeSort(int arr[], int left, int right, bool &isSorted)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, isSorted);
        mergeSort(arr, mid + 1, right, isSorted);
        merge(arr, left, mid, right, isSorted);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool isSorted = true;

    mergeSort(arr, 0, n - 1, isSorted);

    cout << "\nSorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    if (isSorted)
    {
        cout << "The array was already sorted.\n";
    }
    else
    {
        cout << "The array has been sorted using merge sort.\n";
    }

    return 0;
}
