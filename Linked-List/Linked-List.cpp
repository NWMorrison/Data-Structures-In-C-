#include <iostream>

struct Node
{
    int data;
    Node* next;
};

class linkedList
{
    Node* head;

public:
    // Constructor that initializes our head to a nullptr.
    linkedList() : head(nullptr){};

    // Insert Node @ Beginning of the Linked List.
    void node_At_Beginning(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Insert Node @ the end of our Linked List.
    void node_At_End(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;


        // If our linked list is empty
        if (!head) {
            head = newNode;
            return;
        }

        // Traversing To The Last Node In The Linked List.
        Node* temp = head;
        while(temp->next)
        {
            temp = temp->next;
        }

        // Update the last node's next to a new node.
        temp->next = newNode;
    }

    // Inserting Node @ a given position in the Linked List.
    void add_Node_AtPosition(int value, int pos)
    {
        if (pos < 1)
        {
            std::cout << "The position should be at least greater than 1: " << std::endl;
            return;
        }

        if (pos == 1)
        {
            node_At_Beginning(value);
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        // Traverse before the desired position.
        Node* temp = head;
        for (int i{0}; i < pos - 1 && temp; ++i)
        {
            temp = temp->next;
        }

        // Error Message if out of desired range.

        if (!temp)
        {
            std::cout << "Position is out of range. "<< std::endl;
            delete newNode;
            return;
        }

        // Insert Node at desired position.
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void delete_First_Node() {

        // If our linked list is empty.
        if (!head)
        {
            std::cout << "The Linked List is empty..." << std::endl;
        }

        // Deleting our first node and setting our head to whatever is next in our linked list.
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void delete_Last_Node()
    {

        // Throwing an pseudo-error if our linked list happens to be empty.
        if(!head)
        {
            std::cout << "The Linked List Is Empty..." << std::endl;
            return;
        }

        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }

        // Traversing the second to last node.
        Node* temp = head;
        while(temp->next->next)
        {
            temp = temp->next;
        }

        // Deleting the last node.
        delete temp->next;

        // Setting the second to last nodes next value to nullptr.
        temp->next = nullptr;
    }

    void delete_Node_FromPosition(int pos)
    {
        if (pos < 1)
        {
            std::cout << "The Position Should be Greater Than 1..." << std::endl;
            return;
        }

        if (pos == 1)
        {
            delete_First_Node();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            std::cout << "Position out of range." << std::endl;
            return;
        }
        // Save the node to be deleted
        Node* nodeToDelete = temp->next;
        // Update the next pointer
        temp->next = temp->next->next;
        // Delete the node
        delete nodeToDelete;
    }

    // Function to print the nodes of  the linked list
    void display()
    {
        if (!head)
        {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        while (temp)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

}LL;

int main()
{
    /*
    // Initialize a new linked list
     linkedList list1;

    // Insert elements at the end
    list1.node_At_End(10);
    list1.node_At_End(20);

    // Insert element at the beginning
    list1.node_At_Beginning(5);

    // Insert element at a specific position
    list1.add_Node_AtPosition(15, 3);

    std::cout << "Linked list after insertions: ";
    list1.display();

    // Delete element from the beginning
    list1.delete_First_Node();
    std::cout << "Linked list after deleting from beginning: ";
    list1.display();

    // Delete element from the end
    list1.delete_Last_Node();
    std::cout << "Linked list after deleting from end: ";
    list1.display();

    // Delete element from a specific position
    list1.delete_Node_FromPosition(2);
    std::cout << "Linked list after deleting from position 2: ";
    list1.display();
    return 0;
    */
}


