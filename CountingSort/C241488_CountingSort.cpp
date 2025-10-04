#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
    int maxVal = arr[0], minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
        if (arr[i] < minVal) minVal = arr[i];
    }

    int range = maxVal - minVal + 1;
    int* count = new int[range]();
    int* output = new int[n];

    for (int i = 0; i < n; i++)
        count[arr[i] - minVal]++;

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] count;
    delete[] output;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int* arr = new int[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    countingSort(arr, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    delete[] arr;
    return 0;
}
