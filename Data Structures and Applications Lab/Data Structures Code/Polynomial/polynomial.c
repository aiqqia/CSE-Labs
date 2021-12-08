#include <stdio.h>
#include <stdlib.h>

typedef struct term
{
    int coeff;
    int exp;
    struct term *next;
} * Term;

void add(Term l1, Term l2)
{
    if (l1 == NULL && l2 == NULL)
    {
        printf("No polynomials created, create two to add them");
        return;
    }
    Term sum = NULL;
    while (l1 != NULL || l2 != NULL)
    {
        int l1exp = 0, l2exp = 0, l1c = 0, l2c = 0;
        if (l1 != NULL)
        {
            l1exp = l1->exp;
            l1c = l1->coeff;
        }
        if (l2 != NULL)
        {
            l2exp = l2->exp;
            l2c = l2->coeff;
        }
        if (l1c + l2c == 0 && l1exp == l2exp)
        {
            l1 = l1->next;
            l2 = l2->next;
            continue;
        }
        Term n = NULL;
        n = (Term)malloc(sizeof(struct term));
        if (n == NULL){
            printf("\nSpace not alloted, trying again");
            continue;
        }
        n->next = NULL;
        n->coeff = 0;
        n->exp = 0;
        ////////
        //error arises at this step and only when the last two terms of the polynomials are left i.e. 1x^0 and 42x^0
        ////////
        if (l1exp == l2exp)
        {
            n->exp = l1exp;
            n->coeff = l1c + l2c;
            if (sum == NULL)
            {
                sum = n;
            }
            else
            {
                Term cur = sum;
                while (cur->next)
                {
                    cur = cur->next;
                }
                cur->next = n;
            }
            l1 = l1->next;
            l2 = l2->next;
            continue;
        }
        else if (l1exp > l2exp)
        {
            n->exp = l1exp;
            n->coeff = l1c;
            if (sum == NULL)
            {
                sum = n;
            }
            else
            {
                Term cur = sum;
                while (cur->next)
                {
                    cur = cur->next;
                }
                cur->next = n;
            }
            l1 = l1->next;
            continue;
        }
        else if (l1exp < l2exp)
        {
            n->exp = l2exp;
            n->coeff = l2c;
            if (sum == NULL)
            {
                sum = n;
            }
            else
            {
                Term cur = sum;
                while (cur->next)
                {
                    cur = cur->next;
                }
                cur->next = n;
            }
            l2 = l2->next;
        }
    }
    printf("\nThe sum polynomial is : \n");
    if(sum == NULL){
        printf("\n0");
        return;
    }
    while (sum->next)
    {
        printf("(%d)x^(%d) + ", sum->coeff, sum->exp);
        sum = sum->next;
    }
    printf("(%d)x^(%d)", sum->coeff, sum->exp);
}

int main()
{
    Term l1 = NULL, l2 = NULL;
    int choice = 0, coeff, exp;
    while (choice < 3)
    {
        printf("\n1 : Create polynomials \n2 : Add polynomials \n3 : exit\n\nEnter the choice of operation : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nPlease enter the terms in the decreasing order of exponents only!! Press 0 for coeff to terminate term input\nEnter the first polynomial : ");
            while (1)
            {
                printf("\nEnter the coefficient : ");
                scanf("%d", &coeff);
                if (coeff == 0)
                {
                    printf("\nPolynomial Created!");
                    break;
                }
                printf("\nEnter the exponent : ");
                scanf("%d", &exp);
                Term n = (Term)malloc(sizeof(struct term));
                n->coeff = coeff;
                n->exp = exp;
                n->next = NULL;

                if (l1 == NULL)
                {
                    l1 = n;
                    printf("\nEnter the next term : ");
                    continue;
                }
                Term cur = l1;
                while (cur->next)
                {
                    cur = cur->next;
                }
                cur->next = n;
                printf("\nEnter the next term : ");
            }
            printf("\nEnter the next polynomial");
            while (1)
            {
                printf("\nEnter the coefficient : ");
                scanf("%d", &coeff);
                if (coeff == 0)
                {
                    printf("\nPolynomial Created!");
                    break;
                }
                printf("\nEnter the exponent : ");
                scanf("%d", &exp);
                Term n = (Term)malloc(sizeof(struct term));
                n->coeff = coeff;
                n->exp = exp;
                n->next = NULL;

                if (l2 == NULL)
                {
                    l2 = n;
                    printf("\nEnter the next term : ");
                    continue;
                }
                Term cur = l2;
                while (cur->next)
                {
                    cur = cur->next;
                }
                cur->next = n;
                printf("\nEnter the next term : ");
            }
            printf("\nThe polynomials are : \n");
            Term one = l1, two = l2;
            while (one->next)
            {
                printf("(%d)x^(%d) + ", one->coeff, one->exp);
                one = one->next;
            }
            printf("(%d)x^(%d)", one->coeff, one->exp);
            printf("\n");
            while (two->next)
            {
                printf("(%d)x^(%d) + ", two->coeff, two->exp);
                two = two->next;
            }
            printf("(%d)x^(%d)", two->coeff, two->exp);
            printf("\n");
            break;

        case 2:
            add(l1, l2);
            l1 = NULL, l2 = NULL;
            break;

        default:
            break;
        }
    }
}