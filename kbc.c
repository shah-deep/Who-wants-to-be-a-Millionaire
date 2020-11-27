#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>

				//GLOBAL DECLARATION
int login();
void showscore(int);
void header();
void showrules();
void signup();
void correct();
void choosemode();
void printlowerdiamond();
void printupperdiamond();
void printlowercircle();
void printuppercircle();
void qset1();
void qset2();
void qset3();

struct contestant
{
	char name[25];
	char username[25];
	char pwd[25];
	int age;
}d;

struct leaderboard
{
	char uname[25];
	int price;
} c;

int q1, lifeline;

int main()
{
	int n,p=0;
	p1:
	printf("********************************************************************************\n");
	printf("\t\t$$$  Kaun Banega Crorepati  $$$\n");
	printf("********************************************************************************\n");
	printf("\n\t\t\t1.Login\n\t\t\t2.Sign up\n\t\tPlease enter your choice:-");
	fflush(stdin);
	scanf("%d",&n);
	system("cls");
	switch(n)
	{
		case 1:
                {printf("\n\n\n\n");
				p=1;
				login();
				break;}
		case 2:
                {printf("\n\n\n\n");
                p=1;
				signup();
				break;}
		default:
		    {
		      	printf("Please enter correct data.");
		      	system("cls");
		      	goto p1;

		    }

	}
	if(p==0)
	goto p1;
	else if (p==1)
	{
	system("cls");
	showrules();
	system("cls");
	header();
	mainmenu();
    }
	return 0;


}

void header()
{
     system("cls");
    printf("\t\t");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
     printf("\t\t");

    printf("**********************************************************\n\n");
 printf("\t\t");
    printf("\t$$$$                 KBC Quiz                 $$$$\n\n \t\t\t\tUSER NAME :: \" %s\"\n\n",d.username);
     printf("\t\t");
    printf("***********************************************************\n\n");
     printf("\t\t");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

}

void showrules()
{
    header();
    printf("\n\t\t************Before we Start The Game**************\n\n\t\t********* Read The Following Rules And Regulations-*********\n\n");
    printf("\n\n\t\t1. Game is divided into three levels:\n\t\t1.Easy\t\t\t2.Medium\t\t\t3.Hard  \n");
    printf("\n\n\t\t2. Each level contains 10 questions which you\n\t\t have to answer one by one .\n");
    printf("\n\t\t3. Each question has a fixed prize money starting from\n\t\t Rs. 10,000 to Rs. 1 Crore which will increase depending \n\t\tupon toughness of the question.\n");
    printf("\n\t\t4.Each correct answer will take you to a higher question\n\t\t and you will earn some money .\n");
    printf("\n\t\t5. If you will give a wrong answer you will fall down\n\t\t to level's starting point and loose your earned money.\n");
    printf("\n\t\t6. You may use  two Life Lines during your game:\n\t\t 1.50-50(two incorrect options will get vanished)\n\t\t 2.Expert Advice:(you can take help from the expert.)\n ");
    printf("\n\t\t7.You may quit the game anytime .");
    getch();
}

void signup()
{
	FILE *fp,*fp1;
	fp=fopen("b.txt","ab");
	fp1=fopen("p.txt","a");
	printf("Enter your name:-\t");
	scanf("%s",d.name);
	printf("Enter your username:-\t");
	fflush(stdin);
	scanf("%s",d.username);
	strcpy(c.uname,d.username);
	fprintf(fp1,"%s ",c.uname);
	printf("Enter your password:-\t");
	fflush(stdin);
	scanf("%s",d.pwd);
	printf("Enter your age:-     \t");
	scanf("%d",&d.age);
	fwrite(&d,sizeof(d),1,fp);
	fclose(fp);
	fclose(fp1);
}

int login()
{
	char u[25],pw[25];
	FILE *fp;
	fp=fopen("b.txt","rb");
	printf("\t\tUsername:-  ");
	scanf("%s",u);
	printf("\t\tPassword:-  ");
	fflush(stdin);
	scanf("%s",pw);
	while(!feof(fp))
    {fread(&d,sizeof(d),1,fp);
	if((strcmp(d.username,u)==0)&&(strcmp(d.pwd,pw)==0))
        {printf("You are successfully logged in.....\n");
		getch();
        return 1;}
    }
	fclose(fp);
	printf("\n\t\tPlease enter valid username or password.");
	getch();
	system("cls");
	main();
	return 0;
}

void showscore(int a)
{
	FILE *fp;
	fp=fopen("p.txt","a");
	if(q1==1 &&a)
	{
		printf("Congratulations!!!\nYou have won %d.",10000);
		c.price=10000;
		getch();
	}
	else if(q1==1 &&a==0)

	{
		printf("Better Luck.....\nYou haven't won any rupees..");
		c.price=0;
		fprintf(fp,"%d\n",c.price);
		getch();
	}
	else if(q1==2 &&a)
	{
		printf("Congratulations!!!\nYou have won %d.",80000);
		c.price=80000;
		getch();
	}
	else if(q1==2 &&a==0)
	{
		printf("Better Luck.....\nYou haven't win any rupees..");
		c.price=0;
		fprintf(fp,"%d\n",c.price);
		getch();
	}
	else if(q1==3 &&a)
	{
		printf("Congratulations!!!\nYou have won %d.",160000);
		c.price=160000;
		getch();
	}
	else if(q1==3 &&a==0)
	{
		printf("Better Luck.....\nYou haven't win any rupees..");
		c.price=0;
		fprintf(fp,"%d\n",c.price);
	}
	else if(q1==4 &&a)
	{
		printf("Congratulations!!!\nYou have won Rs.2,50,000");
		printf("\nCongo!!!!!!You have cleared first part of this quiz. In your account Rs.2,50,000 is transferred.");
		c.price=250000;
		getch();
		cheque(c.price);
	}
	else if(q1==4 &&a==0)
	{
		printf("Better Luck.....\nBut you won 250000 Rupees..");
		c.price=250000;
		fprintf(fp,"%d\n",c.price);
		getch();
		cheque(c.price);
	}
	else if(q1==5 &&a)
	{
		printf("Congratulations!!!\nYou have won %d.",320000);
		c.price=320000;
        getch();
	}
	else if(q1==5 &&a==0)
	{
		printf("Better Luck.....\nBut You won Rs.250000");
		c.price=250000;
		fprintf(fp,"%d\n",c.price);
		getch();
		cheque(c.price);
	}
	else if(q1==6 &a)
	{
		printf("Congratulations!!!\nYou have won %d.",640000);
		c.price=640000;
        getch();
	}
	else if(q1==6 &a==0)
	{
		printf("Better Luck.....\nBut You won Rs.250000");
		c.price=250000;
		fprintf(fp,"%d\n",c.price);
		getch();
		cheque(c.price);
	}
	else if(q1==7 &&a)
	{
	    printf("Congo!!!You had also cleared second part of this quiz....");
		printf("Congratulations!!!\nYou have won %d.",1250000);
		c.price=1250000;
		getch();
        cheque(c.price);
	}
	else if(q1==7 &&a==0)
	{
		printf("Better Luck.....\nBut You won Rs.250000");
		c.price=250000;
		fprintf(fp,"%d\n",c.price);
		getch();
		cheque(c.price);
	}
	else if(q1==8 &&a)
	{
		printf("Congratulations!!!\nYou have won %d.",2500000);
		c.price=2500000;
        getch();
	}
	else if(q1==8 &&a==0)
	{
		printf("Better Luck.....\nBut You won Rs.1250000");
		c.price=1250000;
		fprintf(fp,"%d\n",c.price);
		getch();
		cheque(c.price);
	}
	else if(q1==9 &&a)
	{
		printf("Congratulations!!!\nYou have won %d.",500000);
		c.price=500000;
		getch();
	}
	else if(q1==9 &&a==0)
	{
		printf("Better Luck.....\nBut You won Rs.1250000");
		c.price=1250000;
		fprintf(fp,"%d\n",c.price);
		getch();
		cheque(c.price);
	}
	else if(q1==10 &&a)
	{
		printf("Congratulations!!!\nYou have won Rs.%d.",1000000);
		printf("\n\t\tYOU ARE A MILLIONAIRE!!");
		c.price=1000000;
		fprintf(fp,"%d\n",c.price);
		getch();
		cheque(c.price);
	}
	else if(q1==10 &&a==0)
	{
		printf("Better Luck.....\n But You won 1250000 Rupees.");
		c.price=1250000;
		fprintf(fp,"%d\n",c.price);
		getch();
		cheque(c.price);
	}


}

void cheque(int a)
{
system("cls");
printf("\n\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
printf("\t$                             *                                     $\n");
printf("\t$                           ****                                    $\n");
printf("\t$                         ********                                  $\n");
printf("\t$                       ************                                $\n");
printf("\t$                   ****AXIS   BANK****           Date :12/11/18    $\n");
printf("\t$                                                                   $\n");
printf("\t$   PAY:   Mr  Username          %s              OR ORDER         $\n",d.username);
printf("\t$                                                                   $\n");
printf("\t$                                                                   $\n");
printf("\t$   RUPEES   %d                                                 $\n",a);
printf("\t$                                                                   $\n");
printf("\t$   A/C No:3246634582652    A/C Payee : _________________           $\n");
printf("\t$                                                                   $\n");
printf("\t$                                                                   $\n");
printf("\t$  [MULTY CITY CHEQUE: Payable at par at All branches of AB ]       $\n");
printf("\t$                                                                   $\n");
printf("\t$                                          __________________       $\n");
printf("\t$                                          Please sign above        $\n");
printf("\t$              *950020*   *695002032*: 002060*                      $\n");
printf("\t$                                                                   $\n");
printf("\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
                   Beep(1000,400);
                   Beep(500,400);
                   Beep(1200,400);
                   printf("\n\n\t\t\tPress any key to continue......");
                   getch();
}

void mainmenu()
{
    while (1)

    {
    	system("cls");
        int choise;

        header();
        printf("\n\n\t\t\t\t\t*** MAIN MENU ***");
        printf("\n\n\t\t\t\t\t1. Start Game");
        printf("\n\t\t\t\t\t2. Rules");
        printf("\n\t\t\t\t\t3. About the Game");
        printf("\n\t\t\t\t\t4. Log out User");
        printf("\n\t\t\t\t\t5. Exit");


        printf("\n\n\t\t\t\t\tEnter your choice >>>");
        fflush(stdin);
        scanf("%d",&choise);
		system("cls");
        switch(choise)
        {
             case 1:
                  choosemode();
                  break;

               case 2:
                   showrules();
                   printf("\n\n\t\t\t\t<<<Press any key for main menu >>>");
                   getch();
                   break;

               case 3:
                aboutgame();
                break;

               case 4:
                   main();

               case 5:
                    exit(0);

               default:
                    printf("\nEnter any valid choice");
                    getch();
                    fflush(stdin);

        }

     }
}

void choosemode()
{
                   system("cls");
                   printf("\n\n\t\t\t\t  CHOOSE MODE: !");
                   printf("\n\n\t\t\t\t  1. Easy  ");
                   printf("\n\n\t\t\t\t  2. Medium ");
                   printf("\n\n\t\t\t\t  3. Hard ");
                   printf("\n\n\t\t\t\t\tEnter your choice >>> ");
                   int setnumber;
                   fflush(stdin);
                   scanf("%d",&setnumber);
                   lifeline=2;
                   switch(setnumber)
                        {
                            case 1:
                            printf("\n\n\t\t\t\t  BEST OF LUCK !");
                            printf("\n\n\t\t\t\t<<<Press any key to begin the game>>>");
                            getch();
                            qset1();
                            break;

                            case 2:
                            printf("\n\n\t\t\t\t  BEST OF LUCK !");
                            printf("\n\n\t\t\t\t<<<Press any key to begin the game>>>");
                            getch();
                            qset2();
                            break;

                            case 3:
                            printf("\n\n\t\t\t\t  BEST OF LUCK !");
                            printf("\n\n\t\t\t\t<<<Press any key to begin the game>>>");
                            getch();
                            qset3();
                            break;

                            default:
                            printf("\nChoose correct Mode");
                            getch();
                            choosemode();
                            fflush(stdin);
                        }

}

void aboutgame()
{
    header();
    printf("\n\n\t\t\t\t\t*** ABOUT THE GAME***");
    printf("\n\n\n\t\tKaun Banega Crorepati ");
    printf("\n\n\n\t\tMade in C language");
    printf("\n\n\n\t\tBy: ");
    printf("\n\t\tDeep Shah (IIIT Vadodara)");
  getch();
}

void printlowerDiamond()
{

     int n=10,i,j,space=9;
     printf("\t\t\t\t");
    for ( i = n; i > 0; i--)
    {
        printf("\t\t\t");
        for (j = 0; j < space; j++)
            printf(" ");


        for ( j = 0;j < i;j++)
            printf("* ");

        printf("\n");
        space++;
    }
}

void printupperDiamond()
{
    int n=10,i,j;
    int space = n - 1;


    for (i = 0; i < n; i++)
    {
        printf("\t\t\t\t");
        for (j = 0;j < space; j++)
            printf(" ");


        for (j = 0;j <= i; j++)
            printf("* ");

        printf("\n");
        space--;
    }
}

void printlowercircle()
{

     int n=10,i,j,space=9;
     printf("\t\t\t");
    for ( i = n; i > 0; i--)
    {
        printf("\t\t\t");
        for (j = 0; j < space; j++)
            printf(" ");


        for (j = 0;j < i;j++)
            printf("O ");

        printf("\n");
        space++;
    }
}

void printuppercircle()
{
    int n=10;int i,j;
    int space = n - 1;


    for (i = 0; i < n; i++)
     {
        printf("\t\t\t\t");
        for (j = 0;j < space; j++)
            printf(" ");


        for (j = 0;j <= i; j++)
            printf("O ");

        printf("\n");
        space--;
    }
}


void correct()
{
     system("cls");
        printupperDiamond();
        printf("\t\t*************Congratulations!!!***********  \n\n\t\t\t\t You got it Right.");
        printlowerDiamond();

            Beep(500,500);
           Beep(1000,500);
           Beep(1500,500);
            showscore(1);
    }

void wrong()
{
    	system("cls");
	 printuppercircle();
      printf("\t\t*************OOOOPPSS!!!***********  \n\n\t\t\t\t That was a Wrong Answer.");
      printlowercircle() ;
       Beep(5000,500);
         Beep(4500,500);
           Beep(3500,500);
        showscore(0);
        printf("\n\n\t\t\t\t Press any key for Main menu >> ");
        getch();
       mainmenu();

    }

void quit ()
{
		FILE *fp1;
		fp1=fopen("p.txt","w");
        header();
        printf("\n\n \t\t\tYou just quit the game");
        printf("\n\n \t\t\tYOU HAVE WON ");
        printf("%d Rupees ",c.price);
        if(c.price>=10000)
        cheque(c.price);
        fprintf(fp1,"%d\n",c.price);
        fclose(fp1);
        printf("\n\n\t\t\t\t Press any key for Main menu >> ");
       getch();
       mainmenu();

}



/*
 ANSWERS:
 Q1: A
 Q2: C
 Q3: C
 Q4: D
 Q5: B
 Q6: C
 Q7: B
 Q8: A
 Q9: A
Q10: D
*/


void qset1()
{
    char q, l;
     /*  QUESTION 1 */
		q1=1;
        q111:
        header();
        printf("\n Question no 1");
        printf("\t\t\t\t\t\t\t\t\t\tRS.10,000/-");
        printf("\n\n\t\t\tWho is popularly known as 'Father of Indian Cinema'?");
        printf("\n\n\t\t\t\tA. Dadasaheb Phalke");
        printf("\n\t\t\t\tB. V. Shantaram");
        printf("\n\t\t\t\tC. Ardeshir Irani");
        printf("\n\t\t\t\tD. Kidar Sharma");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q110:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q112;
                break;

            case 'B':
                goto q113;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q110;
            }

          q112:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 1    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.10,000/-");
        printf("\n\n\t\t\tWho is popularly known as 'Father of Indian Cinema'?");
        printf("\n\n\t\t\t\tA. Dadasaheb Phalke");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Kidar Sharma");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'D' :
        wrong();
        break;
        case 'E':
        goto q113;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q112;
       }
       break;
        }

     q113:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 1    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.10,000/-");
        printf("\n\n\t\t\tWho is popularly known as 'Father of Indian Cinema'?");
        printf("\n\n\t\t\t\tA. Dadasaheb Phalke");
        printf("\n\t\t\t\tB. V. Shantaram");
        printf("\n\t\t\t\tC. Ardeshir Irani");
        printf("\n\t\t\t\tD. Kidar Sharma");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA. Dadasaheb Phalke");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q112;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q113;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q111;

       }

       }

        /*  QUESTION 2 */

                q121:
        header();
        q1=2;
        printf("\n Question no 2");
        printf("\t\t\t\t\t\t\t\t\t\tRS.80,000/-");
        printf("\n\n\t\t\tWhat is the age limit for the athletes participating in the Youth Olympic Games?");
        printf("\n\n\t\t\t\tA. 14 to 20");
        printf("\n\t\t\t\tB. 15 to 22");
        printf("\n\t\t\t\tC. 14 to 18");
        printf("\n\t\t\t\tD. 16 to 25");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q120:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q122;
                break;

            case 'B':
                goto q123;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q120;
            }

          q122:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 2    You are using life line 50:50");
        printf("\t\t\t\t\t\t\t\t\t\tRS.80,000/-");
        printf("\n\n\t\t\tWhat is the age limit for the athletes participating in the Youth Olympic Games?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\tB. 15 to 22");
        printf("\n\t\t\t\tC. 14 to 18");
        printf("\n\t\t\t\t");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :
        wrong();
        break;
        case 'E':
        goto q123;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q122;
       }
       break;
        }

     q123:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 2    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.80,000/-");
        printf("\n\n\t\t\tWhat is the age limit for the athletes participating in the Youth Olympic Games?");
        printf("\n\n\t\t\t\tA. 14 to 20");
        printf("\n\t\t\t\tB. 15 to 22");
        printf("\n\t\t\t\tC. 14 to 18");
        printf("\n\t\t\t\tD. 16 to 25");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. 14 to 18");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q122;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q123;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q121;

       }

       }


   /*  QUESTION 3 */

        q131:
        header();
		q1=3;
        printf("\n Question no 3");
        printf("\t\t\t\t\t\t\t\t\t\tRS.1,60,000/-");
        printf("\n\n\t\t\tWhat is the name for the mapped hexagonal geographic areas that make up the cellular phone grid?");
        printf("\n\n\t\t\t\tA. Hexagrids");
        printf("\n\t\t\t\tB. Pins");
        printf("\n\t\t\t\tC. Cells");
        printf("\n\t\t\t\tD. Containers");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q130:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q132;
                break;

            case 'B':
                goto q133;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q130;
            }

          q132:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 1    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.1,60,000/-");
        printf("\n\n\t\t\tWhat is the name for the mapped hexagonal geographic areas that make up the cellular phone grid?");
        printf("\n\n\t\t\t\tA. Hexagrids");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tC. Cells");
        printf("\n\t\t\t\t");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'A' :
        wrong();
        break;
        case 'E':
        goto q133;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q132;
       }
       break;
        }

     q133:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 3    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.1,60,000/-");
        printf("\n\n\t\t\tWhat is the name for the mapped hexagonal geographic areas that make up the cellular phone grid?");
        printf("\n\n\t\t\t\tA. Hexagrids");
        printf("\n\t\t\t\tB. Pins");
        printf("\n\t\t\t\tC. Cells");
        printf("\n\t\t\t\tD. Containers");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. Cells");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q132;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q133;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q131;

       }

       }


        /*  QUESTION 4 */

                q141:
        header();
        q1=4;
        printf("\n Question no 4");
        printf("\t\t\t\t\t\t\t\t\t\tRS.2,50,000/-");
        printf("\n\n\t\t\tWho is the only leader to be selected Prime Minister of Pakistan three times ??");
        printf("\n\n\t\t\t\tA. Syed Yousaf Raza Gillani");
        printf("\n\t\t\t\tB. Benazir Bhutto");
        printf("\n\t\t\t\tC. Liaqat Ali Khan");
        printf("\n\t\t\t\tD. Nawaz Sharif ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'B' :case 'C' :case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q140:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q142;
                break;

            case 'B':
                goto q143;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q140;
            }

          q142:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 4    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.2,50,000/-");
        printf("\n\n\t\t\tWho is the only leader to be selected Prime Minister of Pakistan three times ??");
        printf("\n\n\t\t\t\tA. Syed Yousaf Raza Gillani");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Nawaz Sharif ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'D':
        correct();
        break;
        case 'A' :
        wrong();
        break;
        case 'E':
        goto q143;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q142;
       }
       break;
        }

     q143:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 4    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.2,50,000/-");
        printf("\n\n\t\t\tWho is the only leader to be selected Prime Minister of Pakistan three times ??");
        printf("\n\n\t\t\t\tA. Syed Yousaf Raza Gillani");
        printf("\n\t\t\t\tB. Benazir Bhutto");
        printf("\n\t\t\t\tC. Liaqat Ali Khan");
        printf("\n\t\t\t\tD. Nawaz Sharif ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tD. Nawaz Sharif ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'D':
        correct();
        break;
        case 'B' :case 'C' :case 'A' :
        wrong();
        break;
        case 'E':
        goto q142;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q143;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q141;

       }

       }


        /*  QUESTION 5 */
        q151:
        header();
        q1=5;
        printf("\n Question no 5");
        printf("\t\t\t\t\t\t\t\t\t\tRS.3,20,000/-");
        printf("\n\n\t\t\tWhich was the first telephone company to create a handheld mobile phone");
        printf("\n\n\t\t\t\tA. Apple");
        printf("\n\t\t\t\tB. Motorola");
        printf("\n\t\t\t\tC. Nokia");
        printf("\n\t\t\t\tD. Samsung ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q150:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q152;
                break;

            case 'B':
                goto q153;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q150;
            }

          q152:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 5    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.3,20,000/-");
        printf("\n\n\t\t\tWhich was the first telephone company to create a handheld mobile phone");
        printf("\n\n\t\t\t\tA. Apple");
        printf("\n\t\t\t\tB. Motorola");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :
        wrong();
        break;
        case 'E':
        goto q153;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q152;
       }
       break;
        }

     q153:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 5    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.3,20,000/-");
        printf("\n\n\t\t\tWhich was the first telephone company to create a handheld mobile phone");
        printf("\n\n\t\t\t\tA. Apple");
        printf("\n\t\t\t\tB. Motorola");
        printf("\n\t\t\t\tC. Nokia");
        printf("\n\t\t\t\tD. Samsung ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tB. Motorola");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'C' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q152;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q153;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q151;

       }

       }


         /*  QUESTION 6 */
        q161:
        header();
        q1=6;
        printf("\n Question no 6");
        printf("\t\t\t\t\t\t\t\t\t\tRS.6,40,000/-");
        printf("\n\n\t\t\tIn 2012, which of these countries has been removed by WHO from the polioendemic countries ?");
        printf("\n\n\t\t\t\tA. Pakistan ");
        printf("\n\t\t\t\tB. Nigeria ");
        printf("\n\t\t\t\tC. India ");
        printf("\n\t\t\t\tD. Afghanistan  ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q160:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q162;
                break;

            case 'B':
                goto q163;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q160;
            }

          q162:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 6    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.6,40,000/-");
        printf("\n\n\t\t\tIn 2012, which of these countries has been removed by WHO from the polioendemic countries ?");
        printf("\n\n\t\t\t\t ");
        printf("\n\t\t\t\tB. Nigeria ");
        printf("\n\t\t\t\tC. India ");
        printf("\n\t\t\t\t ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :
        wrong();
        break;
        case 'E':
        goto q163;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q162;
       }
       break;
        }

     q163:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 6    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.6,40,000/-");
        printf("\n\n\t\t\tIn 2012, which of these countries has been removed by WHO from the polioendemic countries ?");
        printf("\n\n\t\t\t\tA. Pakistan ");
        printf("\n\t\t\t\tB. Nigeria ");
        printf("\n\t\t\t\tC. India ");
        printf("\n\t\t\t\tD. Afghanistan  ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. India ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q162;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q163;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q161;

       }

       }


         /*  QUESTION 7 */

        q171:
        header();
        q1=7;
        printf("\n Question no 7");
        printf("\t\t\t\t\t\t\t\t\t\tRS.12,50,000/-");
        printf("\n\n\t\t\tWhich of these personalities has also served as Deputy Prime Minister of India ? ?");
        printf("\n\n\t\t\t\tA. Lal Bahadur Shastri  ");
        printf("\n\t\t\t\tB. L K Advani  ");
        printf("\n\t\t\t\tC. Gulzarilal Nanda");
        printf("\n\t\t\t\tD. Arjun Singh ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q170:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q172;
                break;

            case 'B':
                goto q173;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q170;
            }

          q172:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 7    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.12,50,000/-");
        printf("\n\n\t\t\tWhich of these personalities has also served as Deputy Prime Minister of India ? ?");
        printf("\n\n\t\t\t\tA. Lal Bahadur Shastri  ");
        printf("\n\t\t\t\tB. L K Advani  ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :
        wrong();
        break;
        case 'E':
        goto q173;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q172;
       }
       break;
        }

     q173:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 7    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.12,50,000/-");
        printf("\n\n\t\t\tWhich of these personalities has also served as Deputy Prime Minister of India ? ?");
        printf("\n\n\t\t\t\tA. Lal Bahadur Shastri  ");
        printf("\n\t\t\t\tB. L K Advani  ");
        printf("\n\t\t\t\tC. Gulzarilal Nanda");
        printf("\n\t\t\t\tD. Arjun Singh ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tB. L K Advani  ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'C' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q172;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q173;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q171;

       }

       }


          /*  QUESTION 8 */

        q181:
        header();
        q1=8;
        printf("\n Question no 8");
        printf("\t\t\t\t\t\t\t\t\t\tRS.25,00,000/-");
        printf("\n\n\t\t\tWho among these conquerors was the first to invade India ?");
        printf("\n\n\t\t\t\tA. Timur  ");
        printf("\n\t\t\t\tB. Nadir Shah  ");
        printf("\n\t\t\t\tC. Ahmad Shah Durrani");
        printf("\n\t\t\t\tD. Babur ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q180:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q182;
                break;

            case 'B':
                goto q183;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q180;
            }

          q182:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 8    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.25,00,000/-");
        printf("\n\n\t\t\tWho among these conquerors was the first to invade India ?");
        printf("\n\n\t\t\t\tA. Timur  ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Babur ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'D' :
        wrong();
        break;
        case 'E':
        goto q183;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q182;
       }
       break;
        }

     q183:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 8    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.25,00,000/-");
        printf("\n\n\t\t\tWho among these conquerors was the first to invade India ?");
        printf("\n\n\t\t\t\tA. Timur  ");
        printf("\n\t\t\t\tB. Nadir Shah  ");
        printf("\n\t\t\t\tC. Ahmad Shah Durrani");
        printf("\n\t\t\t\tD. Babur ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA. Timur  ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q182;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q183;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q181;

       }

       }


           /*  QUESTION 9 */
        q191:
        header();
        q1=9;
        printf("\n Question no 9");
        printf("\t\t\t\t\t\t\t\t\t\tRS.50,00,000/-");
        printf("\n\n\t\t\t What part of the body is normally cut open during an appendix operation?");
        printf("\n\n\t\t\t\tA. Abdomen  ");
        printf("\n\t\t\t\tB. Chest  ");
        printf("\n\t\t\t\tC. Head");
        printf("\n\t\t\t\tD. Neck");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q190:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q192;
                break;

            case 'B':
                goto q193;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q190;
            }

          q192:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 9    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.50,00,000/-");
        printf("\n\n\t\t\t What part of the body is normally cut open during an appendix operation?");
        printf("\n\n\t\t\t\tA. Abdomen  ");
        printf("\n\t\t\t\t  ");
        printf("\n\t\t\t\tC. Head");
        printf("\n\t\t\t\t");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'C' :
        wrong();
        break;
        case 'E':
        goto q193;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q192;
       }
       break;
        }

     q193:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 9    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.50,00,000/-");
        printf("\n\n\t\t\t What part of the body is normally cut open during an appendix operation?");
        printf("\n\n\t\t\t\tA. Abdomen  ");
        printf("\n\t\t\t\tB. Chest  ");
        printf("\n\t\t\t\tC. Head");
        printf("\n\t\t\t\tD. Neck");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA. Abdomen ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q192;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q193;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q191;

       }

       }



      /*  QUESTION 10*/

        q1101:
        header();
        q1=10;
        printf("\n Question no 10");
        printf("\t\t\t\t\t\t\t\t\t\tRS. 1 CRORE/-");
        printf("\n\n\t\t\t What was the largest social network prior to Facebook??");
        printf("\n\n\t\t\t\tA. LetsBeFriends  ");
        printf("\n\t\t\t\tB. Google+  ");
        printf("\n\t\t\t\tC.Friendster");
        printf("\n\t\t\t\tD. MySpace");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'B' :case 'C' :case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q1100:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q1102;
                break;

            case 'B':
                goto q1103;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q1100;
            }

          q1102:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 10    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS. 1 CRORE/-");
        printf("\n\n\t\t\t What was the largest social network prior to Facebook??");
        printf("\n\n\t\t\t\t ");
        printf("\n\t\t\t\t ");
        printf("\n\t\t\t\tC.Friendster");
        printf("\n\t\t\t\tD. MySpace");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'D':
        correct();
        break;
        case 'A' :
        wrong();
        break;
        case 'E':
        goto q1103;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q1102;
       }
       break;
        }

     q1103:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 10    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS. 1 CRORE/-");
        printf("\n\n\t\t\t What was the largest social network prior to Facebook??");
        printf("\n\n\t\t\t\tA. LetsBeFriends  ");
        printf("\n\t\t\t\tB. Google+  ");
        printf("\n\t\t\t\tC.Friendster");
        printf("\n\t\t\t\tD. MySpace");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tD. MySpace");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'D':
        correct();
        break;
        case 'B' :case 'C' :case 'A' :
        wrong();
        break;
        case 'E':
        goto q1102;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q1103;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1101;

       }

       }
return;
}

void qset2()
{
    char q, l;
     /*  QUESTION 1 */
		q1=1;
        q111:
        header();
        printf("\n Question no 1");
        printf("\t\t\t\t\t\t\t\t\t\tRS.10,000/-");
        printf("\n\n\t\t\tWhich was the last movie directed by Yash Chopra?");
        printf("\n\n\t\t\t\tA. Jab Tak Hai Jaan");
        printf("\n\t\t\t\tB. Rab Ne Bana Di Jodi");
        printf("\n\t\t\t\tC. Veer Zara");
        printf("\n\t\t\t\tD. Ek Tha Tiger");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q110:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q112;
                break;

            case 'B':
                goto q113;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q110;
            }

          q112:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 1    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.10,000/-");
        printf("\n\n\t\t\tWhich was the last movie directed by Yash Chopra?");
        printf("\n\n\t\t\t\tA. Jab Tak Hai Jaan");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tC. Veer Zara");
        printf("\n\t\t\t\t");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'C' :
        wrong();
        break;
        case 'E':
        goto q113;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q112;
       }
       break;
        }

     q113:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 1    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.10,000/-");
        printf("\n\n\t\t\tWhich was the last movie directed by Yash Chopra?");
        printf("\n\n\t\t\t\tA. Jab Tak Hai Jaan");
        printf("\n\t\t\t\tB. Rab Ne Bana Di Jodi");
        printf("\n\t\t\t\tC. Veer Zara");
        printf("\n\t\t\t\tD. Ek Tha Tiger");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA. Jab Tak Hai Jaan");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q112;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q113;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q111;

       }

       }

        /*  QUESTION 2 */

                q121:
        header();
        q1=2;
        printf("\n Question no 2");
        printf("\t\t\t\t\t\t\t\t\t\tRS.80,000/-");
        printf("\n\n\t\t\tWho has been India's longest serving woman Chief Minister ?");
        printf("\n\n\t\t\t\tA. Vasundhara Raje");
        printf("\n\t\t\t\tB. Jayalalita");
        printf("\n\t\t\t\tC. Sheila Dixit ");
        printf("\n\t\t\t\tD. Mayavati");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q120:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q122;
                break;

            case 'B':
                goto q123;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q120;
            }

          q122:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 2    You are using life line 50:50");
        printf("\t\t\t\t\t\t\t\t\t\tRS.80,000/-");
        printf("\n\n\t\t\tWho has been India's longest serving woman Chief Minister ?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\tB. Jayalalita");
        printf("\n\t\t\t\tC. Sheila Dixit ");
        printf("\n\t\t\t\t");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :
        wrong();
        break;
        case 'E':
        goto q123;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q122;
       }
       break;
        }

     q123:
         {
          lifeline=lifeline-1;
          header();

        printf("\n Question no 2    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.80,000/-");
        printf("\n\n\t\t\tWho has been India's longest serving woman Chief Minister ?");
        printf("\n\n\t\t\t\tA. Vasundhara Raje");
        printf("\n\t\t\t\tB. Jayalalita");
        printf("\n\t\t\t\tC. Sheila Dixit ");
        printf("\n\t\t\t\tD. Mayavati");


        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. Sheila Dixit ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q122;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q123;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q121;

       }

       }


   /*  QUESTION 3 */

        q131:
        header();
		q1=3;
        printf("\n Question no 3");
        printf("\t\t\t\t\t\t\t\t\t\tRS.1,60,000/-");
        printf("\n\n\t\t\tWho won the first nobel prize from India");
        printf("\n\n\t\t\t\tA. Mahatma Gandhi");
        printf("\n\t\t\t\tB. Rabindra Naath Tagore");
        printf("\n\t\t\t\tC. C V Raman");
        printf("\n\t\t\t\tD. Mother Teresa");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q130:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q132;
                break;

            case 'B':
                goto q133;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q130;
            }

          q132:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 1    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.1,60,000/-");
        printf("\n\n\t\t\tWho won the first nobel prize from India");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\tB. Rabindra Naath Tagore");
        printf("\n\t\t\t\tC. C V Raman");
        printf("\n\t\t\t\t");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :
        wrong();
        break;
        case 'E':
        goto q133;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q132;
       }
       break;
        }

     q133:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 3    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.1,60,000/-");
        printf("\n\n\t\t\tWho won the first nobel prize from India");
        printf("\n\n\t\t\t\tA. Mahatma Gandhi");
        printf("\n\t\t\t\tB. Rabindra Naath Tagore");
        printf("\n\t\t\t\tC. C V Raman");
        printf("\n\t\t\t\tD. Mother Teresa");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. C V Raman");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q132;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q133;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q131;

       }

       }


        /*  QUESTION 4 */

                q141:
        header();
        q1=4;
        printf("\n Question no 4");
        printf("\t\t\t\t\t\t\t\t\t\tRS.2,50,000/-");
        printf("\n\n\t\t\t.Olympic games 2008 were held in which  of the following places?");
        printf("\n\n\t\t\t\tA. London");
        printf("\n\t\t\t\tB. Brazil");
        printf("\n\t\t\t\tC. Athenes");
        printf("\n\t\t\t\tD. Beijing ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'B' :case 'C' :case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q140:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q142;
                break;

            case 'B':
                goto q143;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q140;
            }

          q142:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 4    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.2,50,000/-");
        printf("\n\n\t\t\t.Olympic games 2008 were held in which  of the following places?");
        printf("\n\n\t\t\t\tA. London");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Beijing ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'D':
        correct();
        break;
        case 'A' :
        wrong();
        break;
        case 'E':
        goto q143;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q142;
       }
       break;
        }

     q143:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 4    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.2,50,000/-");
        printf("\n\n\t\t\t.Olympic games 2008 were held in which  of the following places?");
        printf("\n\n\t\t\t\tA. London");
        printf("\n\t\t\t\tB. Brazil");
        printf("\n\t\t\t\tC. Athenes");
        printf("\n\t\t\t\tD. Beijing ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tD. Beijing");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'D':
        correct();
        break;
        case 'B' :case 'C' :case 'A' :
        wrong();
        break;
        case 'E':
        goto q142;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q143;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q141;

       }

       }


        /*  QUESTION 5 */
        q151:
        header();
        q1=5;
        printf("\n Question no 5");
        printf("\t\t\t\t\t\t\t\t\t\tRS.3,20,000/-");
        printf("\n\n\t\t\tWeb pages are written using");
        printf("\n\n\t\t\t\tA. FTPB");
        printf("\n\t\t\t\tB. HTML");
        printf("\n\t\t\t\tC. c++");
        printf("\n\t\t\t\tD. URL   ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q150:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q152;
                break;

            case 'B':
                goto q153;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q150;
            }

          q152:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 5    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.3,20,000/-");
        printf("\n\n\t\t\tWeb pages are written using");
        printf("\n\n\t\t\t\tA. FTPB");
        printf("\n\t\t\t\tB. HTML");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :
        wrong();
        break;
        case 'E':
        goto q153;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q152;
       }
       break;
        }

     q153:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 5    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.3,20,000/-");
        printf("\n\n\t\t\tWeb pages are written using");
        printf("\n\n\t\t\t\tA. FTPB");
        printf("\n\t\t\t\tB. HTML");
        printf("\n\t\t\t\tC. c++");
        printf("\n\t\t\t\tD. URL   ");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tB. HTML");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'C' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q152;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q153;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q151;

       }

       }


         /*  QUESTION 6 */
        q161:
        header();
        q1=6;
        printf("\n Question no 6");
        printf("\t\t\t\t\t\t\t\t\t\tRS.6,40,000/-");
        printf("\n\n\t\t\tWhich one of the following air pollution can affect blood stream leading to death ?");
        printf("\n\n\t\t\t\tA. Cadmium  ");
        printf("\n\t\t\t\tB. Asbestos dust  ");
        printf("\n\t\t\t\tC. Carbon monodioxide ");
        printf("\n\t\t\t\tD. Lead   ");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q160:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q162;
                break;

            case 'B':
                goto q163;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q160;
            }

          q162:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 6    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.6,40,000/-");
        printf("\n\n\t\t\tWhich one of the following air pollution can affect blood stream leading to death ?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\tB. Asbestos dust  ");
        printf("\n\t\t\t\tC. Carbon monodioxide ");
        printf("\n\t\t\t\t ");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :
        wrong();
        break;
        case 'E':
        goto q163;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q162;
       }
       break;
        }

     q163:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 6    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.6,40,000/-");
        printf("\n\n\t\t\tWhich one of the following air pollution can affect blood stream leading to death ?");
        printf("\n\n\t\t\t\tA.  Cadmium  ");
        printf("\n\t\t\t\tB. Asbestos dust  ");
        printf("\n\t\t\t\tC. Carbon monodioxide ");
        printf("\n\t\t\t\tD. Lead   ");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. Carbon monodioxide");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q162;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q163;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q161;

       }

       }


         /*  QUESTION 7 */

        q171:
        header();
        q1=7;
        printf("\n Question no 7");
        printf("\t\t\t\t\t\t\t\t\t\tRS.12,50,000/-");
        printf("\n\n\t\t\t Out of the given countries which got independence on 15 August 1971 ?");
        printf("\n\n\t\t\t\tA.  Congoi  ");
        printf("\n\t\t\t\tB. Bahrain   ");
        printf("\n\t\t\t\tC.  Pakistan ");
        printf("\n\t\t\t\tD. India");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q170:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q172;
                break;

            case 'B':
                goto q173;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q170;
            }

          q172:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 7    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.12,50,000/-");
        printf("\n\n\t\t\t Out of the given countries which got independence on 15 August 1971 ?");
        printf("\n\n\t\t\t\tA.  Congoi  ");
        printf("\n\t\t\t\tB. Bahrain   ");
        printf("\n\t\t\t\tC. ");
        printf("\n\t\t\t\tD. ");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :
        wrong();
        break;
        case 'E':
        goto q173;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q172;
       }
       break;
        }

     q173:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 7    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.12,50,000/-");
        printf("\n\n\t\t\t Out of the given countries which got independence on 15 August 1971 ?");
        printf("\n\n\t\t\t\tA.  Congoi  ");
        printf("\n\t\t\t\tB. Bahrain   ");
        printf("\n\t\t\t\tC.  Pakistan ");
        printf("\n\t\t\t\tD. India");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tB. Bahrain   ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'C' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q172;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q173;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q171;

       }

       }


          /*  QUESTION 8 */

        q181:
        header();
        q1=8;
        printf("\n Question no 8");
        printf("\t\t\t\t\t\t\t\t\t\tRS.25,00,000/-");
        printf("\n\n\t\t\tThe first mechanical computer designed by Charles Babbage was called what? ");
        printf("\n\n\t\t\t\tA. Analytical Engine  ");
        printf("\n\t\t\t\tB. Abacus  ");
        printf("\n\t\t\t\tC. Calculator");
        printf("\n\t\t\t\tD. Processor ");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}
        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q180:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q182;
                break;

            case 'B':
                goto q183;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q180;
            }

          q182:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 8    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.25,00,000/-");
        printf("\n\n\t\t\tThe first mechanical computer designed by Charles Babbage was called what? ");
        printf("\n\n\t\t\t\tA. Analytical Engine  ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Processor ");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'D' :
        wrong();
        break;
        case 'E':
        goto q183;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q182;
       }
       break;
        }

     q183:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 8    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.25,00,000/-");
        printf("\n\n\t\t\tThe first mechanical computer designed by Charles Babbage was called what? ");
        printf("\n\n\t\t\t\tA. Analytical Engine  ");
        printf("\n\t\t\t\tB. Abacus  ");
        printf("\n\t\t\t\tC. Calculator");
        printf("\n\t\t\t\tD. Processor ");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA. Analytical Engine ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q182;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q183;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q181;

       }

       }


           /*  QUESTION 9 */
        q191:
        header();
        q1=9;
        printf("\n Question no 9");
        printf("\t\t\t\t\t\t\t\t\t\tRS.50,00,000/-");
        printf("\n\n\t\t\t Who is the world’s second batsman to hit a double century in ODI cricket?");
        printf("\n\n\t\t\t\tA. Virendra Sehwag ");
        printf("\n\t\t\t\tB. Sachin Tendulkar  ");
        printf("\n\t\t\t\tC. Virat Kohli ");
        printf("\n\t\t\t\tD. Bryan Lara");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q190:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q192;
                break;

            case 'B':
                goto q193;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q190;
            }

          q192:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 9    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.50,00,000/-");
        printf("\n\n\t\t\t Who is the world’s second batsman to hit a double century in ODI cricket?");
        printf("\n\n\t\t\t\tA. Virendra Sehwag ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tC. Virat Kohli ");
        printf("\n\t\t\t\t");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'C' :
        wrong();
        break;
        case 'E':
        goto q193;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q192;
       }
       break;
        }

     q193:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 9    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.50,00,000/-");
        printf("\n\n\t\t\t Who is the world’s second batsman to hit a double century in ODI cricket?");
        printf("\n\n\t\t\t\tA. Virendra Sehwag ");
        printf("\n\t\t\t\tB. Sachin Tendulkar  ");
        printf("\n\t\t\t\tC. Virat Kohli ");
        printf("\n\t\t\t\tD. Bryan Lara");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA. Virendra Sehwag ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q192;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q193;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q191;

       }

       }



      /*  QUESTION 10*/

        q1101:
        header();
        q1=10;
        printf("\n Question no 10");
        printf("\t\t\t\t\t\t\t\t\t\tRS. 1 CRORE/-");
        printf("\n\n\t\t\t Where was Mughal empress Mumtaz Mahal originally buried in 1631 ?");
        printf("\n\n\t\t\t\t(A)  Agra  ");
        printf("\n\t\t\t\t(B) Burhanpur  ");
        printf("\n\t\t\t\t(C)  Gwalior");
        printf("\n\t\t\t\t(D) Lahore  ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'D' :case 'C' :case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q1100:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q1102;
                break;

            case 'B':
                goto q1103;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q1100;
            }

          q1102:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 10    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS. 1 CRORE/-");
        printf("\n\n\t\t\t Where was Mughal empress Mumtaz Mahal originally buried in 1631 ?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\t(B) Burhanpur  ");
        printf("\n\t\t\t\t(C)  Gwalior");
        printf("\n\t\t\t\t");

        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'B':
        correct();
        break;
        case 'C' :
        wrong();
        break;
        case 'E':
        goto q1103;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q1102;
       }
       break;
        }

     q1103:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 10    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS. 1 CRORE/-");
        printf("\n\n\t\t\t Where was Mughal empress Mumtaz Mahal originally buried in 1631 ?");
        printf("\n\n\t\t\t\t(A)  Agra  ");
        printf("\n\t\t\t\t(B) Burhanpur  ");
        printf("\n\t\t\t\t(C)  Gwalior");
        printf("\n\t\t\t\t(D) Lahore  ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\t(B) Burhanpur");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'B':
        correct();
        break;
        case 'D' :case 'C' :case 'A' :
        wrong();
        break;
        case 'E':
        goto q1102;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q1103;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1101;

       }

       }
return;
}

void qset3()
{
    char q, l;
     /*  QUESTION 1 */
		q1=1;
        q111:
        header();
        printf("\n Question no 1");
        printf("\t\t\t\t\t\t\t\t\t\tRS.10,000/-");
        printf("\n\n\t\t\t1.Which of these artists was principally entrusted with the task of \n\t\t\t‘illuminating’ the original document of the Constitution of India?");
        printf("\n\n\t\t\t\tA.  Nandlal Bose ");
        printf("\n\t\t\t\tB.  Ram Kinker Baij");
        printf("\n\t\t\t\tC.  Benode Behari Mukherjee");
        printf("\n\t\t\t\tD.  Abanindranath Tagore");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q110:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q112;
                break;

            case 'B':
                goto q113;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q110;
            }

          q112:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 1    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.10,000/-");
        printf("\n\n\t\t\t1.Which of these artists was principally entrusted with the task of \n\t\t\t‘illuminating’ the original document of the Constitution of India?");
        printf("\n\n\t\t\t\tA.  Nandlal Bose ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD.  Abanindranath Tagore");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'D' :
        wrong();
        break;
        case 'E':
        goto q113;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q112;
       }
       break;
        }

     q113:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 1    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.10,000/-");
        printf("\n\n\t\t\t1.Which of these artists was principally entrusted with the task of \n\t\t\t‘illuminating’ the original document of the Constitution of India?");
        printf("\n\n\t\t\t\tA.  Nandlal Bose ");
        printf("\n\t\t\t\tB.  Ram Kinker Baij");
        printf("\n\t\t\t\tC.  Benode Behari Mukherjee");
        printf("\n\t\t\t\tD.  Abanindranath Tagore");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA.  Nandlal Bose ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q112;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q113;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q111;

       }

       }

        /*  QUESTION 2 */

                q121:
        header();
        q1=2;
        printf("\n Question no 2");
        printf("\t\t\t\t\t\t\t\t\t\tRS.80,000/-");
        printf("\n\n\t\t\Whom does the Indian Constitution permit to take part in the Proceedings of Parliament?");
        printf("\n\n\t\t\t\tA. Solicitor General");
        printf("\n\t\t\t\tB. Cabinet Secretary");
        printf("\n\t\t\t\tC. Attorney General  ");
        printf("\n\t\t\t\tD. Chief Justice");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q120:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q122;
                break;

            case 'B':
                goto q123;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q120;
            }

          q122:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 2    You are using life line 50:50");
        printf("\t\t\t\t\t\t\t\t\t\tRS.80,000/-");
        printf("\n\n\t\t\Whom does the Indian Constitution permit to take part in the Proceedings of Parliament?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\tB. Cabinet Secretary");
        printf("\n\t\t\t\tC. Attorney General  ");
        printf("\n\t\t\t\t");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :
        wrong();
        break;
        case 'E':
        goto q123;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q122;
       }
       break;
        }

     q123:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 2    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.80,000/-");
        printf("\n\n\t\t\tWhom does the Indian Constitution permit to take part in the Proceedings of Parliament?");
        printf("\n\n\t\t\t\tA. Solicitor General");
        printf("\n\t\t\t\tB. Cabinet Secretary");
        printf("\n\t\t\t\tC. Attorney General  ");
        printf("\n\t\t\t\tD. Chief Justice");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. Attorney General ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q122;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q123;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q121;

       }

       }


   /*  QUESTION 3 */

        q131:
        header();
		q1=3;
        printf("\n Question no 3");
        printf("\t\t\t\t\t\t\t\t\t\tRS.1,60,000/-");
        printf("\n\n\t\t\tWhich colonial power ended its involvement in India by selling the rights of \n\t\t\tthe Nicobar Islands to the British on October 18, 1868?");
        printf("\n\n\t\t\t\tA. Belgium");
        printf("\n\t\t\t\tB. Italy");
        printf("\n\t\t\t\tC. Denmark ");
        printf("\n\t\t\t\tD. France");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q130:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q132;
                break;

            case 'B':
                goto q133;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q130;
            }

          q132:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 1    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.1,60,000/-");
        printf("\n\n\t\t\tWhich colonial power ended its involvement in India by selling the rights of \n\t\t\tthe Nicobar Islands to the British on October 18, 1868?");
        printf("\n\n\t\t\t\tA. Belgium");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tC. Denmark ");
        printf("\n\t\t\t\t");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'A' :
        wrong();
        break;
        case 'E':
        goto q133;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q132;
       }
       break;
        }

     q133:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 3    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.1,60,000/-");
        printf("\n\n\t\t\tWhich colonial power ended its involvement in India by selling the rights of \n\t\t\tthe Nicobar Islands to the British on October 18, 1868?");
        printf("\n\n\t\t\t\tA. Belgium");
        printf("\n\t\t\t\tB. Italy");
        printf("\n\t\t\t\tC. Denmark ");
        printf("\n\t\t\t\tD. France");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. Denmark");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q132;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q133;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q131;

       }

       }


        /*  QUESTION 4 */

                q141:
        header();
        q1=4;
        printf("\n Question no 4");
        printf("\t\t\t\t\t\t\t\t\t\tRS.2,50,000/-");
        printf("\n\n\t\t\tWho is the first woman to successfully climb K2, the world’s second highest mountain peak?");
        printf("\n\n\t\t\t\tA. Junko Tabei");
        printf("\n\t\t\t\tB. Tamae Watanabe");
        printf("\n\t\t\t\tC. Chantal Maudui");
        printf("\n\t\t\t\tD. Wanda Rutkiewicz ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'B' :case 'C' :case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q140:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q142;
                break;

            case 'B':
                goto q143;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q140;
            }

          q142:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 4    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.2,50,000/-");
        printf("\n\n\t\t\tWho is the first woman to successfully climb K2, the world’s second highest mountain peak?");
        printf("\n\n\t\t\t\tA. Junko Tabei");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Wanda Rutkiewicz ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'D':
        correct();
        break;
        case 'A' :
        wrong();
        break;
        case 'E':
        goto q143;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q142;
       }
       break;
        }

     q143:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 4    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.2,50,000/-");
        printf("\n\n\t\t\tWho is the first woman to successfully climb K2, the world’s second highest mountain peak?");
        printf("\n\n\t\t\t\tA. Junko Tabei");
        printf("\n\t\t\t\tB. Tamae Watanabe");
        printf("\n\t\t\t\tC. Chantal Maudui");
        printf("\n\t\t\t\tD. Wanda Rutkiewicz ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tD. Wanda Rutkiewicz ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'D':
        correct();
        break;
        case 'B' :case 'C' :case 'A' :
        wrong();
        break;
        case 'E':
        goto q142;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q143;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q141;

       }

       }

        /*  QUESTION 5 */
        q151:
        header();
        q1=5;
        printf("\n Question no 5");
        printf("\t\t\t\t\t\t\t\t\t\tRS.3,20,000/-");
        printf("\n\n\t\t\tWho, in 1978, became the first person to be born in the continent of Antarctica?");
        printf("\n\n\t\t\t\tA. James Weddell");
        printf("\n\t\t\t\tB. Emilio Palma");
        printf("\n\t\t\t\tC. Nathaniel Palmer");
        printf("\n\t\t\t\tD. Chales Wilkes");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q150:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q152;
                break;

            case 'B':
                goto q153;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q150;
            }

          q152:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 5    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.3,20,000/-");
        printf("\n\n\t\t\tWho, in 1978, became the first person to be born in the continent of Antarctica?");
        printf("\n\n\t\t\t\tA. James Weddell");
        printf("\n\t\t\t\tB. Emilio Palma");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :
        wrong();
        break;
        case 'E':
        goto q153;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q152;
       }
       break;
        }

     q153:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 5    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.3,20,000/-");
        printf("\n\n\t\t\tWho, in 1978, became the first person to be born in the continent of Antarctica?");
        printf("\n\n\t\t\t\tA. James Weddell");
        printf("\n\t\t\t\tB. Emilio Palma");
        printf("\n\t\t\t\tC. Nathaniel Palmer");
        printf("\n\t\t\t\tD. Chales Wilkes");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tB. Emilio Palma");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'C' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q152;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q153;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q151;

       }

       }

         /*  QUESTION 6 */
        q161:
        header();
        q1=6;
        printf("\n Question no 6");
        printf("\t\t\t\t\t\t\t\t\t\tRS.6,40,000/-");
        printf("\n\n\t\t\tWho commanded the ‘Hector’, the first British trading ship to land at Surat?");
        printf("\n\n\t\t\t\tA. Paul Canning ");
        printf("\n\t\t\t\tB. Thomas Roe ");
        printf("\n\t\t\t\tC. William Hawkins  ");
        printf("\n\t\t\t\tD. James Lancaster");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q160:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q162;
                break;

            case 'B':
                goto q163;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q160;
            }

          q162:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 6    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.6,40,000/-");
        printf("\n\n\t\t\tWho commanded the ‘Hector’, the first British trading ship to land at Surat?");
        printf("\n\n\t\t\t\t ");
        printf("\n\t\t\t\tB. Thomas Roe ");
        printf("\n\t\t\t\tC. William Hawkins  ");
        printf("\n\t\t\t\t");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :
        wrong();
        break;
        case 'E':
        goto q163;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q162;
       }
       break;
        }

     q163:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 6    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.6,40,000/-");
        printf("\n\n\t\t\tWho commanded the ‘Hector’, the first British trading ship to land at Surat?");
        printf("\n\n\t\t\t\tA. Paul Canning ");
        printf("\n\t\t\t\tB. Thomas Roe ");
        printf("\n\t\t\t\tC. William Hawkins  ");
        printf("\n\t\t\t\tD. James Lancaster");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. William Hawkins ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'C':
        correct();
        break;
        case 'B' :case 'A' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q162;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q163;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q161;

       }

       }

         /*  QUESTION 7 */

        q171:
        header();
        q1=7;
        printf("\n Question no 7");
        printf("\t\t\t\t\t\t\t\t\t\tRS.12,50,000/-");
        printf("\n\n\t\t\tWhich of the following is NOT a pair of parent and child, who have both won Nobel Prizes?");
        printf("\n\n\t\t\t\tA. Marie Curie, Irene Joliot Curie  ");
        printf("\n\t\t\t\tB. Herman Emil Fischer, Hans Fischer  ");
        printf("\n\t\t\t\tC. JJ Thomson, George Paget Thomson");
        printf("\n\t\t\t\tD. Niels Bohr, Aage Bohr ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q170:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q172;
                break;

            case 'B':
                goto q173;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q170;
            }

          q172:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 7    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.12,50,000/-");
        printf("\n\n\t\t\tWhich of the following is NOT a pair of parent and child, who have both won Nobel Prizes?");
        printf("\n\n\t\t\t\tA. Marie Curie, Irene Joliot Curie  ");
        printf("\n\t\t\t\tB. Herman Emil Fischer, Hans Fischer  ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :
        wrong();
        break;
        case 'E':
        goto q173;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q172;
       }
       break;
        }

     q173:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 7    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.12,50,000/-");
        printf("\n\n\t\t\tWhich of the following is NOT a pair of parent and child, who have both won Nobel Prizes?");
        printf("\n\n\t\t\t\tA. Marie Curie, Irene Joliot Curie  ");
        printf("\n\t\t\t\tB. Herman Emil Fischer, Hans Fischer  ");
        printf("\n\t\t\t\tC. JJ Thomson, George Paget Thomson");
        printf("\n\t\t\t\tD. Niels Bohr, Aage Bohr ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tB. Herman Emil Fischer, Hans Fischer ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'B':
        correct();
        break;
        case 'A' :case 'C' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q172;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q173;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q171;

       }

       }


          /*  QUESTION 8 */

        q181:
        header();
        q1=8;
        printf("\n Question no 8");
        printf("\t\t\t\t\t\t\t\t\t\tRS.25,00,000/-");
        printf("\n\n\t\t\tWho became first sportsperson to be honoured with Rajiv Gandhi Khel Ratna award?");
        printf("\n\n\t\t\t\tA. Vishwanathan Anand ");
        printf("\n\t\t\t\tB. Sachin Tendulkar  ");
        printf("\n\t\t\t\tC. Geet Sethi");
        printf("\n\t\t\t\tD. Leande ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q180:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q182;
                break;

            case 'B':
                goto q183;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q180;
            }

          q182:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 8    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.25,00,000/-");
        printf("\n\n\t\t\tWho became first sportsperson to be honoured with Rajiv Gandhi Khel Ratna award?");
        printf("\n\n\t\t\t\tA. Vishwanathan Anand ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Leande ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'D' :
        wrong();
        break;
        case 'E':
        goto q183;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q182;
       }
       break;
        }

     q183:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 8    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.25,00,000/-");
        printf("\n\n\t\t\tWho became first sportsperson to be honoured with Rajiv Gandhi Khel Ratna award?");
        printf("\n\n\t\t\t\tA. Vishwanathan Anand ");
        printf("\n\t\t\t\tB. Sachin Tendulkar  ");
        printf("\n\t\t\t\tC. Geet Sethi");
        printf("\n\t\t\t\tD. Leande ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA. Vishwanathan Anand ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q182;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q183;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q181;

       }

       }


           /*  QUESTION 9 */
        q191:
        header();
        q1=9;
        printf("\n Question no 9");
        printf("\t\t\t\t\t\t\t\t\t\tRS.50,00,000/-");
        printf("\n\n\t\t\t How long was the Mesozoic Era?");
        printf("\n\n\t\t\t\tA. 185 million years ");
        printf("\n\t\t\t\tB. 400 million years");
        printf("\n\t\t\t\tC. 250 million years");
        printf("\n\t\t\t\tD. 65 million years");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q190:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q192;
                break;

            case 'B':
                goto q193;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q190;
            }

          q192:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 9    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.50,00,000/-");
        printf("\n\n\t\t\t How long was the Mesozoic Era?");
        printf("\n\n\t\t\t\tA. 185 million years ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tC. 250 million years");
        printf("\n\t\t\t\t");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'C' :
        wrong();
        break;
        case 'E':
        goto q193;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q192;
       }
       break;
        }

     q193:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 9    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS.50,00,000/-");
        printf("\n\n\t\t\t How long was the Mesozoic Era?");
        printf("\n\n\t\t\t\tA. 185 million years ");
        printf("\n\t\t\t\tB. 400 million years");
        printf("\n\t\t\t\tC. 250 million years");
        printf("\n\t\t\t\tD. 65 million years");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA. 185 million years ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'A':
        correct();
        break;
        case 'B' :case 'C' :case 'D' :
        wrong();
        break;
        case 'E':
        goto q192;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q193;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q191;

       }

       }



      /*  QUESTION 10*/

        q1101:
        header();
        q1=10;
        printf("\n Question no 10");
        printf("\t\t\t\t\t\t\t\t\t\tRS. 1 CRORE/-");
        printf("\n\n\t\t\tWhich of the following forts was not built by the European colonial powers in India?");
        printf("\n\n\t\t\t\tA. Fort Dansborg");
        printf("\n\t\t\t\tB. Fort Naarden");
        printf("\n\t\t\t\tC. Fort Santa Katherina");
        printf("\n\t\t\t\tD. Fort Chambray ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
        switch(q)
       {case 'D':
        correct();
        break;
        case 'B' :case 'C' :case 'A' :
        wrong();
        break;

        case 'F':
        quit();
        break;

        case 'E':

      {   q1100:
          printf("\n\n\t\t\t\t Choose Your Life Line:");
          printf("\n\n\t\t\t\t A. 50:50");
          printf("\n\n\t\t\t\t B. Expert Advice");
          printf("\n\n\t\t\t\t\tEnter your choice >>> ");
          fflush(stdin);
          scanf("%c",&l);
          switch(l)
            {
            case 'A':
                goto q1102;
                break;

            case 'B':
                goto q1103;
                break;

            default :
            printf("\nEnter any valid choice");
            getch();
            goto q1100;
            }

          q1102:
          {
          lifeline=lifeline-1;
          header();
        printf("\n Question no 10    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS. 1 CRORE/-");
        printf("\n\n\t\t\tWhich of the following forts was not built by the European colonial powers in India?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tC. Fort Santa Katherina");
        printf("\n\t\t\t\tD. Fort Chambray ");
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'D':
        correct();
        break;
        case 'A' :
        wrong();
        break;
        case 'E':
        goto q1103;
        break;
        case 'F':
        quit();
        break;

        default :
            printf("\nEnter any valid choice");
            getch();
            goto q1102;
       }
       break;
        }

     q1103:
         {
          lifeline=lifeline-1;
          header();

            printf("\n Question no 10    You are using life line Expert Advice");
        printf("\n\t\t\t\t\t\t\t\t\t\tRS. 1 CRORE/-");
        printf("\n\n\t\t\tWhich of the following forts was not built by the European colonial powers in India?");
        printf("\n\n\t\t\t\tA. Fort Dansborg");
        printf("\n\t\t\t\tB. Fort Naarden");
        printf("\n\t\t\t\tC. Fort Santa Katherina");
        printf("\n\t\t\t\tD. Fort Chambray ");;
        if (lifeline>0)
        {printf("\n\n\t\t\t\tE. Use Life line: 50:50");}

        printf("\n\n\t\t\t\tF. Quit Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tD. Fort Chambray ");
           printf("\n\n\t\t\t\t Enter your choice >>>");
       fflush(stdin);
       scanf("%c",&q);
       switch(q)
       {case 'D':
        correct();
        break;
        case 'B' :case 'C' :case 'A' :
        wrong();
        break;
        case 'E':
        goto q1102;
        break;
        case 'F':
        quit();
        break;
        default :
            printf("\nEnter any valid choice");
            getch();
            goto q1103;
         }

    }
        break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1101;

       }

       }
return;
}
