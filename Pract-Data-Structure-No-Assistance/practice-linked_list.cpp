#include <iostream>

struct node
    {
        int data;
        node* next;
    };

class linked_List {

    node* head;

public:
    linked_List():head(nullptr){};

    void add_node(int value) {
        node* newNode = new node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

void add_node_at_end(int value) {
        node* newNode = new node();
        newNode->data = value;
        newNode->next = nullptr;

        if (!head) {
            std::cout << "NO link list...\n" << std::endl;
            return;
        }

        node* temp = head;

        while(temp->next) {
            temp = temp->next;
        }

        temp->next = newNode;

    }

    void display() {
        if (!head) {
            std::cout << "empty list...\n" << std::endl;
            return;
        }

        node* temp = head;

        while (temp) {
            std::cout << temp->data << "->";
            temp = temp->next;
        }

        std::cout << "NULL" << std::endl;
    }
};


int main() {
    linked_List link;

    link.add_node(3);
    link.add_node_at_end(4);
    link.display();
    return 0;
}
