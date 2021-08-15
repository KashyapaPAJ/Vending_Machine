/**
* ENGG1110 Problem Solving by Programming
*
* Course Project
*
* I declare that the project here submitted is original
* except for source material explicitly acknowledged,
* and that the same or closely related material has not been
* previously submitted for another course.
* I also acknowledge that I am aware of University policy and
* regulations on honesty in academic work, and of the disciplinary
* guidelines and procedures applicable to breaches of such
* policy and regulations, as contained in the website.
*
* University Guideline on Academic Honesty:
* https://www.cuhk.edu.hk/policy/academichonesty/
*
* Student Name : Kashyapa Peter Arnodage Jayasekera
* Student ID : 1155135962
* Class/Section : ENGG1110A
* Date : 4/12/2019
*/
#include <stdio.h>
//                 G L O B A L  V A R I A B L E  D E C L A R A T I O N
int money=0,revenue=0;
char prodlight=61;
typedef struct product{
  int stock,price;
  char light,name[20];
} Product;
Product A={5,10,32,"Juice"};
Product B={1,6,32,"Cola"};
Product C={2,5,32,"Tea"};
Product D={1,8,32,"Water"};
Product E={9,7,32,"Coffee"};
//                                P R O D U C T  I N F O R M A T I O N
void prodinfo() {
	printf("\n(1) The displayed products are: \n");
	printf("A. %s ($%d)\n",A.name,A.price);
	printf("B. %s ($%d)\n",B.name,B.price);
	printf("C. %s ($%d)\n",C.name,C.price);
	printf("D. %s ($%d)\n",D.name,D.price);
	printf("E. %s ($%d)\n",E.name,E.price);
}
//                                                    M A I N  M E N U
int mainmenu() {
	int choice,i=0;
  while (i==0) {
	  printf("\nWhat would you like to do?\n");
	  printf("1. Read product information\n");
	  printf("2. Insert coin\n");
	  printf("3. Press product button\n");
	  printf("4. Press return button\n");
	  printf("9. Open service menu (code required)\n");
	  printf("0. Quit\n");
	  printf("Your choice:");
	  scanf("%d",&choice);
	  if ((choice>=0)&&(choice<=4)){i++;}
  	  else if(choice==9) {i++;}
  	  else {printf("\nInvalid choice!\n");}
  }return choice;
}
//                                                       D I S P L A Y
void display2() { 
  if (money>=A.price) {A.light=79;}
  else {A.light=32;}
  if (money>=B.price) {B.light=79;}
  else {B.light=32;}
  if (money>=C.price) {C.light=79;}
  else {C.light=32;}
  if (money>=D.price) {D.light=79;}
  else {D.light=32;}
  if (money>=E.price) {E.light=79;}
  else {E.light=32;}
  if (A.stock==0){A.light=88;}
  if (B.stock==0){B.light=88;}
  if (C.stock==0){C.light=88;}
  if (D.stock==0){D.light=88;}
  if (E.stock==0){E.light=88;}
  printf("*---------------------------*\n");
	printf("|      Vending Machine      |\n");
  printf("*---------------------------*\n");
	printf("|   A    B    C    D    E   |\n");
	printf("|  $%2d  $%2d  $%2d  $%2d  $%2d  |\n",A.price,B.price,C.price,D.price,E.price);
  printf("|  [%c]  [%c]  [%c]  [%c]  [%c]  |\n",A.light,B.light,C.light,D.light,E.light);
	printf("*---------------------------*\n");
  printf("|                    [$%2d]  |\n",money);
	printf("|                           |\n");
  printf("|           [=%c=]           |\n",prodlight);
  printf("*---------------------------*\n");
  if (prodlight!=61) {prodlight=61;}
}
//                                                          C O I N S 
void coins() {
  int choice;
  printf("\n(2) Which coin would you like to insert?\n");
  printf("1. $1\n");
  printf("2. $2\n");
  printf("3. $5\n");
  printf("4. $10\n");
  printf("0. Go back\n");
  printf("Your choice:");
  scanf("%d",&choice);
  if (choice==1) {
    money=money+1;
    printf("You have inserted $1.\n\n");
    display2();
    coins();}
  else if (choice==2) {
    money=money+2;
    printf("You have inserted $2.\n\n");
    display2();
    coins();}
  else if (choice==3) {
    money=money+5;
    printf("You have inserted $5.\n\n");
    display2();
    coins();}
  else if (choice==4) {
    money=money+10;
    printf("You have inserted $10.\n\n");
    display2();
    coins();}
  else if (choice==0) {
    printf("Going back!\n\n");
    display2();}
  else {
    printf("\nInvalid choice!\n");
    coins();}
}
//                                          P R O D U C T  B U T T O N
void product() {
  int choice,i=0;
  while (i==0) {
    printf("\n(3) Which product button would you like to press?\n");
    printf("1. A\n");
    printf("2. B\n");
    printf("3. C\n");
    printf("4. D\n");
    printf("5. E\n");
    printf("0. Go back\n");
    printf("Your choice:");
    scanf("%d",&choice);
    if (choice==1) {
      printf("You have pressed button A.\n\n");
      if ((A.stock!=0)&&(money>=10)){A.stock--;money=money-A.price;
      prodlight=65;}
      revenue=revenue+A.price;
      display2();
      i++;}
    else if (choice==2) {
      printf("You have pressed button B.\n\n");
      if ((B.stock!=0)&&(money>=6)){B.stock--;money=money-B.price;
      prodlight=66;}
      revenue=revenue+B.price;
      display2();
      i++;}
    else if (choice==3) {
      printf("You have pressed button C.\n\n");
      if ((C.stock!=0)&&(money>=5)){C.stock--;money=money-C.price;prodlight=67;}
      revenue=revenue+C.price;
      display2();
      i++;}
    else if (choice==4) {
      printf("You have pressed button D.\n\n");
      if ((D.stock!=0)&&(money>=8)){D.stock--;money=money-D.price;prodlight=68;}
      revenue=revenue+D.price;
      display2();
      i++;}
    else if (choice==5) {
      printf("You have pressed button E.\n\n");
      if ((E.stock!=0)&&(money>=7)){E.stock--;money=money-E.price;prodlight=69;}
      revenue=revenue+E.price;
      display2(); 
      i++;}
    else if (choice==0) {
      printf("Going back!\n\n");
      display2();
      i++;}
    else {printf("\nInvalid choice!\n");}
  }
}
//                                          M A C H I N E  S T A T U S
void status() {
  printf("\n(9-1) Machine status\n");
  printf("Amount of revenue: $%d\n",revenue);
  printf("Amount of inserted coins: $%d\n",money);
  printf("Product information:\n");
  printf("A. %s ($%d) ",A.name,A.price);
  if (A.stock!=0){printf("(%d left)\n",A.stock);}
  else {printf("(sold out)\n");}
  printf("B. %s ($%d) ",B.name,B.price);
  if (B.stock!=0){printf("(%d left)\n",B.stock);}
  else {printf("(sold out)\n");}
  printf("C. %s ($%d) ",C.name,C.price);
  if (C.stock!=0){printf("(%d left)\n",C.stock);}
  else {printf("(sold out)\n");}
  printf("D. %s ($%d) ",D.name,D.price);
  if (D.stock!=0){printf("(%d left)\n",D.stock);}
  else {printf("(sold out)\n");}
  printf("E. %s ($%d) ",E.name,E.price);
  if (E.stock!=0){printf("(%d left)\n",E.stock);}
  else {printf("(sold out)\n");}
}
//                                          W I T H D R A W  M O N E Y
void withdraw() {
  printf("\n(9-2) All money is being withdrawn.\n");
  printf("$%d is withdrawn.\n",revenue);
  revenue=0;
}
//                                                         R E F I L L
void refill() {
  int choice,i=0;
  while (i==0) {
  printf("\n(9-3) Which product would you like to refill?\n");
  printf("1. A\n");
  printf("2. B\n");
  printf("3. C\n");
  printf("4. D\n");
  printf("5. E\n");
  printf("0. Go back\n");
  printf("Your choice:");
  scanf("%d",&choice);
  if (choice==1) {A.stock=10;printf("You have refilled product A to full.\n");i++;}
  else if (choice==2) {B.stock=10;printf("You have refilled product B to full.\n");i++;}
  else if (choice==3) {C.stock=10;printf("You have refilled product C to full.\n");i++;}
  else if (choice==4) {D.stock=10;printf("You have refilled product D to full.\n");i++;}
  else if (choice==5) {E.stock=10;printf("You have refilled product E to full.\n");i++;}
  else if (choice==0) {printf("Going back!\n");i++;}
  else {printf("\nInvalid choice!\n");}
  }
}
//                                          C H A N G E  P R O D U C T 
void change() {
  int choice,i=0;
  while (i==0) {
    printf("\n(9-4) Which product would you like to change?\n");
    printf("1. A\n");
    printf("2. B\n");
    printf("3. C\n");
    printf("4. D\n");
    printf("5. E\n");
    printf("0. Go back\n");
    printf("Your choice:");
    scanf("%d",&choice);
    if (choice==1) {
      printf("You are changing product A.\n");
      printf("\nEnter new product name:");
      scanf("%s",A.name);
      printf("Enter new product price:");
      scanf("%d",&A.price);
      A.stock=10;
      printf("The new product A has been filled to full.\n");
      i++;}
    else if (choice==2) {
      printf("You are changing product B.\n");
      printf("\nEnter new product name:");
      scanf("%s",B.name);
      printf("Enter new product price:");
      scanf("%d",&B.price);
      B.stock=10;
      printf("The new product B has been filled to full.\n");
      i++;}
    else if (choice==3) {
      printf("You are changing product C.\n");
      printf("\nEnter new product name:");
      scanf("%s",C.name);
      printf("Enter new product price:");
      scanf("%d",&C.price);
      C.stock=10;
      printf("The new product C has been filled to full.\n");
      i++;}
    else if (choice==4) {
      printf("You are changing product D.\n");
      printf("\nEnter new product name:");
      scanf("%s",D.name);
      printf("Enter new product price:");
      scanf("%d",&D.price);
      D.stock=10;
      printf("The new product D has been filled to full.\n");
      i++;}
    else if (choice==5) {
      printf("You are changing product E.\n");
      printf("\nEnter new product name:");
      scanf("%s",E.name);
      printf("Enter new product price:");
      scanf("%d",&E.price);
      E.stock=10;
      printf("The new product E has been filled to full.\n");
      i++;}
  }
}
//                                              S E R V I C E  M E N U
void service() {
  int choice,i=0;
  while (i==0) {
    printf("\n(9) What would you like to do?\n");
    printf("1. Inspect machine status\n");
    printf("2. Withdraw all money\n");
    printf("3. Refill product\n");
    printf("4. Change product\n");
    printf("0. Go back\n");
    printf("Your choice:");
    scanf("%d",&choice);
    if (choice==1) {status();}
    else if (choice==2) {withdraw();}
    else if (choice==3) {refill();}
    else if (choice==4) {change();}
    else if (choice==0) {
      printf("Going back!\n\n");
      display2();
      i++;}
    else {printf("\nInvalid choice!\n");}
  }
}
//                                                A C C E S S  C O D E
void code() {
  int pin;
  printf("\n(9) Opening service menu. Access code is required.\n");
  printf("Enter access code:");
  scanf("%d",&pin);
  if (pin==1110) {
    printf("\nCorrect code!\n");
    service();}
  else {
    printf("\nIncorrect code!\n\n");
    display2();}
}
//                                              M A I N  P R O G R A M
int main(void) {
  int choice,i=0;
  display2();
  while (i==0) {
    choice=mainmenu();
    if (choice==1) {
      prodinfo();
    }
    else if (choice==2) {
      coins();
    }
    else if (choice==3) {
      product();
    }
    else if (choice==4){ 
      printf("\n(4) Return button is pressed.\n");
      printf("$%d has been returned.\n\n",money);
      revenue=revenue-money;
      money=0;
      display2();
    }
    else if (choice==9) {
      code();
    }
    else if (choice==0){
      i++;
    }
  }
  return 0;
}

