#include <iostream>
using namespace std;

struct Order {

	int orderNo;
	char name[50];
	char item[50];
	int qty;
	bool completed;

	Order* next;
};

Order* head = NULL;
int counter = 1;

Order* createOrder(char n[], char i[], int q) {

	Order* o = new Order;

	o->orderNo = counter++;
	o->qty = q;
	o->completed = false;
	o->next = NULL;

	int k = 0;
	while (n[k] != '\0') {
		o->name[k] = n[k];
		k++;
	}
	o->name[k] = '\0';

	k = 0;
	while (i[k] != '\0') {
		o->item[k] = i[k];
		k++;
	}
	o->item[k] = '\0';

	return o;
}

void showMenu() {

	cout << "\n------ MENU ------" << endl;
	cout << "1. Espresso" << endl;
	cout << "2. Latte" << endl;
	cout << "3. Cappuccino" << endl;
	cout << "4. Cold Coffee" << endl;
	cout << "5. Green Tea" << endl;
	cout << "------------------" << endl;
}

void placeOrder() {

	char name[50], item[50];
	int qty;

	cout << "\nCustomer Name: ";
	cin >> name;

	showMenu();

	cout << "Enter Item Name: ";
	cin >> item;

	cout << "Enter Quantity: ";
	cin >> qty;

	Order* o = createOrder(name, item, qty);

	if (head == NULL) {
		head = o;
	}
	else {
		Order* t = head;
		while (t->next != NULL)
			t = t->next;
		t->next = o;
	}

	cout << "\nOrder Placed Successfully!" << endl;
	cout << "Order Number: #" << o->orderNo << endl;
}

void showAllOrders() {

	if (head == NULL) {
		cout << "\nNo Orders Available!" << endl;
		return;
	}

	Order* t = head;

	cout << "\n====== ALL ORDERS ======" << endl;

	while (t != NULL) {

		cout << "\nOrder #" << t->orderNo << endl;
		cout << "Customer : " << t->name << endl;
		cout << "Item     : " << t->item << endl;
		cout << "Quantity : " << t->qty << endl;

		if (t->completed)
			cout << "Status   : READY" << endl;
		else
			cout << "Status   : Waiting" << endl;

		t = t->next;
	}
}

void waitingOrders() {

	if (head == NULL) {
		cout << "\nNo Orders Available!" << endl;
		return;
	}

	bool found = false;
	Order* t = head;

	cout << "\n WAITING ORDERS" << endl;

	while (t != NULL) {

		if (t->completed == false) {

			cout << "Order #" << t->orderNo;
			cout << " | " << t->name;
			cout << " | " << t->item;
			cout << " x" << t->qty << endl;

			found = true;
		}

		t = t->next;
	}

	if (!found)
		cout << "No Waiting Orders!" << endl;
}

void completeOrder() {

	int num;
	cout << "\nEnter Order Number: ";
	cin >> num;

	Order* t = head;

	while (t != NULL) {

		if (t->orderNo == num) {

			if (t->completed)
				cout << "Already Completed!" << endl;
			else {
				t->completed = true;
				cout << "Order Completed!" << endl;
			}

			return;
		}

		t = t->next;
	}

	cout << "Order Not Found!" << endl;
}

void removeOrder() {

	if (head == NULL) {
		cout << "\nNo Orders Available!" << endl;
		return;
	}

	int num;
	cout << "\nEnter Order Number to Remove: ";
	cin >> num;

	Order* t = head;
	Order* prev = NULL;

	while (t != NULL && t->orderNo != num) {
		prev = t;
		t = t->next;
	}

	if (t == NULL) {
		cout << "Order Not Found!" << endl;
		return;
	}

	if (prev == NULL)
		head = t->next;
	else
		prev->next = t->next;

	delete t;

	cout << "Order Removed Successfully!" << endl;
}

int main() {

	int ch;

	cout << " Coffee Shop " << endl;

	while (true) {

		cout << "\n1. Place Order";
		cout << "\n2. Show All Orders";
		cout << "\n3. Waiting Orders";
		cout << "\n4. Complete Order";
		cout << "\n5. Remove Order";
		cout << "\n6. Exit";

		cout << "\n\nEnter Choice: ";
		cin >> ch;

		if (ch == 1)
			placeOrder();

		else if (ch == 2)
			showAllOrders();

		else if (ch == 3)
			waitingOrders();

		else if (ch == 4)
			completeOrder();

		else if (ch == 5)
			removeOrder();

		else if (ch == 6) {
			cout << "\nProgram Closed!" << endl;
			break;
		}

		else
			cout << "Invalid Choice!" << endl;
	}

	return 0;
}
