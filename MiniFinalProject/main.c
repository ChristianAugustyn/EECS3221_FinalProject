#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
#define CYLINDER_MAX 99

void fcfs(int *cylinders, int head, int len);
void scan(int *cylinders, int head, int len);
void c_scan(int *cylinders, int head, int len);
void selectionSort(int *arr, int n);
void swap_values(int *i, int *j);
void print_arr(int *arr, int len);

int main(int argc, int *argv[]) {

    FILE *in;
    int cylinder_num;
    char cylinder[SIZE];
    int *cylinders = (int*)malloc(sizeof(int));
    int c = 0;
    int head = 33;

    in = fopen("input.txt", "r");
    while(fgets(cylinder, SIZE, in) != NULL)
    {
        cylinder_num = atoi(cylinder);
        cylinders = realloc(cylinders, (c + 1) * sizeof(int));
        *(cylinders + c) = cylinder_num;
        c++;
    }
    fclose(in);

    fcfs(cylinders, head, c);
    selectionSort(cylinders, c);
    scan(cylinders, head, c);
    c_scan(cylinders, head, c);
    return 0;
}

void fcfs(int *cylinders, int head, int len) 
{
    FILE *out;
    out = fopen("out.txt", "a");
    int total_moves = 0;

    fprintf(out, "\nFCFS Algorithm\nInitial head position = %d\nSeek Sequence is:", head);

    for (int i = 0; i < len; i++)
    {
        fprintf(out, "\n%d", *(cylinders + i));
        total_moves += abs(head - *(cylinders + i));
        head = *(cylinders + i);
    }
    fprintf(out, "\nTotal head movement for FCFS = %d\n", total_moves);
    fclose(out);
}

void scan(int *cylinders, int head, int len)
{
    FILE *out;
    out = fopen("out.txt", "a");
    int total_moves = 0;
    int lc = 0;
    int rc = 0;
    int *left = (int*)malloc(sizeof(int));
    int *right = (int*)malloc(sizeof(int));

    for(int i = 0; i < len; i++){
        if (*(cylinders + i) <= head) //left of head
        {
            left = realloc(left, (lc + 1) * sizeof(int));
            *(left + lc) = *(cylinders + i);
            lc++;
        } else if (*(cylinders + i) > head) //to the right of head
        {
            right = realloc(right, (rc + 1) * sizeof(int));
            *(right + rc) = *(cylinders + i);
            rc++;
        }
    }
    fprintf(out, "\nSCAN Algorithm\nInitial head position = %d\nSeek Sequence is:", head);
    for (int i = lc - 1; i >= 0 ; i--) //go accross the left array
    {
        fprintf(out, "\n%d", *(left + i));
        total_moves += abs(head - *(left + i));
        head = *(left + i);
    }
    total_moves += head; //move the head all the way to zero
    head = 0;
    for (int i = 0; i < rc; i++)
    {
        fprintf(out, "\n%d", *(right + i));
        total_moves += abs(head - *(right + i));
        head = *(right + i);
    }
    fprintf(out, "\nTotal head movement for SCAN = %d\n", total_moves);
    fclose(out);
}

void c_scan(int *cylinders, int head, int len)
{
    FILE *out;
    out = fopen("out.txt", "a");
    int total_moves = 0;
    int lc = 0;
    int rc = 0;
    int *left = (int*)malloc(sizeof(int));
    int *right = (int*)malloc(sizeof(int));

    for(int i = 0; i < len; i++){
        if (*(cylinders + i) < head) //left of head
        {
            left = realloc(left, (lc + 1) * sizeof(int));
            *(left + lc) = *(cylinders + i);
            lc++;
        } else if (*(cylinders + i) > head) //to the right of head
        {
            right = realloc(right, (rc + 1) * sizeof(int));
            *(right + rc) = *(cylinders + i);
            rc++;
        }
    }
    fprintf(out, "\nC_SCAN Algorithm\nInitial head position = %d\nSeek Sequence is:", head);
    for (int i = 0; i < rc; i++)
    {
        fprintf(out, "\n%d", *(right + i));
        total_moves += abs(head - *(right + i));
        head = *(right + i);
    }
    total_moves += abs(head - CYLINDER_MAX );
    head = CYLINDER_MAX ;
    total_moves += head;
    head = 0;
    for (int i = 0; i < lc; i++) //go accross the left array
    {
        fprintf(out, "\n%d", *(left + i));
        total_moves += abs(head - *(left + i));
        head = *(left + i);
    }
    fprintf(out, "\nTotal head movement for C_SCAN = %d", total_moves);
    fclose(out);
}

void selectionSort(int *arr, int n)
{
    int id;

    for (int i = 0; i < n - 1; i++)
    {
        id = i;
        for (int j = i + 1; j < n; j++)
        {
            if (*(arr + j) < *(arr + id))
            {
                id = j;
            }
        }
        swap_values((arr + id), (arr + i));
    }
}

void swap_values(int *i, int *j)
{
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

void print_arr(int *arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("\n%d : %d", i, *(arr + i));
    }
}

