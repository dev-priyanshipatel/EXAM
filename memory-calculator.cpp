#include<iostream>
#include<vector>

using namespace std;

class MemoryCalc{
    private :

        int id;
        string name;

    public : 

        MemoryCalc(int id, string name){

            this->id = id;
            this->name = name;

        }

        void displayStudentDetail(){

            cout << "\n---------------------------\n";
            cout << "Student Name : " << this->name << endl;
            cout << "Student ID : " << this->id << endl;
            cout <<"\n----------------------------\n\n";

        }
        
        int getId() {

            return this->id;
        }

        

};

int main(){

    vector<MemoryCalc> student;
    int choice;

    do{
        cout << "\n---------------------------\n";
        cout << "0. Exit " << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students " << endl;
        cout << "3. Remove Students by ID " << endl;
        cout << "4. Search Student by ID " << endl;
        cout << "Enter choice : ";
        cin >> choice;

        switch(choice){
            case 0:
            {
                cout << "\n---------------------------\n";
                cout << "Exiting...";
                cout <<"\n----------------------------\n\n";

                break;
            }

            case 1:
            {
                int id;
                string name;

                cout << "Enter the ID : ";
                cin >> id;

                cin.ignore();

                cout << "Enter Name : ";
                getline(cin, name);

                student.push_back(MemoryCalc(id, name));

                cout << "\n---------------------------\n";
                cout << "student added successfully...";
                cout <<"\n----------------------------\n\n";
                break;
            }

            case 2:
            {
        
                for(auto val : student){
                    val.displayStudentDetail();
                }

                break;
            }

            case 3:
            {
                int id;

                cout << "Enter ID : ";
                cin >> id;
                bool isFound = false;
                for(auto i = student.begin(); i != student.end(); i++){

                    if(i->getId() == id){
                        isFound = true;
                        student.erase(i);

                        cout << "\n---------------------------\n";
                        cout << "student deleted successfully...";
                        cout <<"\n----------------------------\n\n";
                        break;
                    }
                }

                if(isFound == false){

                    cout << "\n---------------------------\n";
                    cout << "student not found...";
                    cout <<"\n----------------------------\n\n";
                }
                break;
            }

            case 4:
            {
                int id;

                cout << "Enter ID : ";
                cin >> id;
                bool isFound = false;
                for(auto i = student.begin(); i != student.end(); i++){

                    if(i->getId() == id){
                        isFound = true;
                        i->displayStudentDetail();

                        cout << "\n---------------------------\n";
                        cout << "student searched successfully...";
                        cout <<"\n----------------------------\n\n";
                        break;
                    }
                }

                if(isFound == false){

                    cout << "\n---------------------------\n";
                    cout << "student not found...";
                    cout <<"\n----------------------------\n\n";
                }
                break;
            }
        }
    }while(choice != 0);
    return 0;
}