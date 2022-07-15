void fun_input_matrix(float *arr,int a,int b)
{
   fun(0);
   printf("\n\n Enter the element of your matrix of order (%d*%d) one by one :\n\n\n",a,b);
   int i,j;
   for(i=0;i<a;i++)
   {
      for(j=0;j<b;j++)
      {
         printf("\t Enter the element at position (%d,%d) : ",i+1,j+1);
         scanf("%f",(arr+i*b+j));
         printf("\n\n");
      }
   }
   fun(0);
   return;
}
void fun_print_operation(int ch2b)
{
   if(ch2b==0)
   {
      printf("\n\t\t\t Operation : ADDITION\n\n");
   }
   else if(ch2b==1)
   {
      printf("\n\t\t\t Operation : TRACE\n\n");
   }
   else if(ch2b==2)
   {
      printf("\n\t\t\t Operation : TRANSPOSE\n\n");
   }
   else if(ch2b==3)
   {
      printf("\n\t\t\t Operation : ADDITION/SUBTRACTION\n\n");
   }
   else if(ch2b==4)
   {
      printf("\n\t\t\t Operation : MULTIPLICATION\n\n");
   }
   else if(ch2b==5)
   {
      printf("\n\t\t\t Operation : DETERMINANT\n\n");
   }
   else if(ch2b==6)
   {
      printf("\n\t\t\t Operation : ADJOINT\n\n");
   }
   else if(ch2b==7)
   {
      printf("\n\t\t\t Operation : INVERSE\n\n");
   }
   else if(ch2b==8)
   {
      printf("\n\t\t\t Operation : SUBTRACTION\n\n");
   }

}
void fun_print_matrix(float * arr,int a, int b)
{
   int i,j;
   for(i=0;i<a;i++)
   {
      printf("\n\n\t");
      for(j=0;j<b;j++)
      {
         printf("%.f\t",*(arr+i*b+j));
      }
   }
}

void fun_print_matrices(float * arr1,float * arr2,float * arr3,int a,int b,int c)
{
   int i,j;
   for(i=0;i<a;i++)
   {
      printf("\n\n\t");
      for(j=0;j<b;j++)
      {
         printf("%.f  ",*(arr1+i*b+j));
      }
      printf("\t ");
      for(j=0;j<c;j++)
      {
         printf("%.f  ",*(arr2+i*c+j));
      }
      printf("\t\t ");
      for(j=0;j<c;j++)
      {
         printf("%.f  ",*(arr3+i*c+j));
      }
   }
}

void fun_copy_matrix(float * arr1,float *arr2,int a,int b)
{
   int i,j;
   for(i=0;i<a;i++)
   {
      for(j=0;j<b;j++)
      {
         *(arr2+i*b+j)=*(arr1+i*b+j);
      }
   }
   return;
}

char check_valid_order_fun(int ch2a2,int a1,int b1,int a2,int b2)
{
   if(ch2a2==1||ch2a2==5||ch2a2==6||ch2a2==7)
   {
      if(a1==b1)
      {
         return 'y';
      }
      else
      {
         fun(0);
         printf("\n\n\t\t Can't perform this operation on this matrix,\n\t\t because matrix should be a square matrix");
         fun(1);
         return 'n';
      }
   }
   else if(ch2a2==2||ch2a2==3)
   {
      if(a1==a2&&b1==b2)
         return 'y';
      else
      {
         fun(0);
         printf("\n\n\t\t Matrices should be of same order for addition and subtraction.");
         fun(1);
         return 'n';
      }
   }
   else
   {
      if(b1==a2)
         return 'y';
      else
      {
         fun(0);
         printf("\n\n\t\t For matrix multiplication no. of rows in second matrix should be equal\n\t\t to no. of columns in the first matrix");
         fun(1);
         return 'n';

      }
   }
}
void fun_traceof_matrix(float *arr,int a1,int b1)
{
   char validity;
   validity = check_valid_order_fun(1,a1,b1,0,0);
   if(validity=='n')
   {
      return;
   }
   float tr=0;int i=0;
   while(i<a1)
   {
      tr+=*(arr+i*a1+i);
      i++;
   }
   printf("\n\n\t Trace : %.1f",tr);
   return;
}
char fun_transposeof_matrix(float *arr,int a1,int b1)
{
   int i,j;
   float arrt[b1][a1];
   float a;
   for(i=0;i<a1;i++)
   {
      for(j=0;j<b1;j++)
      {
         arrt[j][i]=*(arr +i*b1+j);
      }
   }

   if(a1==b1)
   {
      fun_copy_matrix(arrt,arr,a1,b1);
      return;
   }
   else
   {
      printf("\n\n  Transpose matrix is : ");
      fun_print_matrix(arrt,b1,a1);
      return 'n';
   }
}
void fun_additionof_matrices(float *arr,int a1,int b1)
{
   fun(0);
   fun_print_operation(0);
   printf("\n\n  First Matrix is : ");
   fun_print_matrix(arr,a1,b1);
   getch();

   float arr1[a1][b1],arr2[a1][b1];
   fun_copy_matrix(arr,arr1,a1,b1);

   fun_input_matrix(arr2,a1,b1);

   fun(0);
   fun_print_operation(0);
   printf("\n\n  First Matrix is : ");
   fun_print_matrix(arr1,a1,b1);
   printf("\n\n  Second Matrix is : ");
   fun_print_matrix(arr2,a1,b1);
   getch();
   int i,j;
   for(i=0;i<a1;i++)
   {
      for(j=0;j<b1;j++)
      {
         *(arr+i*b1+j)= arr1[i][j]+arr2[i][j];
      }
   }
   printf("\n\n  Result : ");
   fun_print_matrices(arr1,arr2,arr,a1,b1,b1);
   return;
}
void fun_subtractionof_matrices(float *arr,int a1,int b1)
{
   fun(0);
   fun_print_operation(8);
   printf("\n\n  First Matrix is : ");
   fun_print_matrix(arr,a1,b1);
   getch();

   float arr1[a1][b1],arr2[a1][b1];
   fun_copy_matrix(arr,arr1,a1,b1);

   fun_input_matrix(arr2,a1,b1);

   fun(0);
   fun_print_operation(8);
   printf("\n\n  First Matrix is : ");
   fun_print_matrix(arr1,a1,b1);
   printf("\n\n  Second Matrix is : ");
   fun_print_matrix(arr2,a1,b1);
   getch();
   int i,j;
   for(i=0;i<a1;i++)
   {
      for(j=0;j<b1;j++)
      {
         *(arr+i*b1+j)= arr1[i][j]-arr2[i][j];
      }
   }
   printf("\n\n  Result : ");
   fun_print_matrices(arr1,arr2,arr,a1,b1,b1);
   return;
}
char fun_multiplicationof_matrix(float *arr,int a1,int b1)
{
   float arr1[a1][b1];
   fun_copy_matrix(arr,arr1,a1,b1);
   int a2=0,b2=0;char validity;
   do
   {
      fun(0);
      fun_print_operation(4);
      printf("\n\n  First Matrix is : ");
      fun_print_matrix(arr,a1,b1);
      getch();

      printf("\n\n  Enter the order of the second matrix (a*b) : ");
      scanf("%d*%d",&a2,&b2);
      validity=check_valid_order_fun(4,a1,b1,a2,b2);
   }while(validity!='y');
   float arr2[a2][b2];
   fun_input_matrix(arr2,a2,b2);

   fun(0);
   fun_print_operation(4);
   printf("\n\n  First Matrix is : ");
   fun_print_matrix(arr1,a1,b1);
   printf("\n\n  Second Matrix is : ");
   fun_print_matrix(arr2,a2,b2);
   getch();

   int i,j,k;
   float arr3[a1][b2];
   for(i=0;i<a1;i++)
   {
      for(j=0;j<b2;j++)
      {
         arr3[i][j]=0;
         for(k=0;k<b1;k++)
         {
            arr3[i][j]+=arr1[i][k]*arr2[k][j];
         }
      }
   }
   printf("\n\n  Result : ");
   if(a1==b1&&a2==b2)
   {
      fun_print_matrices(arr1,arr2,arr3,a1,b1,b1);
      fun_copy_matrix(arr3,arr,a1,b2);
      return;
   }
   else if(a2==a1)
      fun_print_matrices(arr1,arr2,arr3,a1,b1,b2);

   else
      fun_print_matrix(arr3,a1,b2);
   return 'n';
}
float fun_determinantof_matrix(float *arr,int m)
{
   int i,j,k,l;
   float d=0,e;
   for(i=0;i<m;i++)
   {
      e = *(arr+i);
      if(m!=1&&e!=0)
      {
         float arr2[m-1][m-1];
         for(k=1;k<m;k++)
         {
            j=0;
            for(l=0;l<m;l++)
            {
               if(l!=i)
               {
                  arr2[k-1][j]=*(arr+k*m+l);
                  j++;
               }
            }
         }
         e = e*fun_determinantof_matrix(arr2,m-1);
      }
      if(i%2==0)
         d+=e;
      else
         d-=e;
   }
   return d;
}
void fun_adjointof_matrix(float *arr,int m)
{
   int i,j,k,l,p=0,q=0,z;
   float arr2[m-1][m-1],adj1[m][m],d;
   for(i=0;i<m;i++)
   {
      for(j=0;j<m;j++)
      {
         p=0;q=0;
         for(k=0;k<m;k++)
         {
            if(k!=i)
            {
               q=0;
               for(l=0;l<m;l++)
               {
                  if(l!=j)
                  {
                     arr2[p][q]=*(arr+k*m+l);
                     q++;
                  }
               }
               p++;
            }
         }
         d=0;
         d=fun_determinantof_matrix(arr2,m-1);
         z=(pow(-1,i+j+2));
         adj1[i][j]= z*d;
      }

   }
   fun_transposeof_matrix(adj1,m,m);
   fun_copy_matrix(adj1,arr,m,m);

}
char fun_inverseof_matrix(float *arr,int m)
{
   float d = fun_determinantof_matrix(arr,m);
   if(d==0)
   {
      return 'n';
   }
   fun_adjointof_matrix(arr,m);
   return;
}

void fun_matrix_main(int ch2b)
{
   initiate:;
   fun(0);
   int a1,b1;
   fun_print_operation(ch2b);
   printf("\n\n\tEnter the order of your matrix (a*b) : ");
   scanf("%d*%d",&a1,&b1);
   if(ch2b==1||ch2b==5||ch2b==6||ch2b==7)
   {
      while(a1!=b1)
      {
         fun(0);
         printf("\n\n\t\tHere, Matrix should be a square matrix...\n\n");
         fun(1);
         fun_print_operation(ch2b);
         printf("\n\n\tEnter the order of your matrix (a*b) : ");
         scanf("%d*%d",&a1,&b1);
      }
   }
   float arr[a1][b1];
   fun_input_matrix(arr,a1,b1);
   operation:;
   if(ch2b==1)
   {
      fun(0);
      fun_print_operation(ch2b);
      printf("\n\n  Matrix is : ");
      fun_print_matrix(arr,a1,b1);
      getch();
      fun_traceof_matrix(arr,a1,b1);
   }
   else if(ch2b==2)
   {

      fun(0);
      fun_print_operation(ch2b);
      printf("\n\n  Matrix is : ");
      fun_print_matrix(arr,a1,b1);
      getch();
      char ch;
      ch = fun_transposeof_matrix(arr,a1,b1);
      if(ch=='n')
      {
         fun(1);
         return;
      }
      printf("\n\n  Transpose matrix is : ");
      fun_print_matrix(arr,a1,b1);
   }
   else if(ch2b==3)
   {
      char ch;
      ch = choice_fun2b3();
      if(ch=='2')
         fun_subtractionof_matrices(arr,a1,b1);
      else
         fun_additionof_matrices(arr,a1,b1);
   }
   else if(ch2b==4)
   {
      char ch;
      ch = fun_multiplicationof_matrix(arr,a1,b1);
      if(ch=='n')
      {
         fun(1);
         return;
      }
   }
   else if(ch2b==5)
   {
      fun(0);
      fun_print_operation(ch2b);
      printf("\n\n  Matrix is : ");
      fun_print_matrix(arr,a1,b1);
      char ch;
      ch=check_valid_order_fun(ch2b,a1,b1,0,0);
      if(ch=='n')
      {
         goto result2;
      }
      getch();
      float d;
      d = fun_determinantof_matrix(arr,a1);
      printf("\n\n\t Determinant : %.1f",d);
   }
   else if(ch2b==6)
   {
      fun(0);
      fun_print_operation(ch2b);
      printf("\n\n  Matrix is : ");
      fun_print_matrix(arr,a1,b1);
      char ch;
      ch=check_valid_order_fun(ch2b,a1,b1,0,0);
      if(ch=='n')
      {
         goto result2;
      }
      getch();
      fun_adjointof_matrix(arr,a1);
      printf("\n\n Adjoint Matrix : ");
      fun_print_matrix(arr,a1,b1);
   }
   else if(ch2b==7)
   {

      fun(0);
      fun_print_operation(ch2b);
      printf("\n\n  Matrix is : ");
      fun_print_matrix(arr,a1,b1);
      char ch1;
      ch1=check_valid_order_fun(ch2b,a1,b1,0,0);
      if(ch1=='n')
      {
         goto result2;
      }

      getch();
      char ch;
      float d=fun_determinantof_matrix(arr,a1);
      ch = fun_inverseof_matrix(arr,a1);
      if(ch=='n')
      {
         fun(0);
         printf("\n\n Inverse of this matrix is not possible,\n\t because determinant is zero");
         goto result;
      }
      printf("\n\n  Inverse Matrix : \n\n\n\t  1/%.2f of matrix \n",d);
      fun_print_matrix(arr,a1,b1);
      int i,j;
      for(i=0;i<a1;i++)
      {
         for(j=0;j<b1;j++)
         {
            arr[i][j]/=d;
         }
      }
      printf("\n\n  or");
      //fun_print_matrix(arr,a1,a1);
      for(i=0;i<a1;i++)
      {
         printf("\n\n\t");
         for(j=0;j<b1;j++)
         {
            printf("%.2f\t",arr[i][j]);
         }
      }
      fun(1);
      return;
   }
   result:;
   fun(1);
   result2:;
   printf("\n\n  Matrix in main : ");
   fun_print_matrix(arr,a1,b1);
   char op;
   printf("\n\n Option : ");
   op=getch();
   switch (op)
   {
      case 'n':
         goto initiate;
         break;
      case 'r':
         ch2b=1;
         goto operation;
         break;
      case 't':
         ch2b=2;
         goto operation;
         break;
      case 's':
         ch2b=3;
         goto operation;
         break;
      case 'm':
         ch2b=4;
         goto operation;
         break;
      case 'd':
         ch2b=5;
         goto operation;
         break;
      case 'a':
         ch2b=6;
         goto operation;
         break;
      case 'i':
         ch2b=7;
         goto operation;
         break;
      case 'o':
         choice_fun2b_note();
         goto result2;
         break;
      default:
         op=quit_fun();
         if(op=='y')
            return;
         else
            goto result;
         break;
   }
   return;
}


void fun_areaoftriangle()
{
   initiate:;
   fun(0);
   static int ab=1;
   if(ab==1)
      fun_describe_p3b1();
   else
      fun(0);
   ab=0;
   printf("\n\n\t\t\t Area of a triangle\n\n");
   printf("\n\t Enter the vertex one by one : \n\n");

   float arr1[3][3];
   printf("\n\n\t\t Vertex 1 (a1,b1) : ");
   scanf("%f,%f",&arr1[0][0],&arr1[0][1]);
   arr1[0][2]=1;
   printf("\n\n\t\t Vertex 2 (a2,b2) : ");
   scanf("%f,%f",&arr1[1][0],&arr1[1][1]);
   arr1[1][2]=1;
   printf("\n\n\t\t Vertex 3 (a3,b3) : ");
   scanf("%f,%f",&arr1[2][0],&arr1[2][1]);
   arr1[2][2]=1;
   float area;
   area = fun_determinantof_matrix(arr1,3);
   area/=2.0;
   if(area<0)
      area*=-1;
   printf("\n\n\n\t\t\t Area : %.2f sq. units",area);
   printf("\n\n\n  Option : ");
   char o;
   o = getch();
   if(o=='n')
      goto initiate;
   else
   {
      o=quit_fun();
      if(o!='y')
         goto initiate;
      else
         return;
   }
}

void fun_print_equations(float *arr2,float *arrc,int n)
{
   fun(1);
   int i,j;
   printf("\n\n\t\t\t Solving %d equations",n);
   printf("\n\n\t Equations entered by you are : \n");
   char var;
   for(i=0;i<n;i++)
   {
      var = 'a';
      printf("\n\n\t\t ");
      for(j=0;j<n;j++)
      {
         if(*(arr2+i*n+j)!=0)
         {
            if(*(arr2 + i*n +j+1)<0||j==n-1)
            {
               printf("%.f%c ",*(arr2+i*n+j),var);

            }
            else
            {
               printf("%.f%c + ",*(arr2+i*n+j),var);
            }
         }
         var++;
      }
      printf("= %.f",*(arrc + i));
   }
}

void fun_solving_n_eq()
{
   initiate:;
   fun(0);
   static int ab=1;
   if(ab==1)
      fun_describe_p3b2();
   else
      fun(0);
   ab=0;
   int n,i,j,k;
   printf("\n\n\t\t\t Solving n equations\n\n");
   printf("\n\t Enter the number of equations or number of variables : ");
   scanf("%d",&n);
   printf("\n\n\t\t OK");
   printf("\n\n\t\t We are storing equation in the form \n\n");
   printf("\n\t\t\t a1x + b1y +c1z + ... = C1\n\n");
   printf("\n\n\t\t You have to enter the coefficients and constants of the equation's");
   fun(1);
   printf("\n\n\t\t\t Solving %d equations\n\n",n);
   float arr2[n][n],arrc[n][1];
   char var='a';int val=1;
   for(i=0;i<n;i++,val++)
   {
      printf("\n\t\t Enter the coefficients and constants of equation %d\n ",i+1);
      var = 'a';
      for(j=0;j<n;j++)
      {
         printf("\n\t\t\t %c%d : ",var,val);
         scanf("%f",&arr2[i][j]);
         var++;
      }
      printf("\n\t\t\t C%d : ",val);
      scanf("%f",&arrc[i][0]);
      printf("\n\n");
   }
   fun_print_equations(arr2,arrc,n);
   getch();
   float d = fun_determinantof_matrix(arr2,n);
   fun_adjointof_matrix(arr2,n);
   //fun_print_matrix(arr2,n,n);
   //printf("\n%.f",d);
   float arr3[n][1];
   for(i=0;i<n;i++)
   {
      for(j=0;j<1;j++)
      {
         arr3[i][j]=0;
         for(k=0;k<n;k++)
         {
            arr3[i][j]+=arr2[i][k]*arrc[k][j];
         }
      }
   }
   k=0;
   if(d==0)
   {
      for(i=0;i<n;i++)
      {
         if(arr3[i][0]!=0)
         {
            k=1;
            break;
         }
      }
      if(k==0)
      {
         printf("\n\n\t\t There are many and infinite solution's");
      }
      else
      {
         printf("\n\n\t\t There is no solution");
      }
   }
   else
   {
      printf("\n\n\t\t Solutions : ");
      var='a';
      for(i=0;i<n;i++)
      {
         printf("\n\n\t\t %c : %.f/%.f  or  %.3f",var,arr3[i][0],d,arr3[i][0]/d);
         var++;
      }
   }
   printf("\n\n\n  Option : ");
   char o;
   o = getch();
   if(o=='n')
      goto initiate;
   else
   {
      o=quit_fun();
      if(o!='y')
         goto initiate;
      else
         return;
   }
}
