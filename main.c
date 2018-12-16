#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct date{
  int day,month,year;
};

struct car{
  int ID;
  char owner_name[20],owner_surname[20],make[20],model[20],owner_phone_number[11];
  struct date reg_date,ns_date;
}car_directory[100];
// temp is determined global variable for used all of the function
int temp;
//function declared --> start
void menuList();
void howManyCars(); // how many car want add
void addCar(struct car car_directory[],int size);
void deleteCar(struct car car_directory[]);
void searchCar();
void listCars(struct car car_directory[]);
void searchCarID(struct car car_directory[]);
void searchRegDate(struct car car_directory[]);
void updateCarInf(struct car car_directory[]);
void sortCarID(struct car car_directory[]);
int quitprogram();
void doWant();
//function declared --> finish


int main(int argc, char const *argv[]) {

    menuList();

  return 0;
}// main --> finished

void menuList(){
  char num[1];
  int i,cnt=0,f;
  
  do{
  	printf("\n");//menu start
  printf("CAR SERVICE DIRECTORY\n");
  printf("----------------------------------------------------------------------------------------------\n");
  printf("1) Add a new car to directory\n");
  printf("2) Delete a car from the directory\n");
  printf("3) List available cars in the directory\n");
  printf("4) Search a car : \n");
            printf("\tA) Search according to car id\n");
            printf("\tB) Search according to registration year\n");
  printf("5) Update car information\n");
  printf("6) Sort according to car id\n");
  printf("7) Quit\n");//menu finish
  printf("----------------------------------------------------------------------------------------------\n");
  printf("Please, enter your choose number : ");
  scanf("%s",num); //choose an operation --> start
  
  	for(i=0;i<num[i]!='\0';i++){ // check the num , digit or not-digit
  		if(!isdigit(num[i])>0){ // if num will not digit display warning !
  			printf("\nPlease enter number between [1 - 7] !\n");
		  }
	  }
	  f=*num; // describe f for pointer num , take the ascii code for control method
	  //printf("%d",f); ==> bug control
  }while((f<49) || (f>55));
  
  	switch(f){
  		case 49:howManyCars();break;
  		case 50:deleteCar(car_directory);break;
  		case 51:listCars(car_directory);break;
  		case 52:searchCar();break;
  		case 53:updateCarInf(car_directory);break;
  		case 54:sortCarID(car_directory);break;
  		case 55:quitprogram();
	  }// choose an operation --> finish

}// menuList --> finished

void howManyCars(){
  int howMany;  // enter how many cars want
  printf("Please, enter how many cars want add : ");
  scanf("%d",&howMany);

  //howMany add over the temp because it need contiune to index from stay
  temp=temp+howMany;

/*firstly call the function of howManyCars i take howMany cars want add from user
than call the function of addCar for add new cars*/

  addCar(car_directory,howMany);
}// howManyCars --> finished

void addCar(struct car car_directory[],int howMany){

  //title --> start
  printf("\n\n");
  printf("==============================================================================================\n");
  printf("Add to a new car to directory\n");
  printf("\n\n");
  //title --> finish
  int i;
  int result=temp-howMany; // kaldigi yerden devam etmesi icin islem yapildi
  result=result-1; // index degeri olacak ayrica dongu icinde 1 arttirlip devam edck
  for (i =0; i < howMany; i++) {// eklemek istenen arac sayisi kadar dongu calisir
    result++; // kaldigi index degerinde baslayip artmaya devam edecek
    printf("Please, enter %d. ID : ",result+1);
    scanf("%d",&car_directory[result].ID);
    printf("Please, enter %d. Name : ",result+1);
    scanf("%s",car_directory[result].owner_name);
    printf("Please, enter %d. Surname : ",result+1);
    scanf("%s",car_directory[result].owner_surname);
    printf("Please, enter %d. Phone Number : ",result+1);
    scanf("%s",car_directory[result].owner_phone_number);
    printf("Please, enter %d. Make : ",result+1);
    scanf("%s",car_directory[result].make);
    printf("Please, enter %d. Model : ",result+1);
    scanf("%s",car_directory[result].model);
    printf("Please, enter %d. Registration Date (dd mm yyyy) : ",result+1);
    scanf("%d%d%d",&car_directory[result].reg_date.day,&car_directory[result].reg_date.month,&car_directory[result].reg_date.year);
    printf("Please, enter %d. Next Service (dd mm yyyy) : ",result+1);
    scanf("%d%d%d",&car_directory[result].ns_date.day,&car_directory[result].ns_date.month,&car_directory[result].ns_date.year);
    printf("\n");
  }
  doWant(); //i asked what do you do want.
}// addCar --> finished

void doWant(){
  int ask;
  printf("\n");
  printf("Do you want go to Menu ?\n");
  printf("\n");

  printf("1) Yes\t\t2)Quit\n");
  printf("Please enter your choose : ");
  scanf("%d",&ask);
  switch (ask) {
    case 1:menuList();break;
    case 2:quitprogram();break;
  }
}// i asked menu --> finished

void deleteCar(struct car car_directory[]){  //title --> start
  printf("\n\n");
  printf("==============================================================================================\n");
  printf("Delete a car from the directory\n");
  printf("\n\n");
  //title --> finish
  if(temp==0){ // is there temp has any information --> not contiune
    printf("\t\t\t\t\tEmpty !!!\n\n");
    printf("==============================================================================================\n");
    doWant();
  }else{ // is there temp has any information --> contiune
    int i,number,key,j;
    printf("Please, enter the ID you want to delete : ");
    scanf("%d",&number);

      for(i=0;i<temp;i++){
        if(number==car_directory[i].ID){
          //printf("number ==> %d car_directory ==> %d\n",number,car_directory[i].ID); ==> bug control
          for(j=i;j<temp;j++){ //write over the next id for delete
            //printf("j : %d\n",j); ==> bug control
            car_directory[j].ID=car_directory[j+1].ID;
            strcpy(car_directory[j].owner_name,car_directory[j+1].owner_name);
            strcpy(car_directory[j].owner_surname,car_directory[j+1].owner_surname);
            strcpy(car_directory[j].owner_phone_number,car_directory[j+1].owner_phone_number);
            strcpy(car_directory[j].make,car_directory[j+1].make);
            strcpy(car_directory[j].model,car_directory[j+1].model);
            car_directory[j].reg_date.day=car_directory[j+1].reg_date.day;
            car_directory[j].reg_date.month=car_directory[j+1].reg_date.month;
            car_directory[j].reg_date.year=car_directory[j+1].reg_date.year;
            car_directory[j].ns_date.day=car_directory[j+1].ns_date.day;
            car_directory[j].ns_date.month=car_directory[j+1].ns_date.month;
            car_directory[j].ns_date.year=car_directory[j+1].ns_date.year;
          }// for loop for delete --> finished
          temp=temp-1; // if delete the information, we need substract 1 from temp
          printf("ID was deleted.\n\n");
          break;
        }
      }

	doWant(); //i asked what do you do want.
  }// is there temp has any information --> finished

  
}//deleteCar --> finished

void listCars(struct car car_directory[]){
  //title --> start
  printf("\n\n");
  printf("==============================================================================================\n");
  printf("List available cars in the directory\n");
  printf("\n\n");
  //title --> finish
  if(temp==0){
  	printf("\t\t\t\t\tEmpty !!!\n\n");
  	printf("==============================================================================================\n");
  } 
  int i;
  for (i = 0; i < temp; i++) {
    printf("\n");
    printf("Owner : %d\t",car_directory[i].ID);
    printf("Full Name : %s %s\t\t",car_directory[i].owner_name,car_directory[i].owner_surname);
    printf("Mobile Phone : %s\t\n",car_directory[i].owner_phone_number);
    printf("Make  : %s\t\t",car_directory[i].make);
    printf("Model     : %s\n",car_directory[i].model);
    printf("Registration (dd/mm/yyyy) : %d/%d/%d\t\t\t",car_directory[i].reg_date.day,car_directory[i].reg_date.month,car_directory[i].reg_date.year);
    printf("Next Service (dd/mm/yyyy) : %d/%d/%d\n",car_directory[i].ns_date.day,car_directory[i].ns_date.month,car_directory[i].ns_date.year);
    printf("----------------------------------------------------------------------------------------------\n\n");
  }
  doWant(); //i asked what do you do want.
}// listCars --> finished

void searchCar(){
  //title --> start
  printf("\n\n");
  printf("==============================================================================================\n");
  printf("Search Cars\n");
  printf("\n\n");
  //title --> finish
 
  char key;
  
    do{ // we check the key , user what will enter
  printf("A) Search according to car id\t\t");
  printf("B) Search according to registration year\n\n");
  printf("Please, enter your choose : ");
  scanf("%s",&key);
    	//choose which one you want search type
      if(key=='A' || key=='a'){
        searchCarID(car_directory);break; // for exit from loop we need write breake
      }else if(key=='B' || key=='b'){
        searchRegDate(car_directory);break; // if we do not write break, we going to continue loop, it will not exit from loop
      }else{
		printf("\nPlease enter just [a-A or b-B]\n\n");
	  }// choose key --> finished
      
	}while((key!='A') || (key!='a') || (key!='B') || (key!='b'));

}// searchCar --finished

void searchCarID(struct car car_directory[]){
  //title --> start
  printf("\n\n");
  printf("==============================================================================================\n");
  printf("Search according to car ID\n");
  printf("\n\n");
  //title --> finish
  int i,num,count=0;

  printf("Please, enter your want search ID : ");
  scanf("%d",&num);

    for (i = 0; i < temp; i++) {
        if(num==car_directory[i].ID){
          printf("\n");
          printf("Owner : %d\t",car_directory[i].ID);
          printf("Full Name : %s %s\t",car_directory[i].owner_name,car_directory[i].owner_surname);
          printf("Mobile Phone : %s\t\n",car_directory[i].owner_phone_number);
          printf("Make  : %s\t\t",car_directory[i].make);
          printf("Model     : %s\n",car_directory[i].model);
          printf("Registration (dd/mm/yyyy) : %d/%d/%d\t\t\t",car_directory[i].reg_date.day,car_directory[i].reg_date.month,car_directory[i].reg_date.year);
          printf("Next Service (dd/mm/yyyy) : %d/%d/%d\n",car_directory[i].ns_date.day,car_directory[i].ns_date.month,car_directory[i].ns_date.year);
          printf("----------------------------------------------------------------------------------------------\n\n");
          count++;
        }//if --> finished
    }// for loop --> finished
    if(count==0){
      printf("\n\t\t\t\t\tSorry, Not Found !!!\n\n");
      printf("==============================================================================================\n");
    }
  doWant(); //i asked what do you do want.
}

void searchRegDate(struct car car_directory[]){
  //title --> start
  printf("\n\n");
  printf("==============================================================================================\n");
  printf("Search according to registration year\n");
  printf("\n\n");
  //title --> finish
  int i,num,count=0;

  printf("Please, enter your want search registration year : ");
  scanf("%d",&num);

    for (i = 0; i < temp; i++) {
      if(num==car_directory[i].reg_date.year){
        printf("\n");
        printf("Owner : %d\t",car_directory[i].ID);
        printf("Full Name : %s %s\t",car_directory[i].owner_name,car_directory[i].owner_surname);
        printf("Mobile Phone : %s\t\n",car_directory[i].owner_phone_number);
        printf("Make  : %s\t\t",car_directory[i].make);
        printf("Model     : %s\n",car_directory[i].model);
        printf("Registration (dd/mm/yyyy) : %d/%d/%d\t\t\t",car_directory[i].reg_date.day,car_directory[i].reg_date.month,car_directory[i].reg_date.year);
        printf("Next Service (dd/mm/yyyy) : %d/%d/%d\n",car_directory[i].ns_date.day,car_directory[i].ns_date.month,car_directory[i].ns_date.year);
        printf("----------------------------------------------------------------------------------------------\n\n");
        count++;
      }//if --> finished
    }// for loop --> finished
    if(count==0){
      printf("\n\t\t\t\t\tSorry, Not Found !!!\n\n");
      printf("==============================================================================================\n");
      
    }
  doWant(); //i asked what do you do want.
}

void updateCarInf(struct car car_directory[]){

  //title --> start
  printf("\n\n");
  printf("==============================================================================================\n");
  printf("Update car information\n");
  printf("\n\n");
  //title --> finish
  if(temp==0){ // if temp==0 does not contiune
    printf("\t\t\t\t\tEmpty !!!\n\n");
  	printf("==============================================================================================\n");
    doWant();
  }else{ // if temp>0 program is contiune
    int i,number;
    printf("Please, enter the id you want to update : ");
    scanf("%d",&number);

    for(i=0;i<temp;i++){
      if(number==car_directory[i].ID){
        printf("Please, enter new Name : ");
        scanf("%s",car_directory[i].owner_name);
        printf("Please, enter new Surname : ");
        scanf("%s",car_directory[i].owner_surname);
        printf("Please, enter new Phone Number : ");
        scanf("%s",car_directory[i].owner_phone_number);
        printf("Please, enter new Make : ");
        scanf("%s",car_directory[i].make);
        printf("Please, enter new Model : ");
        scanf("%s",car_directory[i].model);
        printf("Please, enter new Registration Date (dd mm yyyy) : ");
        scanf("%d%d%d",&car_directory[i].reg_date.day,&car_directory[i].reg_date.month,&car_directory[i].reg_date.year);
        printf("Please, enter new Next Service (dd mm yyyy) : ");
        scanf("%d%d%d",&car_directory[i].ns_date.day,&car_directory[i].ns_date.month,&car_directory[i].ns_date.year);
      }// number==car_directory --> finished
    }// for loop --> finished
    doWant(); //i asked what do you do want.
  }

}//updateCarInf --> finished

void sortCarID(struct car car_directory[]){
  //title --> start
  printf("\n\n");
  printf("==============================================================================================\n");
  printf("Sort according to car ID \n");
  printf("\n\n");
  //title --> finish
  if(temp==0) {
  	printf("\t\t\t\t\tEmpty !!!\n\n");
  	printf("==============================================================================================\n");
  }
  int i,j,b,tempr;//bubble sort
  for(i=0;i<temp;i++){
    for(j=0;j<temp-1;j++){
      if(car_directory[j].ID > car_directory[j+1].ID){ // swap
        tempr=car_directory[j+1].ID;
        car_directory[j+1].ID=car_directory[j].ID;
        car_directory[j].ID=tempr;
      }
    }// inside for loop --> finished
  }//first for loop -- finished

  for(b=0;b<temp;b++){
    printf("\n");
    printf("Owner : %d\t",car_directory[b].ID);
    printf("Full Name : %s %s\t",car_directory[b].owner_name,car_directory[b].owner_surname);
    printf("Mobile Phone : %s\t\n",car_directory[b].owner_phone_number);
    printf("Make  : %s\t\t",car_directory[b].make);
    printf("Model     : %s\n",car_directory[b].model);
    printf("Registration (dd/mm/yyyy) : %d/%d/%d\t\t\t",car_directory[b].reg_date.day,car_directory[b].reg_date.month,car_directory[b].reg_date.year);
    printf("Next Service (dd/mm/yyyy) : %d/%d/%d\n",car_directory[b].ns_date.day,car_directory[b].ns_date.month,car_directory[b].ns_date.year);
    printf("----------------------------------------------------------------------------------------------\n\n");

  }// display for loop --> finished
  doWant(); //i asked what do you do want.
}// sortCarID --> finished

int quitprogram(){
  printf("\nGoodbye :)\n");
  return -1;
}
