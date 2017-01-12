#ifndef KMP_H
#define KMP_H

#ifdef __cplusplus
extern "C" {
#endif

/*
1 argument: pattern as char array that will be looked for. '\0' is the end of pattern
2 argument: data as char array in which pattern will be looked for. '\0' is the end of data
resault: pointer to array of inteagers. Each inteager represents that pattern starts at this
         index in data. -1 represents that previous inteager was last occurenc of pattern in data.
         Array possibly can be greater then number of founded occurences of pattern
         !!!Array have to be manualy freeded by user!!!
*/
int* KMP(char* pattern, char* data);


#ifdef __cplusplus
}  //extern "C"
#endif

#endif // KMP_H
