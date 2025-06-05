#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

struct Contact
{
        string name;
        string phone;
        string email;
        string address;
};

//Loading contacts from a file
vector<Contact> loadcontacts(){
        vector<Contact> contact;
        // Load contacts from a file or database
        ifstream file("mycontacts.txt");
        
        if (!file) {
        cerr << "Error opening file" << endl;
        return contact;
    }
        Contact c;
        while(getline(file, c.name) && 
              getline(file, c.phone) && 
              getline(file, c.email) && 
              getline(file, c.address)) {
            contact.push_back(c);
        }
        file.close();
        // For now, we will return an empty vector
        return contact;
}


// saving the contacts
void savecontacts(vector<Contact>& contact)
{
        ofstream file("mycontacts.txt");
        for(auto &c: contact)
        {
                file<<c.name<<endl;
                file<<c.phone<<endl;
                file<<c.email<<endl;    
                file<<c.address<<endl;          
        }
        file.close();
}

//adding contacts
void addcontact()
{
    // Implementation for adding a contact goes here
    Contact c;
    cout<<"Enter Name: ";       
    getline(cin,c.name);
    cout<<"Enter Phone: ";
    getline(cin,c.phone);
    cout<<"Enter Email: ";
    getline(cin,c.email);
    cout<<"Enter Address: ";
    getline(cin,c.address);

    ofstream file("mycontacts.txt", ios::app);
    file<<c.name<<endl;
    file<<c.phone<<endl;
    file<<c.email<<endl;
    file<<c.address<<endl;

    file.close();
    cout<<"Contact added successfully!"<<endl;
}

void searchcontact()
{
        string searchname;
        cout << "Enter the name to search: ";
        getline(cin, searchname);
        
        vector<Contact> contact = loadcontacts();
        bool found = false;
        for (auto& c : contact) 
        {
                if (c.name == searchname) 
                {
                        cout << "Name: " << c.name << endl;
                        cout << "Phone: " << c.phone << endl;
                        cout << "Email: " << c.email << endl;
                        cout << "Address: " << c.address << endl;
                        found = true;
                        break;
                }
        }
        
        if (!found) 
        {
                cout << "Contact not found!" << endl;
        }
}

void edit()
{
   string name;
        cout << "Enter the name of the contact to edit: ";
        getline(cin, name);
        vector<Contact> contact = loadcontacts();
        bool found = false;
        for(auto &c: contact)
        {
                if(c.name == name)
                {
                        found = true;
                        cout << "Editing contact: " << c.name << endl;
                        cout << "Enter new phone (or press Enter to keep current): ";
                        string newPhone;
                        getline(cin, newPhone);
                        if (!newPhone.empty()) {
                            c.phone = newPhone;
                        }
                        
                        cout << "Enter new email (or press Enter to keep current): ";
                        string newEmail;
                        getline(cin, newEmail);
                        if (!newEmail.empty()) {
                            c.email = newEmail;
                        }
                        
                        cout << "Enter new address (or press Enter to keep current): ";
                        string newAddress;
                        getline(cin, newAddress);
                        if (!newAddress.empty()) {
                            c.address = newAddress;
                        }
                        
                        savecontacts(contact);
                        cout << "Contact updated successfully!" << endl;
                }
        }
}

void dlt()
{
        string name;
        cout << "Enter the name of the contact to delete: ";
        cin.ignore();
        getline(cin, name);
        
        vector<Contact> contact = loadcontacts();
        bool found = false;
        
        for (auto it = contact.begin(); it != contact.end(); it++)
        {
                if (it->name == name) 
                {
                found = true;
                contact.erase(it);
                cout << "Contact deleted successfully!" << endl;
                break;
                }
        }
        
        if (!found) 
        {
                cout << "Contact not found!" << endl;
        } 
        else 
        {
                savecontacts(contact);
        }
}

int main()
{
    short int choice;
    cout << "Contact Management System\n" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. Search Contacts" << endl;
    cout << "3. Edit" << endl;
    cout << "4. Delete" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin>>choice;
    cin.ignore();
    
    switch(choice)
    {
        case 1: addcontact();
                break;
        case 2: searchcontact();
                break;
        case 3: edit();
                break;
        case 4: dlt();
                break;
        default: cout << "Invalid choice! Press any key to continue." << endl;
    }while(choice!=5)
    return 0;
}

