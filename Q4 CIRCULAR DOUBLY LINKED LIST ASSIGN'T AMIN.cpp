#include <iostream>
using namespace std;

// Node structure
class Node {
	public:
		int data;
		Node *prev;
		Node *next;

		Node(int value) {
			data = value;
			prev = NULL;
			next = NULL;
		}
};

// Circular Doubly Linked List class
class CircularDoublyLinkedList {
	private:
		Node *head; // Head pointer for convenience

	public:
		// Constructor
		CircularDoublyLinkedList() {
			head = NULL;
		}

		// Insert at the beginning
		void insertAtBeginning(int value) {
			Node *newNode = new Node(value);
			if (head == NULL) {
				head = newNode;
				newNode->prev = newNode;
				newNode->next = newNode;
			} else {
				Node *tail = head->prev;
				newNode->next = head;
				newNode->prev = tail;
				tail->next = newNode;
				head->prev = newNode;
				head = newNode;
			}
			cout << "Inserted " << value << " at the beginning.\n";
		}

		// Insert at the end
		void insertAtEnd(int value) {
			Node *newNode = new Node(value);
			if (head == NULL) {
				head = newNode;
				newNode->prev = newNode;
				newNode->next = newNode;
			} else {
				Node *tail = head->prev;
				newNode->next = head;
				newNode->prev = tail;
				tail->next = newNode;
				head->prev = newNode;
			}
			cout << "Inserted " << value << " at the end.\n";
		}

		// Insert at a specific position
		void insertAtPosition(int value, int position) {
			Node *newNode = new Node(value);
			if (position == 1) {
				insertAtBeginning(value);
				return;
			}

			Node *temp = head;
			for (int i = 1; i < position - 1 && temp->next != head; i++) {
				temp = temp->next;
			}

			if (temp->next == head && position != 2) {
				cout << "Position out of bounds!\n";
				return;
			}

			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next->prev = newNode;
			temp->next = newNode;
			cout << "Inserted " << value << " at position " << position << ".\n";
		}

		// Delete from the beginning
		void deleteFromBeginning() {
			if (head == NULL) {
				cout << "The list is empty! Nothing to delete.\n";
				return;
			}

			Node *tail = head->prev;
			if (head->next == head) { // Only one node
				delete head;
				head = NULL;
			} else {
				Node *temp = head;
				head = head->next;
				tail->next = head;
				head->prev = tail;
				delete temp;
			}
			cout << "Deleted node from the beginning.\n";
		}

		// Delete from the end
		void deleteFromEnd() {
			if (head == NULL) {
				cout << "The list is empty! Nothing to delete.\n";
				return;
			}

			Node *tail = head->prev;
			if (head->next == head) { // Only one node
				delete head;
				head = NULL;
			} else {
				Node *temp = tail;
				tail = tail->prev;
				tail->next = head;
				head->prev = tail;
				delete temp;
			}
			cout << "Deleted node from the end.\n";
		}

		// Delete from a specific position
		void deleteFromPosition(int position) {
			if (head == NULL) {
				cout << "The list is empty! Nothing to delete.\n";
				return;
			}

			if (position == 1) {
				deleteFromBeginning();
				return;
			}

			Node *temp = head;
			for (int i = 1; i < position - 1 && temp->next != head; i++) {
				temp = temp->next;
			}

			if (temp->next == head) {
				cout << "Position out of bounds!\n";
				return;
			}

			Node *toDelete = temp->next;
			temp->next = toDelete->next;
			toDelete->next->prev = temp;
			delete toDelete;
			cout << "Deleted node from position " << position << ".\n";
		}

		// Display the circular list
		void display() {
			if (head == NULL) {
				cout << "The list is empty!\n";
				return;
			}

			Node *temp = head;
			cout << "Circular Doubly Linked List: ";
			do {
				cout << temp->data << " <-> ";
				temp = temp->next;
			} while (temp != head);
			cout << "(circular)\n";
		}

		// Destructor to free memory
		~CircularDoublyLinkedList() {
			if (head == NULL)
				return;

			Node *temp = head;
			do {
				Node *nextNode = temp->next;
				delete temp;
				temp = nextNode;
			} while (temp != head);

			head = NULL;
		}
};

// Main function with menu-driven interface
int main() {
	CircularDoublyLinkedList list;
	int choice, value, position;

	while (true) {
		cout << "\n Circular Doubly Linked List Operations \n";
		cout << "1. Insert at Beginning\n";
		cout << "2. Insert at End\n";
		cout << "3. Insert at Specific Position\n";
		cout << "4. Delete from Beginning\n";
		cout << "5. Delete from End\n";
		cout << "6. Delete from Specific Position\n";
		cout << "7. Display List\n";
		cout << "8.successfully\n";
		cout << "9. Exit\n";
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
				cout << "successfully\n";
				break;
			case 9:
				cout << "Exiting...\n";
				return 0;
			default:
				cout << "Invalid choice! Try again.\n";
		}
	}
}
