/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if (!q)
    {
        return NULL;
    }
    q->head = NULL;
    q->tail = NULL;
    q->count = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if (!q) return;
    list_ele_t *current = q->head;
    while (current != NULL)
    {
        list_ele_t *next = current->next;
        free(current->value); // Free the string
        free(current);
        current = next;
    }
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    if (!q)
    {
        return false;
    }

    list_ele_t *newh;
    /* What should you do if the q is NULL? */

    newh = malloc(sizeof(list_ele_t));
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
    if (!newh)
    {
        return false;
    }
    /* Allocate spaces for the string */
    newh->value = malloc(sizeof(char) * (strlen(s) + 1));
    if (!newh->value)
    {
        free(newh);
        return false;
    }
    strncpy(newh->value, s, strlen(s));
    newh->value[strlen(s)] = '\0'; /* safe strncpy */

    newh->next = q->head;
    q->head = newh;
    // Update tail if the queue was empty
    if (!q->tail)
    {
        q->tail = newh;
    }
    q->count++;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    if (!q)
    {
        return false;
    }

    list_ele_t *newt;

    newt = malloc(sizeof(list_ele_t));
    if (!newt)
    {
        return false;
    }
    /* Allocate spaces for the string */
    newt->value = malloc(sizeof(char) * (strlen(s) + 1));
    if (!newt->value)
    {
        free(newt);
        return false;
    }
    strncpy(newt->value, s, strlen(s));
    newt->value[strlen(s)] = '\0'; /* safe strncpy */
    newt->next = NULL;
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    if (!q->head)
    {
        q->head = q->tail = newt; // Initialize head and tail for empty queue
    }
    else
    {
        q->tail->next = newt;
        q->tail = newt;
    }
    q->count++;
    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* You need to fix up this code. */
    if (q == NULL || q->head == NULL)
    {
        return false;
    }
    if (sp)
    {
        strncpy(sp, q->head->value, bufsize - 1);
        sp[bufsize - 1] = '\0';
    }
    list_ele_t *temp = q->head;
    q->head = q->head->next;
    free(temp->value);
    free(temp);
    q->count--;
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if (!q) return 0;
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    return q->count;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    if (!q || !q->head || !q->head->next) return;

    list_ele_t *next = NULL;
    list_ele_t *curr = q->head;
    list_ele_t *prev = NULL;
    q->tail = q->head;
    /* You need to write the code for this function */
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    q->head = prev;
}
