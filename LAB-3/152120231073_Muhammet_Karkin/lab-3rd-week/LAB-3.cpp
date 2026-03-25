#include <iostream>
#include <string>

using namespace std;

struct Page {
    string url;
    string title;
    int accessTime[3];
    Page* next;
    Page* prev;
};

class BrowserHistory {
private:
    Page* head;
    Page* current;

public:
    BrowserHistory() {
        head = nullptr;
        current = nullptr;
    }

    void visit(string u, string t, int h, int m, int s) {
        Page* newPage = new Page();
        newPage->url = u;
        newPage->title = t;
        newPage->accessTime[0] = h;
        newPage->accessTime[1] = m;
        newPage->accessTime[2] = s;
        newPage->next = nullptr;
        newPage->prev = nullptr;

        if (head == nullptr) {
            head = newPage;
            current = newPage;
        }
        else {
            Page* temp = current->next;
            while (temp != nullptr) {
                Page* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }

            current->next = newPage;
            newPage->prev = current;
            current = newPage;
        }
        cout << "[visit] visited: " << current->title << "\n";
    }

    void back() {
        if (current != nullptr && current->prev != nullptr) {
            current = current->prev;
            cout << "[back] went back to: " << current->title << "\n";
        }
        else {
            cout << "[back] error: no previous page!\n";
        }
    }

    void forward() {
        if (current != nullptr && current->next != nullptr) {
            current = current->next;
            cout << "[forward] went forward to: " << current->title << "\n";
        }
        else {
            cout << "[forward] error: no next page!\n";
        }
    }

    void deleteEntry() {
        if (current == nullptr) {
            cout << "[delete] error: history is empty.\n";
            return;
        }

        Page* toDelete = current;
        cout << "[delete] removed: " << toDelete->title << "\n";

        if (toDelete == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            current = head;
        }
        else {
            toDelete->prev->next = toDelete->next;

            if (toDelete->next != nullptr) {
                toDelete->next->prev = toDelete->prev;
                current = toDelete->next;
            }
            else {
                current = toDelete->prev;
            }
        }

        delete toDelete;
    }

    void displayHistory() {
        if (head == nullptr) {
            cout << "\n--- browser history (empty) ---\n\n";
            return;
        }

        Page* temp = head;
        cout << "\n--- browser history ---\n";

        while (temp != nullptr) {
            if (temp == current) {
                cout << " ==> ";
            }
            else {
                cout << "     ";
            }

            cout << temp->title << " (" << temp->url << ") - time: ";

            for (int i = 0; i < 3; i++) {
                if (temp->accessTime[i] < 10) cout << "0";
                cout << temp->accessTime[i];
                if (i < 2) cout << ":";
            }
            cout << "\n";

            temp = temp->next;
        }
        cout << "------------------------\n\n";
    }

    void clearMemory() {
        Page* temp = head;
        int deletedCount = 0;

        while (temp != nullptr) {
            Page* nextNode = temp->next;
            delete temp;
            temp = nextNode;
            deletedCount++;
        }

        head = nullptr;
        current = nullptr;
        cout << "[exit] memory cleared. " << deletedCount << " nodes deleted.\n";
    }
};

int main() {
    BrowserHistory browser;
    string command;

    cout << "--- browser history manager ---\n";
    cout << "commands: visit, back, forward, delete, print, exit\n";
    cout << "-------------------------------\n";

    while (true) {
        cout << "\n> enter command: ";
        cin >> command;

        if (command == "visit") {
            string url, title;
            int h, m, s;

            cout << "  url: ";
            cin >> url;

            cout << "  title: ";
            cin.ignore();
            getline(cin, title);

            cout << "  time (h m s): ";
            if (!(cin >> h >> m >> s)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "  error: invalid time format.\n";
                continue;
            }

            browser.visit(url, title, h, m, s);
        }
        else if (command == "back") {
            browser.back();
        }
        else if (command == "forward") {
            browser.forward();
        }
        else if (command == "delete") {
            browser.deleteEntry();
        }
        else if (command == "print") {
            browser.displayHistory();
        }
        else if (command == "exit") {
            browser.clearMemory();
            cout << "exiting...\n";
            break;
        }
        else {
            cout << "error: invalid command.\n";
        }
    }

    return 0;
}