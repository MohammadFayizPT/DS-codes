#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
struct student
{
    char name[20];
    float height;
    float weight;
};

int partition(struct student* st, int p, int r)
{
    struct student temp;
    float x = st[r].height;
    int i = p-1;

    for(int j = p; j < r; j++)
        if(st[j].height <= x)
        {
            i++;
            if(i != j)
            {
                temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }

    if(r != i+1)
    {
        temp = st[i+1];
        st[i+1] = st[r];
        st[r] = temp;
    }
    return i+1;
}

void quicksort(struct student* st, int p, int r)
{
    if(p < r)
    {
        int q = partition(st, p ,r);
        quicksort(st, p, q-1);
        quicksort(st, q+1, r);
    }
}

void merge(struct student* st1, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    struct student L[n1], R[n2];
    for(int i = 0; i < n1; i++)
        L[i] = st1[p+i];

    for(int j = 0; j < n2; j++)
        R[j] = st1[q+j+1];

    int i = 0, j = 0;
    int k;

    for(k = p; k <= r; k++)
    {
        if(L[i].height <= R[j].height)
        {
            st1[k] = L[i];
            i++;
            if(i == n1)
            {
                k++;
                break;
            }
        }
        else
        {
            st1[k] = R[j];
            j++;
            if(j == n2)
            {
                k++;
                break;
            }
        }
    }

    while(i < n1)
    {
        st1[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        st1[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(struct student* st1, int p, int r)
{
    if(p < r)
    {
        int q = floor((p+r)/2);
        mergesort(st1, p, q);
        mergesort(st1, q+1, r);
        merge(st1, p, q, r);
    }
}

void main()
{
    int n;
    char c;
    printf("Enter the number of students\n");
    scanf("%d", &n);

    FILE *fp = fopen("Student details.txt", "w");
    FILE *fpq = fopen("Quick student details.txt", "w");
    FILE *fpm = fopen("Merge student details.txt", "w");

    fprintf(fp, "NAME\t\tHEIGHT\tWEIGHT\n");
    fprintf(fpq, "NAME\t\tHEIGHT\tWEIGHT\n");
    fprintf(fpm, "NAME\t\tHEIGHT\tWEIGHT\n");

    struct student* st = malloc(n * sizeof(struct student));

    for(int i=0; i<n; i++)
    {
        printf("\nEnter the student details\n");
        printf("Name = ");
        scanf("%c", &c);
        fgets(st[i].name, 20, stdin);
        st[i].name[strlen(st[i].name) - 1] = '\0';
        printf("Height = ");
        scanf("%f", &st[i].height);
        printf("Weight = ");
        scanf("%f", &st[i].weight);
    }

    printf("\nWriting to file...\n");

    for(int i = 0; i < n; i++)
        fprintf(fp, "%s\t\t%.2f\t%.2f\n", st[i].name, st[i].height, st[i].weight);

    fclose(fp);

    //quick sort
    printf("\nPerforming quick sort...\n");
    clock_t t = clock();
    quicksort(st, 0, n-1);
    t = clock() - t;
    for(int i = 0; i < n; i++)
        fprintf(fpq, "%s\t\t%.2f\t%.2f\n", st[i].name, st[i].height, st[i].weight);
    fprintf(fpq, "\nTime taken = %lf", (double) t / CLOCKS_PER_SEC);
    for(int i = 0; i < n; i++)
        fscanf(fp, "%s\t\t%f\t%f\n", st[i].name, &st[i].height, &st[i].weight);
    
    //merge sort
    printf("\nPerforming merge sort...\n");
    t = clock();
    mergesort(st, 0, n-1);
    t = clock() - t;
    for(int i = 0; i < n; i++)
        fprintf(fpm, "%s\t\t%.2f\t%.2f\n", st[i].name, st[i].height, st[i].weight);
    fprintf(fpm, "\nTime taken = %lf", (double) t / CLOCKS_PER_SEC);
    printf("\nWrite successful.\n\n");

    
    fclose(fpq);
    fclose(fpm);
}