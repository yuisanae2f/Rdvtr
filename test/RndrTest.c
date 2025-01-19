#include <Rdvtr/Rndr.h>
#include <stdio.h>

int main() {
    size_t len;

    // Blank
    if(Rdvtr_RndrGen(0, "", 0) != 1) {
        printf("Must be 1 but got: %d\n", Rdvtr_RndrGen(0, "", 0));
        return 1;
    }

    // Not really blank
    if(Rdvtr_RndrGen(0, "Hello World!", 0) != sizeof("Hello World!")) {
        printf(
            "Must be %d but got %d\n", 
            sizeof("Hello World!"), 
            Rdvtr_RndrGen(0, "Hello World!", 0)
        );
        return 1;
    }

    return 0;
}