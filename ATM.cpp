#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;
#define ll long long

//-------------------------GLOBAL_VARIABLES------------------------

ll income;
ll strength = 0;
ll DD, MM, YY;
ll basicAmount = 0;
ll amount;
ll balance = 0;
ll withdrawAmount = 0;
ll password;
ll count;
ll CNIC;
ll phone;
string name;
string occupation;
string fatherName;
string address;
string email;

//-------------------------ACCOUNT_OPENING--------------------------

void accoundOpening()
{
    int i;
    // for file creation {ofstream}
    ofstream file("std.txt");
    if (!file)
    {
        cout << "File not created" << endl;
    }
    else
    {
        cout << "How many people record you want to store?" << endl;
        cin >> strength;
        for (i = 0; i < strength; i++)
        {
            cin.ignore();
            cout << endl;
            cout << "Enter record " << i + 1 << " person!" << endl;
            cout << endl;

            cout << "Your Name: " << endl;
            getline(cin, name);
            cout << endl;

            cout << "Your Occupation: " << endl;
            getline(cin, occupation);
            cout << endl;

            cout << "Father Name: " << endl;
            getline(cin, fatherName);
            cout << endl;

            cout << "Address: " << endl;
            getline(cin, address);
            cout << endl;

            cout << "Your CNIC number: " << endl;
            cin >> CNIC;
            cout << endl;

            cout << "Your phone number: " << endl;
            cin >> phone;
            cout << endl;

            cout << "Your income per month: " << endl;
            cin >> income;
            cout << endl;

            cout << "Your date of birth: " << endl;
            cin >> DD >> MM >> YY;
            cout << endl;

            cout << "Basic Amount: " << endl;
            cin >> basicAmount;
            cout << endl;

            cout << "Your E-mail Address: " << endl;
            getline(cin, email);
            cout << endl;

            cout << "Enter password of 4-digit" << endl;
            cin >> password;
            cout << endl;
            cout << "Congratulations!!!!! Your account has been successfully created..." << endl;
            cout << endl;

            file << "<------------------------------";
            file << i + 1;
            file << "-person------------------------------>";
            file<<endl;
            file << "ID: "<<i+1<<endl;
            file << "Name: " << name << endl;
            file << "Occupation: " << occupation << endl;
            file << "Father Name: " << fatherName << endl;
            file << "Address: " << address << endl;
            file << "CNIC: " << CNIC << endl;
            file << "Phone: " << phone << endl;
            file << "Income: " << income << endl;
            file << "Date of Birth: " << DD << "/" << MM << "/" << YY << endl;
            file << "Basic Amount: " << basicAmount << endl;
            file << "Email: " << email << endl;
            file << "Password: " << password << endl;
        }
    }
}

void displaying()
{
    system("cls");
    string text;
    ifstream outfile("std.txt");
    while (getline(outfile, text))
    {
        cout << text << endl;
        cout << endl;
    }
    outfile.close();
}

void deposit()
{
    ofstream file("std.txt");
    cout << "\nEnter amount to deposit:" << endl;
    cin >> amount;
    balance += amount + basicAmount;
    cout << "\nYou deposited amount of ->" << amount << " successfully and your current balance is -> " << balance;
    file << "balance:" << balance << endl;
}

void withdraw()
{
    ofstream file("std.txt");
    cout << "\nKindly enter amount to withdraw:" << endl;
    cin >> withdrawAmount;
    balance -= withdrawAmount;
    cout << "\nYou withdraw amount of ->" << withdrawAmount << " successfully and your current balance is -> " << balance;
    file << "balance:" << balance << endl;
}

void end();

void dis()
{
    system("CLS");
    cout<<"-----------------------------------------"<<endl;
    cout<<"---->          Bank System          <----"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"             Choose Option!              "<<endl;
    cout<<"\n-------> Press 1 for open a new account "<<endl;
    cout<<"\n-------> Press 2 for see details "<<endl;
    cout<<"\n-------> Press 3 for deposit "<<endl;
    cout<<"\n-------> Press 4 for withdraw "<<endl;
}

int main()
{
    int choice;
    dis();
    cin>>choice;
    switch(choice){
        case 1:
            accoundOpening();
            end();
            break;
        case 2:
            displaying();
            end();
            break;
        case 3:
            deposit();
            end();
            break;
        case 4:
            withdraw();
            end();
            break;
        case 5: 
            exit(0);
            break;
        default:
        cout<<"Wrong Choice!"<<endl;
    }
    return 0;
}

void end(){
    cout<<"\n Press Enter: ";
    getch();
    system("CLS");
    cout<<"\n-----------------------------------------------\n";
    char a;
    cout<<"\n\t Press y to go to main menu: "<<endl;
    cout<<"\tPress n to exit from program: "<<endl;
    cout<<"Enter your option: ";
    cin>>a;
    if(a=='y' or a=='Y'){
        main();
    }else if(a=='n' or a=='N'){
        exit(0);
    }
    else{
        cout<<"Wrong Output: "<<endl;
        end();
    }
}