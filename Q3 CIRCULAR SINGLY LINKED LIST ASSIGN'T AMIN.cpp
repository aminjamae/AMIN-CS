#include <iostream>
using namespace std;

// Node structure
class Node {
	public:
		int data;
		Node *next;

		Node(int value) {
			data = value;
			next = NULL;
		}
};

// Circular Singly Linked List class
class CircularSinglyLinkedList {
	private:
		Node *tail; // Pointer to the last node

	public:
		// Constructor
		CircularSinglyLinkedList() {
			tail = NULL;
		}

		// Insert at the beginning
		void insertAtBeginning(int value) {
			Node *newNode = new Node(value);
			if (tail == NULL) {
				tail = newNode;
				tail->next = newNode; // Point to itself
			} else {
				newNode->next = tail->next;
				tail->next = newNode;
			}
			cout << "Inserted " << value << " at the beginning.\n";
		}

		// Insert at the end
		void insertAtEnd(int value) {
			Node *newNode = new Node(value);
			if (tail == NULL) {
				tail = newNode;
				tail->next = newNode; // Point to itself
			} else {
				newNode->next = tail->next;
				tail->next = newNode;
				tail = newNode; // Update tail to the new node
			}
			cout << "Inserted " << value << " at the end.\n";
		}

		// Insert at a specific position
		void insertAtPosition(int value, int position) {
			Node *newNode = new Node(value);
			if (position == 1) {
				if (tail == NULL) {
					tail = newNode;
					tail->next = newNode;
				} else {
					newNode->next = tail->next;
					tail->next = newNode;
				}
				cout << "Inserted " << value << " at position " << position << ".\n";
				return;
			}

			Node *temp = tail->next;
			for (int i = 1; i < position - 1 && temp != tail; i++) {
				temp = temp->next;
			}

			if (temp == tail && position != 2) {
				cout << "Position out of bounds!\n";
				return;
			}

			newNode->next = temp->next;
			temp->next = newNode;
			if (temp == tail) {
				tail = newNode;
			}
			cout << "Inserted " << value << " at position " << position << ".\n";
		}

		// Delete from the beginning
		void deleteFromBeginning() {
			if (tail == NULL) {
				cout << "The list is empty! Nothing to delete.\n";
				return;
			}

			Node *temp = tail->next;
			if (tail->next == tail) { // Only one node
				delete tail;
				tail = NULL;
			} else {
				tail->next = temp->next;
				delete temp;
			}
			cout << "Deleted node from the beginning.\n";
		}

		// Delete from the end
		void deleteFromEnd() {
			if (tail == NULL) {
				cout << "The list is empty! Nothing to delete.\n";
				return;
			}

			if (tail->next == tail) { // Only one node
				delete tail;
				tail = NULL;
			} else {
				Node *temp = tail->next;
				while (temp->next != tail) {
					temp = temp->next;
				}
				temp->next = tail->next;
				delete tail;
				tail = temp;
			}
			cout << "Deleted node from the end.\n";
		}

		// Delete from a specific position
		void deleteFromPosition(int position) {
			if (tail == NULL) {
				cout << "The list is empty! Nothing to delete.\n";
				return;
			}

			if (position == 1) {
				deleteFromBeginning();
				return;
			}

			Node *temp = tail->next;
			for (int i = 1; i < position - 1 && temp->next != tail->next; i++) {
				temp = temp->next;
			}

			if (temp->next == tail->next) {
				cout << "Position out of bounds!\n";
				return;
			}

			Node *toDelete = temp->next;
			temp->next = toDelete->next;
			if (toDelete == tail) {
				tail = temp;
			}
			delete toDelete;
			cout << "Deleted node from position " << position << ".\n";
		}

		// Display the circular list
		void display() {
			if (tail == NULL) {
				cout << "The list is empty!\n";
				return;
			}

			Node *temp = tail->next;
			cout << "Circular Linked List: ";
			do {
				cout << temp->data << " -> ";
				temp = temp->next;
			} while (temp != tail->next);
			cout << "(circular)\n";
		}

		// Destructor to free memory
		~CircularSinglyLinkedList() {
			if (tail == NULL)
				return;

			Node *temp = tail->next;
			do {
				Node *nextNode = temp->next;
				delete temp;
				temp = nextNode;
			} while (temp != tail->next);

			tail = NULL;
		}
};

// Main function with menu-driven interface
int main() {
	CircularSinglyLinkedList list;
	int choice, value, position;

	while (true) {
		cout << "\n--- Circular Singly Linked List Operations ---\n";
		cout << "1. Insert at Beginning\n";
		cout << "2. Insert at End\n";
		cout << "3. Insert at Specific Position\n";
		cout << "4. Delete from Beginning\n";
		cout << "5. Delete from End\n";
		cout << "6. Delete from Specific Position\n";
		cout << "7. Display List\n";
		cout << "8. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter value to insert: ";
				cin >> value;
				list.insertAtBeginning(value);
				break;
			case 2:
				cout << "Enter value to insert: ";
				cin >> value;
				list.insertAtEnd(value);
				break;
			case 3:
				cout << "Enter value to insert: ";
				cin >> value;
				cout << "Enter position to insert: ";
				cin >> position;
				list.insertAtPosition(value, position);
				break;
			case 4:
				list.deleteFromBeginning();
				break;
			case 5:
				list.deleteFromEnd();
				break;
			case 6:
				cout << "Enter position to delete: ";
				cin >> position;
				list.deleteFromPosition(position);
				break;
			case 7:
				list.display();
				break;
			case 8:
				cout << "Exiting...\n";
				return 0;
			default:
				cout << "Invalid choice! Try again.\n";
		}
	}
}
