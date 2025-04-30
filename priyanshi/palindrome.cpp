#include<iostream>
#include<string.h>

using namespace std;

class Stack{
    private:
        int count;
        int top;
        int size;
        string *str;

    public:
        Stack(){
            this->count = 0;
            this->top = 1;
            this->size = size;
            this->str = new string[size];
        }

        void Push(string);
        bool isPalindrome(string);
};

void Stack::Push(string s1){

    if(this->size == this->count){
        cout << "\n--------------\n";
        cout << "Stack is Full..." << endl;
        cout << "--------------\n\n";
        return;
    }

    this->top++;
    this->str[top] = s1;
    this->count++;

    cout << "\n---------------------------\n";
    cout << "Data Inserted successfully..." << endl;
    cout << "------------------------------\n\n";
}

bool Stack::isPalindrome(string s1){

    

}

int main(){

    string s1;

    Stack stack;

    cout << "Enter String : ";
    getline(cin , s1);



    return 0;
}
