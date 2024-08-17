#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
}node;


node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}


void push_back(node** array, int value)
{
    node* temp;
    temp = createNode(value); // khoi tao node
                              // temp = 0xa1

    
    if (*array == NULL)   // if array doesn't have any node yet
    {

        *array = temp;
    }
    else                // if array has some node
    {
        node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node

        }

        p->next = temp;     // change it next member point to address of new node have just create
    }
}



void pop_back(node** array)
{
    node* p, * temp;
    p = *array;
    int i = 0; // to 

    while (p->next->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);

}



int get(node* array, int pos)
{
    int i = 0;
 
    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}





int main()
{
    node* arr = NULL;
    push_back(&arr, 2);
    push_back(&arr, 7);
    push_back(&arr, 4);
    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 10);

    printf("Value test: %d\n", get(arr, 2));
    printf("Value test: %d\n", get(arr, 0));
    printf("Value test: %d\n", get(arr, 5));


	return 0;
}

