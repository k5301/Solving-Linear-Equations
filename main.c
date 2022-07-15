#include<stdio.h>
#include<string.h>
#include"1.menu.h"
#include"2.standard_features.h"
#include"3.matrix_and_determinant.h"
/*
semantics
   p0,p1,p2a..... position defining for using goto function;
   choice_fun's,fun_menu(),fun() are defined in menu.h;

*/
int main()
{
   char ex;
   p0:;/*denotes page 0 done*/
   {
      fun_menu();/*menu of project*/
   }

   p1:;/*denotes page 1 done*/
   {
      int ch1;
      ch1=choice_fun1();
      switch (ch1)
      {
         case 0:
            ex=exit_fun();
            if(ex=='y')
               goto exit;
            else
               goto p1;
            break;
         case 9:
            goto p0;
            break;
         case 1:
            goto p2a;
            break;
         case 2:
            goto p2b;
            break;
         default:
            printf("\n\t!!! enter the correct choice ___ !!!!");
            fun(1);
            goto p1;
            break;
      }
   }

   p2a:;/*denotes page 2a i.e. Standard features*/
   {
      int ch2a;
      ch2a = choice_fun2a();
      switch (ch2a)
      {
         case 0:
            ex=exit_fun();
            if(ex=='y')
               goto exit;
            else
               goto p2a;
            break;
         case 9:
            goto p1;
            break;

         case 1:
            goto p2a1;
            break;
         case 2:
            goto p2a2;
            break;
         case 3:
            goto p2a3;
            break;
         case 4:
            goto p3a;
            break;
         default:
            printf("\n\t!!! enter the correct choice ___ !!!!");
            fun(1);
            goto p2a;
            break;
      }

      p2a1:;/*denotes solving arithmetic expression*/
      {
         fun_SAE();
         goto p2a;
      }
      p2a2:;/*denotes number conversion*/
      {
         fun_NC();
         goto p2a;
      }
      p2a3:;/*denotes solving Quadratic equation*/
      {
         fun_QUAD();
         goto p2a;
      }
   }
   p2b:;/*denotes page 2b i.e. Matrix and Determinant*/
   {
      int ch2b;
      ch2b = choice_fun2b();

      switch (ch2b)
      {
         case 0:
            ex=exit_fun();
            if(ex=='y')
               goto exit;
            else
               goto p2b;
            break;
         case 9:
            goto p1;
            break;

         case 1:
            goto p2b1;
            break;
         case 2:
            goto p2b2;
            break;
         case 3:
            goto p2b3;
            break;
         case 4:
            goto p2b4;
            break;
         case 5:
            goto p2b5;
            break;
         case 6:
            goto p2b6;
            break;
         case 7:
            goto p2b7;
            break;
         case 8:
            goto p3b;
            break;
         default:
            printf("\n\t!!! enter the correct choice ___ !!!!");
            fun(1);
            goto p2b;
            break;
      }
      p2b1:;/*denotes Trace of a matrix*/
      {
         fun_matrix_main(ch2b);
         goto p2b;
      }
      p2b2:;/*denotes Transpose of a Matrix*/
      {
         fun_matrix_main(ch2b);
         goto p2b;
      }
      p2b3:;/*denotes Addition/Subtraction of Matrices*/
      {
         fun_matrix_main(ch2b);
         goto p2b;
      }
      p2b4:;/*denotes Multiplication of Matrices*/
      {
         fun_matrix_main(ch2b);
         goto p2b;
      }
      p2b5:;/*denotes Determinant of a Matrix*/
      {
         fun_matrix_main(ch2b);
         goto p2b;
      }
      p2b6:;/*denotes Adjoint of a Matrix*/
      {
         fun_matrix_main(ch2b);
         goto p2b;
      }
      p2b7:;/*denotes Inverse of a Matrix*/
      {
         fun_matrix_main(ch2b);
         goto p2b;
      }
   }
   p3a:;/*denotes others option of page p2a*/
   {
      fun(0);
      printf("\n\n\t\t\tCOMING SOON");
      fun(1);
      goto p2a;
   }

   p3b:;/*denotes Applications option of p2b*/
   {
      int ch3b;
      ch3b = choice_fun3b();
      switch (ch3b)
      {
         case 0:
            ex=exit_fun();
            if(ex=='y')
               goto exit;
            else
               goto p3b;
            break;
         case 9:
            goto p2b;
            break;

         case 1:
            goto p3b1;
            break;
         case 2:
            goto p3b2;
            break;
         default:
            printf("\n\t!!! enter the correct choice ___ !!!!");
            fun(1);
            goto p3b;
            break;
      }
      p3b1:;/*denotes area of triangle*/
      {
         fun_areaoftriangle();
         goto p3b;
      }
      p3b2:;/*denotes solving of n equations*/
      {
         fun_solving_n_eq();
         goto p3b;
      }
   }

   exit:;
   return;
}
