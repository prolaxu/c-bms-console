#include <stdio.h>
#include <stdlib.h> // For exit() function
#include <string.h>
int fsize(FILE *fp){
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz=ftell(fp);
    fseek(fp,prev,SEEK_SET); //go back to where we were
    return sz;
}

int line(char * token){

        char * line = strtok(token, ",");
        printf("%s",line);
          
        
    return 0;
}


int main() {
    FILE *fptr;
    char *newdata;
    if ((fptr = fopen("data.db", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    int sz = fsize(fptr);
    char data[sz];
    // reads text until newline is encountered
    fscanf(fptr, "%[^;]", data);
    fclose(fptr);
    
    char *end_line;
    char *end_sd;
    char * line = strtok_r(data, "\n",&end_line);
    char * sd;

    char *array[5];
    

    char ary[6][20];
    char *s;
    int c=0;
    char br[]="\n";
    while( line != NULL ) {
        sd = strtok_r(line, ",",&end_sd);
        int i=0;
        while( sd != NULL ) {
            array[i++] = sd;
            sd = strtok_r(NULL, ",",&end_sd);
        }
        if (atoi(array[0])==3)
        {
            strcat(newdata,line);
            strcat(newdata,br);
            printf("This is to be changed .");
            
        }else{
            strcat(newdata,line);
            strcat(newdata,br);
        }
        
        
        
        printf("%s \n",array[0]);
        line = strtok_r(NULL, "\n",&end_line);
   }
  // printf("%s",newdata);
    return 0;
}