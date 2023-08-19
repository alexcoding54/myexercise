#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node * create_linked_list()
{
    return NULL;
}

node * insert_at_beginning(node * head, int data)
{
    node * new_node = (node *)malloc(sizeof(node));

    new_node->data = data;
    new_node->next = head;
    head = new_node;

    return head;
}

node * insert_at_end(node * head, int data)
{
    node * new_node = (node *)malloc(sizeof(node));

    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node * temp = head;

        while (temp->next != NULL) 
            temp = temp->next;

        temp->next = new_node;
    }

    return head;
}

node * delete_node(node * head, int data)
{
    if(head == NULL)
        return head;

    if (head->data == data) {
        node * temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node * current = head;
    node * prev = NULL;

    while (current != NULL) {
        if (current->data == data) {
            prev->next = current->next;
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }

    return head;
}

void print_linked_list(node * head)
{
    node * temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    node * head = create_linked_list();

    insert_at_beginning(head, 1);
    insert_at_beginning(head, 2);
    insert_at_beginning(head, 3);

    print_linked_list(head);

    delete_node(head, 2);

    print_linked_list(head);

    return 0;
}