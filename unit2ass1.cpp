#include <iostream>
#include <string>
using namespace std;


struct Node {
    int prn;
    string name;
    Node* next;
};

class VertexClub {
private:
    Node* head;
public:
    VertexClub() {
        head = nullptr;
    }

    // Add member at end
    void addMember() {
        Node* newNode = new Node();
        cout << "Enter PRN: ";
        cin >> newNode->prn;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, newNode->name);
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            cout << "Member added as President (first member)." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        cout << "Member added successfully." << endl;
    }

    // Delete member by PRN
    void deleteMember() {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        int prn;
        cout << "Enter PRN to delete: ";
        cin >> prn;

        if (head->prn == prn) { // delete head
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Member deleted successfully." << endl;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->prn != prn) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Member with PRN " << prn << " not found." << endl;
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Member deleted successfully." << endl;
    }

    // Display members
    void displayMembers() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "\nVertex Club Members:\n";
        cout << "----------------------------------\n";
        while (temp != nullptr) {
            cout << "PRN: " << temp->prn << " | Name: " << temp->name << endl;
            temp = temp->next;
        }
        cout << "----------------------------------\n";
    }

    // Count members
    void countMembers() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "Total members: " << count << endl;
    }

    // Search member by PRN
    void searchMember() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        int prn;
        cout << "Enter PRN to search: ";
        cin >> prn;

        Node* temp = head;
        while (temp != nullptr) {
            if (temp->prn == prn) {
                cout << "Member found: PRN: " << temp->prn << ", Name: " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Member with PRN " << prn << " not found." << endl;
    }

    // Reverse list
    void reverseList() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout << "List reversed successfully." << endl;
    }

    // Sort list by PRN (Bubble sort)
    void sortList() {
        if (head == nullptr || head->next == nullptr) {
            cout << "List is too short to sort." << endl;
            return;
        }

        for (Node* i = head; i->next != nullptr; i = i->next) {
            for (Node* j = head; j->next != nullptr; j = j->next) {
                if (j->prn > j->next->prn) {
                    swap(j->prn, j->next->prn);
                    swap(j->name, j->next->name);
                }
            }
        }
        cout << "List sorted by PRN successfully." << endl;
    }

    // Concatenate another list
    void concatenateList(VertexClub& other) {
        if (head == nullptr) {
            head = other.head;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = other.head;
        }
        other.head = nullptr; // Clear the other list
        cout << "Lists concatenated successfully." << endl;
    }
};

int main() {
    VertexClub club1, club2;
    int choice, division;

    // Initially display empty lists
    cout << "--- Initial Lists ---\n";
    cout << "Division 1:\n";
    club1.displayMembers();
    cout << "Division 2:\n";
    club2.displayMembers();

    do {
        cout << "\n--- Vertex Club Membership Management ---\n";
        cout << "1. Add Member\n";
        cout << "2. Delete Member\n";
        cout << "3. Display Members\n";
        cout << "4. Count Members\n";
        cout << "5. Search Member by PRN\n";
        cout << "6. Reverse List\n";
        cout << "7. Sort List by PRN\n";
        cout << "8. Concatenate Two Division Lists\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch(choice) {
            case 1:
                cout << "Select Division (1 or 2): ";
                cin >> division;
                if (division == 1)
                    club1.addMember();
                else
                    club2.addMember();
                break;
            case 2:
                cout << "Select Division (1 or 2): ";
                cin >> division;
                if (division == 1)
                    club1.deleteMember();
                else
                    club2.deleteMember();
                break;
            case 3:
                cout << "Select Division (1 or 2): ";
                cin >> division;
                if (division == 1)
                    club1.displayMembers();
                else
                    club2.displayMembers();
                break;
            case 4:
                cout << "Select Division (1 or 2): ";
                cin >> division;
                if (division == 1)
                    club1.countMembers();
                else
                    club2.countMembers();
                break;
            case 5:
                cout << "Select Division (1 or 2): ";
                cin >> division;
                if (division == 1)
                    club1.searchMember();
                else
                    club2.searchMember();
                break;
            case 6:
                cout << "Select Division (1 or 2): ";
                cin >> division;
                if (division == 1)
                    club1.reverseList();
                else
                    club2.reverseList();
                break;
            case 7:
                cout << "Select Division (1 or 2): ";
                cin >> division;
                if (division == 1)
                    club1.sortList();
                else
                    club2.sortList();
                break;
            case 8:
                club1.concatenateList(club2);
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while(choice != 0);

    return 0;
}
