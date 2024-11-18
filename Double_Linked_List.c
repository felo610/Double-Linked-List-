#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the double linked list
struct Node
{
    int Node_Data;
    struct Node *Right_Link;
    struct Node *Left_Link;
};

/*Functions Prototype*/
struct Node *Create_DLL(void);
void Insert_Node_At_Beginning(struct Node **List_Head);
void Insert_Node_At_End(struct Node **List_Head);
void Insert_Node_After(struct Node **List_Head);
void Insert_Node_Before(struct Node **List_Head);
void Delete_Node_At_Beginning(struct Node **List_Head);
void Delete_Node_At_End(struct Node **List_Head);
void Delete_Node_At(struct Node **List_Head);
void Diplay_Nodes_Forward(struct Node **List_Head);
void Diplay_Nodes_Reverse(struct Node **List_Head);
int Options(void);
int DLL_Length(struct Node **List_Head);

/*Global Variables*/
int My_Option = 1;
struct Node *Node_1 = NULL;

/*Main Function*/
int main()
{
    while (1)
    {
        switch (Options())
        {

        case (1):
            Insert_Node_At_Beginning(&Node_1);
            break;

        case (2):
            Insert_Node_At_End(&Node_1);
            break;

        case (3):
            Insert_Node_After(&Node_1);
            break;

        case (4):
            Insert_Node_Before(&Node_1);
            break;

        case (5):
            Delete_Node_At_Beginning(&Node_1);

            break;

        case (6):
            Delete_Node_At_End(&Node_1);
            break;

        case (7):
            Delete_Node_At(&Node_1);
            break;

        case (8):
            Diplay_Nodes_Forward(&Node_1);
            break;

        case (9):
            Diplay_Nodes_Reverse(&Node_1);
            break;

        case (10):
            printf("Double_Linked_List_Length =>%i\n", DLL_Length(&Node_1));
            break;

        default:
            My_Option = -1;
            printf("\"End of programe .......Thank you\"\n");
            break;
        }

        if (-1 == My_Option)
        {
            break;
        }
    }

    return (0);
}

/**
 * @brief Create a new node with user input
 * @return Pointer to the newly created node
 */
struct Node *Create_DLL(void)
{
    struct Node *My_Node = NULL;
    int Data = 0;
    printf("Enter Node Data (Integer) :");
    scanf("%i", &Data);
    My_Node = (struct Node *)malloc(sizeof(struct Node));
    if (My_Node)
    {
        My_Node->Node_Data = Data;
        My_Node->Left_Link = NULL;
        My_Node->Right_Link = NULL;
    }
    else
    {
        printf("Cant allocate DLL\n");
    }
    return (My_Node);
}

/**
 * @brief Insert a new node at the beginning of the double linked list
 * @param List_Head Pointer to the head of the linked list
 */
void Insert_Node_At_Beginning(struct Node **List_Head)
{
    struct Node *New_Node = Create_DLL();
    if (*List_Head)
    {
        New_Node->Right_Link = *List_Head;
        (*List_Head)->Left_Link = New_Node;
        *List_Head = New_Node;
        printf("Insert_Node_At_Beginning is VALID\n");
    }
    /*List is empty*/
    else
    {
        *List_Head = New_Node;
        printf("List is empty\n");
    }
}

/**
 * @brief Insert a new node at the end of the double linked list
 * @param List_Head Pointer to the head of the doublelinked list
 */
void Insert_Node_At_End(struct Node **List_Head)
{
    struct Node *New_Node = Create_DLL();
    struct Node *End_Node = *List_Head;

    if (*List_Head)
    {
        while (End_Node->Right_Link != NULL)
        {
            End_Node = End_Node->Right_Link;
        }
        New_Node->Left_Link = End_Node;
        End_Node->Right_Link = New_Node;
        printf("Insert_Node_At_End is VALID\n");
    }
    /*List is empty*/
    else
    {
        *List_Head = New_Node;
        printf("List is empty\n");
    }
}

/**
 * @brief Insert a new node after a specified position in the double linked list
 * @param List_Head Pointer to the head of the linked list
 */
void Insert_Node_After(struct Node **List_Head)
{
    int Pos = 0, Len = 0;
    printf("Enter Node Pos :");
    scanf("%i", &Pos);
    Len = DLL_Length(List_Head);
    if (Pos > Len || Pos < 0)
    {
        printf("Invalid Positon node\n");
    }
    else
    {
        struct Node *New_Node = Create_DLL();
        struct Node *Pos_Node = *List_Head;
        if (*List_Head)
        {
            for (int Counter = 0; Counter < Pos; Counter++)
            {
                Pos_Node = Pos_Node->Right_Link;
            }
            New_Node->Right_Link = Pos_Node->Right_Link;
            New_Node->Left_Link = Pos_Node;
            if (Pos_Node->Right_Link != NULL)
            {
                Pos_Node->Right_Link->Left_Link = New_Node;
            }
            Pos_Node->Right_Link = New_Node;
        }
        /*DLL => Empty*/
        else
        {
            *List_Head = New_Node;
        }
    }
}

/**
 * @brief Insert a new node before a specified position in the double linked list
 * @param List_Head Pointer to the head of the linked list
 */
void Insert_Node_Before(struct Node **List_Head)
{
    int Pos = 0, Len = 0;
    printf("Enter Node Pos :");
    scanf("%i", &Pos);
    Len = DLL_Length(List_Head);
    if (Pos > Len || Pos < 0)
    {
        printf("Invalid Positon node\n");
    }

    struct Node *New_Node = Create_DLL();
    struct Node *Pos_Node = *List_Head;

    for (int Counter = 0; Counter < Pos; Counter++)
    {
        Pos_Node = Pos_Node->Right_Link;
    }

    New_Node->Right_Link = Pos_Node;
    New_Node->Left_Link = Pos_Node->Left_Link;
    if (Pos_Node->Left_Link != NULL)
    {
        Pos_Node->Left_Link->Right_Link = New_Node;
    }
    else
    {
        *List_Head = New_Node;
    }
    Pos_Node->Left_Link = New_Node;

    /*DLL => Empty*/
}

/**
 * @brief Calculate the length of the double linked list
 * @param List_Head Pointer to the head of the double linked list
 * @return Length of the double linked list
 */
int DLL_Length(struct Node **List_Head)
{
    int Counter = 0;
    struct Node *End_Node = *List_Head;
    while (End_Node != NULL)
    {
        End_Node = End_Node->Right_Link;
        Counter++;
    }

    return (Counter);
}

/**
 * @brief Delete the first node of the double linked list
 * @param List_Head Pointer to the head of the double linked list
 */
void Delete_Node_At_Beginning(struct Node **List_Head)
{
    struct Node *Deleted_Node = *List_Head;
    if (*List_Head)
    {
        /*If list has only one node*/
        if (Deleted_Node->Right_Link != NULL)
        {
            Deleted_Node->Right_Link->Left_Link = NULL;
            *List_Head = Deleted_Node->Right_Link;
        }
        else
        {
            *List_Head = NULL;
        }
        free(Deleted_Node);
    }
    else
    {
        printf("DLL is empty ...Cant delete\n");
    }
}

/**
 * @brief Delete the last node of the double linked list
 * @param List_Head Pointer to the head of the linked double list
 */
void Delete_Node_At_End(struct Node **List_Head)
{
    struct Node *Deleted_Node = *List_Head;

    if (*List_Head)
    {

        /*If list has only one node*/
        if (Deleted_Node->Right_Link != NULL)
        {
            while (Deleted_Node->Right_Link != NULL)
            {
                Deleted_Node = Deleted_Node->Right_Link;
            }

            Deleted_Node->Left_Link->Right_Link = NULL;
        }
        else
        {
            *List_Head = NULL;
        }

        free(Deleted_Node);
    }
    else
    {
        printf("DLL is empty ...Cant delete\n");
    }
}

/**
 * @brief Delete a node at a specified position in the double linked list
 * @param List_Head Pointer to the head of the double linked list
 */
void Delete_Node_At(struct Node **List_Head)
{
    int Pos = 0, Len = 0;
    printf("Enter node position :");
    scanf("%i", &Pos);
    Len = DLL_Length(List_Head);
    if (Pos < 0 || Pos >= Len)
    {
        printf("Invlaid Position\n");
    }
    else
    {
        struct Node *Deleted_Node = *List_Head;
        if (*List_Head)
        {

            /*If list has only one node*/
            if (Deleted_Node->Right_Link != NULL)
            {
                for (int Counter = 0; Counter < Pos; Counter++)
                {
                    Deleted_Node = Deleted_Node->Right_Link;
                }
                Deleted_Node->Right_Link->Left_Link = Deleted_Node->Left_Link;
                Deleted_Node->Left_Link->Right_Link = Deleted_Node->Right_Link;
            }
            else
            {
                *List_Head = NULL;
            }

            free(Deleted_Node);
        }
        else
        {
            printf("DLL is empty ...Cant delete\n");
        }
    }
}

/**
 * @brief Print all nodes in the double linked list by forward direction
 * @param List_Head Pointer to the head of the linked list
 */
void Diplay_Nodes_Forward(struct Node **List_Head)
{
    struct Node *End_Node = *List_Head;
    if (*List_Head)
    {
        while (End_Node!= NULL)
        {
            printf("=>%i", End_Node->Node_Data);
            End_Node = End_Node->Right_Link;
        }
    }
    else
    {
        printf("Empty\n");
    }
}

/**
 * @brief Print all nodes in the linked list in reverse direction
 * @param List_Head Pointer to the head of the linked list
 */
void Diplay_Nodes_Reverse(struct Node **List_Head)
{
    struct Node *End_Node = *List_Head;
    if (*List_Head)
    {
        while (End_Node->Right_Link != NULL)
        {
            End_Node = End_Node->Right_Link;
        }

        while (End_Node != NULL)
        {
            printf("=>%i", End_Node->Node_Data);
            End_Node = End_Node->Left_Link;
        }
    }
    else
    {
        printf("Empty\n");
    }
}

/**
 * @brief Display options for user input
 * @return Selected option as an integer
 */
int Options(void)
{
    int option = -1;
    printf("\n\n\"Options you can choose\"                \n");
    printf("1 =>\"Insert_Node_At_Beginning\"              \n");
    printf("2 =>\"Insert_Node_At_End\"                    \n");
    printf("3 =>\"Insert_Node_After\"            \n");
    printf("4 =>\"Insert_Node_Before\"            \n");
    printf("5 =>\"Delete_Node_At_Beginning\"              \n");
    printf("6 =>\"Delete_Node_At_End\"                    \n");
    printf("7 =>\"Delete_Node_At\"            \n");
    printf("8 =>\"Diplay_DLL_Forward\"        \n");
    printf("9 =>\"Diplay_DLL_Reverse\"                   \n");
    printf("10 =>\"Display Double Linked List Length\"                   \n");

    printf("-1 =>\"for End programme\"                    \n");
    printf("\nYour option is :");

    if ((scanf("%i", &option)) != 1)
    {
        printf("Invalid Option\n");
        while (getchar() != '\n')
            ; // Clear the input buffer
        option = -1;
    }

    return (option);
}