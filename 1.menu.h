void fun(int a)/*describes holding and clearing of screen*/
{
   if(a==1)
   {printf("\n\n  Press any key");
   getch();
   system("cls");}
   else
   {
      system("cls");
   }
   return;
}
int fun2()/*takes choice input from user as a char and return into an integer*/
{
   char ch;
   printf("\n\n Enter your choice : ");
   /*scanf("%s",&ch);*/
   ch=getch();
   if(ch=='e')
      return 0;
   else if(ch=='\b')
      return 9;
   else
      return ch-48;
}

char quit_fun()
{
   fun(0);
   char ch;
   printf("\n\n\t\tDO YOU WANT TO QUIT (y/n) : ");
   ch = getch();
   if(ch=='\r')
      return 'y';
   return ch;
}

char exit_fun()
{
   fun(0);
   int ch;
   printf("\n\n\n\t\t\t DO YOU WANT TO EXIT (y/n) : ");
   ch = getch();
   if(ch=='\r')
      return 'y';
   return ch;
}
void fun_menu()/*describes contents of the project*/
{
   fun(0);
   printf("\n\n\t\t\t\t\tMULTI-FEATURED CALCULATOR");
   printf("\n\t\t\t\t   ___________________________________");
   printf("\n\nFeatures : \n\n");
   printf("\tStandard features -\n");
   printf("\t\t> Solving Arithmetic Expression;\n");
   printf("\t\t> Number Conversion;\n");
   printf("\t\t> Solving Quadratic Equation;\n");
   printf("\t\t> Others - \n");
   printf("\n\tMatrices And Determinant -\n");
   printf("\t\t> Trace of a Matrix\n");
   printf("\t\t> Transpose of a Matrix\n");
   printf("\t\t> Addition of Matrices\n");
   printf("\t\t> Subtraction of Matrices\n");
   printf("\t\t> Multiplication of Matrices\n");
   printf("\t\t> Determinant of a Matrix\n");
   printf("\t\t> Adjoint of a Matrix\n");
   printf("\t\t> Inverse of a Matrix\n");
   printf("\t\t> Applications - ");
   fun(1);
   static int c = 0;
   if(c==0)
   {
      printf("\n\n\n[NOTE : Press 'e' or 0 to exit from the program,\n\tPress backspace key or 9 to go to the previous page,\n\twhere you have a option to choose]");
      c=1;
      fun(1);
   }

   return;
}
int choice_fun1()/*describe menu of the project*/
{
   fun(0);
   printf("\n\n\t\t\t MULTI-FEATURED CALCULATOR");
   printf("\n\n\n Choose a option :\n\n");
   printf("\t1. Standard Features\n");
   printf("\t2. Matrices and Determinant\n");
   int ch1=fun2();
   /*printf("\n\n Enter your choice : ");
   scanf("%d",&ch1);*/
   return ch1;
}
int choice_fun2a()/*describe menu of the standard features page*/
{
   fun(0);
   printf("\n\n\t\t\t STANDARD FEATURES");
   printf("\n\n\n Choose a option :\n\n");
   printf("\t1. Solving Arithmetic Expression\n");
   printf("\t2. Number Conversion\n");
   printf("\t3. Solving Quadratic Equation\n");
   printf("\t4. Others-\n");
   int ch2a=fun2();
   /*printf("\n\n Enter your choice : ");
   scanf("%d",&ch2a);*/
   return ch2a;
}

int choice_fun2a2()/*describe menu of the project*/
{
   fun(0);
   printf("\n\n\t\t\t NUMBER CONVERSION");
   printf("\n\n\n Choose a form in which you want to enter :\n\n");
   printf("\n\n\t\t 1. Decimal form");
   printf("\n\n\t\t 2. Binary form");
   printf("\n\n\t\t 3. Octal form ");
   printf("\n\n\t\t 4. Hexadecimal form\n");
   int ch1=fun2();
   return ch1;
}
void choice_fun2b_note()
{
   fun(0);
   printf("\n\t\t\t Matrix and Determinant");
   printf("\n\n\t\t [NOTE : press 'q' to quit,\n\t\t          press 'n' to perform the same operation on another matrix\n\t\t          in the option]");
   printf("\n\n\t\t YOU CAN ALSO PERFORM ANOTHER OPERATIONS WITH THE RESULTANT MATRIX : ");
   printf("\n\n\n\t\t\t >> Press 'r' : to know the trace of the matrix ;");
   printf("\n\n\t\t\t >> Press 't' : to find the transpose of the matrix ;");
   printf("\n\n\t\t\t >> Press 's' : to add or subtract another matrix to the resultant matrix ;");
   printf("\n\n\t\t\t >> Press 'm' : to multiply another matrix to the resultant matrix ;");
   printf("\n\n\t\t\t >> Press 'd' : to find determinant of the matrix;");
   printf("\n\n\t\t\t >> Press 'a' : to find adjoint matrix;");
   printf("\n\n\t\t\t >> Press 'i' : to find inverse matrix;");
   printf("\n\n\n\t PRESS 'o' TO OPEN THIS LIST AGAIN");

   printf("\n\n\n\t Enter the order in a*b format");
   fun(1);
}

int choice_fun2b()/*describe menu of the matrices and determinant page*/
{
   fun(0);
   static int ab=1;
   if(ab==1)
      choice_fun2b_note();
   else
      fun(0);
   ab=0;
   printf("\n\n\t\t\t MATRIX and DETERMINANT");
   printf("\n\n\n Choose a option :\n\n");
   printf("\t1. Trace of a Matrix\n");
   printf("\t2. Transpose of a Matrix\n");
   printf("\t3. Addition/Subtraction of Matrices\n");
   printf("\t4. Multiplication of Matrices\n");
   printf("\t5. Determinant of a Matrix\n");
   printf("\t6. Adjoint of a Matrix\n");
   printf("\t7. Inverse of a Matrix\n");
   printf("\t8. Applications-\n");
   int ch2b=fun2();
   /*printf("\n\n Enter your choice : ");
   scanf("%d",&ch2b);*/
   return ch2b;
}
char choice_fun2b3()
{

   char ch;
   initiate:;
   fun(0);
   printf("\n\n\t\t\t Matrix and Determinant\n");
   printf("\n\n\t Choose a option : ");
   printf("\n\n\t\t 1. Addition \n\n\t\t 2. Subtraction");
   printf("\n\n\t Operator : ");
   ch = getch();
   if(ch!='1'&&ch!='2')
   {
      printf("\n\t!!! enter the correct choice ___ !!!!");
      fun(1);
      goto initiate;
   }
   return ch;
}

int choice_fun3b()/*describe menu of the matrices and determinant page*/
{
   fun(0);
   printf("\n\n\t\t\t MATRIX and DETERMINANT APPLICATION'S");
   printf("\n\n\n Choose a option :\n\n");
   printf("\t1. Area of a Triangle\n\n");
   printf("\t2. Solving n linear equation\n");
   int ch2b=fun2();
   return ch2b;
}


void fun_describe_p2a1()/*a1*/
{
   fun(0);
   printf("\n\n\t\t\t Solving Arithmetic Expression");
   printf("\n\n\n Enter the expression as you enter in a calculator");
   printf("\n\n\n OPERATORS CAN BE USED :\n\n");
   printf("\t\t > Addition(+);\n\n");
   printf("\t\t > Subtraction(-);\n\n");
   printf("\t\t > Multiplication(*);\n\n");
   printf("\t\t > Division(/);\n\n");
   printf("\t\t > Bracket's( '(' or ')' );\n\n");
   fun(1);
   printf("\n\n\t\t\t Solving Arithmetic Expression");
   printf("\n\n\n Functioning Keys :\n\n");
   printf("\t\t > Equal to function (press =);\n\n");
   printf("\t\t > Backspace function (backspace-key);\n\n");
   printf("\t\t > Clear-screen function (press Enter-key);\n\n");
   printf("\t\t > Quit function (press q)");
   fun(1);
}

void fun_describe_p2a2()
{
   fun(0);
   printf("\n\n\t\t\t Number Conversion");
   printf("\n\n\n\t FEATURE'S : ");
   printf("\n\n\t\t\tConverting a no. entered in one form into rest of the three(only int not float)");
   printf("\n\n\t Forms Accepted : ");
   printf("\n\n\t\t\t > Decimal form");
   printf("\n\n\t\t\t > Binary form");
   printf("\n\n\t\t\t > Octal form ");
   printf("\n\n\t\t\t > Hexadecimal form");
   fun(1);
   printf("\n\n\n [Note : press 'q' to quit,\n\t press 'enter key' to enter a new no.,\n\t press 's' to shift the choice]");
   fun(1);
   return;
}


void fun_describe_p2a3()
{
   fun(0);
   printf("\n\n\t\t\t Solving Quadratic Expression");
   printf("\n\n\n\t FEATURE'S : ");
   printf("\n\n\t\t\t FINDING REAL AND COMPLEX ROOTS OF A EQUATION");
   printf("\n\n\n\t[NOTE : press 'q' to quit, 'n' to solve a new quadratic equation in the option]");
   fun(1);
}

void fun_describe_p3b1()
{
   fun(0);
   printf("\n\n\t\t\t Area of a Triangle");
   printf("\n\n\n  Feature : \n\n\t Here you can find the area of a triangle with three vertices in 2D");
   printf("\n\n\n\n  ENTER THE VERTEX AS a,b");
   fun(1);
   printf("\n\n\n\n\n\t [Note : press 'q' to quit,\n\t        press 'n' to find area of a new triangle\n\t        in the option");
   fun(1);
}


void fun_describe_p3b2()
{
   fun(0);
   printf("\n\n\t\t\t Solving n linear equations");
   printf("\n\n  Feature : \n\n\t\t Here you can find the solution of n variables by entering\n\n\t\t n number of equations.");
   printf("\n\n\t\t Here you have to enter the coefficients and constant terms only ");
   fun(1);
   printf("\n\n\n\n\n\t [Note : press 'q' to quit,\n\t        press 'n' to solve another n equations\n\t        in the option");
   fun(1);
}
