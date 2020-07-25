#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Structure ITEM
typedef struct item{
    char *pName;
    int Quantity, Price, Total;
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

/*
Function for trim all spaces from string
Argument is a pointer while returning also a pointer.
*/

char *trim_all(char *_str){
    int len, i = 0, j = 0;
    char *out;

    len = strlen(_str);

    out = (char *)malloc(len+1);

    while(*(_str+i)!='\0'){
        if(*(_str+i) == ' '){
            int count = i;
            if(*(_str+count)!='\0'){
                while(*(_str+count)==' ' && *(_str+count)!='\0'){
                    if(*(_str+count)==' ') i++;
                    count++;
                }
            }
        }
        *(out+j)=*(_str+i);
        i++;
        j++;
    }
    *(out+j)='\0';

    // Returns trimmed string
    return out;
}

/*
Function for splitting a string with a delimiter.
Arguments are the string to be split and the delimiter character
*/
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
 ITEM *Exam(char *pInput, int *pnItems);
 ITEM *items_g;

////////////////////////////////////////////////// Main Function ////////////////////////////////////////////////////
int main(){
    char *input_string; size_t bufsize = 3000;
    input_string = (char *) malloc (bufsize);
    int items_num=0;

    // Shirt, 100, 15; jacket, 10, 20; jeans, 30, 400;   toothbrush, 30, 90;     tops,  50,    300;  Socks, 20, 300;
    getline(&input_string, &bufsize, stdin);

    char *out;
    out = trim_all(input_string);
    strcpy(input_string, out);
    input_string[strlen(input_string)-1]='\0';

    items_g = Exam(input_string, &items_num);
    // free(input_string);
    printf("\nThere are %d items stored.\n", (items_num));
    printf("\n");

    for(int i=0;i<(items_num);i++)
        printf("Item No: %d -- Name: %s, Quantity: %d, Price: %d, Total: %d\n", i+1, items_g[i].pName, items_g[i].Quantity, items_g[i].Price, items_g[i].Total);

    printf("\n");
    // free(items_g);
    return 0;
}

///////////////////////////////////////////////////// Assigned Fucntion ////////////////////////////////////////////
 ITEM *Exam(char *pInput, int *pnItems){
    char** item;
    int item_number=0, flag=0;
    if(pInput[strlen(pInput)-2]!=';') flag=1;

    item = str_split(pInput, ';');
    if(item){
        for(int i = 0; *(item +i); i++) item_number = i;
        if(flag) item_number++;
    }

    *pnItems = item_number;


    ITEM *items;
    if( (items =(ITEM *) malloc(sizeof(ITEM)*item_number)) == NULL) puts("malloc fail");

    if(item){
        int i;
        for(i=0; *(item+i); i++){
            char *_item;
            strcpy(_item, *(item+i));
            char **item_comp;
            item_comp = str_split(_item, ',');
            for(int j=0;*(item_comp+j);j++){
                if(j==0){
                    items[i].pName = (char *)malloc((strlen(*(item_comp+j))+1)*sizeof(char));
                    strcpy(items[i].pName, *(item_comp+j));

                }
                else{
                    int x;
                    sscanf(*(item_comp+j), "%d", &x);
                    if(j==1){

                        items[i].Quantity = x;

                    }
                    if(j==2){
                        items[i].Price = x;
                        items[i].Total = items[i].Quantity*items[i].Price;

                    }
                }
                free(*(item_comp+j));
            }
            // printf("%d -- name: %s, quant: %d, price: %d, tot: %d\n", i, items[i].pName, items[i].Quantity, items[i].Price, items[i].Total);

            free(*(item+i));
            // free(_item);
        }

    }
    // free(item);
    return items;
}
