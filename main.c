#include"student.h"
#define pf printf
Student *head = NULL;
int main(void)
{
   char choice,exit_choice;
  stud_load();
 while(1)
{
   pf("\n***** STUDENT RECORD MENU *****\n");
   pf("A/a : Add new record\n");
   pf("D/d : Delete a record\n");
   pf("S/s : Show the list\n");
   pf("M/m : Modify a record\n");
   pf("V/v : Save\n");
   pf("E/e : Exit\n");

   pf("Enter your choice: ");
   scanf(" %c",&choice);

switch(choice)
{
         case 'A': case 'a': stud_add();
         break;
         case 'D': case 'd': stud_del();
         break;
         case 'S': case 's': stud_show();
         break;
         case 'M': case 'm': stud_mod();
         break;
         case 'V': case 'v': stud_save();
         break;
         case 'T': case 't': stud_sort();
         break;
         case 'E': case 'e':
                     pf("S/s : Save and Exit\n");
                     pf("E/e : Exit without saving\n");
                     pf("Enter Your choice: ");
                     scanf(" %c", &exit_choice);
         if(exit_choice == 'S' || exit_choice == 's')
         {
          stud_save();
         pf("Record saved. Exiting.....\n");
         }else{
            pf("Exiting without saving.....\n");}
        break;
     default:
         pf("Invalid choice! Please try again.\n");
       }
}
free_list();
return 0;
}








