// THE CODE HAS NO ERROR HANDELING IN ANY FUNC PLZ ADD THAT

#include <stdio.h>
#include<stdlib.h>

// structure for the linked list
typedef struct Linked_list
{
    int data;
    struct Linked_list * next;
}NODE ;


NODE * create_node(int value, NODE * temp);
void display(NODE * head);
void delete_begining(NODE **head);
void delete_index(NODE ** head);
void delete_end(NODE * head);
void delete_with_value(NODE * head);



int main(int argc, char const *argv[])
{
    NODE * head;
    NODE * temp;
    int num, choice, value;
    
    head = NULL;
    temp = NULL;

    printf("Enter number of nodes you want:  ");
    scanf("%d", &num);
    
    for (int i = 0; i < num; i++)
    {
        printf("Enter a value of element %d : ", i+1);
        scanf("%d",&value);
        NODE * fresh_node = create_node(value, temp);
        if (head == NULL)
        {
            head = fresh_node; 
        }
        temp = fresh_node;
    }
    do
    {
        printf("\nCurrent List:\n");
        display(head);

        printf("\nLinked List Operations:\n");
        printf("1. Delete at  Begining\n");
        printf("2. Delete at Ending\n");
        printf("3. Delete at an Index\n");
        printf("4. Delete an Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Deleting the first element.....\n");
                delete_begining(&head);
                break;
            case 2:
                printf("Deleting the last elemnet.....\n");
                delete_end(head);
                break;
            case 3:
                printf("Deleting as your desired index...\n");
                delete_index(head);
                break;
            case 4:
                printf("Deleting the desired element.....\n");
                delete_with_value(head);
                break;
            case 5:
                printf("Exiting.....\n");
                exit(-100);
            default:
                printf("INVALID OPTION!!!! \n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}

// 1. func for NODE creation 
NODE * create_node(int value, NODE * temp){
    NODE * new_node = (NODE * )malloc(sizeof(NODE));
    new_node->data = value;
    new_node->next = NULL;

    if (temp != NULL)
    {
        temp->next = new_node;
    }
    return new_node;
}

// 2. Func for Displaying the Linked list
void display(NODE * head){

    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
    
}

// 3. Func for deleting the head
// Either make is a func that returns a ptr (in this case it should retun the new head)
// or call it by ref

void delete_begining(NODE ** head){ // we called head by ref so that it auto changes it in main
    if (*head == NULL)
    {
        printf("The list is already empty.\n");
        return;
    }
    NODE * ptr = *head;
    *head = (*head)->next;
    free(ptr);
}


// 4. Func to delete at a particular indx 
/* as this doesnt change the head of the linked list 
we dont need to return or pass head as ref*/

void delete_index(NODE ** head){
    
    int index;
    printf("Enter a valid index: ");
    scanf("%d", &index);

    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    NODE * ptr = *head; 

    if (index == 0) {
        delete_begining(head);
        return;
    }

    for (int i = 0; i < index - 1 && ptr->next != NULL; i++) // checks whether its end of list??
    {
        ptr = ptr->next;
    }

    if (ptr->next == NULL) {
        printf("Index out of bounds.\n");
        return;
    }
    // MAIN DELETION PART
    NODE * qtr = ptr->next;
    ptr->next = qtr->next;
    free(qtr);


    // ANOTHER METHORD 
    // int i = 0;                            // we use an var to track the index
    // while (i != index-1)                  // just stops before the index 
    // {
    //     ptr = ptr->next;
    //     i++;
    // }
        
}


// 5. Func to delete any node at the end
/* we simply traverse the 2nd last node and then we made 
it point to NULL and delete the last node using another pointer*/

void delete_end(NODE * head){
    NODE * ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}


// 6. Func to delete any node with value
/* we simply search and traver through until reach 
1 node before the desired node then delete */
void delete_with_value(NODE * head){
    int num;
    printf("Enter the value you want to delete: ");
    scanf("%d",&num);
    NODE * ptr = head;
    while (ptr->next->data != num)                  // checks if the value of next node matches the desired one
    {
        ptr = ptr->next;
    }
    NODE * qtr = ptr->next;
    ptr->next = qtr->next;
    free(qtr);
    
}