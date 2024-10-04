#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Bank
{
    string name, abcd, acc_no, name1, line, deleteline, str, acc_no1, str1, princi, depo, princi2, search, with;
    int princi1, princi4, with1;

public:
    void addAccount();
    void showAll();
    void searchAcc();
    void deposit();
    void withdraw();
    void deleteAcc();
    void inquiry();
} obj;

int main()
{

    char choice;
    cout << "----------------------------" << endl;
    cout << "1-Create New Account" << endl;
    cout << "2-Show All Account" << endl;
    cout << "3-Search Account" << endl;
    cout << "4-Deposit Money" << endl;
    cout << "5-Withdraw Money" << endl;
    cout << "6-Delete Account" << endl;
    cout << "7-Banking Inquiry" << endl;
    cout << "8-Exit" << endl;
    cout << "----------------------------" << endl;

    cout << "Enter your Choice :" << endl;
    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.addAccount();
        break;
    case '2':
        cin.ignore();
        obj.showAll();
        break;
    case '3':
        cin.ignore();
        obj.searchAcc();
        break;
    case '4':
        cin.ignore();
        obj.deposit();
        break;
    case '5':
        cin.ignore();
        obj.withdraw();
        break;
    case '6':
        cin.ignore();
        obj.deleteAcc();
        break;
    case '7':

        break;
    case '8':
        return 0;
        break;

    default:
        cout << "Invalid Code........" << endl;
        break;
    }
}

void Bank ::addAccount()
{
    cout << "\nEnter Account Number :: " << endl;
    getline(cin, acc_no);
    cout << "Enter your Name :: " << endl;
    getline(cin, name);
    cout << "Enter the Principal Amount :: " << endl;
    getline(cin, princi);

    ofstream fout;
    fout.open("bank.txt", ios::app);
    fout << acc_no << "*" << name << "*" << princi << endl;
    fout.close();
};

void Bank ::showAll()
{
    ifstream fin;
    fin.open("bank.txt");
    getline(fin, acc_no, '*');
    getline(fin, name, '*');
    getline(fin, princi, '\n');
    cout << "\n\n\n";
    cout << "\t\t\t\tAccount No.\t\t\t\t\tName\t\t\t\t\tPrinicipal Amt." << endl;

    while (!fin.eof())
    {
        cout << "\t\t\t\t" << acc_no << "\t\t\t\t\t\t" << name << "\t\t\t\t\t" << princi << endl;
        getline(fin, acc_no, '*');
        getline(fin, name, '*');
        getline(fin, princi, '\n');
    }

    fin.close();
}

void Bank::searchAcc()
{
    cout << "Enter Account Number : " << endl;
    cin >> search;

    ifstream fin;
    fin.open("bank.txt");
    getline(fin, acc_no, '*');
    getline(fin, name, '*');
    getline(fin, princi, '\n');
    cout << "\n\n\n";
    cout << "\t\t\t\tAccount No.\t\t\t\t\tName\t\t\t\t\tPrinicipal Amt." << endl;

    while (!fin.eof())
    {
        if (search == acc_no)
        {
            cout << "\t\t\t\t" << acc_no << "\t\t\t\t\t\t" << name << "\t\t\t\t\t" << princi << endl;
            cout << "\t\t\t\tAccount Found successfully" << endl;
        }

        getline(fin, acc_no, '*');
        getline(fin, name, '*');
        getline(fin, princi, '\n');
    }

    fin.close();
}

void Bank ::deposit()
{

    cout << "Enter Account Number : " << endl;
    cin >> search;
    cout << "Enter the amount of Money to be Deposited :: " << endl;
    cin >> depo;

    fstream file, file1;
    file.open("bank.txt", ios::in);
    file1.open("data1.txt", ios::out | ios::app);
    // file >> acc_no >> name >> princi;
    // ifstream fin;
    // fin.open("bank.txt");
    getline(file, acc_no, '*');
    getline(file, name, '*');
    getline(file, princi, '\n');

    while (!file.eof())
    {
        if (search == acc_no)
        {
            cout << "Current Amount :: " << princi << endl;
            princi1 = stoi(depo) + stoi(princi);
            princi2 = to_string(princi1);
            cout << "Updated Amount :: " << princi2 << endl;
            file1 << acc_no << '*' << name << '*' << princi2 << endl;
        }
        else
        {
            file1 << acc_no << '*' << name << '*' << princi << endl;
        }
        // file>>acc_no>>name>>princi>>endl;
        getline(file, acc_no, '*');
        getline(file, name, '*');
        getline(file, princi, '\n');
    }
    file.close();
    file1.close();
    remove("bank.txt");
    rename("data1.txt", "bank.txt");
};

void Bank ::withdraw()
{

    cout << "Enter Account Number : " << endl;
    cin >> search;
    cout << "Enter the amount of Money to Withdraw :: " << endl;
    cin >> with;

    fstream file, file1;
    file.open("bank.txt", ios::in);
    file1.open("data1.txt", ios::out | ios::app);

    getline(file, acc_no, '*');
    getline(file, name, '*');
    getline(file, princi, '\n');
    // princi1 = stoi(princi) - stoi(with);
    // princi4 = stoi(princi);
    with1 = stoi(with);
    princi2 = to_string(princi1);
    while (!file.eof())
    {
        if (search == acc_no)
        {
            if (princi4 > with1)
            {
                cout << "Current Amount :: " << princi << endl;
                princi1 = stoi(princi) - stoi(with);
                princi2 = to_string(princi1);
                cout << "Updated Amount :: " << princi2 << endl;
                file1 << acc_no << '*' << name << '*' << princi2 << endl;
            }
            else
            {
                cout << "Not sufficient Balance" << endl;
            }
        }
        else
        {
            file1 << acc_no << '*' << name << '*' << princi << endl;
        }
        // file>>acc_no>>name>>princi>>endl;
        getline(file, acc_no, '*');
        getline(file, name, '*');
        getline(file, princi, '\n');
    }
    file.close();
    file1.close();
    remove("bank.txt");
    rename("data1.txt", "bank.txt");
};

void Bank ::deleteAcc()
{

    cout << "Enter the account number : " << endl;
    cin >> search;

    fstream file, file1;
    file.open("bank.txt", ios::in);
    file1.open("data1.txt", ios::out | ios::app);
    getline(file, acc_no, '*');
    getline(file, name, '*');
    getline(file, princi, '\n');
    while (!file.eof())
    {
        if (search == acc_no)
        {
            // name = "";
            // acc_no = "";
            // princi = "";
            // file << acc_no << name << princi << endl;
            // std::string line;
            // while (getline(file, line))
            // {
            //     if (!line.empty())
            //     {
            //         file1 << line << '\n';
            //     }
            // }
            //   file1 << acc_no << name << princi << endl;
            cout<<"Your Account Number "<<acc_no<<" have been successfully Deleted"<<endl;
        }
        else
        {
            file1 << acc_no << '*' << name << '*' << princi << endl;
            
        }
        getline(file, acc_no, '*');
        getline(file, name, '*');
        getline(file, princi, '\n');
    }
    file.close();
    file1.close();
    remove("bank.txt");
    rename("data1.txt", "bank.txt");
};
