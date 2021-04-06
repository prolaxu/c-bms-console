void read_ac(int id,char act[]){

    FILE *fptr;
    if ((fptr = fopen("db/accounts.db", "r")) == NULL) {
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
    
    char * sd;
    char *array[5];
    int c=0;
    
    char * line = strtok_r(data, "\n",&end_line);
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