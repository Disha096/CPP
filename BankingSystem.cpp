#include<iostream>
#include<string>
#include<vector>
using namespace std;

class BankAccount{
	private:
		
	    string name;
	    int accNo;
	    double balance;
	    static int nextAccNo;

	public:
		
	    void createBankAccount(string n, double b) {
	        name = n;
	        accNo = nextAccNo++;
	        balance = b;
	    }
	    
	    int getAccNo(){
	    	return accNo;
		}
		
		string getName(){
			return name;
		}
		
		double getBalance(){
			return balance;
		}
		
		void deposit(double amt){
			if(amt > 0){
				balance = balance + amt;
				cout<<"Amount Deposited Successfully!!"<<endl;
			}
			else{
				cout<<"Invalid Deposit Amount."<<endl;
			}
		}
		
		void withdraw(double amt){
			if(amt <= 0){
				cout<<"Invalid withdrawal amount."<<endl;
			}
			else if(amt > balance){
				cout<<"Insufficient balance!!"<<endl;
			}
			else{
				balance = balance - amt;
				cout<<"Amount Withdrawn  Successfully!!"<<endl;
			}
		}
		
		void Display(){
			cout << "\nAccount Holder: " << name;
	        cout << "\nAccount Number: " << accNo;
	        cout << "\nBalance: " << balance <<endl;
		}
		
		

};

int BankAccount::nextAccNo = 100;

int main(){
	vector<BankAccount> accounts;
	int ch;
	string name;
    int accNo ,counter;
    double bal , amt;
    BankAccount acc;
	
	do{
		
		cout << "\n******************* Bank Management System *******************";
	    cout << "\n1. Create Account";
	    cout << "\n2. Deposit Money";
	    cout << "\n3. Withdraw Money";
	    cout << "\n4. Display Account";
	    cout << "\n5. Exit";
	    cout << "\n Enter choice: ";
	    cin >> ch;    
		
		switch(ch){
			
			case 1: 
				cout << "Enter Name: ";
	            cin.ignore();
	            getline(cin, name);
	            cout << "Enter Initial Balance: ";
	            cin >> bal;
	           
                acc.createBankAccount(name, bal); 
                accounts.push_back(acc);
	            cout << "Account Created Successfully!!\n";
	            acc.Display();
				break;
			
			case 2:
				cout << "Enter Account Number: ";
                cin >> accNo;
                counter = 0;

                for (int i = 0; i < accounts.size(); i++) {
                    if (accounts[i].getAccNo() == accNo) {
                    	cout << "Name: " << accounts[i].getName() << endl;
                        cout << "Enter Amount to Deposit: ";
                        cin >> amt;
                        accounts[i].deposit(amt);
                        counter = 1;
                        cout << "Current Balance: " << accounts[i].getBalance() << endl;
                        break;
                    }
                }
                if (counter == 0) {
				cout << "Account not found."<<endl;
				cout<<"Use valid / Existing Account number."<<endl;
                break;
            	}
				
				break;  	
            	
            case 3:
				cout << "Enter Account Number: ";
                cin >> accNo;
                counter = 0;

                for (int i = 0; i < accounts.size(); i++) {
                    if (accounts[i].getAccNo() == accNo) {
                    	cout << "Name: " << accounts[i].getName() << endl;
                        cout << "Enter Amount to Withdraw: ";
                        cin >> amt;
                        accounts[i].withdraw(amt);
                        counter = 1;
                        cout << "Current Balance: " << accounts[i].getBalance() << endl;
                        break;
                    }
                }
                if (counter == 0) {
				cout << "Account not found."<<endl;
				cout<<"Use valid / Existing Account number."<<endl;
                break;
            	} 
				
				break; 	
			
			case 4:
				cout << "Enter Account Number: ";
                cin >> accNo;
                counter = 0;

                for (int i = 0; i < accounts.size(); i++) {
                    if (accounts[i].getAccNo() == accNo) {
                    	accounts[i].Display();
                        counter = 1;
                        break;
                    }
                }
                if (counter == 0) {
				cout << "Account not found."<<endl;
				cout<<"Use valid / Existing Account number."<<endl;
                break;
            	}  
				break;	
            	
            case 5:
                cout << "Thank you for using the system.\n";
                break;
				
			default:
                cout << "Invalid choice.\n";	
					
		}
		
	}while(ch!=5);
	
	
	
	return 0;
}