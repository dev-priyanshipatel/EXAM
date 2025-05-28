#include<iostream>
#include<vector>

using namespace std;

class Node{
    public :
        int data;
        Node *next;

        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};

class linkedList{

    public :
        Node *HEAD;
        int count;

    
        linkedList(){
            this->HEAD = nullptr;
        }

        bool isEmpty(){
            if(count == 0 || HEAD == nullptr)
                return true;
            else
                return false;
        }

        void addAtStart(){
            int data;

            cout << "Enter Data to Insert : ";
            cin >> data;

            Node *newNode = new Node(data);

            newNode->next = HEAD;
            HEAD = newNode;

            cout << "\n---------------------------\n";
            cout << "Data Successfully insterted at start.";
            cout << "\n---------------------------\n\n";

            count++;
        }

        void viewData(){
            if(isEmpty()){
                cout << "\n--------------\n";
                cout << "List is Empty."<< endl;
                cout << "\n--------------\n\n";
                return;
            }

            Node *temp;
            temp = HEAD;

            cout << "\n---------------------------\n";
            while(temp != nullptr){
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL";
            cout << "\n---------------------------\n\n";
        }

        void deleteAtPosition(){
            if(isEmpty()){
                cout << "\n-----------------------\n";
                cout << "List is Empty ";
                cout << "\n-----------------------\n";
                return;
            }

            int pos;

            cout << "Enter position :";
            cin >> pos;

            if(pos > count || pos <= 0){
                cout << "\n---------------------\n";
                cout << "Invalid Position";
                cout << "\n----------------------\n\n";
                return;
            }

            Node *deleteNode;

            if(pos == 1){
                deleteNode = HEAD;
                HEAD = HEAD->next;
            }else {
            Node *temp = HEAD;

            for (int i = 1; i < pos - 1; i++){  
                temp = temp->next;
            }

            deleteNode = temp->next;
            temp->next = deleteNode->next;
            }

            delete deleteNode;
            count--;

            cout << "\n----------------------------------------\n";
            cout << "Node Deleted Successfully.";
            cout << "\n----------------------------------------\n\n";
        }

        void updateData(){

            if(isEmpty()){
                cout << "\n-----------------------\n";
                cout << "List is Empty ";
                cout << "\n-----------------------\n";
                return;
            }
            int pos, data;

            cout << "Enter position :";
            cin >> pos;

            if(pos > count || pos <= 0){
                cout << "\n---------------------\n";
                cout << "Invalid Position";
                cout << "\n----------------------\n\n";
                return;
            }

            cout << "Enter new data : ";
            cin >> data;

            

            Node *temp;
            temp = HEAD;

            for(int i = 0; i < pos-1; i++){
                temp = temp->next;
            }
            temp->data = data;

            cout << "\n----------------------------------------\n";
            cout << "Data Updated Successfully.";
            cout << "\n----------------------------------------\n\n";
        }


};

void merge(vector<int> &arr, int low, int mid, int high)
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

void mergeSort(vector<int> &arr, int low, int high)
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

void Display(vector<int> arr){
    cout << "\n---------------------------\n";
    for (int val : arr)
    {
        cout << val << " ";
    }   
    cout << "\n---------------------------\n";

}

int binarySearch(vector<int>& arr,int start, int end, int key ){
    if(start > end)
        return -1;

    int mid = (start+end)/2;
    
    if(key == arr[mid])
        return mid;
    else if(key > arr[mid])
        return binarySearch(arr, mid + 1, arr.size(), key);
    else{
        return binarySearch(arr, start, mid-1, key);
    }
}

int main(){
    int choice;
    linkedList list;

    do{

        cout << "\n---------------------\n";
        cout << "0. Exit "<< endl;
        cout << "1. Linkedlist "<< endl;
        cout << "2. Merge Sort " << endl;
        cout << "3. Binary Search " << endl;
        cout << "Enter Choice : ";
        cin >> choice;

        switch(choice){
            case 0 :
            {
                cout << "\n---------------------\n";
                cout <<" Thank You !";
                cout << "\n---------------------\n\n";
                break;
            }

            case 1 :
            {
                int choice;

                do{

                    cout << "\n---------------------\n";
                    cout << "0. Exit "<< endl;
                    cout << "1. Add at Start "<< endl;
                    cout << "2. Delete At Any position " << endl;
                    cout << "3. Update Data " << endl;
                    cout << "4. View data" << endl;
                    cout << "Enter Choice : ";
                    cin >> choice;

                    switch(choice){
                        case 0:
                        {
                            cout << "\n---------------------\n";
                            cout <<" Exiting from linked list !";
                            cout << "\n---------------------\n\n";
                            break;
                        }

                        case 1:
                        {
                            list.addAtStart();
                            break;
                        }

                        case 2:
                        {
                            list.deleteAtPosition();
                            break;
                        }

                        case 3:
                        {
                            list.updateData();
                            break;
                        }

                        case 4:
                        {
                            list.viewData();
                            break;
                        }
                    }


                }while(choice != 0);
                break;
            }

            case 2 :
            {
                int size;

                cout << "Enter size of array: ";
                cin >> size;

                vector<int> arr(size);

                for (int i = 0; i < arr.size(); i++)
                {
                    cout << "Enter any value : ";
                    cin >> arr[i];
                }

                cout << "\n------------Befor---------------\n";
                Display(arr);
                cout << endl;
                

                mergeSort(arr, 0, arr.size() - 1);

                cout << "\n-------------After--------------\n";
                Display(arr);
                cout << endl;
                
                break;
            }

            case 3 :
            {
                int size, key;

                cout << "Enter the size of array: ";
                cin >> size;

                vector<int> arr(size);

                for(int i = 0; i < size; i++){

                cout <<" Enter the Elements of Array : ";
                cin >> arr[i];

                }

    

                cout << "\n-------------------Before---------------------\n ";
                Display(arr);

                mergeSort(arr, 0, arr.size() - 1);

                cout << "\n-------------------After---------------------\n ";
                Display(arr);

                cout << "\nEnter key :";
                cin >> key;

                cout << endl;
                int idx =  binarySearch(arr, 0, size - 1, key);

                if(idx == -1){
                    cout << "Element not found !";
                } else {
                    cout << "Element found at index : " << idx << endl;
                }

                break;
            }

        }

    }while(choice != 0);
    return 0;
}
