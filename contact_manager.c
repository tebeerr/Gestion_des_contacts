#include <stdio.h>
#include "contact_list.h"
#define CONTACTS_FILE "contacts.txt"

int main() {
    Node* head = NULL;
    int choice;

    loadContactsFromFile(&head, CONTACTS_FILE);

 do {
        printf("\nContact Manager\n");
        printf("1. Ajouter Contact\n");
        printf("2. Afficher Contacts\n");
        printf("3. Recherche d'un Contact\n");
        printf("4. Supprimer Contact\n");
        printf("5. Quitter\n");
        printf("Entrer Votre choix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(&head); saveContactsToFile(head, CONTACTS_FILE);break;
            case 2: displayContacts(head); break;
            case 3: searchContact(head); break;
            case 4: deleteContact(&head); saveContactsToFile(head, CONTACTS_FILE); break;
            case 5: freeList(head); printf("Deconnexion...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice !=5);

    saveContactsToFile(head,CONTACTS_FILE);

    return 0;
}
