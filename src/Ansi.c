#include <Rdvtr/Ansi.h>

ae2f_SHAREDEXPORT
int32_t Rdvtr_AnsiMeasure(
    const char* prm_string,
    int32_t* firstpadret_optional
) {
    int32_t firstpadret, length = 0;
    if(!firstpadret_optional) firstpadret_optional = &firstpadret;
    if(!prm_string) goto NFound;

    #define firstpadret (*firstpadret_optional)
    firstpadret = 0;
    while(1) {
        switch(prm_string[firstpadret]) {
            case 0: goto NFound;
            case '\033': {
                if(prm_string[firstpadret + 1] == '[')
                goto EscapeWhile1;
                goto NFound;
            }
        }

        firstpadret++;
    } EscapeWhile1: 

    prm_string += firstpadret + 1;
    while(2) {
        switch(prm_string[length]) {
            case 0: goto NFound;
            case 'm': goto EscapeWhile2;
        }
        length++;
    } EscapeWhile2:

    #undef firstpadret
    return length + 3; // '\033', '[', 'm' 

    NFound:
    *firstpadret_optional = -1;
    return -1;
}