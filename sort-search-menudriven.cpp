#include <iostream>
#include <vector>

using namespace std;

class Sort
{
public:
    void Display(vector<int>);
    void selectionSort(vector<int> &);
    void merge(vector<int> &, int, int, int);
    void mergeSort(vector<int> &, int, int);
    int binarySearch(vector<int> &, int, int, int);
    int linearSearch(vector<int>& , int);
};

void Sort::Display(vector<int> arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
}

void Sort::selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void Sort::merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void Sort::mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

 int Sort::linearSearch(vector<int>& arr , int key){

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
 }


int Sort::binarySearch(vector<int> &arr, int start, int end, int key)
{

    if (start > end)
        return -1;

    int mid = (start + end) / 2;

    if (key == arr[mid])
    {
        return mid;
    }
    else if (key > arr[mid])
    {
        return binarySearch(arr, mid + 1, end, key);
    }
    else
    {
        return binarySearch(arr, start, mid-1, key);
    }
}

int main()
{
    Sort s1;

    int size, choice;

    cout << "Enter the size of array : ";
    cin >> size;

    vector<int> arr(size);

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the Elements :";
        cin >> arr[i];
    }

    cout << "\n--------------------------------\n";
    cout << "0. Exit" << endl;
    cout << "1. selection Sort " << endl;
    cout << "2. Merge Sort " << endl;
    cout << "3. Linear Search " << endl;
    cout << "4. Binary Search " << endl;
    cout << "5. Display " << endl;

    cout << "Enter choice : ";
    cin >> choice;

    switch (choice)
    {
    case 0:
        {
            cout << "\n ------Exiting ---------\n";
             break;
        }
       
    case 1:
        {
            cout << "\n--------------Before-------------\n";
            s1.Display(arr);

            s1.selectionSort(arr);

            cout << "\n--------------After-------------\n";
            s1.Display(arr);
            break;
        }
    case 2:
        {
            cout << "\n--------------Before-------------\n";
            s1.Display(arr);

            s1.mergeSort(arr, 0, arr.size() - 1);

            cout << "\n--------------After-------------\n";
            s1.Display(arr);

            break;
        }
    case 3:
        {
            int key, idx;

            cout << "Enter key :";
            cin >> key;

            idx = s1.linearSearch(arr, key);

            if (idx == -1)
            {
                cout << "Oops ! Element not found !";
            }
            else
            {
                cout << "Yayy ! Element found at index : " << idx << endl;
            }

            break;
        }
    case 4:
        {
            int key, idx;

            cout << "Enter key :";
            cin >> key;

            s1.selectionSort(arr);

            cout << "\n--------------After-------------\n";
            s1.Display(arr);

            cout << endl;
            idx = s1.binarySearch(arr, 0, arr.size() - 1, key);

            if (idx == -1)
            {
                cout << "Oops ! Element not found !";
            }
            else
            {
                cout << "Yayy ! Element found at index : " << idx << endl;
            }

            break;
        }
    case 5:
       {
             s1.Display(arr);
            break;
       }
    }

    return 0;
}