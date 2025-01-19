#include <Rdvtr/Rndr.hpp>
#include <stdio.h>
#include <string>

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
    ae2f::Ds::Arr::cOwner::Linear_t<Rdvtr_RndrQueryEl> query;
    
    query.Resize(2);
    query.Write(0, Rdvtr_RndrQueryEl {
        "Hello World!", 2
    });

    query.Write(1, Rdvtr_RndrQueryEl {
        "Hello World2", 4
    });
    if(
        Rdvtr_RndrGen(0, "asdf", (Rdvtr_RndrQuery*)&query) 
        != sizeof("Hello World!" "Hello World2" "asdf")
    ) {
        printf(
            "Must be %d but got %d\n"
            , sizeof("Hello World!" "Hello World2" "asdf")
            , Rdvtr_RndrGen(0, "asdf", (Rdvtr_RndrQuery*)&query)
        );

        return 1;
    }

    char Buff[sizeof("Hello World!" "Hello World2" "asdf")] = {0, };
    if(
        Rdvtr_RndrGen(Buff, "asdf", (Rdvtr_RndrQuery*)&query) 
        != sizeof("Hello World!" "Hello World2" "asdf")
    ) {
        printf(
            "Must be %d but got %d\n"
            , sizeof("Hello World!" "Hello World2" "asdf")
            , Rdvtr_RndrGen(Buff, "asdf", (Rdvtr_RndrQuery*)&query)
        );

        printf("Printed got: %s\n", Buff);
        return 1;
    }

    if(std::string(Buff) != std::string("asHello World!dfHello World2")) {
        printf("Not formed well.\n");
        printf("Malfunctioned output: %s\n", Buff);
        return 1;
    }

    puts("Done Gracefully!");

    return 0;
}