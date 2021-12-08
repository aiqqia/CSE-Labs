#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int val;
    int row;
    int col;
    struct cell *next;
} * Cell;

int isEmpty(Cell start)
{
    if (start == NULL)
    {
        return 1;
    }
    return 0;
}

void insertE(Cell *start, int i, int j, int key)
{
    Cell n = (Cell)malloc(sizeof(struct cell));
    n->row = i;
    n->col = j;
    n->val = key;
    n->next = NULL;
    if (isEmpty(*start))
    {
        *start = n;
        return;
    }
    Cell cur = *start;
    while (cur->next)
    {
        cur = cur->next;
    }
    cur->next = n;
}

void display(Cell start, int row, int col)
{
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (start)
            {
                if (start->row == i && start->col == j)
                {
                    printf("%d\t", start->val);
                    start = start->next;
                }
                else{
                    printf("0\t");
                }
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

int main()
{
    Cell start = NULL;
    int row, col;
    printf("Enter the matrix dimensions : \n");
    printf("Enter number of rows : ");
    scanf("%d", &row);
    printf("Enter number of columns : ");
    scanf("%d", &col);
    int matrix;
    int choice = 0;
    printf("Choose type of input : \n1 : Full Matrix input(enter all values including zeros)\n2 : Only enter non-zeros values with row and column\nEnter choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter the values of the matrix : \n");
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf("ROW - %d, COL - %d : ", i + 1, j + 1);
                scanf("%d", &matrix);
                if(matrix!=0){
                    insertE(&start, i + 1, j + 1, matrix);
                }
            }
        }
        display(start, row, col);
        break;

    case 2:
        printf("ONLY ENTER IN ASCENDING ORDER OF ROW AND COLUMN INDEX.\nTo finish input, enter 0 for val\n");
        int val = 1;
        int userRow;
        int userCol;
        while (val != 0)
        {
            printf("Enter the value of cell : ");
            scanf("%d", &val);
            if (val == 0)
            {
                break;
            }
            printf("Enter the row of cell : ");
            scanf("%d", &userRow);
            printf("Enter the column of cell : ");
            scanf("%d", &userCol);
            insertE(&start, userRow, userCol, val);
        }
        display(start, row, col);
        break;
    }
    return 0;
}