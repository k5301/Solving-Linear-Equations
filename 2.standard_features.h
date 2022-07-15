char arr[500],o='h',p='l',c,m='k';
int i,j,x,a=1;
float b=0,z=0;

float calculate(int k)
{
   float d;char q;int w=0;
   for(j=k;j<strlen(arr);j++)
   {
      if(j==k)
      {
         b=0;
         d=0;
         q='h';
         o='h';
         p='l';
      }
      if(arr[j]==')'&&j!=strlen(arr))/*a4*/
      {
         m='k';
         return d;
      }
      if(arr[j]=='(')/*a5*/
      {
         m='(';
         b=calculate(j+1);
         if(q=='+')
            d+=b;
         else if(q=='-')
            d-=b;
         else if(q=='*')
            d*=b;
         else if(q=='/')
            d/=b;
         goto we;/*a6*/
      }

      c=arr[j];
      x=c;
      if(x>=48&&x<58)
      {
         if(p=='.')
         {
            b+=((x-48)*1.00)/pow(10,a);
            a++;
         }
         else
         {
            b=b*10;
            b+=x-48;
         }
         if(z==0)
         {
            z=d;
         }

         d=z;

         if(q=='+')
            d+=b;
         else if(q=='-')
            d-=b;
         else if(q=='*')
            d*=b;
         else if(q=='/')
            d/=b;
      }
      if(x>57||x<48)
      {
         if(c!='.'&&c!='('&&c!=')')
         {
            z=0;
            o=c;
            if(q=='h'&&c=='-'&&j==0){w=1;}
            else{q=c;}
            b=0;
            p='l';
         }
         if(c=='.')
         {
            a=1;
            p=c;
         }

      }
      if(q=='h')
      {
         if(w==1)
            d=-b;
         else
            d=b;
      }

      if(m=='('&&(arr[j+1]=='\0'||arr[j]=='\0'))
      {
         m='k';
         return d;
      }
      we:;
   }
   return d;
}

int equalfun(float d,int t)/*a17*/
{
   int i=0,arr1[10],arr2[6],a1=0,a2=0,a3=0;
   int r1=d,s1;
   if(r1<0)
   {
      r1*=-1;
      a3=1;
   }
   s1=r1;
   while(s1>0)
   {
      arr1[a1]=s1%10;
      a1++;
      s1/=10;
   }
   float d2=d-r1;
   d2*=1000000;
   int r2=d2,s2=r2;
   while(s2>0)
   {
      arr2[a2]=s2%10;
      a2++;
      s2/=10;
   }
   int x1=0;
   for(i=0;i<a2;i++)
   {
      if(arr2[i]!=0)
         break;
      x1++;
   }
   if(x1!=0)
   {
      a2=6-x1;
      for(i=0;i<a2;i++)
      {
         arr2[i]=arr2[x1+i];
      }
   }
   if(a2==0)
      arr[a1+a2]='\0';
   else
      arr[a1+a2+1]='\0';
   char ch;
   for(i=a1+a2;i>=0;i--)
   {
      if(i>a1)
      {
         ch=arr2[a1+a2-i];
         ch+=48;
         arr[i]=ch;
      }
      else if(i==a1&&a2!=0)
      {
         arr[i]='.';
      }
      else if(i<a1)
      {
         ch=arr1[a1-i-1];
         ch+=48;
         arr[i]=ch;
      }
   }
   if(a3==1)
   {
      arr[strlen(arr)+1]='\0';
      for(i=strlen(arr);i>0;i--)
      {
         arr[i]=arr[i-1];
      }
      arr[0]='-';
   }
   return strlen(arr);/*a33*/
}

char check_valid_syntex_fun(int *u,char f)
{
   if(f>57||f<48)
   {
      if(f!='+'&&f!='-'&&f!='*'&&f!='/'&&f!='(')
      {
         if(f!='\b'&&f!='\r'&&f!='q'&&f!='='&&f!='.')
         {
            if(f==')')
            {
               if(*u!=1)
                  return 'n';
               else
                  {*u=0;return 'y';}

            }
            else
               return 'n';
         }
         else
            return 'y';
      }
      else
         return 'y';
   }
   else
      return 'y';
}

int fun_count_digit(int a)
{
   int co=7;
   if(a<0)
   {
      a*=-1;
      co++;
   }
   while(a>0)
   {
      co++;
      a/=10;
   }
   return co;
}
int fun_SAE()
{
   static int ab=1;
   if(ab==1)
      fun_describe_p2a1(ab);
   else
      fun(0);
   ab=0;
   initiate:;
   int arr2[20],g=0,u=0,s=0;char v;
   float d=0;
   printf("\n\n\t\t\t Solving Arithmetic Expression\n\n");

   printf("\n\n\n\t\t\t ");

   printf("\n\t\t\t _______________________________");
   printf("\n\n\t\t\t|                              ");
   //arr[0] = '(';
   for(i=0;arr[i-1]!='q';i++)/*a35*/
   {
      arr[i]=getch();/*a36*/
      if(arr[i]!='q')
         printf("%c",arr[i]);/*a37*/
      v=check_valid_syntex_fun(&u,arr[i]);
      if(v=='n')
      {
         fun(0);
         printf("\n\n\t\t!!! INVALID SYNTEX !!!");
         fun(1);
         arr[i]='\0';
         goto lmn;
      }
      if(arr[i]=='q')
      {
         char h;
         h=quit_fun();
         printf("%c",h);
         if(h=='y')
            return;
         else
            arr[i]='\0';
            i=equalfun(d,i);
            goto lmn;
      }
      else if(arr[i]=='=')
      {
         i=equalfun(d,i);
         arr2[0] = '\0';
         g=0;u=0;
         goto lmn;
      }

      else if(arr[i]=='\b')
      {
         i=i-2;
      }
      else if(arr[i]=='\r')
      {
         i=0;
         d=0;
         arr[i]='\0';
         system("cls");
         goto initiate;
      }


      if(arr[i]=='('&&(arr[i-1]!='+'&&arr[i-1]!='-'&&arr[i-1]!='*'&&arr[i-1]!='/'))/*code to insert a opening bracket by the user*/
      {
         arr[i]='*';
         s=1;
      }
      if(arr[i-1]==')'&&(arr[i]<57&&arr[i]>48))
      {
         arr[i+1]=arr[i];
         arr[i]='*';
         i++;
      }

      if(arr[i]!='\b'&&(arr[i]!='('&&arr[i-1]!='('&&arr[i]!=')'&&arr[i-1]!=')'))
      {
          if(((arr[i]>57||arr[i]<48)&&(arr[i-1]>57||arr[i-1]<48)))
          {
            arr[i-1]=arr[i];
            i--;
          }
      }

      if(((o=='+'||o=='-')&&(arr[i]=='*'||arr[i]=='/'))&&(arr[i-1]!=')'&&arr[i-1]!='('))
      {
         j=i;
         while(arr[j]!=o)
         {
            arr[j+1]=arr[j];
            j--;
         }
         arr[j+1]='(';
         arr2[g]=0;
         g++;
         i++;

      }
      if(((o=='*'||o=='/')&&(arr[i]=='+'||arr[i]=='-'))&&(arr[i-1]!=')'&&arr[i-1]!='('))
      {
         //condition to close code defined this :(;
         arr[i+1] = arr[i];
         arr[i] = ')';
         arr2[g]=0;
         g++;
         i++;

      }
      if(s==1)
      {
         s=0;
         i++;
         arr[i]='(';
      }
      if(arr[i]=='('||arr[i]==')')
      {
         if(arr[i]=='('){u=1;}
         arr2[g]=1;
         g++;
      }
      arr[i+1]='\0';
      d=calculate(0);
      lmn:;
      int k=0,l=0,m=0,n=strlen(arr);
      m = fun_count_digit(d);
      fun(0);
      //printf("%d",n);
      printf("\n\n\t\t\t Solving Arithmetic Expression\n\n");
      printf("\n\n\n\t\t\t ");
      for(l=0;l<29-m;l++)
      {
         printf(" ");
      }
      printf("%f\n",d);
      printf("\t\t\t _____________________________\n");
      printf("\n\t\t\t|");

      int countbracket = 0;
      for(int h=0;h<g;h++){if(arr2[h]== 0) {countbracket++;}}
      n=n-countbracket;
      if(n<29)
      {
         m=0;
         for(l=0;l<29-n;l++)
         {
            printf(" ");
         }
      }
      else
         m=n-29;

      for(j=m;j<strlen(arr);j++)
      {
         if((arr[j]=='('||arr[j]==')')&&arr2[k]==0)
         {

            k++;
            continue;
         }
         else
         {

            if(arr[j]=='('||arr[j]==')')
            {
               k++;
            }
            printf("%c",arr[j]);
         }
      }
  }
}


typedef struct
{
   char info;
   struct node *link;
}node;


void backspace_fun(node *ptr,node **last1,int i1)
{
   node *last;last=*last1;
   int i2=0;
   while(i2<i1&&ptr!=NULL)
   {
      last=ptr;
      //printf("%c",ptr->info);
      ptr=ptr->link;
      i2++;
   }
   free(last->link);
   last->link=NULL;
   *last1=last;
}

void fun_print_linked_list2(node *ptr)
{
   while(ptr!=NULL)
   {
      printf("%c",ptr->info);
      ptr=ptr->link;
   }
}
char To_check_Invalid_Syntex(char ch,int ch2a2)
{
   if(ch=='\r'||ch=='\b'||ch=='q'||ch=='='||ch=='s')
   {
      return 'y';
   }
   else
   {
      if(ch2a2==1)
      {
         if(ch>57||ch<48)
         {
            return 'n';
         }
      }
      else if(ch2a2==2)
      {
         if(ch!='1'&&ch!='0')
         {
            return 'n';
         }
      }

      else if(ch2a2==3)
      {
         if(ch<48||ch>55)
         {
            return 'n';
         }
      }

      else if(ch2a2==4)
      {
         if((ch>57||ch<48)&&(ch!='A'&&ch!='B'&&ch!='C'&&ch!='D'&&ch!='E'&&ch!='F'))
         {
            return 'n';
         }

      }
      return 'y';
   }

}

void To_int(node *ptr,int ch2a2,int i1)
{
   node *ptr1;
   ptr1=ptr;
   char ch;
   long int a=0;
   if(ch2a2==1)
   {
      while(ptr1!=NULL)
      {
         ch=ptr1->info;
         a*=10;
         a+=ch-48;
         ptr1=ptr1->link;
      }
      To_Binary(a);
      To_Octal(a);
      To_Hexadecimal(a);
   }

   else if(ch2a2==2)
   {
      char ch;
      int b,i=0;
      while(ptr1!=NULL)
      {
         ch=ptr1->info;
         b=ch-48;
         a+=b*pow(2,i1);
         i1--;
         ptr1=ptr1->link;
      }
      printf("\n\n\t\t\tDecimal     : %ld",a);
      To_Octal(a);
      To_Hexadecimal(a);
   }

   else if(ch2a2==3)
   {

      char ch;
      int b;
      while(ptr1!=NULL)
      {
         ch=ptr1->info;
         b=ch-48;
         a+=b*pow(8,i1);
         i1--;
         ptr1=ptr1->link;
      }
      printf("\n\n\t\t\tDecimal     : %ld",a);
      To_Binary(a);
      To_Hexadecimal(a);

   }

   else if(ch2a2==4)
   {
      char ch;
      int b;
      while(ptr1!=NULL)
      {
         ch=ptr1->info;
         if(ch<=57||ch>=48)
            b=ch-48;
         else if(ch=='A')
         {
            b=10;
         }
         else if(ch=='B')
         {
            b=11;
         }
         else if(ch=='C')
         {
            b=12;
         }
         else if(ch=='D')
         {
            b=13;
         }
         else if(ch=='E')
         {
            b=14;
         }
         else if(ch=='F')
         {
            b=15;
         }
         a+=b*pow(16,i1);
         i1--;
         ptr1=ptr1->link;
      }
      printf("\n\n\t\t\tDecimal     : %ld",a);
      To_Binary(a);
      To_Octal(a);
   }
   return;
}
void To_Binary(long int a)
{
   node *top2,*temp;
   top2=NULL;
   while(a>0)
   {
      temp=(node *)malloc(sizeof(node));
      temp->info=a%2+48;
      temp->link=top2;
      top2=temp;
      a/=2;
   }
   printf("\n\n\t\t\tBinary      : ");
   fun_print_linked_list2(top2);
}

void To_Octal(long int a)
{
   node *top3,*temp;
   top3=NULL;
   while(a>0)
   {
      temp=(node *)malloc(sizeof(node));
      temp->info=a%8+48;
      temp->link=top3;
      top3=temp;
      a/=8;
   }
   printf("\n\n\t\t\tOctal       : ");
   fun_print_linked_list2(top3);
}

void To_Hexadecimal(long int a)
{
   node *top4,*temp;
   top4=NULL;
   int t;
   while(a>0)
   {
      temp=(node *)malloc(sizeof(node));
      t=a%16;
      if(t>=0&&t<=9)
         temp->info=t+48;
      else if(t==10)
      {
         temp->info='A';
      }
      else if(t==11)
      {
         temp->info='B';
      }
      else if(t==12)
      {
         temp->info='C';
      }
      else if(t==13)
      {
         temp->info='D';
      }
      else if(t==14)
      {
         temp->info='E';
      }
      else if(t==15)
      {
         temp->info='F';
      }
      temp->link=top4;
      top4=temp;
      a/=16;
   }
   printf("\n\n\t\t\tHexadecimal : ");
   fun_print_linked_list2(top4);
}
char fun_converter(int ch2a2)
{
   node *first,*temp,*ptr;
   initiate:;
   fun(0);
   first=NULL;
   int i1=1;char c1,h,ch[20];
   if(ch2a2==1)
   {
      strcpy(ch,"Decimal    ");
   }
   else if(ch2a2==2)
   {
      strcpy(ch,"Binary     ");
   }
   else if(ch2a2==3)
   {
      strcpy(ch,"Octal      ");
   }
   else if(ch2a2==4)
   {
      strcpy(ch,"Hexadecimal");
   }
   printf("\n\n\t\t\tNumber Conversion\n\n");
   printf("\n %s : ",ch);
   while(i1<100)
   {
      c1=getch();
      h=To_check_Invalid_Syntex(c1,ch2a2);
      if(h=='n')
      {
         fun(0);
         printf("\n\n\t\t!!! INVALID SYNTEX !!!");
         fun(1);
         i1--;
         goto lmn1;
      }
      if(c1!='q')
         printf("%c",c1);

      if(c1=='q')
      {
         h=quit_fun();
         if(h=='y')
            return;
         else
            {i1--;goto lmn1;}

      }
      else if(c1=='\r')
         goto initiate;
      else if(c1=='\b')
      {
         i1-=2;
         if(i1>0)
            backspace_fun(first,&ptr,i1);
         else
            goto initiate;
         goto lmn1;
      }

      else if(c1=='s')
      {
         fun(0);
         printf("\n\n\t\t DO YOU WANT TO SHIFT THE CHOICE (y/n) : ");
         h=getch();
         if(h=='y'||h=='\r')
         {
            return c1;
         }
         i1--;
         goto lmn1;
      }

      else if(c1=='=')
      {
         fun(0);
         printf("\n\n\t\t\t Number Conversion\n\n");
         printf("\n\n\t\t\t%s : ",ch);
         fun_print_linked_list2(first);
         printf("\n");
         To_int(first,ch2a2,i1-1);

         fun(1);
         return 's';
      }
      temp=(node *)malloc(sizeof(node));
      temp->info=c1;
      temp->link=NULL;
      if(first==NULL)
      {
         first=temp;
      }
      else
      {
         ptr->link=temp;
      }
      ptr=temp;
      lmn1:;
      fun(0);
      printf("\n\n\t\t\tNumber Conversion\n\n");
      To_int(first,ch2a2,i1-1);
      printf("\n\n\n\t\t\t%s : ",ch);
      fun_print_linked_list2(first);
      i1++;
   }
   return 'r';
}

int fun_NC()
{

   static int ab2=1;char ex;
   if(ab2==1)
      fun_describe_p2a2();
   else
      fun(0);
   ab2=0;
   int ch2a2;
   p2a2:;
   ch2a2= choice_fun2a2();
   switch (ch2a2)
   {
      case 0:
         ex=quit_fun();
         if(ex=='y')
            return;
         else
            goto p2a2;
         break;
      case 65:
         ex=quit_fun();
         if(ex=='y')
            return;
         else
            goto p2a2;
         break;

      case 9:
         return;
      case 1:
         ex=fun_converter(1);
         break;
      case 2:
         ex=fun_converter(2);
         break;
      case 3:
         ex=fun_converter(3);
         break;
      case 4:
         ex=fun_converter(4);
         break;
      default:
         printf("\n\t!!! enter the correct choice ___ !!!!");
         fun(1);
         goto p2a2;
         break;
   }
   if(ex=='s')
   {
      goto p2a2;
   }
   return 0;
}


int fun_QUAD()
{

   initiate :;

   static int ab2=1;
   if(ab2==1)
      fun_describe_p2a3();
   else
      fun(0);
   ab2=0; ;
   printf("\n\n\t\t\t Solving Quadratic Equation\n\n");
   printf("\n\n\t\t Quadratic equation is of the form : \n");
   printf("\n\n\t\t\t\t ax^2 + bx + c = 0 ; a != 0");
   float a,b,c;
   printf("\n\n\t\t\t\t\t  a : ");
   scanf("%f",&a);
   if(a==0)
   {
      fun(0);
      printf("\n\n\t\t\t\t ax^2 + bx + c = 0 ; a != 0");
      printf("\n\n\t\t\t\t a can't be zero in a quadratic equation .");
      fun(1);
      goto initiate;
   }
   printf("\n\n\t\t\t\t\t  b : ");
   scanf("%f",&b);
   printf("\n\n\t\t\t\t\t  c : ");
   scanf("%f",&c);
   float D,x1,x2;
   D=b*b-4*a*c;
   if(D>0)
   {
      x1 = (-b + pow(D,0.5))/(2*a);
      x2 = (-b - pow(D,0.5))/(2*a);
   }
   else if(D==0)
   {
      x1 = (-b)/(2*a);
      x2=x1;
   }
   else
   {
      //printf("\n\n\t\t\t\t\t No real solution");
      x1 = (-b)/(2*a);
      x2 = (pow(-D,0.5))/2*a;
      printf("\n\n\t\t\t\t\t >> x1 : %.2f + i(%.2f)",x1,x2);
      printf("\n\n\t\t\t\t\t >> x2 : %.2f - i(%.2f)",x1,x2);
      goto options;
   }

   printf("\n\n\t\t\t\t\t >> x1 : %.2f",x1);

   printf("\n\n\t\t\t\t\t >> x2 : %.2f",x2);
   options : ;
   printf("\n\n\t Option : ");
   char ch;
   ch = getch();
   if(ch=='q')
   {
      ch=quit_fun();
      if(ch=='y')
         return;
   }
   else
      goto initiate;
   return;
}
