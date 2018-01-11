#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;

#define MAX 9

typedef struct node
{
    int col;
    int row;
    int value[MAX+1];
}Node;

void print_sudoku(int Sudoku[MAX][MAX]);
int count_num_empty(int Sudoku[MAX][MAX]);
void backtrack(int Sudoku[MAX][MAX], int num_empty, Node *node_stack);
int findvalue(int Sudoku[MAX][MAX], Node *node_stack);



int findvalue(int Sudoku[MAX][MAX], Node *node_stack)
{
    int i = node_stack->col;
    int j = node_stack->row;
    int k = 0;
    int n = 0;

    for(k = 0; k < MAX+1; ++k)
        node_stack->value[k] = 0;

    for(k = 1; k < MAX+1; ++k)
    {
        node_stack->value[Sudoku[i][k-1]] = 1;
        node_stack->value[Sudoku[k-1][j]] = 1;
    }

    for(k = 0; k < 3; ++k)
    {
        for(n = 0; n < 3; ++n)
        {
            node_stack->value[Sudoku[i/3*3+k][j/3*3+n]] = 1;
        }
    }

    node_stack->value[0] = 0;

    for(k = 1; k < MAX+1; ++k)
        if(node_stack->value[k] == 0)
            node_stack->value[0]++;

    for(k = 1; k < MAX+1; ++k)
    {
        if(node_stack->value[k] == 0)
        {
            node_stack->value[k] = 1;
            node_stack->value[0]--;
            break;
        }
    }

    if(k == MAX+1)
        return -1;
    else
        return k;
}

void backtrack(int Sudoku[MAX][MAX], int num_empty, Node *node_stack)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int flag = 0;
    while(num_empty)
    {
        for(i = 0; i < MAX; ++i)
        {
            for(j = 0; j < MAX; ++j)
            {
                if(Sudoku[i][j] == 0)
                {
                    (node_stack + k)->col = i;
                    (node_stack + k)->row = j;
                    Sudoku[i][j] = findvalue(Sudoku, node_stack + k);
                    if(Sudoku[i][j] == -1)
                    {
                        Sudoku[i][j] = 0;
                        k--;
                        while((node_stack + k) -> value[0] == 0)
                        {
                            if(k == 0)
                            {
                                cout << "数独无解" << endl;
                                exit(1);
                            }
                            Sudoku[(node_stack + k) -> col][(node_stack + k) -> row] = 0;
                            num_empty++;
                            k--;
                        }
                        for(flag = 1; flag < MAX+1; ++flag)
                        {
                            if((node_stack + k)->value[flag] == 0)
                            {
                                Sudoku[(node_stack + k) -> col][(node_stack + k) -> row] = flag;
                                (node_stack + k)->value[flag] = 1;
                                (node_stack + k)->value[0]--;
                                break;
                            }
                        }
                        num_empty++;
                        i = (node_stack + k)->col;
                        j = (node_stack + k)->row;
                    }
                    k++;
                    num_empty--;
                }
            }
        }
    }

    free(node_stack);
    node_stack = NULL;
    print_sudoku(Sudoku);
}


int count_num_empty(int Sudoku[MAX][MAX])
{
    int num = 0;
    for(int i = 0; i < MAX; ++i)
    {
        for(int j = 0; j < MAX; ++j)
        {
            if(Sudoku[i][j] == 0)
                num++;
        }
    }
    return num;
}

void print_sudoku(int Sudoku[MAX][MAX])
{
    for(int i = 0; i < MAX; ++i)
    {
        for(int j = 0; j < MAX; ++j)
        {
            cout << " " <<Sudoku[i][j];
        }
        cout << endl;
    }
}


int main(int argc, char const* argv[])
{

#if 0
    int Sudoku[MAX][MAX];

    for(int i = 0; i < MAX; ++i)
    {
        for(int j = 0; j < MAX; ++j)
        {
            cin >> Sudoku[i][j];
        }
    }
#endif

#if 0
    int Sudoku[MAX][MAX] = {
        (8,0,0,0,0,0,0,0,0),
        (0,0,3,6,0,0,0,0,0),
        (0,7,0,0,9,0,2,0,0),
        (0,5,0,0,0,7,0,0,0),
        (0,0,0,0,4,5,7,0,0),
        (0,0,0,1,0,0,0,3,0),
        (0,0,1,0,0,0,0,6,8),
        (0,0,8,5,0,0,0,1,0),
        (0,9,0,0,0,0,4,0,0)
    };
#else
int Sudoku[9][9]={
	{5,3,0,6,0,0,0,9,8},
	{0,7,0,1,9,5,0,0,0},
	{0,0,0,0,0,0,0,6,0},
	{8,0,0,4,0,0,7,0,0},
	{0,6,0,8,0,3,0,2,0},
	{0,0,3,0,0,1,0,0,6},
	{0,6,0,0,0,0,0,0,0},
	{0,0,0,4,1,9,0,8,0},
	{2,8,0,0,0,5,0,7,9},
};  
    

#endif
    int num_empty = count_num_empty(Sudoku);
    Node * node_stack = (Node *)malloc(sizeof(struct node) * num_empty);

    backtrack(Sudoku, num_empty, node_stack);

    return 0;
}
