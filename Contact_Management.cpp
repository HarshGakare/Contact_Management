#include<iostream>
#include<fstream>
#include <cctype>
#include<cstdlib> 
using namespace std;

class detail{
    string Phone_No, Name, Address, Description, Search;
    fstream file;

public:
    void add_Contact();
    void show_All_Contact();
    void search_Contact();
};

int main(){
    detail D;
    char Choose;
   cout<<"\n\t Welcome in Contact Managment system\n"<<endl;
    cout << " Press A --> Add Contact " << endl;
    cout << " Press S --> Show All Contact" << endl;
    cout << " Press F --> Find Contact" << endl;
    cout << " Press E --> Exit" << endl<<endl;
    cin >> Choose;

    switch (Choose)
    {
    case 'A':
        D.add_Contact();
        break;
    case 'S':
        D.show_All_Contact();
        break;
    case 'F':
        D.search_Contact();
        break;
    case 'E':
        exit(0);
        break;
    default:
        cout << "Invalid Selection ..";
        break;
    }

    return 0;
}

void detail::add_Contact(){
    char choice = 'Y';
    
    while(choice == 'Y'){ 
        cin.ignore(); // consume newline character
        cout << "Enter Person Name : ";
        getline(cin, Name);
        cout << "Enter Phone Number : ";
        getline(cin, Phone_No);
        cout << "Enter Address : ";
        getline(cin, Address);
        cout << "Enter Description : ";
        getline(cin, Description);

        file.open("data.csv", ios::out | ios::app);
        file << Name << "," << Phone_No << "," << Address << "," << Description << endl;

        file.close();
        cout<<"\n\t Add to more contact details.......\n\tPress Y --> Yes\n\tPress N --> No"<<endl<<endl;
        cin>>choice;
    }

    cout<<"\n Press S --> show the Contact List\n Press A --> Add more contact number \n Press F --> Find Contact \n Press E --> exit\n"<<endl;
    cin>>choice;
    if(choice == 'S'){
        show_All_Contact();
    }else if(choice == 'A'){
        add_Contact();
    }else if (choice == 'F')
    {
       search_Contact();
    }
    
}

void detail::show_All_Contact(){
    file.open("data.csv", ios::in);

    if (!file.is_open()) {
         cout << "error..." << endl;
        cout << "File not found.." << endl;
        return;
    }
   cout<<"\t----------  Contact List  ----------"<<endl<<endl;
    while (getline(file, Name, ',') &&
           getline(file, Phone_No, ',') &&
           getline(file, Address, ',') &&
           getline(file, Description, '\n'))
    {
        cout << "\tPerson Name : " << Name << endl;
        cout << "\tPhone Number : " << Phone_No << endl;
        cout << "\tAddress : " << Address << endl;
        cout << "\tDescription : " << Description << endl << endl;
    }

    file.close();

    cout<<"\n Press A --> Add more contact number \n Press F --> Find Contact \n Press E --> exit\n";
    char choice;
    cin>>choice;
    if(choice == 'A'){
        add_Contact();
    }else if (choice == 'F')
    {
       search_Contact();
    }
}

void detail::search_Contact(){
    // string Search;
    cout << "Enter Person Name : ";
    cin.ignore();
    getline(cin, Search);

    file.open("data.csv", ios::in);

    if (!file.is_open()) {
        cout << "File not found or could not be opened." << endl;
        return;
    }

    while (getline(file, Name, ',') &&
           getline(file, Phone_No, ',') &&
           getline(file, Address, ',') &&
           getline(file, Description, '\n'))
    {
        if (Name == Search) {
            cout << "\n\tPerson Name : " << Name << endl;
            cout << "\tPhone Number : " << Phone_No << endl;
            cout << "\tAddress : " << Address << endl;
            cout << "\tDescription : " << Description << endl << endl;
        }
    }

    file.close();

    cout<<"\n Press S --> show the Contact List\n Press A --> Add more contact number \n Press E --> exit\n";
    char choice;
    cin>>choice;
    if(choice == 'S'){
        show_All_Contact();
    }else if(choice == 'A'){
        add_Contact();
    }
}
