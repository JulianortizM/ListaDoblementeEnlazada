#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* prev;
    Node* next;

    friend class LinkedList;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    int getFront() const;
    int getBack() const;
    void addFront(int va);
    void addBack(int va);
    void removeFront();
    void removeBack();
    void printReverse();
    void printForward();
    void update(int oldValue, int newValue);
private:
    Node* header;
    Node* trailer;
};

LinkedList::LinkedList() {
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
    header->prev = NULL;
    trailer->next = NULL;
};

int LinkedList::getFront() const {
    return header->next->data;
};

int LinkedList::getBack() const {
    return trailer->prev->data;
};

void LinkedList::addFront(int va) {
    Node* nd = new Node;
    nd->data = va;
    nd->prev = header;
    nd->next = header->next;

    header->next->prev = nd;
    header->next = nd;
};

void LinkedList::addBack(int va) {
    Node* nd = new Node;
    nd->data = va;
    nd->prev = trailer->prev;
    nd->next = trailer;

    trailer->prev->next = nd;
    trailer->prev = nd;
};

void LinkedList::removeFront() {
    Node* nd = header->next->next;
    delete header->next;
    header->next = nd;
    nd->prev = header;
};

void LinkedList::removeBack() {
    Node* nd = trailer->prev->prev;
    delete trailer->prev;
    trailer->prev = nd;
    nd->next = trailer;
};

void LinkedList::printReverse() {
    Node* nd = trailer->prev;

    while (nd != header) {
        cout << nd->data << " ";
        nd = nd->prev;
    }
};

void LinkedList::printForward() {
    Node* nd = header->next;

    while (nd != trailer) {
        cout << nd->data << " ";
        nd = nd->next;
    }
};

void LinkedList::update(int nAnt, int nNue) {
    Node* nd = header->next;

    while (nd != trailer) {
        if (nd->data == nAnt) {
            nd->data = nNue;
        }
        nd = nd->next;
    }
};

LinkedList::~LinkedList() {
    while (header->next != trailer)
        removeFront();

    delete header;
    delete trailer;
};

int main() {
    LinkedList myList;

    while (true) {
        cout << "\nElija una opcion:\n";
        cout << "1. Agregar dato al inicio\n";
        cout << "2. Agregar dato al final\n";
        cout << "3. Eliminar valor del inicio\n";
        cout << "4. Eliminar valor del final\n";
        cout << "5. Mostrar lista de adelante hacia atras\n";
        cout << "6. Mostrar lista de atras hacia adelante\n";
        cout << "7. Actualizar valor\n";
        cout << "8. Salir\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Ingrese el valor a agregar al incio: ";
            int value;
            cin >> value;
            myList.addFront(value);
        } else if (choice == 2) {
            cout << "Ingrese el valor a agregar al final: ";
            int value;
            cin >> value;
            myList.addBack(value);
        } else if (choice == 3) {
            myList.removeFront();
        } else if (choice == 4) {
            myList.removeBack();
        } else if (choice == 5) {
            cout << "Lista en orden de adelante hacia atras: ";
            myList.printForward();
            cout << endl;
        } else if (choice == 6) {
            cout << "Lista en orden de atras hacia adelante: ";
            myList.printReverse();
            cout << endl;
        } else if (choice == 7) {
            int oldValue, newValue;
            cout << "Ingrese el valor antiguo: ";
            cin >> oldValue;
            cout << "Ingrese el nuevo valor: ";
            cin >> newValue;
            myList.update(oldValue, newValue);
        } else if (choice == 8) {
            break;
        } else {
            cout << "Opcion incorrecta. Por favor, elija una opcion valida.\n";
        }
    }
    return 0;
}
