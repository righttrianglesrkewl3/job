// KZ 3-3-21
// ATM App

#include <iostream>
#include <vector> // to get the vector class definition
using std::vector;
using namespace std;

// TODO: Add functionaliry for inheritance to "make sense"
class Bank {
public:
    string m_Greeting { "Welcome to Kevins Bank" };
    int m_YearsOpen { 20 };

    void greetCustomer(){
        cout << m_Greeting << endl;
        cout << "Serving you for " << m_YearsOpen << " years! \n"; 
        cout<<"#############################################################"<<endl;  
        cout<<"#                  _  _                                     #"<<endl;  
        cout<<"#                 ( `   )_                                  #"<<endl;  
        cout<<"#                (    )    `)                               #"<<endl;  
        cout<<"#              (_   (_ .  _) _)                             #"<<endl;  
        cout<<"#                                             _             #"<<endl;  
        cout<<"#                                            (  )           #"<<endl;  
        cout<<"#             _ .                         ( `  ) . )        #"<<endl;  
        cout<<"#           (  _ )_                      (_, _(  ,_)_)      #"<<endl;  
        cout<<"#         (_  _(_ ,)                                        #"<<endl;  
        cout<<"#############################################################"<<endl;
    }
};

class Client : public Bank {
public:
    string m_Name;
    float m_Balance = 0;
    int m_AccountNum;

public:
    Client(string sName, float fBalance, int accountNum)
    {
        m_Name = sName;
        m_Balance = fBalance;
        m_AccountNum = accountNum;  
    }

    void setInfo (string sName, float fBalance, int accountNum){
        m_Name = sName;
        m_Balance = fBalance;
        m_AccountNum = accountNum;
    }

    void showInfo(){
        cout << "Name: " << m_Name << endl;
        cout << "Balance: " << m_Balance << endl;
        cout << "Account Number: " << m_AccountNum << endl;
        cout << endl;
    }

};

int main()
{
    int ch;
    int acno;
    char name[30];
    long balance;
    int total { 0 };
    vector<Client> clients;

    Bank bank;
    
    do {
        // display options
        cout << "\n\n1: Add client \n2: Display All" << endl;

        // user input 
        cout << "Please enter your choice: ";
        cin >> ch;

    // TODO: need to assert correct cin types or program crashes
    switch(ch) {
        case 1: // Add customer
        bank.greetCustomer();
        
        cout << "Enter Account Number: ";
        cin >> acno; // need to assert
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Balance: ";
        cin >> balance;
        
        clients.push_back(Client (name, float(balance), acno));
        total ++;
        break;

        case 2: // Display All
            cout << "Total # of clients = " << total << endl;
            for (int i=0; i <= clients.size()-1; i++){
                clients[i].showInfo();
                // cout << "name" << clients[i].m_Name; how to access class attributes for reference
            }
        break;
        
    default:
        cout << "Wrong Option" << endl;
    }

    } while (ch != 5);
    return 0;
}
