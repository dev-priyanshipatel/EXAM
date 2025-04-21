#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        

        Node(int data){
            this->data = data;
            this->next =nullptr;
        }
};

class linkedList {
    private:
        Node *HEAD;
        int counter = 0;

    public:

        linkedList(){
            HEAD = nullptr;
        }

        bool isEmpty(){
            if(HEAD == nullptr)
                return true;
            else
                return false;
        }

   void  AddAtStart(){
    int data;
    cout << "Enter data to insert: ";
    cin >> data;

    Node *newNode = new Node(data);

    newNode->next = HEAD;
    HEAD = newNode;
   
    cout << "\nSuccessfully inserted at the beginning." << endl ;
   
    counter++;

    }

    void DisplayNode(){

        if (isEmpty())
            return;

        Node *temp;
        temp = HEAD;
        
        while (temp != nullptr)
        {
            cout << "\n\n";
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
        
    }

    void deleteAtStart()
    {
        if (isEmpty())
            return;

        if (HEAD->next == nullptr)
        {
            delete HEAD;
            HEAD = nullptr;

            
            cout << "\nFirst Node Deleted Successfully.\n" << endl;
           
            counter--;
            return;
        }

        Node *temp;
        temp = HEAD;

        HEAD = HEAD->next;

        delete temp;
        temp = nullptr;

       
        cout << "\nFirst Node Deleted Successfully.\n" << endl;
       

        counter--;
    }


    void deleteAtEnd()
    {
        if (isEmpty())
            return;

        if (HEAD->next == nullptr)
        {
            delete HEAD;
            HEAD = nullptr;

          
            cout << "\nLast Node Deleted Successfully.\n" << endl;
           

            counter--;

            return;
        }

        Node *temp;
        temp = HEAD;

        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;

        
        cout << "\nLast Node Deleted Successfully.\n"<< endl;
       
        counter--;
    }

    void deleteAtPosition()
    {
        if (isEmpty())
            return;

        int pos;
        cout << "Enter position to delete data from: ";
        cin >> pos;

        if (pos > counter || pos < 0)
        {
           
            cout << "\nInvalid Position.";
            
            return;
        }

        if (pos == 0)
        {
            deleteAtStart();
            return;
        }

        if (pos == counter)
        {
            deleteAtEnd();
            return;
        }

        Node *temp;
        temp = HEAD;

        for (int i = 0; i < (pos - 1); i++)
        {
            temp = temp->next;
        }

        Node *deleteNode = temp->next;
        temp->next = deleteNode->next;

        delete deleteNode;
        deleteNode = nullptr;

        counter--;

       
        cout << "\n\nNode at position " << pos << " deleted successfully.\n" << endl;
   

        return;
    }
};




int main(){

    linkedList list;
    int choice;

    do{
        cout << "\n\n1.Add data At Start" << endl;
        cout << "2.search Node At Any index " << endl;
        cout << "3.Display Nodes " << endl;
        cout << "4.Delete Node " << endl;

        cout << "Input your choice : ";
        cin >> choice;

        switch(choice){
            case 1:
            {
        
                list.AddAtStart();
                break;
            }

            case 2:
            {
                
                break;
            }

            case 3 :
            {
                 list.DisplayNode();
                 break;
            }

            case 4:
            {
                list.deleteAtPosition();
                break;
            }
        }

    }while(choice != 0);

    return 0;
}