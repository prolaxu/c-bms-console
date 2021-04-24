#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*detecting os and giveing clearing screen command  according to os*/
#if defined(WIN64) || defined(WIN32)
char clear[]="cls";
#else
char clear[]="clear";
#endif

// defing variables
FILE *file;
int lid;


struct update {
   char  act[50];
   int  id;
   int  did;
   int  bid;
   char  name[100];
   char  age[50];
   char  pnumber[50];
   char  email[100];
   float  balance;
};

struct logt
{
    int status;
    int bid;
    int did;
    float amt;
};

//Function Prototypes
void gotoxy();
void drawhome();
void drawbox();
void actions();
void alert();
void cacc();
int fsize();
void read_ac();
void allt();
void oacc();
void up_date();
int findlid();
void cal();
void adminlogin();

//main Function
int main(){
    system(clear); //clears the screen
    drawhome();
    read_ac(0,"lac");
   // adminlogin(); // login 
    return 0;
}

//For printing data in specific position in the screen with x and y cordinate
void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}

//draw all Ui of home
void drawhome(){
    system(clear);
    drawbox(1,1,90,43,"#","##");
    drawbox(30,5,30,2,"#","");
    gotoxy(33,6);
    printf(" Bank Management System ");
    drawbox(8,10,74,17,"-","|"); 
    
}

//print box shape
void drawbox(int x,int y,int xlen,int ylen,char xtok[],char ytok[]){
    int i,j;
    int sl= strlen(ytok)-1;
    for ( i = y; i <= ylen+y; i++)
    {
         if (i==y || i==ylen+y ){
                // printf("\n");
                gotoxy(x,i);
                for (j=x;j<=x+xlen;j++){
                    printf("%s",xtok);  
                    }
            }else{
                    gotoxy(x,i);
                    printf("%s",ytok);
                    gotoxy(x+xlen-sl,i);
                    printf("%s",ytok);
            }
    }
}


//prints all options and calls actions
void actions(){
    int ch;
    struct update data;
    float nb;
    int an,dan,ban;
    gotoxy(5,30);
    printf("Choose the actions: \n##   1.Create New Account \n##   2.Account Enquiry \n##   3.Customer List \n##   4.All Transations \n##   5.Doposit \n##   6.Withdraw \n##   7.Transfer \n##   8.Delete Account \n##   0.Exit \n## =>");
    scanf("%d",&ch);
    
    if (ch==1){
        //regenerate screen
        drawhome();
        cacc();
    }else if (ch==2){
        //Load account info
        int id;
        gotoxy(49,25);
        printf(" ");
        gotoxy(30,23);
        printf("Load Account Information:");
        gotoxy(34,25);
        printf("Account Number:");
        scanf("%d",&id);
        drawhome();
        read_ac(id,"oac");
    }else if(ch==3){  
        //Prints all accounts
        drawhome();
        read_ac(0,"lac");
    }else if(ch==4){
        //prints logs
        drawhome();
        allt(); 
    }else if(ch==5){
        //Action to Deposite
        drawhome();
        gotoxy(30,15);
        printf("Doposit Account Information:");

        gotoxy(34,16);
        printf("Account Number : ");
        scanf("%d",&an);
        gotoxy(34,17);
        printf("Diposit amount : ");
        scanf("%f",&nb);

        data.id=an;
        strcpy(data.act,"ub");
        data.balance=nb;
        up_date(data);
    }else if(ch==6){
        //Action to Withdraw
        drawhome();
        gotoxy(30,15);
        printf("Withdraw Account Information:");
        gotoxy(34,16);
        printf("Account Number :");
        scanf("%d",&an);

        gotoxy(34,17);
        printf("Withdraw amount : ");
        scanf("%f",&nb);
        
        data.id=an;
        strcpy(data.act,"wb");
        data.balance=nb;
        up_date(data);

    }else if(ch==7){
        //Action to Trasfur
        drawhome();
        gotoxy(30,15);
        printf("Transfer Accounts Information:");
        gotoxy(34,16);
        printf("Drawback Account Number :");
        scanf("%d",&dan);

        gotoxy(34,17);
        printf("Transfer  Amount : ");
        scanf("%f",&nb);

        gotoxy(34,18);
        printf("Benificial Number :");
        scanf("%d",&ban);
        
        data.did=dan;
        data.bid=ban;
        strcpy(data.act,"tb");
        data.balance=nb;
        up_date(data);

    }else if (ch==8){
        //Action to Delete
        drawhome();
        gotoxy(30,15);
        printf(" Delete Account :");
        gotoxy(34,16);
        printf("Account Number :");
        scanf("%d",&an);
        data.id=an;
        strcpy(data.act,"dl");
        up_date(data);


    }
    else if (ch==0){
        //End Program
        alert("Thanks for Using This Program");
        gotoxy(1,45);
        printf("Program Closed \n");
        exit(0);
    }else{
        //if out of option
        drawhome();
        alert("Invalid Command !");
        actions();
    }
}
//print alert massage 
void alert(char str[]){
    drawbox(25,28,35,2,"#","#");
    gotoxy(30,29);
    printf("%s",str);
    
}

//stores account info in file
void store_ac(char name[],char dob[],char phone_no[],char  email[],float balance){
	file= fopen("db/accounts.db","a+");
	if (file==NULL)
	{
		alert("Err: DB file not opend.");
	}else{
        int id=findlid(file)+1;
		fprintf(file,"\n%d,%s,%s,%s,%s,%f,e:",id,name,dob,phone_no,email,balance);
		fclose(file);
        gotoxy(40,20);
        printf("| Note You New Account number : %d |",id);
	}
}

//Create account Action
void cacc(){
    int i,j;
    for ( i = 0; i <= 6; i++)
    {
        gotoxy(15,i+12);
        for ( j = 0; j <= 10; j++)
        {
            printf("#");
        }
    }
    
    int s=35,age;
    char phone_no[15];
    char name[50];
    char dob[11];
    char email[50];
    float balance;
    char temp;
    gotoxy(s,13);
    printf("Name             : ");
    scanf("%c",&temp); 
    scanf("%[^\n]",name);
    
    gotoxy(s,14);
    printf("DOB (dd-mm-yyyy) : ");
    scanf("%s",dob);

    gotoxy(s,15);
    printf("Phone No         : ");
    scanf("%s",phone_no);
    gotoxy(s,16);
    printf("Email            : ");
    scanf("%s",email);
    gotoxy(s,17);
    printf("First Diposit    : ");
    scanf("%f",&balance);
    store_ac(name,dob,phone_no,email,balance);
    alert("Account Created.");
    actions();

}


//Read account info
void read_ac(int id,char act[]){

    FILE *fptr;
    if ((fptr = fopen("db/accounts.db", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    int sz = fsize(fptr);
    char data[sz];
    // reads text until newline is encountered
    char fend[1]=";";
    char *mdata = strcat(data,fend);
    fscanf(fptr, "%[^;]", mdata);
    fclose(fptr);
    
    char *end_line;
    char *end_sd;
    char * line = strtok_r(data, "\n",&end_line);
    char * sd;
    char *array[5];
    

    char ary[6][20];
    char *s;
    int c=0;
    while( line != NULL ) {
        sd = strtok_r(line, ",",&end_sd);
        int i=0;
        while( sd != NULL ) {
            array[i++] = sd;
            sd = strtok_r(NULL, ",",&end_sd);
        }
        if ( strcmp(act,"oac")==0 && atoi(array[0])==id){
                    oacc(array[0],array[1],array[2],array[3],array[4],array[5]);
                    break;
                
                }else if(strcmp(act,"lac")==0){
                    gotoxy(10,13+c);
                    printf("Account no :%s  Name :%s  Balance :Rs. %s", array[0],array[1],array[5]);
                    
                }else if(strcmp(act,"lid")==0){
                    lid=atoi(array[0]);
                }  

        line = strtok_r(NULL, "\n",&end_line);
        c++;
   }

   if(strcmp(act,"lid")!=0){
       actions();
    }
    
}

//get file size
int fsize(FILE *fp){
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz=ftell(fp);
    fseek(fp,prev,SEEK_SET); //go back to where we were
    return sz;
}

//prints account info
void oacc(int id,char name[],char dob[],char phone_no[],char email[] ,char balance[]){
    int i,j;
    for ( i = 0; i <= 6; i++)
    {
        gotoxy(15,i+12);
        for ( j = 0; j <= 10; j++)
        {
            printf("#");
        }
    }
    
    int s=35;
    gotoxy(s,13);
    printf("Name             : ");
    printf("%s",name); 
    

    gotoxy(s,14);
    printf("DOB (dd-mm-yyyy) : ");
    printf("%s",dob);

    gotoxy(s,15);
    printf("Phone No         : ");
    printf("%s",phone_no);
    gotoxy(s,16);
    printf("Email            : ");
    printf("%s",email);
    gotoxy(s,17);
    printf("Balance          : ");
    printf("%s",balance);
     alert("Account Information !");
    actions();

}

//prints all transation log
void allt(){
char * line = NULL;
    size_t len = 0;
    ssize_t read;

    file = fopen("db/transations.db", "r");
    if (file == NULL)
        exit(EXIT_FAILURE);

    int c=0;
    while ((read = getline(&line, &len, file)) != -1) {


        int i = 0;
        char *p = strtok (line, ",");
        char *array[3];

        

        while (p != NULL)
        {
            array[i++] = p;
            p = strtok (NULL, ",");
        }

        gotoxy(15,13+c);
        printf("Transation No :%s => Rs.%s ",array[0],array[3]);
        gotoxy(16,14+c);
        printf("[ From Account Number: %s To Account Number: %s ]",array[1],array[2]);
        gotoxy(16,15+c);
        printf("-----------------------------------------------------------------");
        c=c+3;
    }
    
    
    fclose(file);
    if (line)
        free(line);
    actions();
    
}

//update account info infile
void up_date(struct update ud){
 FILE *fptr;
    FILE *toupdate;
    
    if ((fptr = fopen("db/accounts.db", "r")) == NULL) {
        alert("Error: DB Error");
    }
    int sz = fsize(fptr);
    char data[sz];
    char fend[1]=";";
    char *mdata = strcat(data,fend);
    fscanf(fptr, "%[^;]", mdata);
    fclose(fptr);

    char target[sz];
    char *end_line;
    char *end_sd;
    char * line = strtok_r(data, "\n",&end_line);
    char * sd;

    char *array[5];
    int c=0;
    int dls=0;

    struct logt transations;
    

    toupdate = fopen("db/accounts.db","w");
   if(toupdate == NULL)
   {
        alert("Error: DB Error");          
   }
    while( line != NULL ) {
        sd = strtok_r(line, ",",&end_sd);
        int i=0;
        while( sd != NULL ) {
            array[i++] = sd;
            sd = strtok_r(NULL, ",",&end_sd);
        }
        if (strcmp(ud.act,"ub")==0)
        {
            if (atoi(array[0])==ud.id){
                if(c==0){
                    snprintf( target, sizeof( target ), "%s,%s,%s,%s,%s,%f,e:",array[0],array[1],array[2],array[3],array[4],atof(array[5])+ud.balance);
                }else{
                     snprintf( target, sizeof( target ), "\n%s,%s,%s,%s,%s,%f,e:",array[0],array[1],array[2],array[3],array[4],atof(array[5])+ud.balance);
                }
            
            }else{
                if(c==0){
                    snprintf( target, sizeof( target ), "%s,%s,%s,%s,%s,%s,e:",array[0],array[1],array[2],array[3],array[4],array[5]);
                }else{
                    snprintf( target, sizeof( target ), "\n%s,%s,%s,%s,%s,%s,e:",array[0],array[1],array[2],array[3],array[4],array[5]);
                }
            
        }
        }else if(strcmp(ud.act,"wb")==0){
            if (atoi(array[0])==ud.id){
                if(c==0){
                 snprintf( target, sizeof( target ), "%s,%s,%s,%s,%s,%f,e:",array[0],array[1],array[2],array[3],array[4],atof(array[5])-ud.balance);    
                }else{
                     snprintf( target, sizeof( target ), "\n%s,%s,%s,%s,%s,%f,e:",array[0],array[1],array[2],array[3],array[4],atof(array[5])-ud.balance);
                }
            
           
            }else{
                if(c==0){
                snprintf( target, sizeof( target ), "%s,%s,%s,%s,%s,%s,e:",array[0],array[1],array[2],array[3],array[4],array[5]);    
                }else{
                    snprintf( target, sizeof( target ), "\n%s,%s,%s,%s,%s,%s,e:",array[0],array[1],array[2],array[3],array[4],array[5]);
                }
            
        }
        }else if(strcmp(ud.act,"tb")==0){
            
            if (atoi(array[0])==ud.bid){
                if(c==0){
                    snprintf( target, sizeof( target ), "%s,%s,%s,%s,%s,%f,e:",array[0],array[1],array[2],array[3],array[4],atof(array[5])+ud.balance);
                }else{
                    snprintf( target, sizeof( target ), "\n%s,%s,%s,%s,%s,%f,e:",array[0],array[1],array[2],array[3],array[4],atof(array[5])+ud.balance);
                }
            
            transations.bid=ud.bid;
            transations.amt=ud.balance;
            transations.status=1;
            }else if (atoi(array[0])==ud.did){
                if(c==0){
                snprintf( target, sizeof( target ), "%s,%s,%s,%s,%s,%f,e:",array[0],array[1],array[2],array[3],array[4],atof(array[5])-ud.balance);    
                }else{
                    snprintf( target, sizeof( target ), "\n%s,%s,%s,%s,%s,%f,e:",array[0],array[1],array[2],array[3],array[4],atof(array[5])-ud.balance);
                }
            
            transations.did=ud.did;
            }else{
                if(c==0){
                    snprintf( target, sizeof( target ), "%s,%s,%s,%s,%s,%s,e:",array[0],array[1],array[2],array[3],array[4],array[5]);
                }else{
                    snprintf( target, sizeof( target ), "\n%s,%s,%s,%s,%s,%s,e:",array[0],array[1],array[2],array[3],array[4],array[5]);
                }
            
            }

        }else if (strcmp(ud.act,"dl")==0)
        {
            if (atoi(array[0])!=ud.id){
                if(c==0){
                 snprintf( target, sizeof( target ), "%s,%s,%s,%s,%s,%s,e:",array[0],array[1],array[2],array[3],array[4],array[5]);    
                }else{
                     snprintf( target, sizeof( target ), "\n%s,%s,%s,%s,%s,%s,e:",array[0],array[1],array[2],array[3],array[4],array[5]);
                }
           
            //printf("%s",target);
            fprintf(toupdate,"%s",target);
            dls=1;
        }
        }
        
       if (dls==0)
       {
          //printf("%s",target);
          fprintf(toupdate,"%s",target);
       }
       
        line = strtok_r(NULL, "\n",&end_line);
        c++;
   }
   fclose(toupdate);

   if (transations.status==1)
   {
       toupdate = fopen("db/transations.db","a+");
        if(toupdate == NULL)
        {
                alert("Error: DB Error");          
        }
        fprintf(toupdate,"%d,%d,%d,%f\n",findlid(toupdate)+1,transations.did,transations.bid,transations.amt);
        fclose(toupdate);
        transations.status=0;
   }

   if(strcmp(ud.act,"wb")==0){
               alert("Ammount Withdrawed.");
   }else if(strcmp(ud.act,"ub")==0){
               alert("Ammount Doposited.");
   }else if(strcmp(ud.act,"tb")==0){
               alert("Ammount Transfured.");
   }else if(strcmp(ud.act,"dl")==0){
               alert("Account Deleted.");
   }
    actions();
   

}


//finds last id in file
int findlid( FILE *fptr) {
    int sz = fsize(fptr);
    char data[sz];
    // reads text until newline is encountered
    char fend[1]=";";
    char *mdata = strcat(data,fend);
    fscanf(fptr, "%[^;]", mdata);
    
    
    char *end_line;
    char *end_sd;
    char * line = strtok_r(data, "\n",&end_line);
    char * sd;

    char *array[5];
    

    char ary[6][20];
    char *s;
    int c=0;
    int lid;
    while( line != NULL ) {
        sd = strtok_r(line, ",",&end_sd);
        int i=0;
        while( sd != NULL ) {
            array[i++] = sd;
            sd = strtok_r(NULL, ",",&end_sd);
        }
       lid=atoi(array[0]);
        line = strtok_r(NULL, "\n",&end_line);
        c++;
   }
    return lid;
}

//Admin Login action
void adminlogin(){
    char user[30];
    char pass[30];
    int i,j;

    gotoxy(55,5);
    printf(" Admin Login:");
    drawbox(28,7,64,7,"#","#");
    
    
    gotoxy(30,10);
    printf("User Name : ");
    scanf("%s",user);
    gotoxy(30,12);
    printf("Password  : ");
    scanf("%s",pass);


    char dbuser[30];
    char dbpass[30];
	file= fopen("db/admin.db","r");
	if (file==NULL)
	{
		printf("Err: Not opend");
	}else{
		fscanf(file,"%s %s\n",dbuser,dbpass);
		fclose(file);
	}

    if (strcmp(dbuser,user)==0 && strcmp(dbpass,pass)==0 )
    {
        drawhome();
        actions();
    }else{
         gotoxy(47,15);
         system(clear);
         printf("Login Failed Invalid Cradintatial.");
         adminlogin();
    }
    

}