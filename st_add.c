#include "student.h"
static int get_smallest_roll(void)
{
    int roll=1;
    int found;
    Student *temp;
   
   while(1){
     found=0;
     temp = head;
    while(temp != NULL){
     if(temp->roll ==roll)
      {
         found =1;
         break;
      }
       temp = temp->next;
     }
      if(!found)
        return roll;
      roll++;

     }
 }
 
void stud_add(void)
{
  Student *new_node = (Student *)malloc(sizeof(Student));
  if(new_node == NULL)
  {
   printf("Memory allocation failed!\n");
   return;
  }
 
 new_node->roll = get_smallest_roll();
 printf("Assigned Roll Number: %d\n", new_node->roll);

 printf("Enter Student Name: ");
 scanf(" %[^\n]",new_node->name); 
 
 printf("Enter percentage: ");
 scanf(" %f",&new_node->percentage);

 new_node->next = NULL;
 
 if(head == NULL)
 {
    head = new_node;
 }
 else
 {
    Student *temp = head;
    while(temp->next != NULL)
       temp = temp->next;
    temp->next = new_node;
 }
 
 printf("Record added successfully!\n");
} 




















