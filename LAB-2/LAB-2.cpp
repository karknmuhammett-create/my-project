#include <iostream>
#include <string>

using namespace std;


struct Node {
    string songTitle;
    Node* next;
};


void addSong(Node*& head, string title);
void searchSong(Node* head, string title);
void listSongs(Node* head);


int main() {
    Node* head = nullptr;
    int choice;
    string title;

    do {

        cout << "\n=== MUSIC PLAYLIST MENU ===\n";
        cout << "1. Add\n";
        cout << "2. Search\n";
        cout << "3. List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;


        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter song title to add: ";
            getline(cin, title);
            addSong(head, title);
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "Enter song title to search: ";
            getline(cin, title);
            searchSong(head, title);
            system("pause");
            system("cls");

            break;
        case 3:
            listSongs(head);
            system("pause");
            system("cls");
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);



    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}


void addSong(Node*& head, string title) {
    Node* newNode = new Node;
    newNode->songTitle = title;
    newNode->next = head;
    head = newNode;
    cout << "Song '" << title << "' added to the playlist.\n";
}


void searchSong(Node* head, string title) {
    Node* current = head;
    while (current != nullptr) {
        if (current->songTitle == title) {
            cout << "Result: Song '" << title << "' was FOUND in the playlist.\n";
            return;
        }
        current = current->next;
    }

    cout << "Result: Song '" << title << "' was NOT FOUND in the playlist.\n";
}


void listSongs(Node* head) {
    if (head == nullptr) {
        cout << "The playlist is currently empty.\n";
        return;
    }

    Node* current = head;
    int orderNumber = 1;

    cout << "\n--- Your Playlist ---\n";
    while (current != nullptr) {
        cout << orderNumber << ". " << current->songTitle << "\n";
        current = current->next;
        orderNumber++;
    }
}