#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};
struct Node *START=NULL;
void insertAsFirstNode()
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data : ");
    scanf("%d",&n->info);
    n->link=NULL;
    if(START==NULL)
        START=n;
    else{
        n->link=START;
        START=n;
    }
}
void insertAsLastNode()
{
    struct Node *n,*t;
    n=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data : ");
    scanf("%d",&n->info);
    n->link=NULL;
    if(START==NULL)
        START=n;
    else{
        t=START;
        while(t->link!=NULL)
            t=t->link;
        t->link=n;
    }
}
void insertAfterSomeNode(int X)
{
    int flag=0;
    struct Node *n,*t;
    n=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter new data : ");
    scanf("%d",&n->info);
    n->link=NULL;
    if(START==NULL)
        printf("List is empty");
    else{
        t=START;
        while(t->link!=NULL){
            if(t->info==X){
                n->link=t->link;
                t->link=n;
                flag=1;
            }
            t=t->link;
        }
        if(!flag)
            printf("Data do not match with any data");
    }
}
void insertBeforeNode(int X)
{
    int flag=1;
    struct Node *n,*t;
    n=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter new data : ");
    scanf("%d",&n->info);
    n->link=NULL;
    if(START==NULL)
        printf("List is empty");
    else if(START->info==X){
        n->link=START;
        START=n;
    }
    else{
        t=START;
        while(t->link!=NULL){
            if(t->link->info==X){
                n->link=t->link;
                t->link=n;
                flag=0;
                break;
            }
            t=t->link;
        }
        if(flag)
            printf("Data Not Found");
    }
}
void deleteFirstNode()
{
    struct Node *r;
    if(START==NULL)
        printf("List is empty");
    else{
        r=START;
        START=START->link;
        free(r);
    }
}
void deleteLastNode()
{
    struct Node *r,*t;
    if(START==NULL)
        printf("List is empty");
    else if(START->link==NULL)
        START=NULL;
    else{
        r=START;
        while(r->link->link!=NULL)
            r=r->link;
        t=r->link;
        r->link=NULL;
        free(t);
    }
}
void deleteGivenNode(int X)
{
    int flag=1;
    struct Node *r,*t;
    if(START==NULL)
        printf("List is empty");
    else if(START->info==X){
        r=START;
        START=START->link;
        free(r);
    }
    else{
        t=START;
        while(t->link!=NULL){
            if(t->link->info==X){
                r=t->link;
                t->link=t->link->link;
                free(r);
                flag=0;
                break;
            }
            t=t->link;
        }
        if(flag)
            printf("Data not found in the list");
    }
}
void deleteAfterGivenNode(int X)
{
    int flag=1;
    struct Node *r,*t;
    if(START==NULL)
        printf("List is empty");
    else{
        t=START;
        while(t->link!=NULL){
            if(t->info==X){
                r=t->link;
                t->link=r->link;
                flag=0;
                free(r);
                break;
            }
            t=t->link;
        }
        if(t->link == NULL){
            printf("No data after that data");
            flag=0;
        }
        if(flag)
            printf("Given Reference not found");
    }
}
void deleteBeforeGivenNode(int X)
{
    int flag=1;
    struct Node *t,*r;
    if(START==NULL)
        printf("list is empty");
    else if(START->link->info==X){
        r=START;
        START=START->link;
        free(r);
    }
    else if(START->info==X){}
    else{
        t=START;
        while(t->link!=NULL){
            if(t->link->link->info == X){
                r=t->link;
                t->link=r->link;
                flag=0;
                free(r);
                break;
            }
            t=t->link;
        }
        if(flag)
            printf("Given reference data is not found");
    }
}
void traverse()
{
    struct Node *t;
    if(START==NULL)
        printf("CANT traverse, list is empty");
    else{
        t=START;
        while(t!=NULL){
            printf("%d ",t->info);
            t=t->link;
        }
    }
}
int menu()
{
    int ch;
    printf("1. Insert As A First node\n");
    printf("2. Insert As A Last Node\n");
    printf("3. Insert After Particular Node\n");
    printf("4. Insert Before a Particular Node\n");
    printf("5. Delete First node\n");
    printf("6. Delete Last Node\n");
    printf("7. Delete Given Node\n");
    printf("8. Delete After Given Node\n");
    printf("9. Delete before given node\n");
    printf("11. Traverse\n");
    printf("12. Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    return(ch);
}
main()
{
    int N;
    while(1){
        system("cls");
        switch(menu())
        {
        case 1:
            insertAsFirstNode();
            break;
        case 2:
            insertAsLastNode();
            break;
        case 3:
            printf("Enter data after which new data will enter : ");
            scanf("%d",&N);
            insertAfterSomeNode(N);
            break;
        case 4:
            printf("Enter data before which you want to add new data : ");
            scanf("%d",&N);
            insertBeforeNode(N);
            break;
        case 5:
            deleteFirstNode();
            break;
        case 6:
            deleteLastNode();
            break;
        case 7:
            printf("Enter data for delete : ");
            scanf("%d",&N);
            deleteGivenNode(N);
            break;
        case 8:
            printf("Enter data after which data are deleted : ");
            scanf("%d",&N);
            deleteAfterGivenNode(N);
            break;
        case 9:
            printf("Enter your given data : ");
            scanf("%d",&N);
            deleteBeforeGivenNode(N);
            break;
        case 11:
            traverse();
            break;
        case 12:
            printf("Thank You for Using this application,\nHave a Nice DAY");
            exit(1);
        default:
              printf("Invalid choice");
        }
        _getch();
    }
}
