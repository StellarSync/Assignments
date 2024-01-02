

void pop(struct Stack *SS, char *element)
{
    strcpy(element, SS->Data[SS->TOS]);
    SS->TOS -= 1;
}

void display(struct Stack *SS)
{
    if (isEmpty(SS))
        printf("STACK EMPTY\n");
    else
    {
        printf("STACK CONTENTS:\n");
        for (int i = 0; i <= SS->TOS; i++)
        {
            printf("%s\n", SS->Data[i]);
        }
    }
}

void emptyStack(struct Stack *SS)
{
    SS->TOS = -1;
}
