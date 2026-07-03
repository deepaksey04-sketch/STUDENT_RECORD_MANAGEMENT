#include "student.h"
static void delete_by_roll(int roll)
{
 Student *temp = head,*prev = NULL;
 while(temp != NULL && temp->roll!= roll)
{
 prev = temp;
 temp = temp->next;
}
 if(temp == NULL)
 {
  printf("Roll number %d not found!\n",roll);
  return;
 }
 if(prev == NULL)
   head = temp->next;
 else 
  prev->next = temp->next;
 
 free(temp);
 printf("Record will Roll number %d deleted successfully!\n",roll);
}

static void delete_by_name(void)
{
 char name[50];
 Student *temp = head;
 int match_count =0;
 int roll;

 printf("Enter Name to search: ");
 scanf(" %[^\n]",name);
 
 printf("\n---------------------------------------------------------\n");
 printf("Roll No\tName\t\tPercentage\n");
 printf("-----------------------------------------------------------\n");
 
 while(temp != NULL)
{ 
 if(strcasecmp(temp->name,name)==0){
   printf("%d\t%-12s\t%.2f\n",temp->roll,temp->name,temp->percentage);
  match_count++;
}
 temp = temp->next;
}
printf("------------------------------------------------------------\n");
 
 if(match_count==0)
{
 printf("No matching records found!\n");
 return;
}
 printf("Enter Roll Number of the record to delete: ");
 scanf("%d",&roll);
 delete_by_roll(roll);
}

void stud_del(void)
{
 char choice;
 if(head == NULL)
{
 printf("No records available to delete!\n");
 return;
}
 
 printf("R/r : Delete using Roll Number\n");
 printf("N/n : Delete using Name\n");
 scanf("%c",&choice);
 
 switch (choice){
  case 'R': case 'r' :{
  int roll;
 printf("Enter Roll Numberto delete: ");
 scanf("%d",&roll);
 delete_by_roll(roll);
 break;
} 
 case 'N': case 'n': 
      delete_by_name();
        break;
      default:
             printf("Invalid choice!\n");
}
}




























































