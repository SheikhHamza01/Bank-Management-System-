#include <iostream>				//Libraries
#include <iomanip>				//indentation
#include <fstream>				//file
#include <string>				//string
#include <stdlib.h>				//To use some functions
using namespace std;

int index = 0;

struct Customer
{
	long long int accountNumber;
	string f_name;
	string l_name;
	string city;
	string state;
	int zip;
	long long int telephone;
	int balance;
	string date;
};

Customer num1[100];				//Structure array
string copy_data;
int add();						//Functions
int search();
int update();
int remove();
int all();
int balance();
int deposit();
int withdraw();
int transfer();
int end();
void loadData();
void saveData();
void main()
{
	loadData();						//Function to load data from file to program
	int choice;
	char input;
label:
	cout << "\t\t\t\tWelcome\n\n";
	cout << "Select your requirement from 1-10\n";
	cout << "1- Add new record\n";
	cout << "2- Search record\n";
	cout << "3- Update record\n";
	cout << "4- Delete record\n";
	cout << "5- View all record\n";
	cout << "6- Balance inquiry\n";
	cout << "7- Deposit amount\n";
	cout << "8- Withdraw amount\n";
	cout << "9- Transfer amount\n";
	cout << "10- Exit\n";
	cout << "Enter your choice\n";
	cin >> choice;
	system("cls");
	while (choice < 1 || choice>10)				//Input validation
	{
		cout << "You entered the invalid input.Please enter again.\n";
		cin >> choice;
		system("cls");
	}
	if (choice == 1)							//Selection of task
	{
		add();
	}
	else if (choice == 2)
	{
		search();
	}
	else if (choice == 3)
	{
		update();
	}
	else if(choice==4)
	{
		remove();
	}
	else if (choice == 5)
	{
		all();
	}
	else if (choice == 6)
	{
		balance();
	}
	else if (choice == 7)
	{
		deposit();
	}
	else if (choice == 8)
	{
		withdraw();
	}
	else if (choice == 9)
	{
		transfer();
	}
	if (choice == 10)
	{
		end();
	}
	else
	{

		do
		{
			cout << "\n\n\t\t\tDo you want to go back to main menu(Y/N).\n";
			cin >> input;
			system("cls");
			if (input == 'y' || input == 'Y')
			{
				goto label;
			}
			else if (input == 'n' || input == 'N')
			{
				cout << "\t\t\tThank you\n\n";
				exit;
			}
			else
			{
				cout << "Please enter the valid input.\n\n";
			}
		} while (input != 'y' && input != 'Y' && input != 'n' && input != 'N');



	}
	saveData();									//Function to save data in file
}

int add()								//Function to add new record
{
	int n = 1;

	for (int i = index; i <= index; i++)
	{
	back:
	label1:
		cout << "Please enter your account number.\n";
		cin >> num1[i].accountNumber;
		while (n)
		{
			if (!cin >> num1[i].accountNumber)
			{
				cout << "Please enter a valid input.\n";
				cin.clear();
				cin.ignore(123, '\n');
				goto label1;
				
			}
			n = 0;
			
		}
		cin.ignore();
		cout << "Please enter your fisrt name.\n";
		getline(cin, num1[i].f_name);

		cout << "Please enter your last name.\n";
		getline(cin, num1[i].l_name);

		cout << "Please enter your city.\n";
		getline(cin, num1[i].city);

		cout << "Please enter your state.\n";
		getline(cin, num1[i].state);
		label2:
		cout << "Please enter your zip code.\n";
		cin >> num1[i].zip;
		n = 1;
		while (n)
		{
			if (!cin >> num1[i].zip)
			{
			
				cout << "Please enter a valid input.\n";
				cin.clear();
				cin.ignore(123, '\n');
				goto label2;
				
			}
			n = 0;
			
		}
		label3:
		cout << "Please enter your phone number.\n";
		cin >> num1[i].telephone;
		n = 1;
		while (n)
		{
			if (!cin >> num1[i].telephone)
			{
				cout << "Please enter a valid input.\n";
				cin.clear();
				cin.ignore(123, '\n');
				goto label3;
				
			}
			n = 0;
			
		}
		label4:
		cout << "Please enter account balance in ruppees.\n";
		cin >> num1[i].balance;
		n = 1;
		while (n)
		{
			if (!cin >> num1[i].balance)
			{
				cout << "Please enter a valid input.\n";
				cin.clear();
				cin.ignore(123, '\n');
				goto label4;

			}
			n = 0;
		}
		cout << "Please enter the date of your last payment.\n";
		cout << "dd/mm/yyyy\n";
		cin >> num1[i].date;
		cout << "Your data has been added successfully.\n";
	}
	index++;
	return 0;
}				

int search()								//Function of search for a record
{
	int n;
	bool flag = 0;
	cout << "Please enter the account number which you want to search.\n";
	cin >> n;

	for (int i = 0; i < index; i++)			//Searching the whole file
	{

		if (num1[i].accountNumber == n)		//Checking to find account number
		{
			cout << setw(20) << left << "Account Number" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(15) << "City";
			cout << setw(15) << left << "State" << setw(10) << left << "Zip" << setw(15) << "Telephone" << setw(10) << "Balance";
			cout << left << "date\n\n";
			cout << setw(20) << left << num1[i].accountNumber << setw(15) << num1[i].f_name << setw(15) << num1[i].l_name;
			cout << setw(15) << left << num1[i].city << setw(15) << num1[i].state << setw(10) << num1[i].zip << setw(15) << num1[i].telephone;
			cout << setw(10) << left << num1[i].balance << setw(15) << num1[i].date << endl;
			flag = 1;
		}
	}
	if (flag == 0)						//Checking if the account number is not available
	{
		cout << "Not found\n";
	}
	return 0;
}

int update()							//Function to change existing record
{
	int acc_Num;
	cout << "Account Number you want to Update : ";
	cin >> acc_Num;
	for (int i = 0; i < index; i++)				//Reading complete file
	{
		if (acc_Num == num1[i].accountNumber)		//Check to change data
		{
			cout << "Please enter your account number.\n";
			cin >> num1[i].accountNumber;
			cin.ignore();
			cout << "Please enter your fisrt name.\n";
			getline(cin, num1[i].f_name);
			cout << "Please enter your last name.\n";
			getline(cin, num1[i].l_name);
			cout << "Please enter your city.\n";
			
			getline(cin, num1[i].city);
			cout << "Please enter your state.\n";
			
			getline(cin, num1[i].state);
			cout << "Please enter your zip code.\n";
			cin >> num1[i].zip;
			cout << "Please enter your phone number.\n";
			cin >> num1[i].telephone;
			cout << "Please enter account balance in ruppees.\n";
			cin >> num1[i].balance;
			cout << "Please enter the date of your last payment.\n";
			cout << "dd/mm/yyyy\n";
			cin >> num1[i].date;
			cout << "Data Added Successfully !";
			break;
		}
	}
	return 0;
}

int remove()
{

	return 0;
}

int all()						//Function to view all record
{
	cout << setw(20) << left << "Account Number" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(15) << "City";
	cout << setw(15) << left << "State" << setw(10) << left << "Zip" << setw(15) << "Telephone" << setw(10) << "Balance";
	cout << left << "date\n\n";

	for (int i = 0; i < index; i++)				//Writing all data on console
	{
		cout << setw(20) << left << num1[i].accountNumber << setw(15) << num1[i].f_name << setw(15) << num1[i].l_name;
		cout << setw(15) << left << num1[i].city << setw(15) << num1[i].state << setw(10) << num1[i].zip << setw(15) << num1[i].telephone;
		cout << setw(10) << left << num1[i].balance << setw(15) << num1[i].date << endl;
	}
	return 0;
}

int balance()						//Function to check available balance
{
	long long int n;
	cout << "Enter the account number whose balance you want to check.\n";
	cin >> n;
	for (int i = 0; i < index; i++)
	{
		if (num1[i].accountNumber == n)				//Checking the account number
		{
			cout << "Your current balance is " << num1[i].balance << " ruppees.\n";
			break;
		}
	}
	return 0;
}

int deposit()					//to deposit money
{
	long long int n;
	int amount;
	int pos;
	cout << "Enter the account number where you want to deposit.\n";
	cin >> n;
	cout << "Enter the value you want to deposit.\n";
	cin >> amount;
	for (int i = 0; i < index; i++)		//finding the account to deposit
	{
		if (num1[i].accountNumber == n)				//checking the account number
		{
			num1[i].balance += amount;
			cout << "Your current balance is " << num1[i].balance << " ruppees.\n";
			break;
		}
	}
	return 0;
}

int withdraw()					//To witdraw money
{
	long long int n;
	int amount;
	cout << "Enter the account number from where you want to withdraw.\n";
	cin >> n;
	cout << "Enter the value you want to withdraw.\n";
	cin >> amount;
	for (int i = 0; i < index; i++)				//Finding account
	{

		if (num1[i].accountNumber == n)			//Checking account
		{

			num1[i].balance -= amount;
			cout << "Your current balance is " << num1[i].balance << " ruppees.\n";
		}
	}

	return 0;
}

int transfer()			//To transfer from one account to another
{
	int input_amount, sending_Acc, Recieving_Acc;
	cout << "Enter Account Number From which you to want to transfer : ";
	cin >> sending_Acc;
	cout << "Enter The Account Number in which you want to Transfer your amount : ";
	cin >> Recieving_Acc;
	cout << "Enter amount you want to transfer : ";
	cin >> input_amount;
	for (int i = 0; i < index; i++)			//Reading the file
	{
		for (int j = 1; j < index; j++)		
		{
			if (sending_Acc == num1[i].accountNumber)		//finding account from which the money is transferred
			{
				if (Recieving_Acc == num1[j].accountNumber)		//finding account to which the money is transferred
				{
					num1[i].accountNumber -= input_amount;
					num1[j].accountNumber += input_amount;
				}
			}
		}
	}

	return 0;
}

int end()
{
	cout << "\t\t\t Hope you satisty from our facilities.\n\t\t\t\t Thank you\n\n";
	exit;
	return 0;
}

void loadData()				//Function to save load data from file to the program
{
	fstream input;
	input.open("Management System.txt", ios::in);
	if (!input)
	{
		return;
	}
	else
	{
		string oneLineData;
		int startingIndex;
		int endingIndex;
		for (; !input.eof();) 
		{
			if (input.eof())
			{
				break;
			}
			input >> oneLineData;
			string subString = "";
			startingIndex = 0;
			endingIndex = oneLineData.find(',', startingIndex);
			for (int j = startingIndex; j < endingIndex; j++)
			{
				subString += oneLineData[j];
			}
			num1[index].accountNumber = stoi(subString);
			subString = "";
			startingIndex = endingIndex + 1;
			endingIndex = oneLineData.find(',', startingIndex);
			for (int j = startingIndex; j < endingIndex; j++)
			{
				subString += oneLineData[j];
			}
			num1[index].f_name = subString;
			subString = "";
			startingIndex = endingIndex + 1;
			endingIndex = oneLineData.find(',', startingIndex);
			for (int j = startingIndex; j < endingIndex; j++)
			{
				subString += oneLineData[j];
			}
			num1[index].l_name = subString;
			subString = "";
			startingIndex = endingIndex + 1;
			endingIndex = oneLineData.find(',', startingIndex);
			for (int j = startingIndex; j < endingIndex; j++)
			{
				subString += oneLineData[j];
			}
			num1[index].city = subString;
			subString = "";
			startingIndex = endingIndex + 1;
			endingIndex = oneLineData.find(',', startingIndex);
			for (int j = startingIndex; j < endingIndex; j++)
			{
				subString += oneLineData[j];
			}
			num1[index].state = subString;
			subString = "";
			startingIndex = endingIndex + 1;
			endingIndex = oneLineData.find(',', startingIndex);
			for (int j = startingIndex; j < endingIndex; j++)
			{
				subString += oneLineData[j];
			}
			num1[index].zip = stoi(subString);
			subString = "";
			startingIndex = endingIndex + 1;
			endingIndex = oneLineData.find(',', startingIndex);
			for (int j = startingIndex; j < endingIndex; j++)
			{
				subString += oneLineData[j];
			}
			num1[index].telephone = stoi(subString);
			subString = "";
			startingIndex = endingIndex + 1;
			endingIndex = oneLineData.find(',', startingIndex);
			for (int j = startingIndex; j < endingIndex; j++)
			{
				subString += oneLineData[j];
			}
			num1[index].balance = stoi(subString);
			subString = "";
			startingIndex = endingIndex + 1;
			endingIndex = oneLineData.find(',', startingIndex);
			for (int j = startingIndex; j < endingIndex; j++)
			{
				subString += oneLineData[j];
			}
			num1[index].date = subString;
			index++;
		}
		index--;

	}
	input.close();
}

void saveData()				//Function to save data from program to file
{
	fstream output;
	output.open("Management System.txt", ios::out);
	for (int i = 0; i < index; i++)
	{
		output << num1[i].accountNumber << ",";
		output << num1[i].f_name << ",";
		output << num1[i].l_name << ",";
		output << num1[i].city << ",";
		output << num1[i].state << ",";
		output << num1[i].zip << ",";
		output << num1[i].telephone << ",";
		output << num1[i].balance << ",";
		output << num1[i].date << ",\n";
	}
	output.close();
}