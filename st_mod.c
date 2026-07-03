#include "student.h"

static Student *find_by_roll(int roll)
{
    Student *temp = head;
    while (temp != NULL) {
        if (temp->roll == roll)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

static void modify_fields(Student *s)
{
    char choice;

    printf("N/n : Name\n");
    printf("P/p : Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'N':
        case 'n':
            printf("Enter New Name: ");
            scanf(" %[^\n]", s->name);
            printf("Name updated successfully!\n");
            break;
        case 'P':
        case 'p':
            printf("Enter New Percentage: ");
            scanf("%f", &s->percentage);
            printf("Percentage updated successfully!\n");
            break;
        default:
            printf("Invalid choice!\n");
    }
}


static Student *select_via_listing(int by_name, const char *name, float percentage)
{
    Student *temp = head;
    int match_count = 0;
    int roll;

    printf("\n--------------------------------------\n");
    printf("Roll No\tName\t\tPercentage\n");
    printf("--------------------------------------\n");

    while (temp != NULL) {
        int is_match = by_name
            ? (strcasecmp(temp->name, name) == 0)
            : (temp->percentage == percentage);

        if (is_match) {
            printf("%d\t%-12s\t%.2f\n", temp->roll, temp->name, temp->percentage);
            match_count++;
        }
        temp = temp->next;
    }
    printf("--------------------------------------\n");

    if (match_count == 0) {
        printf("No matching records found!\n");
        return NULL;
    }

    printf("Enter Roll Number of the record to modify: ");
    scanf("%d", &roll);
    return find_by_roll(roll);
}

void stud_mod(void)
{
    char choice;
    Student *target = NULL;

    if (head == NULL) {
        printf("No records available to modify!\n");
        return;
    }

    printf("R/r : Roll Number\n");
    printf("N/n : Name\n");
    printf("P/p : Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'R':
        case 'r': {
            int roll;
            printf("Enter Roll Number: ");
            scanf("%d", &roll);
            target = find_by_roll(roll);
            if (target == NULL)
                printf("Roll number %d not found!\n", roll);
            break;
        }
        case 'N':
        case 'n': {
            char name[50];
            printf("Enter Name to search: ");
            scanf(" %[^\n]", name);
            target = select_via_listing(1, name, 0);
            break;
        }
        case 'P':
        case 'p': {
            float pct;
            printf("Enter Percentage to search: ");
            scanf("%f", &pct);
            target = select_via_listing(0, NULL, pct);
            break;
        }
        default:
            printf("Invalid choice!\n");
            return;
    }

    if (target != NULL)
        modify_fields(target);
}

