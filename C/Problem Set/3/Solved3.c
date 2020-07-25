#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Structure ITEM
typedef struct item{
    char *pName;
    int quantity, write_off;
}ITEM;

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

/*
Function for getting values for particular field
Arguments are the input string and the identifier for value
*/

char *get_field_value(char *str, char *identifier){

    char *ptr = strstr(str, identifier);
    char *pptr = strstr(ptr, ": ");
    char *part = (char *)malloc(sizeof(char)*strlen(pptr));
    memcpy(part, pptr, strlen(pptr));
    for(int i = 0; i < strlen(pptr); i++){
        part[i] = pptr[i+2];
        if(!pptr[i+2]) part[i]='\0';
    }
    char *ppart = (char *)memchr(part, ' ', strlen(part));
    char *pppart = (char *)malloc(sizeof(char)*strlen(pptr));
    if(ppart!=NULL) memcpy(pppart, part, (int)(ppart-part));
    else memcpy(pppart, part, strlen(part));
    return pppart;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Definitions
 ITEM *Exam(char *pInput, char *pItemName);
 ITEM *items_g;

////////////////////////////////////////////////// Main Function ////////////////////////////////////////////////////
int main(){
    char *input_string; size_t bufsize = 3000;
    input_string = (char *) malloc (bufsize);
    char item_name[]="Tuna";

    // S[Name: Johny Quantity: 1000 Expires: 10-2018] [Name: John Expires: 10-2019 Quantity: 1000 ] [ Quantity: 200 Name: Eve Expires: 3-2019]      [  Expires: 7-2019    Name: Yolla   Quantity: 600   ] [ Quantity: 500 Expires: 7-2020 Name: Doen  ]
    getline(&input_string, &bufsize, stdin);
    //input_string[strlen(input_string)-1]='\0';

    items_g = Exam(input_string, item_name);

    if(items_g!=0) printf("\n\n%s %d %d\n\n", items_g->pName, items_g->quantity, items_g->write_off);
    else printf("\nNo item found matching %s\n\n", item_name);
    return 0;
}

///////////////////////////////////////////////////// Assigned Fucntion ////////////////////////////////////////////
 ITEM *Exam(char *pInput, char *pItemName){
    char** item;

    item = str_split(pInput, ']');

    ITEM *item_struct;
    if( (item_struct =(ITEM *) malloc(sizeof(ITEM))) == NULL) puts("malloc fail");

    if(item){
        int i;
        for(i=0; *(item+i); i++){
            if(!*(item+i+1)) break;
            char *_item = (char *)malloc(strlen(*(item+i))*sizeof(char));
            strcpy(_item, *(item+i));
            //printf("%s\n",_item);

            char *item_name, *str_quantity, *str_expires;
            item_name = get_field_value(_item, "Name");
            str_quantity = get_field_value(_item, "Quantity");
            str_expires = get_field_value(_item, "Expires");

            if(strcmp(item_name, pItemName)==0) {
                int x_int, month, year;

                char **expires_comp;
                expires_comp = str_split(str_expires, '-');

                for(int k=0;*(expires_comp+k);k++){
                    sscanf(*(expires_comp+k), "%d", &x_int);
                    if(k==0) month = x_int;
                    else year = x_int;
                }

                free(str_expires);

                // Storing write_off
                if(year < 2019) item_struct->write_off = 1;
                else item_struct->write_off = 0;

                //Storing Quantity
                sscanf(str_quantity, "%d", &x_int);
                item_struct->quantity = x_int;

                //Storing Item Name
                //item_struct->pName = (char *)realloc(item_struct->pName, sizeof(char)*strlen(item_name));
                item_struct->pName = (char *)malloc(sizeof(char)*strlen(item_name));
                //memcpy(item_struct->pName, item_name, strlen(item_name));
                strcpy(item_struct->pName, item_name);

                //printf("%s %d %d\n", item_struct->pName, item_struct->quantity, item_struct->write_off);

                free(*(item+i));
                free(_item);

                return item_struct;
            }

        }

    }

    return 0;

}
