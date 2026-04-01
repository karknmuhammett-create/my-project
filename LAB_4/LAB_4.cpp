#include <iostream>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

struct MoneyBundle {
    string serialNumber;
    string currencyType;
    int billCounts[3];
    MoneyBundle* next;
};

class MoneyStack {
private:
    MoneyBundle* top;

public:
    MoneyStack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(string serialNum, string currency, int count100, int count50, int count20) {
        MoneyBundle* newBundle = new MoneyBundle;
        newBundle->serialNumber = serialNum;
        newBundle->currencyType = currency;
        newBundle->billCounts[0] = count100;
        newBundle->billCounts[1] = count50;
        newBundle->billCounts[2] = count20;

        newBundle->next = top;
        top = newBundle;
        cout << "[SUCCESS] Money bundle added to safe." << endl;
    }

    MoneyBundle* pop() {
        if (isEmpty()) {
            return nullptr;
        }
        MoneyBundle* temp = top;
        top = top->next;
        return temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Money safe is empty." << endl;
            return;
        }
        MoneyBundle* current = top;
        cout << "--- Money Safe (Stack) ---" << endl;
        while (current != nullptr) {
            cout << "SN: " << current->serialNumber
                << " | Currency: " << current->currencyType
                << " | Bills [100s, 50s, 20s]: ["
                << current->billCounts[0] << ", "
                << current->billCounts[1] << ", "
                << current->billCounts[2] << "]" << endl;
            current = current->next;
        }
    }
};

struct Customer {
    string customerName;
    string transactionType;
};

class CustomerQueue {
private:
    static const int SIZE = 5;
    Customer queue[SIZE];
    int front;
    int rear;
    int count;

public:
    CustomerQueue() {
        front = 0;
        rear = 0;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == SIZE;
    }

    void enqueue(string name, string transaction) {
        if (isFull()) {
            cout << "[ERROR] Queue is full (Max 5)." << endl;
            return;
        }
        queue[rear].customerName = name;
        queue[rear].transactionType = transaction;

        rear = (rear + 1) % SIZE;
        count++;
        cout << "[SUCCESS] Customer joined the queue." << endl;
    }

    Customer* dequeue() {
        if (isEmpty()) {
            return nullptr;
        }
        Customer* servedCustomer = new Customer;
        servedCustomer->customerName = queue[front].customerName;
        servedCustomer->transactionType = queue[front].transactionType;

        front = (front + 1) % SIZE;
        count--;

        return servedCustomer;
    }

    void display() {
        if (isEmpty()) {
            cout << "Customer queue is empty." << endl;
            return;
        }
        cout << "--- Customer Queue ---" << endl;
        for (int i = 0; i < count; i++) {
            int index = (front + i) % SIZE;
            cout << ">>> " << queue[index].customerName
                << " (" << queue[index].transactionType << ")" << endl;
        }
    }
};

void displayMenu() {
    cout << "\n=========================================" << endl;
    cout << "   BANK BRANCH MANAGEMENT SYSTEM" << endl;
    cout << "=========================================" << endl;
    cout << "1. Receive Money" << endl;
    cout << "2. New Customer" << endl;
    cout << "3. Process Transaction" << endl;
    cout << "4. Display System Status" << endl;
    cout << "5. Exit" << endl;
    cout << "Select an operation (1-5): ";
}

int main() {
    MoneyStack safe;
    CustomerQueue branchQueue;
    int choice;

    do {
        displayMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[ERROR] Invalid input. Please enter a number." << endl;
            continue;
        }

        cout << endl;

        switch (choice) {
        case 1: {
            string sn, curr;
            int c100, c50, c20;

            while (true) {
                cout << "Serial Number (Must be exactly 6 characters): ";
                cin >> sn;
                if (sn.length() == 6) {
                    break;
                }
                else {
                    cout << "[ERROR] Invalid length! Serial number must be exactly 6 characters long.\n";
                }
            }

            while (true) {
                cout << "Currency (TL, USD, EURO, POUND): ";
                cin >> curr;

                for (auto& c : curr) {
                    c = toupper(c);
                }

                if (curr == "TL" || curr == "USD" || curr == "EURO" || curr == "POUND") {
                    break;
                }
                else {
                    cout << "[ERROR] Invalid currency! Please enter only TL, USD, EURO, or POUND.\n";
                }
            }

            while (true) {
                cout << "Count of 100s: ";
                if (cin >> c100 && c100 >= 0) {
                    break;
                }
                else {
                    cout << "[ERROR] Invalid input! Please enter a valid positive number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            while (true) {
                cout << "Count of 50s: ";
                if (cin >> c50 && c50 >= 0) {
                    break;
                }
                else {
                    cout << "[ERROR] Invalid input! Please enter a valid positive number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            while (true) {
                cout << "Count of 20s: ";
                if (cin >> c20 && c20 >= 0) {
                    break;
                }
                else {
                    cout << "[ERROR] Invalid input! Please enter a valid positive number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            safe.push(sn, curr, c100, c50, c20);
            break;
        }
        case 2: {
            if (branchQueue.isFull()) {
                cout << "[ERROR] Queue is full." << endl;
                break;
            }
            string name, trans;
            cout << "Customer Name: ";
            cin >> ws;
            getline(cin, name);
            cout << "Transaction Type (Withdraw/Deposit): ";
            cin >> trans;

            branchQueue.enqueue(name, trans);
            break;
        }
        case 3: {
            if (branchQueue.isEmpty()) {
                cout << "[WARNING] No customers in queue." << endl;
            }
            else if (safe.isEmpty()) {
                cout << "[WARNING] No money in safe." << endl;
            }
            else {
                Customer* servedCustomer = branchQueue.dequeue();
                MoneyBundle* usedBundle = safe.pop();

                cout << ">>> Served: " << servedCustomer->customerName << " (" << servedCustomer->transactionType << ")" << endl;
                cout << ">>> Money Provided: Bundle " << usedBundle->serialNumber << " (" << usedBundle->currencyType << ")" << endl;

                delete servedCustomer;
                delete usedBundle;
            }
            break;
        }
        case 4: {
            safe.display();
            cout << endl;
            branchQueue.display();
            break;
        }
        case 5: {
            cout << "Exiting system." << endl;
            break;
        }
        default: {
            cout << "[ERROR] Invalid choice. Select 1-5." << endl;
            break;
        }
        }
    } while (choice != 5);

    return 0;
}