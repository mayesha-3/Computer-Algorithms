
#include <iostream>
using namespace std;

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


    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }


        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
            isSorted = false;
        }
    }


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
        cout << "The array has been sorted using selection sort.\n";
    }

    return 0;
}
