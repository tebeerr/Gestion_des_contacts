#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H

typedef struct Contact {
    char Nom[50];
    char Tel[15];
    char email[50];
} Contact;

typedef struct Node {
    Contact data;
    struct Node* next;
} Node;

void addContact(Node** head);
void displayContacts(Node* head);
void searchContact(Node* head);
void deleteContact(Node** head);
void freeList(Node* head);

#endif
