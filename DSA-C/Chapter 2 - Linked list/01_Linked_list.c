#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};


void display(struct node * head);   // displays the LL
struct node * create_node_1(int value); // creates the nodes with an input value but doesnt links them
struct node * create_node_2(int value, struct node * temp); // creates nodes with a value and links all nodes





int main(int argc, char const *argv[])
{

    // This would be the manual way of making nodes and linking them
    struct node * head;
    struct node * first;
    struct node * second;
    struct node * third;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    // Data is alloacted to each node
    head -> data   = 10 ;
    first -> data  = 20 ;
    second -> data = 30 ;
    third -> data  = 40 ;

    // Nodes are linked together 
    head -> next   = first ;
    first -> next  = second ;
    second -> next = third ;
    third -> next  = NULL ;



    // this was cerated by create_node_1 fx
    struct node * head_1  = create_node_1(10);
    struct node * first_1  = create_node_1(10);
    struct node * second_1 = create_node_1(10);
    struct node * third_1  = create_node_1(10);

    // linking part of fx_1
    head_1 ->next = first_1;
    first_1 ->next = second_1;
    second_1 ->next = third_1;
    third_1 ->next = NULL;

    // creation and linking of fx_2

    struct node *head_2 = NULL;
    struct node *temp_2 = NULL;
    int num, value;

    printf("Enter the amount of nodes you want: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Enter the value of element %d: ", i + 1);
        scanf("%d", &value);
        struct node *newnode = create_node_2(value, temp_2);
        if (head_2 == NULL) {
            head_2 = newnode;
        }
        temp_2 = newnode;
    }
    
    // display
    int choice;
    printf("choose the option to display\n");
    printf("1. LL - 1 (manual)\n");
    printf("2. LL - 2 (semi-manual)\n");
    printf("3. LL - 2 (automatic)\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        display(head);
        break;
    case 2:
        display(head_1);
        break;
    case 3:
        display(head_2);
    default:
        break;
    }

    return 0;
}

void display(struct node * head){
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head -> next;
    }
    printf("NULL\n");
    
}

struct node * create_node_1(int value){
    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = value;
    new_node -> next = NULL;
    return new_node;
}

struct node * create_node_2(int value, struct node * temp_2){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if (temp_2 != NULL) {
        temp_2->next = new_node; // temp_2 contains newnode thus
         // this  means newnode ->next (in for loop) is now pointing to new_node created  connecting nodes in heap
    }
    return new_node;
}

/*
### Answers to Your Questions:

#### 1. Why `head = fresh_node` and not `*head = fresh_node` at line 31?
- **`head = fresh_node`**:
  - Here, `head` is a pointer variable of type `Node*`. It holds the address of the first node in the linked list.
  - When we assign `fresh_node` (also a `Node*`) to `head`, we are setting the `head` pointer to point to the newly created node.
  - Using `*head` would mean dereferencing the pointer to access the actual structure, but here we are assigning a memory address (not data inside the node), so we simply use `head`.

#### 2. Why not `*temp = fresh_node` at line 33?
- **`temp = fresh_node`**:
  - Similar to the above explanation, `temp` is also a pointer variable. It holds the address of the last node created so far.
  - Assigning `fresh_node` to `temp` updates the pointer `temp` to point to the new node, making it the "current last node."
  - Using `*temp` would dereference the pointer and attempt to overwrite the data inside the node that `temp` points to, which is not the goal here.

---

#### 3. What Each Pointer Contains at Each Step of the Process?

Here's an explanation of what happens to the pointers (`head`, `temp`, and `fresh_node`) during each step:

**Before the loop starts:**
- `head = NULL`: The linked list is empty, so the head pointer is initialized to `NULL`.
- `temp = NULL`: No nodes exist yet, so `temp` is also `NULL`.

**Step-by-Step in the Loop:**
- **Step 1 (First Node Creation):**
  - `create_node(value, temp)` is called with `value` and `temp = NULL`.
    - A new `Node` is allocated (`fresh_node`) with:
      - `fresh_node->data = value`.
      - `fresh_node->next = NULL` (no other node exists yet).
    - Since `temp = NULL`, no linking to a tempious node occurs.
  - **State after creation:**
    - `fresh_node`: Points to the first node with `data = value` and `next = NULL`.
    - `head`: Still `NULL` at this point.
    - `temp`: Still `NULL`.
  - After the check `if (head == NULL)`, we assign `head = fresh_node`, so:
    - `head` now points to the first node.
    - `temp` is updated to `fresh_node`.

- **Step 2 (Subsequent Node Creation):**
  - `create_node(value, temp)` is called with `value` and `temp` pointing to the last node created.
    - A new `Node` is allocated (`fresh_node`) with:
      - `fresh_node->data = value`.
      - `fresh_node->next = NULL` (no other node exists yet).
    - Since `temp != NULL`, we set `temp->next = fresh_node`, linking the tempious node to the new node.
  - **State after creation:**
    - `fresh_node`: Points to the newly created node.
    - `head`: Still points to the first node.
    - `temp`: Still points to the tempious node (before update).
  - After the update `temp = fresh_node`:
    - `temp` now points to the newly created node.

- **Final State After the Loop:**
  - `head`: Points to the first node in the list.
  - `temp`: Points to the last node in the list.
  - Each node's `next` pointer links it to the next node in the list, and the last node's `next` is `NULL`.

---

#### Example Trace with `num = 3` and Input Values `[10, 20, 30]`:

| Step | `value` | `fresh_node`           | `temp`                 | `head`                 | Description                              |
|------|---------|------------------------|------------------------|------------------------|------------------------------------------|
| 1    | 10      | Points to `Node(10)`   | `NULL`                 | `NULL`                 | First node created, `head = fresh_node`. |
| 2    | 20      | Points to `Node(20)`   | Points to `Node(10)`   | Points to `Node(10)`   | New node created, `temp->next = fresh_node`. |
| 3    | 30      | Points to `Node(30)`   | Points to `Node(20)`   | Points to `Node(10)`   | New node created, `temp->next = fresh_node`. |

The final linked list: `10 -> 20 -> 30 -> NULL`.

Let me know if you need more details!
*/