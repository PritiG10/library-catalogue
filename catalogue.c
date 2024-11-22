#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogue.h"
// #include "book.h"

struct Book *tail = NULL;
struct Book *head = NULL;

void Add_NewBook()
{
    printf("\n ***** Enter the Book Details ***** \n");
    struct Book *temp = malloc(sizeof(struct Book));
    printf("Enter the Book Title : ");
    scanf("%s", temp->book_title);

    printf("Enter the Author Name : ");
    scanf("%s", temp->author);

    printf("Enter the ISBN Number : ");
    scanf("%s", temp->ISBN_number);

    printf("Enter the Publisher Name : ");
    scanf("%s", temp->publisher);

    printf("Enter the Publication Year : ");
    scanf("%d", temp->publication_year);

    printf("Enter the Genre : ");
    scanf("%s", temp->genre);

    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void Display_BookDetails()
{
    struct Book *temp = head;
    if(head == NULL)
    {
        printf("Records are not present");
    }
    else
    {
        while (temp != NULL)
        {
            printf("\n ***** Display the Book Details ***** \n");
            printf("Book's Title : %s\n", temp->book_title);
            printf("Author Name : %s\n", temp->author);
            printf("ISBN Number : %s\n", temp->ISBN_number);
            printf("Publisher Name : %s\n", temp->publisher);
            printf("Publication Year : %d\n", temp->publication_year);
            printf("Genre : %s\n", temp->genre);
            temp = temp->next;
            if(temp != NULL)
            {
                printf("Press the enter key to continue...");
            }
        } 
    }
}

void Free_MemoryAllocated()
{
    if(head == NULL)
    {
        printf("Records are not present");
    }
    else
    {
        int count = 0;
        struct Book *temp = head;
        while ((temp != NULL))
        {
           struct Book *var = temp->next;
           free(temp);
           temp = var;
           count++;
        }
        printf("%d records are deleted", count);
    }
}

int main()
{
    Add_NewBook();
    Display_BookDetails();
    Free_MemoryAllocated();
    Display_BookDetails();
    return 0;
}

