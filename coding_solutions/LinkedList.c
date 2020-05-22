/*Q.
Write a C program to construct a singly linked list by removing duplicate elements in the sorted linked list
Description:
Take a sorted list and traverse the list. Compare the current node element with next adjacent node. If it is same then delete second element, if not retain. Finally print the resulting list.
Sample output:
Given list {1,2,2,3,3,3,4}
Resulting list{1,2,3,4}

ANS:
*/


#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int num;                    
    struct node *nextptr;       
}*stnode;

void createNodeList(int n);     
void reverseDispList();         
void displayList();             

int main()
{
    int n;
		printf("\n\n Linked List : Create a singly linked list and print it in reverse order :\n");
		printf("------------------------------------------------------------------------------\n");
		
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createNodeList(n);
    printf("\n Data entered in the list are : \n");		
    displayList();
    reverseDispList();
    printf("\n The list in reverse are :  \n");
    displayList();
    return 0;
}

void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL) 
    {
        printf(" Memory can not be allocated.");
    }
    else
    {

        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode-> num = num;      
        stnode-> nextptr = NULL; 
        tmp = stnode;

        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL) //check whether the fnnode is NULL and if so no memory allocation
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);
                fnNode->num = num;      
                fnNode->nextptr = NULL; 
                tmp->nextptr = fnNode; 
                tmp = tmp->nextptr;
            }
        }
    }
}

void reverseDispList()
{
    struct node *prevNode, *curNode;
 
    if(stnode != NULL)
    {
        prevNode = stnode;
        curNode = stnode->nextptr;
        stnode = stnode->nextptr;
 
        prevNode->nextptr = NULL; //convert the first node as last
 
        while(stnode != NULL)
        {
            stnode = stnode->nextptr;
            curNode->nextptr = prevNode;
 
            prevNode = curNode;
            curNode = stnode;
        }
        stnode = prevNode; 
    }
}

void displayList()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" No data found in the list.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);   
            tmp = tmp->nextptr;                 
        }
    }
}