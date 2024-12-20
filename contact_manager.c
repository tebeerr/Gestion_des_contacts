#include <stdio.h>
#include "contact_list.h"

int main() {
    Node* head = NULL;
    int choice;


        printf("\nContact Manager\n");
        printf("1. Ajouter Contact\n");
        printf("2. Afficher Contacts\n");
        printf("3. Recherche d'un Contact\n");
        printf("4. Supprimer Contact\n");
        printf("5. Quitter\n");
        printf("Entrer Votre choix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(&head); break;
            case 2: displayContacts(head); break;
            case 3: searchContact(head); break;
            case 4: deleteContact(&head); break;
            case 5: freeList(head); printf("Deconnexion...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }


    return 0;
}
