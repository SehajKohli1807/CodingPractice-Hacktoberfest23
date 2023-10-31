#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int index_min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[index_min])
            {
                index_min = j;
            }
        }
        swap(&arr[index_min], &arr[i]);
    }
}

void print(int arr[], int size)
{
    cout << endl;
    cout << "After Sorting: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int size;
    cout << "Enter size of array\n";
    cin >> size;

    int *arr = new int[size];

    cout << "Enter Elements in the array\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    selection_sort(arr, size);
    print(arr, size);

    return 0;
}