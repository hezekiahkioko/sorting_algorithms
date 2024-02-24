#include "sort.h"

/**
 * swap_left - swap two nodes left in a doubly linked list
 * @node: pointer to the node
 * Return: void
 **/
void swap_left(listint_t *node) {
    listint_t *temp, *head;
    while (node->prev != NULL) {
        if (node->n < node->prev->n) {
            temp = node->prev->prev;
            node->prev->next = node->next;
            node->next = node->prev;
            node->prev->prev = node;
            node->prev = temp;
            node->next->next->prev = node->next;
            if (temp != NULL)
                temp->next = node;
            head = node;
            while (head->prev != NULL)
                head = head->prev;
            print_list(head);
        } else
            node = node->prev;
    }
}

/**
 * swap_right - swap two nodes right in a doubly linked list
 * @node: pointer to the node
 * Return: void
 **/
void swap_right(listint_t *node) {
    listint_t *temp, *head;
    temp = node->prev;
    if (temp != NULL) {
        temp->next = node->next;
        node->next->prev = temp;
    } else
        node->next->prev = NULL;
    node->prev = node->next;
    if (node->next->next != NULL) {
        node->next = node->next->next;
        node->prev->next = node;
        node->next->prev = node;
    } else {
        node->next->next = node;
        node->next = NULL;
    }
    head = node;
    while (head->prev != NULL)
        head = head->prev;
    print_list(head);
    swap_left(node->prev);
}

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: pointer to the head of the list
 * Return: void
 */
void insertion_sort_list(listint_t **list) {
    listint_t *current_node;
    if ((list == NULL) || (*list == NULL) || ((*list)->next == NULL))
        return;
    current_node = *list;
    while (current_node->next != NULL) {
        if (current_node->n > current_node->next->n) {
            swap_right(current_node);
        } else
            current_node = current_node->next;
    }
    while ((*list)->prev != NULL)
        *list = (*list)->prev;
}
