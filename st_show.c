#include "student.h"
void stud_show(void)
{
 Student *temp = head;
 if(head ==NULL)
{
 printf("No records to display!\n");
 return;
}
 printf("------------------------------------------------------------\n");
 printf("Roll No\tName\t\tPercentage\n");
 printf("------------------------------------------------------------\n");

 while(temp != NULL)
{
 printf("%d\t%-12s\t%.2f\n",temp->roll,temp->name,temp->percentage);
 temp=temp->next;
}
 printf("--------------------------------------------------------------\n");
}
