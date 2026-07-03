#include "student.h"
#define DATA_FILE "student.dat"
void stud_save(void)
{
    FILE *fp = fopen(DATA_FILE, "wb");
    Student *temp = head;

    if (fp == NULL) {
        printf("Error opening file for saving!\n");
        return;
    }

    while (temp != NULL) {
        fwrite(temp, sizeof(Student), 1, fp);
        temp = temp->next;
    }

    fclose(fp);
    printf("Records saved successfully to %s!\n", DATA_FILE);
}

void stud_load(void)
{
    FILE *fp = fopen(DATA_FILE, "rb");
    Student buffer;
    Student *new_node, *tail = NULL;

    if (fp == NULL)
        return; /* no saved data yet, nothing to load */

    while (fread(&buffer, sizeof(Student), 1, fp) == 1) {
        new_node = (Student *)malloc(sizeof(Student));
        if (new_node == NULL) {
            printf("Memory allocation failed during load!\n");
            break;
        }
        *new_node = buffer;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    fclose(fp);
}


static void swap_data(Student *a, Student *b)
{
    int tmp_roll = a->roll;
    char tmp_name[50];
    float tmp_pct = a->percentage;

    strcpy(tmp_name, a->name);

    a->roll = b->roll;
    strcpy(a->name, b->name);
    a->percentage = b->percentage;

    b->roll = tmp_roll;
    strcpy(b->name, tmp_name);
    b->percentage = tmp_pct;
}

static void sort_by_name(void)
{
    Student *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcasecmp(i->name, j->name) > 0)
                swap_data(i, j);
        }
    }
}

static void sort_by_percentage(void)
{
    Student *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->percentage > j->percentage)
                swap_data(i, j);
        }
    }
}

void stud_sort(void)
{
    char choice;

    if (head == NULL) {
        printf("No records available to sort!\n");
        return;
    }

    printf("N/n : Sort by Name\n");
    printf("P/p : Sort by Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'N':
        case 'n':
            sort_by_name();
            printf("Records sorted by Name!\n");
            break;
        case 'P':
        case 'p':
            sort_by_percentage();
            printf("Records sorted by Percentage!\n");
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void free_list(void)
{
    Student *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

