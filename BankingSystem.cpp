#include <iostream>
using namespace std;

//Class for the bank account
class bankAccount {
private: //Privated variables
	string accountHolderName;
	int accountNumber;
	double balance;

public: //Public member functions
	
	//Constructor initializer
	bankAccount(double Depos, const string& Name) { balance = Depos; accountHolderName = Name; accountNumber = rand(); }

	//Takes the request and verifies name, then subtracts, if not, cancel
	double withdraw(double amount, string name) {
		if (name != "" && balance >= amount) {
			cout << "Verified for account " << accountNumber << ", " << name << endl;
			balance -= amount;
		}
		else
			cout << "No account detected or withdraw request invalid. Withdrawl not processed." << endl;
		return balance;
	}

	//Takes the request and verifies name, then adds, if not, cancel
	double deposit(double ammount, string name) {
		if (name != "") {
			cout << "Verified for account " << accountNumber << ", " << name << endl;
			balance += ammount;
		}
		else
			cout << "No account detected. Deposit not processed." << endl;
		return balance;
	}

	//Returns private variable balance
	double getBalance() {
		return balance;
	}
};

//Takes the request and reads it back
void withdraw(double Outtake) {
	cout << "Withdraw request: " << Outtake << endl;
}

//Takes the request and reads it back
void deposit(double Intake) {
	cout << "Deposit request: " << Intake << endl;
}

//Retrieves data from variables, then displays them
void displayBalance(double Display, string name) {
	cout << endl;
	cout << "Account for: " << name << endl;
 	cout << "Your balance is : " << Display << endl;
}

int main() {
	//Starting variables, blank slate
	double ATM = 0; 
	string Name = "";
	//Access privatized variables 
	bankAccount Acc(ATM, Name);
	int choice;
	//Main Menu
	cout << "Welcome to the Simple Bank System" << endl;
	do {
		cout << endl; 
		cout << "1. Create an account" << endl;
		cout << "2. Withdraw money" << endl;
		cout << "3. Deposit money" << endl;
		cout << "4. Check balance" << endl;
		cout << "5. Exit" << endl;
		cout << endl;
		cout << "Enter your choice" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			if (Name == "") {
				cout << "Enter account name: " << endl;
				cin >> Name;
				cout << "Account created successfully!" << endl;
				cout << "How much would you like to Deposit?" << endl;
				cin >> ATM;
				cout << endl;
				//Input request
				deposit(ATM);
				double Intake = Acc.deposit(ATM, Name);
				//Output request
				cout << endl;
			}
			else
				cout << "You already have an account." << endl;
		}
			break;
		case 2: {
			cout << "How much would you like to withdraw?" << endl;
			cin >> ATM;
			cout << endl;
			//Input request
			withdraw(ATM);
			double Outtake = Acc.withdraw(ATM, Name);
			//Output request
			cout << endl;
		}
			break;
		case 3: {
			cout << "How much would you like to Deposit?" << endl;
			cin >> ATM;
			cout << endl;
			//Input request
			deposit(ATM);
			double Intake = Acc.deposit(ATM, Name);
			//Output request
			cout << endl;
		}
			break;
		case 4: {
			//Show the balance from data request
			double Display = Acc.getBalance();
			displayBalance(Display, Name);
			cout << endl;
		}
			break;
		}

		//Throws an error if user tries to withdraw or deposit before making an account
		//*Missing error handling on non-numeric inputs, hard to implement with a loop like this and time constraint
		try {
			if (Name == "")
				throw runtime_error("Account not created. You MUST create an account.");
		}
		catch (const exception& e) {
			cout << "Warning: " << e.what() << endl;
		}
	} while (choice != 5);
	return 0;
}