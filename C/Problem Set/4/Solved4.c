#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Structure ITEM
typedef struct employee{
    char *pFirstName, *pMiddleName, *pLastName;
    int Brutto, TaxCoefficient, Netto;
}EMPLOYEE;

/////////////////////////////////////////// Additional Functions ////////////////////////////////////////////////////

/*
Function to get a line as input string
Not a standard C library function.
If the library libc 4.2... is present, the function is already expected to be in the standard library.
In that scenario, change the name of the function.
*/

size_t getline(char **lineptr, size_t *n, FILE *stream) {
    char *bufptr = NULL;
    char *p = bufptr;
    size_t size;
    int c;

    if (lineptr == NULL) {
        return -1;
    }
    if (stream == NULL) {
        return -1;
    }
    if (n == NULL) {
        return -1;
    }
    bufptr = *lineptr;
    size = *n;

    c = fgetc(stream);
    if (c == EOF) {
        return -1;
    }
    if (bufptr == NULL) {
        bufptr = malloc(128);
        if (bufptr == NULL) {
            return -1;
        }
        size = 128;
    }
    p = bufptr;
    while(c != EOF) {
        if ((p - bufptr) > (size - 1)) {
            size = size + 128;
            bufptr = realloc(bufptr, size);
            if (bufptr == NULL) {
                return -1;
            }
        }
        *p++ = c;
        if (c == '\n') {
            break;
        }
        c = fgetc(stream);
    }

    *p++ = '\0';
    *lineptr = bufptr;
    *n = size;

    return p - bufptr - 1;
}


char **str_split(char* _str, char delim){
    char **out=0;
    size_t count=0;
    char* tmp=_str;
    char* last_split=0;
    char split_c[2]; split_c[0]=delim; split_c[1]=0;

    while(*tmp){
        if(split_c[0] == *tmp){
            count++;
            last_split=tmp;
        }
        tmp++;
    }

    count += last_split < (_str+strlen(_str) - 1);
    count++;

    out = malloc(sizeof(char*) * count);

    if(out){
        size_t index = 0;
        char* token=strtok(_str, split_c);

        while(token){
            assert(index < count);
            *(out + index++)=strdup(token);
            token=strtok(0, split_c);
        }
        assert(index == count - 1);
        *(out + index) = 0;
    }
    return out;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Definitions
 EMPLOYEE *Exam(char *pInput);
 EMPLOYEE *items_g;
 int item_number=0;

////////////////////////////////////////////////// Main Function ////////////////////////////////////////////////////
int main(){
    char *input_string; size_t bufsize = 3000;
    input_string = (char *) malloc (bufsize);

    // John James Smith 15000
    getline(&input_string, &bufsize, stdin);
    input_string[strlen(input_string)-1]='\0';
    if(input_string[strlen(input_string) - 1] != ' ') strcat(input_string, " ");
    strcat(input_string, "\n");

    items_g = Exam(input_string);

    if(item_number==4) printf("\n\n%s %s %s with Brutto: %d, Tax: %d, Netto: %d\n\n", items_g->pFirstName, items_g->pMiddleName, items_g->pLastName, items_g->Brutto, items_g->TaxCoefficient, items_g->Netto);
    else printf("\n\n%s %s with Brutto: %d, Tax: %d, Netto: %d\n\n", items_g->pFirstName, items_g->pLastName, items_g->Brutto, items_g->TaxCoefficient, items_g->Netto);
    return 0;
}

///////////////////////////////////////////////////// Assigned Fucntion ////////////////////////////////////////////
 EMPLOYEE *Exam(char *pInput){
    char** item;

    item = str_split(pInput, ' ');

    if(item){
        for(int i = 0; *(item +i); i++) item_number = i;
    }


    EMPLOYEE *item_struct;
    if( (item_struct =(EMPLOYEE *) malloc(sizeof(EMPLOYEE))) == NULL) puts("malloc fail");

    if(item){
        int i;
        for(i=0; *(item+i); i++){
            if(!*(item+i+1)) break;
            char *_item = (char *)malloc(strlen(*(item+i))*sizeof(char));
            strcpy(_item, *(item+i));

            if(i==0){
                //item_struct->pFirstName = (char *)realloc(item_struct->pFirstName, sizeof(char)*strlen(_item));
                item_struct->pFirstName = (char *)malloc(sizeof(char)*strlen(_item));
                //memcpy(item_struct->pFirstName, _item, strlen(_item));
                strcpy(item_struct->pFirstName, _item);
            } else if(i==1){
                if(item_number == 4){
                    //item_struct->pMiddleName = (char *)realloc(item_struct->pMiddleName, sizeof(char)*strlen(_item));
                    item_struct->pMiddleName = (char *)malloc(sizeof(char)*strlen(_item));
                    //memcpy(item_struct->pMiddleName, _item, strlen(_item));
                    strcpy(item_struct->pMiddleName, _item);
                } else {
                    //item_struct->pLastName = (char *)realloc(item_struct->pLastName, sizeof(char)*strlen(_item));
                    item_struct->pLastName = (char *)malloc(sizeof(char)*strlen(_item));
                    //memcpy(item_struct->pLastName, _item, strlen(_item));
                    strcpy(item_struct->pLastName, _item);
                }
            } else if(i==2){
                if(item_number == 4){
                    //item_struct->pLastName = (char *)realloc(item_struct->pLastName, sizeof(char)*strlen(_item));
                    item_struct->pLastName = (char *)malloc(sizeof(char)*strlen(_item));
                    //memcpy(item_struct->pLastName, _item, strlen(_item));
                    strcpy(item_struct->pLastName, _item);
                } else {
                    int x_int;
                    sscanf(_item, "%d", &x_int);
                    item_struct->Brutto = x_int;
                }
            } else if(i==3){
                int x_int;
                sscanf(_item, "%d", &x_int);
                item_struct->Brutto = x_int;
            }
            free(*(item+i));
            free(_item);
        }
    }

    if(item_struct->Brutto > 10000) item_struct->TaxCoefficient = 25;
    if(item_struct->Brutto >= 7500 && item_struct->Brutto <= 10000) item_struct->TaxCoefficient = 20;
    if(item_struct->Brutto >= 5000 && item_struct->Brutto <= 7500) item_struct->TaxCoefficient = 15;
    if(item_struct->Brutto < 5000) item_struct->TaxCoefficient = 0;

    item_struct->Netto = (int) ((float)item_struct->Brutto - (float)item_struct->Brutto * (float)item_struct->TaxCoefficient / 100);

    return item_struct;

 }


