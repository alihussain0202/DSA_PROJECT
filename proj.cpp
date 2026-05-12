#include <iostream>
using namespace std ;

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

    Order* temp = new Order;

    temp->orderNo = counter++;
    temp->qty = q;
    temp->completed = false;
    temp->next = NULL;

    int x = 0;

    while(n[x] != '\0') {
        temp->name[x] = n[x];
        x++;
    }

    temp->name[x] = '\0';

    x = 0;

    while(i[x] != '\0') {
        temp->item[x] = i[x];
        x++;
    }

    temp->item[x] = '\0';

    return temp;
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

    char name[50];
    char item[50];
    int qty;

    cout << "\nCustomer Name: ";
    cin >> name;

    showMenu();

    cout << "Enter Item Name: ";
    cin >> item;

    cout << "Enter Quantity: ";
    cin >> qty;

    Order* newOrder = createOrder(name, item, qty);

    if(head == NULL) {

        head = newOrder;
    }
    else {

        Order* temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newOrder;
    }

    cout << "\nOrder Placed Successfully!" << endl;
    cout << "Order Number: #" << newOrder->orderNo << endl;
}

void showAllOrders() {

    if(head == NULL) {

        cout << "\nNo Orders Available!" << endl;
        return;
    }

    Order* temp = head;

    cout << "\n====== ALL ORDERS ======" << endl;

    while(temp != NULL) {

        cout << "\nOrder #" << temp->orderNo << endl;
        cout << "Customer : " << temp->name << endl;
        cout << "Item     : " << temp->item << endl;
        cout << "Quantity : " << temp->qty << endl;

        if(temp->completed)
            cout << "Status   : READY" << endl;
        else
            cout << "Status   : Waiting" << endl;

        temp = temp->next;
    }
}

void waitingOrders() {

    if(head == NULL) {

        cout << "\nNo Orders Available!" << endl;
        return;
    }

    bool found = false;

    Order* temp = head;

    cout << "\n WAITING ORDERS" << endl;

    while(temp != NULL) {

        if(temp->completed == false) {

            cout << "Order #" << temp->orderNo;
            cout << " | " << temp->name;
            cout << " | " << temp->item;
            cout << " x" << temp->qty << endl;

            found = true;
        }

        temp = temp->next;
    }

    if(!found)
        cout << "No Waiting Orders!" << endl;
}

void completeOrder() {

    int num;

    cout << "\nEnter Order Number: ";
    cin >> num;

    Order* temp = head;

    while(temp != NULL) {

        if(temp->orderNo == num) {

            if(temp->completed) {

                cout << "Already Completed!" << endl;
            }
            else {

                temp->completed = true;
                cout << "Order Completed!" << endl;
            }

            return;
        }

        temp = temp->next;
    }

    cout << "Order Not Found!" << endl;
}

void removeOrder() {

    if(head == NULL) {

        cout << "\nNo Orders Available!" << endl;
        return;
    }

    int num;

    cout << "\nEnter Order Number to Remove: ";
    cin >> num;

    Order* temp = head;
    Order* prev = NULL;

    while(temp != NULL && temp->orderNo != num) {

        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {

        cout << "Order Not Found!" << endl;
        return;
    }

    if(prev == NULL) {

        head = temp->next;
    }
    else {

        prev->next = temp->next;
    }

    delete temp;

    cout << "Order Removed Successfully!" << endl;
}

int main() {

    int choice;

    cout << " Coffee Shop " << endl;

    while(true) {

        cout << "\n1. Place Order";
        cout << "\n2. Show All Orders";
        cout << "\n3. Waiting Orders";
        cout << "\n4. Complete Order";
        cout << "\n5. Remove Order";
        cout << "\n6. Exit";

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        if(choice == 1)
            placeOrder();

        else if(choice == 2)
            showAllOrders();

        else if(choice == 3)
            waitingOrders();

        else if(choice == 4)
            completeOrder();

        else if(choice == 5)
            removeOrder();

        else if(choice == 6) {

            cout << "\nProgram Closed!" << endl;
            break;
        }

        else
            cout << "Invalid Choice!" << endl;
    }

    return 0;
}