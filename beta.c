#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char clear[5]="clear";
FILE *file;
int lid;
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

int main(){
    drawhome();
    actions();
    //read_ac(0,"lid");
    //printf("%d \n",lid);
    return 0;
}
void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}
void drawhome(){
    system(clear);
    drawbox(1,1,89,43,"#","##");
    drawbox(30,5,30,2,"#","");
    gotoxy(33,6);
    printf(" Bank Management System ");
    drawbox(8,10,74,17,"-","|"); 
    
}

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

void actions(){
    int ch;
    gotoxy(5,30);
    printf("Choose the actions: \n##   1.Create New Account \n##   2.Account Enquiry \n##   3.Customer List \n##   4.All Transations \n##   5.Doposit \n##   6.Withdraw \n##   7.Transfer \n##   0.Exit \n## =>");
    scanf("%d",&ch);
    
    if (ch==1){
        drawhome();
        cacc();
    }else if (ch==2){
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
        drawhome();
        read_ac(0,"lac");
    }else if(ch==4){
        drawhome();
        allt(); 
    }else if (ch==0){
        alert("Thanks for Using This Program");
        exit(0);
    }else{
        drawhome();
        alert("Invalid Command !");
        actions();
    }
}
void alert(char str[]){
    drawbox(25,28,35,2,"#","#");
    gotoxy(30,29);
    printf("%s",str);
    
}
void store_ac(char name[],int age,char dob[],char phone_no[],char  email[],float balance){
	file= fopen("db/accounts.db","a");
	if (file==NULL)
	{
		alert("Err: DB file not opend.");
	}else{
        read_ac(0,"lid");
        int id=lid+1;
		fprintf(file,"\n%d,%s,%d,%s,%s,%s,%f",id,name,age,dob,phone_no,email,balance);
		fclose(file);
        gotoxy(40,20);
        printf("| Note You New Account number : %d |",id);
	}
}

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
    printf("Age              : ");
    scanf("%d",&age);

    gotoxy(s,15);
    printf("DOB (dd-mm-yyyy) : ");
    scanf("%s",dob);

    gotoxy(s,16);
    printf("Phone No         : ");
    scanf("%s",phone_no);
    gotoxy(s,17);
    printf("Email            : ");
    scanf("%s",email);
    gotoxy(s,18);
    printf("First Diposit    : ");
    scanf("%f",&balance);
    store_ac(name,age,dob,phone_no,email,balance);
    alert("Account Created.");
    actions();

}



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
                    oacc(array[0],array[1],array[2],array[3],array[4],array[5],array[6]);
                    break;
                
                }else if(strcmp(act,"lac")==0){
                    gotoxy(10,13+c);
                    printf("Account no :%s  Name :%s  Balance :Rs. %s", array[0],array[1],array[6]);
                    
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

int fsize(FILE *fp){
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz=ftell(fp);
    fseek(fp,prev,SEEK_SET); //go back to where we were
    return sz;
}

void oacc(int id,char name[],char age[],char dob[],char phone_no[],char email[] ,char balance[]){
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
    printf("Age              : ");
    printf("%s",age);

    gotoxy(s,15);
    printf("DOB (dd-mm-yyyy) : ");
    printf("%s",dob);

    gotoxy(s,16);
    printf("Phone No         : ");
    printf("%s",phone_no);
    gotoxy(s,17);
    printf("Email            : ");
    printf("%s",email);
    gotoxy(s,18);
    printf("Balance          : ");
    printf("%s",balance);
     alert("Account Information !");
    actions();

}

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
        //printf("Transation No :%s => Rs.%s [ From Account Number: %s To Account Number: %s ]",array[0],array[3],array[1],array[2]);
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