#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<ctime>
using namespace std;

void checkUserName(string userName, string uPassword);
string userLogin();
int adminLogin();

struct person {

	string id;
	string fname;
	string lname;
	int age = 0;
	string address;
	double salary = 0;
};

struct bakeryItem {

	string name;
	string code;
	string Qty;
	float price = 0;
};

// Function to display the display bakery name.
void displayBakeryName() {
	cout << endl << "=====================================   WELCOME TO BUN TALK!   =====================================================";
	cout << endl << endl;
}


void mainLogin() {
	string i;
	int op;


	do {
		displayBakeryName();
		cout << "1. Login " << endl
			<< "2. help " << endl
			<< "3. exit " << endl
			<< "Enter your Option . . . ";
		cin >> op;
		cout << endl;

		switch (op) {

		case 1:
			break;

		case 2:
			cout << endl
				<< "i) Login:" << endl
				<< "  - Login for an account as per your user name and password." << endl << endl
				<< "ii) User Access and Permissions:" << endl
				<< "  - If you have multiple employees, set up user accounts with varying levels of access and permissions." << endl
				<< "    This ensures that only authorized personnel can access sensitive data.(only 3 more attempts are allowed" << endl << endl
				<< "iii) Create a Product Database:" << endl
				<< "   - Add all your bakery products to the system, including their names, prices," << endl
				<< "     and any relevant categories(e.g., pastries, cakes)." << endl << endl
				<< "iv) Calculating the Total:" << endl
				<< "  - The system should automatically calculate the total cost based on the selected." << endl << endl
				<< "v) Generating Receipt : " << endl
				<< " - Once the payment is processed, generate an invoice or receipt." << endl
				<< "   Ensure it includes all necessary information such as the date, items purchased, and total amount paid." << endl << endl
				<< "vi) Print Receipt:" << endl
				<< "  - Provide a physical or digital copy of the receipt to the customer as per their preference." << endl << endl
				<< "vii) Adding New Employee's Data:" << endl
				<< "   - Add employees' information to the system, including their names, Address," << endl
				<< "     and any relevant informaton(e.g., Age, salary)." << endl << endl
				<< "viii) Exit:" << endl
				<< "    - You must logout to exit." << endl << endl
				<< "Enter any key to back . . .";
			cin >> i;
			cout << endl;
			if (i == "") {
				op = 0;
			}
			else {
				op = 0;
			}
			break;

		case 3:
			exit(0);

		default:
			cout << "_____________________________ Invalid option! _____________________________" << endl << endl;
			op = 5;
			break;
		}

	} while ((op < 1) || (op > 3));
}

// function to get user type and login
string userLogin() {
	string userType, choice;

	do {
		cout << "Please enter user type (admin/cashier) : ";
		cin >> userType;
		cout << endl;

		if (userType == "admin") {
			checkUserName("admin", "admin123");
			choice = userType;
			break;
		}
		else if (userType == "cashier") {
			checkUserName("cashier", "cashier123");
			choice = userType;
			break;
		}
		else {
			cout << "-------------------- Invalid insert! ------------------------" << endl << endl;
		}


	} while (true);

	return choice;
}

// function to check user name and password
void checkUserName(string userName, string uPassword) {
	string user, password;
	int n = 4;

	cout << "User name : ";
	cin >> user;
	cout << "Password : ";
	cin >> password;
	cout << endl;

	do {
		if ((user == userName) && (password == uPassword)) {
			break;
		}
		else if (n == 1) {
			cout << "<<<<<< !!! Access denied >>>>>>" << endl;
			exit(0);
		}
		else {
			--n;
			cout << endl << "<--------- invalid user name or password --------->" << endl
				<< "try again...!" << "\t\t  attempts available : " << n << endl << endl;
			cout << "User Name : "; cin >> user;
			cout << "Password : "; cin >> password;
			cout << endl;
		}
	} while (n >= 1);
	cout << "- - - - - - - - - - -   Logged in successfully - - - - - - - - - - - - - - -  " << endl;
	cout << " - - - - - - - - - - -                          - - - - - - - - - - - - - - -  " << endl << endl;
}

// Function to display admin menu.
int adminLogin() {
	int op = 0;

	cout << "<============================  A D M I N  ==================================>" << endl << endl;
	cout << "1. View bakery items." << endl
		<< "2. Add new bakery items." << endl
		<< "3. Add staff." << endl
		<< "4. View staff details." << endl
		<< "5. Logout." << endl
		<< "Enter your option . . . ";
	cin >> op;
	cout << endl;

	return op;
}

// Function to view bakery items
int viewBakeryItems() {
	int op;
	fstream file;
	string line, i;

	do {
		cout << "<------------------------------- View Bakery Items ---------------------------------->" << endl << endl
			<< "1. Pastry" << endl
			<< "2. Cakes" << endl
			<< "3. back to previous" << endl
			<< "4. back to login" << endl
			<< "Enter your option . . .";
		cin >> op;
		cout << endl;
		switch (op) {
		case 1:
			cout << "------------------------ PASTRY -------------------------" << endl;
			file.open("pastry.txt", ios::in);

			while (getline(file, line)) {
				cout << line << endl;
			}
			file.close();
			cout << endl;

			cout << "Enter any key to continue . . .";
			cin >> i;
			cout << endl;
			if (i == "a") {
				// pass
			}
			else {
				// pass
			}

			break;

		case 2:
			cout << "------------------------ CAKE -------------------------" << endl;
			file.open("cake.txt", ios::in);

			while (getline(file, line)) {
				cout << line << endl;
			}
			file.close();
			cout << endl;

			cout << "Enter any key to continue . . .";
			cin >> i;
			cout << endl;
			if (i == "a") {
				// pass
			}
			else {
				// pass
			}

			break;

		case 3:
			break;

		case 4:
			break;

		default:
			cout << "---------------------- Invalid insert! ------------------------" << endl << endl;
			op = 1;
			break;
		}

	} while ((op == 1) || (op == 2));
	return op;
}

// function to get an option from the user
int addBakeryItems() {
	int op;

	do {
		cout << "<------------------------------- Add New Bakery Items ---------------------------------->" << endl << endl
			<< "1. Add Pastries" << endl
			<< "2. Add Cakes" << endl
			<< "3. back to previous" << endl
			<< "4. back to login" << endl
			<< "Enter your option . . .";
		cin >> op;
		cout << endl;


	} while ((op > 4) || (op < 1));

	return op;
}

bakeryItem insertCake() {
	bakeryItem c;

	cout << "Enter cake's flavor name (e.g, Chocolate, Vanilla, Strawberry...ext ): ";
	cin >> c.name;
	cout << "Enter cake's code: ";
	cin >> c.code;
	cout << "Enter cake's Net weight: ";
	cin >> c.Qty;
	cout << "Enter cake's price: ";
	cin >> c.price;
	return c;
}
bakeryItem insertPastry() {
	bakeryItem p;

	cout << "Enter pastry's type name (e.g, Fish, Egg, Puff, Shortcrust...ext): ";
	cin >> p.name;
	cout << "Enter pastry's code: ";
	cin >> p.code;
	cout << "Enter Qty (e.g, Medium or Large): ";
	cin >> p.Qty;
	cout << "Enter pastry's price: ";
	cin >> p.price;
	return p;
}
// function to insret staffs to the file
void insertStaff() {
	person s;
	fstream file;

	cout << "<------------------------------- Add New Staffs ---------------------------------->" << endl << endl;
	cout << "Enter staff ID: ";
	cin >> s.id;
	cout << "Enter staff's first name: ";
	cin >> s.fname;
	cout << "Enter staff's last name: ";
	cin >> s.lname;
	cout << "Enter staff's age: ";
	cin >> s.age;
	cout << "Enter staff's address: ";
	cin >> s.address;
	cout << "Enter staff's salary: ";
	cin >> s.salary;
	cout << endl;

	file.open("staff.txt", ios::app);
	file << "Full Name: \t" << s.fname << " " << s.lname << endl
		<< "ID: \t\t" << s.id << endl
		<< "Age: \t\t" << s.age << endl
		<< "Address: \t" << s.address << endl
		<< "Salary: \t" << s.salary << endl
		<< endl;
	file.close();

	cout << "                              ---------------          staff added successfully.        --------------" << endl
		<< "                              ===============                                             ==============" << endl << endl;
}

// Adding inserted bakery items to the file.
void addBakeryItemstoFile(int count, bakeryItem item[], string itemType) {
	fstream file;

	if (itemType == "pastry") {
		file.open("pastry.txt", ios::app);
		file << endl << "Name: \t" << item[count].name << " Pastry" << endl
			<< "Code: \t" << item[count].code << endl
			<< "Qty: \t\t" << item[count].Qty << endl
			<< "Price: \t" << item[count].price << endl << endl;
		file.close();

		cout << "                              ---------------          Pastry added successfully.        --------------" << endl
			<< "                              ===============                                             ==============" << endl << endl;
	}
	else if (itemType == "cake") {
		file.open("cake.txt", ios::app);
		file << endl << "Name: \t" << item[count].name << " Cake" << endl
			<< "Code: \t" << item[count].code << endl
			<< "Qty: \t\t" << item[count].Qty << endl
			<< "Price: \t" << item[count].price << endl << endl;
		file.close();

		cout << "                              ---------------            Cake added successfully.        --------------" << endl
			<< "                              ===============                                             ==============" << endl << endl;
	}

}

// function to view staffs detailes
void viewStaffDetailes() {
	fstream file;
	string line, i;

	cout << "<------------------------------------- STAFF DETAILES ------------------------------------------>" << endl;

	file.open("staff.txt", ios::in);

	while (getline(file, line)) {
		cout << line << endl;
	}
	file.close();
	cout << endl;

	cout << "Enter any key to continue . . .";
	cin >> i;
	cout << endl;
	if (i == "a") {
		// pass
	}
	else {
		// pass
	}
}
// Function to display cashier menu.
int cashierLogin() {
	int op = 0;

	cout << "<===========================  C A S H I E R  ==============================>" << endl << endl;
	cout << "1. View bakery items." << endl
		<< "2. Select bakery items and print a bill." << endl
		<< "3. Execute a bill and print bill." << endl
		<< "4. Logout." << endl
		<< "Enter your option . . . ";
	cin >> op;
	cout << endl;

	return op;
}
// function to select bakery items and print a bill for selected items.
void selectandPrintBill(bakeryItem pastry[], bakeryItem cake[], int p, int c) {
	bakeryItem products[20];
	string ch, i, item;
	int  pcs[50], n = 0, ItemNo = 0;
	float total = 0, sum[50], cashe = 0, balance = 0;

	cout << "<----------------------------------- BILLING PROCESS ---------------------------------------->" << endl << endl
		<< "PASTRY \t\t\t\tCAKE" << endl << endl;

	for (int i = 0; (i <= p) || (i <= c); i++) {

		cout << i + 1 << ". " << pastry[i].name << " \t\t" << i + 1 << ". " << cake[i].name << endl;

	}
	cout << endl;

	cout << "-------------- Adding items to the bill ------------" << endl << endl;

	do {
		do {
			cout << "Enter the item type ('p' for pastry/ 'c' for cake):";
			cin >> item;

		} while ((item != "p") && (item != "c"));

		cout << "Enter the item number: ";
		cin >> ItemNo;

		if (((ItemNo <= p + 1) || (ItemNo <= c + 1)) && (ItemNo > 0)) {
			if (item == "p") {
				cout << "Enter Number of PCS: ";
				cin >> pcs[n];
				products[n] = pastry[ItemNo - 1];
				sum[n] = pastry[ItemNo - 1].price * pcs[n];
				total = total + sum[n];
				++n;

			}
			else {
				cout << "Enter Number of PCS: ";
				cin >> pcs[n];
				products[n] = cake[ItemNo - 1];
				sum[n] = cake[ItemNo - 1].price * pcs[n];
				total = total + sum[n];
				++n;
			}
		}
		else {
			cout << "-------------------------------- Invalid input ---------------------------------------" << endl << endl;
		}





		do {
			cout << "Enter 'y' to continue adding items to the bill. . ." << endl << "Enter 'p' to Print the bill . . .";
			cin >> ch;
			cout << endl;

			if ((ch != "y") && (ch != "Y") && (ch != "p") && (ch != "P")) {
				cout << "------------------- invalid insert ---------------------" << endl << endl;
			}
			if ((ch == "p") || (ch == "Y")) {
				cout << "Enter the amount of cash from customer: ";
				cin >> cashe;
				balance = cashe - total;
				cout << endl;
			}

		} while ((ch != "y") && (ch != "Y") && (ch != "p") && (ch != "P"));
	} while ((ch == "y") || (ch == "Y"));

	cout << "==================================================" << endl << endl;
	cout << "\t\tB U N   T A L K" << endl
		<< "\t\t    Colombo" << endl
		<< "\t\t  0771148418" << endl << endl << endl;
	cout << " " << __DATE__ << "\t\t" << __TIME__ << endl
		<< "-------------------------------------------------" << endl;
	cout << " NO  ITEM            QTY     PRICE        AMOUNT" << endl
		<< "-------------------------------------------------" << endl;
	for (int i = 0; i < n; ++i) {
		cout << " " << i + 1 << "   " << products[i].name << endl;
		cout << "     " << products[i].code << "             " << pcs[i]
			<< "      " << products[i].price
			<< "          " << sum[i] << endl;

	}
	cout << "-------------------------------------------------" << endl;
	cout << " Sub Total                                " << total << endl << endl;
	cout << " Cash                                     " << cashe << endl;
	cout << " Balance                                  " << balance << endl << endl << endl;
	cout << " Time End: " << __TIME__ << endl << endl
		<< "                Loyalty Customer                " << endl
		<< "-------------------------------------------------" << endl << endl << endl
		<< "----------------IMPORTANT NOTICE-----------------" << endl << endl
		<< "      In case of a price discrepancy, return     " << endl
		<< "        the item & bill within 24 hours to       " << endl
		<< "            refund the difference                " << endl << endl
		<< "                  THANK YOU                      " << endl << endl
		<< "====================================================" << endl << endl;
	cout << "Enter any key to continue . . .";
	cin >> i;
	cout << endl << endl;

	if (i == "a") {
		// pass
	}
	else {
		// pass
	}

}

// function to execute a bill manually
void executePrintBill() {
	bakeryItem products[20];
	string ch, i;
	int  pcs[50], n = 0;
	float total = 0, sum[50], cashe = 0, balance = 0;

	cout << "   Adding items to the bill" << endl << endl;

	do {
		cout << "Enter item No" << n + 1 << " : ";
		cin >> products[n].name;
		cout << "Enter the price: ";
		cin >> products[n].price;
		cout << "Enter Number of PCS: ";
		cin >> pcs[n];
		cout << endl;
		sum[n] = products[n].price * pcs[n];
		total = total + sum[n];

		do {
			cout << "Enter 'y' to continue adding items to the bill. . ." << endl << "Enter 'p' to Print the bill . . .";
			cin >> ch;
			cout << endl;

			if ((ch != "y") && (ch != "Y") && (ch != "p") && (ch != "P")) {
				cout << "------------------- invalid insert ---------------------" << endl << endl;
			}
			if ((ch == "p") || (ch == "Y")) {
				cout << "Enter the amount of cash from customer: ";
				cin >> cashe;
				balance = cashe - total;
				cout << endl;
			}

		} while ((ch != "y") && (ch != "Y") && (ch != "p") && (ch != "P"));
		++n;
	} while ((ch == "y") || (ch == "Y"));

	cout << "==================================================" << endl << endl;
	cout << "\t\tB U N   T A L K" << endl
		<< "\t\t    Colombo" << endl
		<< "\t\t  0771148418" << endl << endl << endl;
	cout << " " << __DATE__ << "\t\t" << __TIME__ << endl
		<< "-------------------------------------------------" << endl;
	cout << " NO  ITEM            QTY     PRICE        AMOUNT" << endl
		<< "-------------------------------------------------" << endl;
	for (int i = 0; i < n; ++i) {
		cout << " " << i + 1 << "   " << products[i].name << endl;
		cout << "                      " << pcs[i]
			<< "      " << products[i].price
			<< "          " << sum[i] << endl;

	}
	cout << "-------------------------------------------------" << endl;
	cout << " Sub Total                                " << total << endl << endl;
	cout << " Cash                                     " << cashe << endl;
	cout << " Balance                                  " << balance << endl << endl << endl;
	cout << " Time End: " << __TIME__ << endl << endl
		<< "                Loyalty Customer                " << endl
		<< "-------------------------------------------------" << endl << endl << endl
		<< "----------------IMPORTANT NOTICE-----------------" << endl << endl
		<< "      In case of a price discrepancy, return     " << endl
		<< "        the item & bill within 24 hours to       " << endl
		<< "            refund the difference                " << endl << endl
		<< "                  THANK YOU                      " << endl << endl
		<< "====================================================" << endl << endl;
	cout << "Enter any key to continue . . .";
	cin >> i;
	cout << endl;

	if (i == "a") {
		// pass
	}
	else {
		// pass
	}

}
// function for billing process window
int billingProcess() {
	int  op;

	cout << "<--------------------------------- Execute a Bill and Print Bill --------------------------------->" << endl << endl;

	do {
		cout << "1. Generate and print Bills" << endl
			<< "2. Back to previous" << endl
			<< "3. Logout" << endl
			<< "Enter your option . . . ";
		cin >> op;
		cout << endl;

		switch (op) {
		case 1:
			executePrintBill();
			break;


		default:
			if ((op < 1) || (op > 3)) {
				cout << "------------------------------------ Invalid insert ------------------------------------ " << endl << endl;
			}
			break;
		}
		if (op == 3) {
			op = 4;
		}

	} while (op == 1);

	return op;

}
// function to default bakery items
void defaultBakeryItems(bakeryItem cake[], bakeryItem pastry[]) {
	int cCount = 0, pCount = 0;

	cake[cCount].name = "Cheese Cake";
	cake[cCount].code = "C001";
	cake[cCount].Qty = "500g";
	cake[cCount].price = 800.00;
	++cCount;
	cake[cCount].name = "Chocolate Cake";
	cake[cCount].code = "C002";
	cake[cCount].Qty = "500g";
	cake[cCount].price = 500.00;
	++cCount;
	cake[cCount].name = "Vanilla Cake";
	cake[cCount].code = "C003";
	cake[cCount].Qty = "500g";
	cake[cCount].price = 600.00;
	++cCount;
	cake[cCount].name = "Strawberry Cake";
	cake[cCount].code = "C004";
	cake[cCount].Qty = "500g";
	cake[cCount].price = 700.00;
	++cCount;
	cake[cCount].name = "Banana Cake";
	cake[cCount].code = "C005";
	cake[cCount].Qty = "500g";
	cake[cCount].price = 600.00;
	++cCount;

	pastry[pCount].name = "Fish Pastry   ";
	pastry[pCount].code = "P001";
	pastry[pCount].Qty = "Medium";
	pastry[pCount].price = 100.00;
	++pCount;
	pastry[pCount].name = "Sausage Pastry";
	pastry[pCount].code = "P002";
	pastry[pCount].Qty = "Medium";
	pastry[pCount].price = 100.00;
	++pCount;
	pastry[pCount].name = "Puff Pastry   ";
	pastry[pCount].code = "P003";
	pastry[pCount].Qty = "Medium";
	pastry[pCount].price = 120.00;
	++pCount;
	pastry[pCount].name = "Shortcrust Pastry";
	pastry[pCount].code = "P004";
	pastry[pCount].Qty = "Medium";
	pastry[pCount].price = 120.00;
	++pCount;
	pastry[pCount].name = "Chicken Pastry";
	pastry[pCount].code = "P005";
	pastry[pCount].Qty = "Medium";
	pastry[pCount].price = 120.00;
	++pCount;
}

// function to default bakery items to file
void defaultItemstoFile() {
	fstream file;

	file.open("pastry.txt", ios::out);
	file << endl << "Name: \tFish Pastry" << endl
		<< "Code: \tP001" << endl
		<< "Qty: \t\tMedium" << endl
		<< "Price: \t100.00" << endl << endl
		<< endl
		<< "Name: \tSausage Pastry" << endl
		<< "Code: \tP002" << endl
		<< "Qty: \t\tMedium" << endl
		<< "Price: \t100.00" << endl
		<< endl
		<< "Name: \tPuff Pastry" << endl
		<< "Code: \tP003" << endl
		<< "Qty: \t\tMedium" << endl
		<< "Price: \t120.00" << endl
		<< endl
		<< "Name: \tShortcrust Pastry" << endl
		<< "Code: \tP004" << endl
		<< "Qty: \t\tMedium" << endl
		<< "Price: \t120.00" << endl
		<< endl
		<< "Name: \tChicken Pastry" << endl
		<< "Code: \tP005" << endl
		<< "Qty: \t\tMedium" << endl
		<< "Price: \t120.00" << endl
		<< endl;
	file.close();

	file.open("cake.txt", ios::out);
	file << endl << "Name: \tCheese Cake" << endl
		<< "Code: \tC001" << endl
		<< "Qty: \t\t500g" << endl
		<< "Price: \t800.00" << endl
		<< endl
		<< "Name: \tChocolate Cake" << endl
		<< "Code: \tC002" << endl
		<< "Qty: \t\t500g" << endl
		<< "Price: \t500.00" << endl
		<< endl
		<< "Name: \tVanilla Cake" << endl
		<< "Code: \tC003" << endl
		<< "Qty: \t\t500g" << endl
		<< "Price: \t600.00" << endl
		<< endl
		<< "Name: \tStrawberry Cake" << endl
		<< "Code: \tC004" << endl
		<< "Qty: \t\t500g" << endl
		<< "Price: \t700.00" << endl
		<< endl
		<< "Name: \tBanana Cake" << endl
		<< "Code: \tC005" << endl
		<< "Qty: \t\t500g" << endl
		<< "Price: \t600.00" << endl
		<< endl;
	file.close();

	file.open("staff.txt", ios::out);
	file << endl << "Full Name: \tAbdullah Haleem" << endl
		<< "ID: \t\tstf001" << endl
		<< "Age: \t\t21" << endl
		<< "Address: \tKandyRoad, Thihariya" << endl
		<< "Salary: \t80000.00" << endl
		<< endl
		<< "Full Name: \tMohammed" << endl
		<< "ID: \t\tstf002" << endl
		<< "Age: \t\t30" << endl
		<< "Address: \tColombo" << endl
		<< "Salary: \t80000.00" << endl
		<< endl
		<< "Full Name: \tCristiano Ronaldo" << endl
		<< "ID: \t\tstf003" << endl
		<< "Age: \t\t38" << endl
		<< "Address: \tLisbon" << endl
		<< "Salary: \t80000.00" << endl
		<< endl
		<< "Full Name: \tKumar sangakkara" << endl
		<< "ID: \t\tstf004" << endl
		<< "Age: \t\t45" << endl
		<< "Address: \tColombo" << endl
		<< "Salary: \t80000.00" << endl
		<< endl;
	file.close();
}

int main() {

	bakeryItem cake[100], pastry[100];
	string userType[300];
	int pCount = 0, cCount = 0, op1 = 0, op2 = 0, loginCount = 0;
	fstream file;

	defaultBakeryItems(cake, pastry);
	pCount = 4;
	cCount = 4;

	defaultItemstoFile();

	while (true) {

		mainLogin();
		userType[loginCount] = userLogin();

		if (userType[loginCount] == "admin") {

			do {
				op1 = 0;
				switch (adminLogin()) {
				case 1:
					op1 = viewBakeryItems();
					break;

				case 2:
					switch (addBakeryItems()) {
					case 1:
						++pCount;
						pastry[pCount] = insertPastry();
						addBakeryItemstoFile(pCount, pastry, "pastry");
						break;

					case 2:
						++cCount;
						cake[cCount] = insertCake();
						addBakeryItemstoFile(cCount, cake, "cake");
						break;

					case 3:
						op1 = 3;
						break;

					case 4:
						op1 = 4;
						break;

					default:
						cout << "-------------------- Invalid insert! ------------------------" << endl << endl;
						break;
					}
					break;

				case 3:
					insertStaff();
					op1 = 0;
					break;

				case 4:
					viewStaffDetailes();
					op1 = 0;
					break;

				case 5:
					op1 = 4;
					break;

				default:
					break;
				}
			} while (op1 != 4);
		}
		else if (userType[loginCount] == "cashier") {
			do {
				op2 = 0;
				switch (cashierLogin()) {
				case 1:
					op2 = viewBakeryItems();
					break;

				case 2:
					selectandPrintBill(pastry, cake, pCount, cCount);
					break;

				case 3:
					op2 = billingProcess();
					break;

				case 4:
					op2 = 4;
					break;

				default:
					cout << "----------------------------- Invalid insert --------------------------------" << endl;
					break;
				}


			} while (op2 != 4);
		}
		++loginCount;
	}

	return 0;
}
