#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Structure POINTS
typedef struct point{
    int x, y;

}POINT;

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
 POINT *Exam(char *pInput, int *pnPoints);
 POINT *points_g;


////////////////////////////////////////////////// Main Function ////////////////////////////////////////////////////
int main(){
    char *input_string; size_t bufsize = 3000;
    input_string = (char *) malloc (bufsize);
    int points_num=0;

    // (40,50); (40,50); (20,  70);    ( 56,  78);(40,50);  (20,  70);   (80,30);
    getline(&input_string, &bufsize, stdin);

    char *out;
    out = trim_all(input_string);
    strcpy(input_string, out);
    input_string[strlen(input_string)-1]='\0';

    points_g = Exam(input_string, &points_num);
    // free(input_string);
    printf("\nThere are %d points stored.\n", (points_num));
    printf("\n");
    for(int i=0;i<(points_num);i++)
        printf("Point No: %d -- X-Coordinate: %d, Y-Coorddinate: %d\n", i+1, points_g[i].x, points_g[i].y);

    printf("\n");
    // free(items_g);
    return 0;
}

///////////////////////////////////////////////////// Assigned Fucntion ////////////////////////////////////////////////
 POINT *Exam(char *pInput, int *pnPoints){
    char** point;
    int point_number=0, flag=0;
    if(pInput[strlen(pInput)-2]!=';') flag=1;

    point = str_split(pInput, ';');
    if(point){
        for(int i = 0; *(point +i); i++) point_number = i;
        if(flag) point_number++;
    }


    POINT *points;
    if( (points =(POINT *) malloc(sizeof(POINT)*point_number)) == NULL) puts("malloc fail");

    if(point){
        int i;
        for(i=0; *(point+i); i++){

            char *_point_tmp;
            _point_tmp = (char *)malloc(sizeof(char)*strlen(*(point+i)));
            strcpy(_point_tmp, *(point+i));
            int _tmp_len = strlen(_point_tmp);
            char _point[_tmp_len];
            for(int inx=0;inx<(int)_tmp_len;inx++){
                if(inx == 0) continue;
                if(inx == _tmp_len-1) continue;
                _point[inx-1]=_point_tmp[inx];
            }

            if(strlen(_point)==1) break;

            char **point_comp;
            point_comp = str_split(_point, ',');
            for(int j=0;*(point_comp+j);j++){
                int x_int;
                sscanf(*(point_comp+j), "%d", &x_int);

                if(j==0){
                    points[i].x= x_int;
                }
                else{
                    points[i].y = x_int;
                }
                free(*(point_comp+j));
            }
            //printf("%d -- x: %d, y: %d\n", i, points[i].x, points[i].y);

            free(*(point+i));

            //free(_point_tmp);
        }

    }
     free(point);

    for(int p = 0; p<point_number; p++){
        int x_tmp = points[p].x;
        int y_tmp = points[p].y;
        for(int q = p+1; q<point_number;){
            if(points[q].x == x_tmp && points[q].y == y_tmp){
                for(int r = q; r<point_number; r++){
                    points[r].x = points[r+1].x;
                    points[r].y = points[r+1].y;
                }
                point_number--;
                points =(POINT *) realloc(points, sizeof(POINT)*point_number);
            } else q++;
        }
    }

    *pnPoints = point_number;

    return points;

}
