#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	string nur;
	string Hi;
	Node* next;
};
class CircularLikedList {
	Node* LAST;
public:
	CircularLikedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLikedList::addNode() {
	string name;
	cout << "\n the roll name: ";
	cin >> name;
	string nur;
	cout << "\n the roll first name: ";
	cin >> nur;
	string Hi;
	cout << "\n the roll last name: ";
	Node* newNode = new Node(); // step 1
	newNode->name = name; //step 2
	newNode->nur = nur;
	newNode->Hi;

	/**/
	if (LAST == NULL || name <= LAST->name) {
		if (LAST != NULL && name == LAST->name) {
			cout << "\nDuplicate name not allowed" << endl;
			return;
		}
		newNode->next = LAST;
		if (LAST != NULL)
			LAST->next = newNode;
		newNode->next = NULL;
		LAST = newNode;
		return;
	}
	/**/
	Node* current = LAST;
	Node* LAST = NULL;
	while (current->next != NULL && current->next->name < Hi)
	{
		LAST = current;
		current = current->next;
	}
	if (current->next != NULL && name == current->next->name) {
		cout << "\nDuplicate roll name not allowd" << endl;
		return;
	}
	newNode->next = current->next;
	if (current->next != NULL)
		current->next = newNode;
}

bool CircularLikedList::search(int rollno, Node** previous, Node** current) {
	*previous = LAST->next;
	*current = LAST->next;

	while (*current != LAST) {
		if (rollno == (*current)->rollNumber) {
			return true;
		}
		*previous = *current;
		*current = (*current)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
	bool CircularLikedList::listEmpty() {
		return (LAST == NULL);

	}
	bool CircularLikedList::delNode() {

	}

	void CircularLikedList::traverse() {
		if (listEmpty()) {
			cout << "\nList is Empty";
		}
		else {
			cout << "\nRecords in the list are:\n";
			Node* currentNode = LAST->next;
			while (currentNode != Last) {
				cout << currentNode->rollNumber << " " << currentNode->name << endl;
				currentNode = currentNode->next;
			}
			cout << LAST->rollNumber << " " LAST->name << endl;
		}

		int main() {
			CircularLikedList obj;
			while (true) {
				try {
					cout << "1. Tambahkan Data" << endl;
					cout << "2. Hapus Data" << endl;
					cout << "3. Tampilkan Data" << endl;
					cout << "4.Cari Data" << endl;
					cout << "5. Keluar" << endl;
					cout << "pilihan: ";
					cin >> pilihan;
					switch (pilihan)
					{
					case 1:
						addNode();
						cout << "Data Berhasil Ditambahkan" << endl;
						system("pause");
						system("cls");
						break;
					case 2:
						if (listEmpty())
						{
							cout << "List Kosong" << endl;
							system("pause");
							system("cls");
							break;
						}

						int nim;
						cout << "Masukkan NIM: ";
						cin >> nim;
						if (deleteNode(nim)) {
							cout << "nim: " << nim << "berhasil dihapus" << endl;
							system("pause");
							system("cls");
						}
						else
							cout << "Data tidak ditemukan" << endl;
						break;
					case 3:
						traverse();
						break;
					case 4:
						searchData();
					case 5:
						break;
					}
				}
				catch (exception e)
				{
					cout << "Terjadi Kesalahan" << endl;
				}
			} while (pilihan != 5);

		}
				}
			}
		}
	}
}