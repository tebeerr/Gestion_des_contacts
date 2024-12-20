#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact_list.h"

void addContact(Node** head) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
          perror("Memory allocation failed");
          exit(EXIT_FAILURE);
        }
    printf("Entrer le nom: ");
    scanf(" %[^\n]", newNode->data.Nom);
    printf("Entrer le numero de telephone: ");
    scanf("%s", newNode->data.Tel);
    printf("Entrer l'email: ");
    scanf("%s", newNode->data.email);

    newNode->next = *head;
    *head = newNode;

    printf("Contact ajoute avec succes!\n");
}

void displayContacts(Node* head) {
    if (head == NULL) {
        printf("Aucun contact a afficher.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("Nom: %s\nTel: %s\nEmail: %s\n\n",
               temp->data.Nom, temp->data.Tel, temp->data.email);
        temp = temp->next;
    }
}

void searchContact(Node* head) {
    char name[50];
    printf("Entrer le Nom a recherche: ");
    scanf(" %[^\n]", name);

    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data.Nom, name) == 0) {
            printf("Nom: %s\nTel: %s\nEmail: %s\n",
                   temp->data.Nom, temp->data.Tel, temp->data.email);
            return;
        }
        temp = temp->next;
    }
    printf("Contact introuvable.\n");
}

void deleteContact(Node** head) {
    char name[50];
    printf("Entrez le nom à supprimer: ");
    scanf(" %[^\n]", name);

    Node *temp = *head, *prev = NULL;
    while (temp != NULL && strcmp(temp->data.Nom, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Contact introuvable.\n");
        return;
    }

    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Contact supprime avec succes.\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


void saveContactsToFile(Node* head, const char* filename) {
    FILE* file = fopen(filename, "w");

    if (!file) {
        perror("Error opening file for saving");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        fprintf(file, "%s\n%s\n%s\n", temp->data.Nom, temp->data.Tel, temp->data.email);
        temp = temp->next;
    }

    fclose(file);
}



void loadContactsFromFile(Node** head, const char* filename) {
    FILE* file = fopen(filename, "r");

    if (!file) {
       return;
    }

    char Nom[50];
    char Tel[15];
    char email[50];

    while (fscanf(file, " %[^\n]\n%[^\n]\n%[^\n]\n", Nom, Tel, email) == 3) {
        Node* newNode = (Node*)malloc(sizeof(Node));
         if (!newNode) {
            perror("Memory allocation failed");
            fclose(file);
            freeList(*head);
            exit(EXIT_FAILURE);
        }
        strcpy(newNode->data.Nom, Nom);
        strcpy(newNode->data.Tel, Tel);
        strcpy(newNode->data.email, email);


        newNode->next = *head;
        *head = newNode;
    }

  fclose(file);
}