#include <iostream>
using namespace std;

// Define the Node structure
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

// Doubly Linked List class
class DoublyLinkedList {
	private:
		Node *head; // Head pointer

	public:
		// Constructor
		DoublyLinkedList() {
			head = NULL;
		}

		// Insert at the beginning
		void insertAtBeginning(int value) {
			Node *newNode = new Node(value);
			if (head == NULL) {
				head = newNode;
			} else {
				newNode->next = head;
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
			} else {
				Node *temp = head;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = newNode;
				newNode->prev = temp;
			}
			cout << "Inserted " << value << " at the end.\n";
		}

		// Insert at a specific position
		void insertAtPosition(int value, int position) {
			Node *newNode = new Node(value);
			if (position == 1) {
				newNode->next = head;
				if (head != NULL) {
					head->prev = newNode;
				}
				head = newNode;
				cout << "Inserted " << value << " at position " << position << ".\n";
				return;
			}

			Node *temp = head;
			for (int i = 1; i < position - 1 && temp != NULL; i++) {
				temp = temp->next;
			}

			if (temp == NULL) {
				cout << "Position out of bounds!\n";
				return;
			}

			newNode->next = temp->next;
			if (temp->next != NULL) {
				temp->next->prev = newNode;
			}
			newNode->prev = temp;
			temp->next = newNode;
			cout << "Inserted " << value << " at position " << position << ".\n";
		}

		// Delete from the beginning
		void deleteFromBeginning() {
			if (head == NULL) {
				cout << "The list is empty! Nothing to delete.\n";
				return;
			}

			Node *temp = head;
			head = head->next;
			if (head != NULL) {
				head->prev = NULL;
			}
			cout << "Deleted " << temp->data << " from the beginning.\n";
			delete temp;
		}

		// Delete from the end
		void deleteFromEnd() {
			if (head == NULL) {
				cout << "The list is empty! Nothing to delete.\n";
				return;
			}

			if (head->next == NULL) {
				cout << "Deleted " << head->data << " from the end.\n";
				delete head;
				head = NULL;
				return;
			}

			Node *temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->prev->next = NULL;
			cout << "Deleted " << temp->data << " from the end.\n";
			delete temp;
		}

		// Delete from a specific position
		void deleteFromPosition(int position) {
			if (head == NULL) {
				cout << "The list is empty! Nothing to delete.\n";
				return;
			}

			if (position == 1) {
				Node *temp = head;
				head = head->next;
				if (head != NULL) {
					head->prev = NULL;
				}
				cout << "Deleted " << temp->data << " from position " << position << ".\n";
				delete temp;
				return;
			}

			Node *temp = head;
			for (int i = 1; i < position - 1 && temp != NULL; i++) {
				temp = temp->next;
			}

			if (temp == NULL || temp->next == NULL) {
				cout << "Position out of bounds!\n";
				return;
			}

			Node *toDelete = temp->next;
			temp->next = temp->next->next;
			if (temp->next != NULL) {
				temp->next->prev = temp;
			}
			cout << "Deleted " << toDelete->data << " from position " << position << ".\n";
			delete toDelete;
		}

		// Display the linked list
		void display() {
			if (head == NULL) {
				cout << "The list is empty!\n";
				return;
			}

			Node *temp = head;
			cout << "Linked List: ";
			while (temp != NULL) {
				cout << temp->data << " <-> ";
				temp = temp->next;
			}
			cout << "NULL\n";
		}

		// Destructor to free memory
		~DoublyLinkedList() {
			Node *temp;
			while (head != NULL) {
				temp = head;
				head = head->next;
				delete temp;
			}
		}
};

// Main function with menu-driven interface
int main() {
	DoublyLinkedList list;
	int choice, value, position;

	while (true) {
		cout << "\n Doubly Linked List Operations \n";
		cout << "1. Insert at Beginning\n";
		cout << "2. Insert at End\n";
		cout << "3. Insert at Specific Position\n";
		cout << "4. Delete from Beginning\n";
		cout << "5. Delete from End\n";
		cout << "6. Delete from Specific Position\n";
		cout << "7.successfully\n";
		cout << "8. Display List\n";
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
				cout << "successfully\n";
				break;
			case 8:
				list.display();
				break;
			case 9:
				cout << "Exiting...\n";
				return 0;
			default:
				cout << "Invalid choice! Try again.\n";
		}
	}
}
