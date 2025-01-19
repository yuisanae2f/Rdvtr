#include <Rdvtr/Ansi.h>
#include <stdio.h>

#define TestAnsiGood(str) \
printf("Testing Good ANSI [%s]...\n", str); \
if(Rdvtr_AnsiMeasure(str, 0) != sizeof(str)) { \
    printf("Error Diff: %d %d\n", sizeof(str), Rdvtr_AnsiMeasure(str, 0)); \
    return Rdvtr_AnsiMeasure(str, 0) - sizeof(str); \
}

#define TestAnsiGoodWithTail(str, appendix) \
printf("Testing Good ANSI [%s] With Tail [%s] as [%s]...\n", str, appendix, str appendix); \
if(Rdvtr_AnsiMeasure(str appendix, 0) != sizeof(str)) { \
    printf("Error Diff: %d %d\n", sizeof(str), Rdvtr_AnsiMeasure(str, 0)); \
    return Rdvtr_AnsiMeasure(str appendix, 0) - sizeof(str); \
}

#define TestAnsiBad(str) \
printf("Testing Bad ANSI [%s]...\n", str); \
if(Rdvtr_AnsiMeasure(str, &V) && V != -1) { \
    printf("No, it must not find it.\n"); \
    return -1; \
}

#define TestAnsiPad(str, pad) \
printf("Testing Ansi [%s] with Pad [%s] as [%s]...\n", str, pad, str pad); \
if(Rdvtr_AnsiMeasure(str, &V) != sizeof(str) && V != sizeof(pad)) { \
    printf(""); \
}

int main() {
    int32_t V;

    // Good
    TestAnsiGood("\033[30m");
    TestAnsiGood("\033[40m");
    TestAnsiGood("\033[1;31m");
    TestAnsiGood("\033[m");

    // Good with tail
    TestAnsiGoodWithTail("\033[30m", "Would work");
    TestAnsiGoodWithTail("\033[30m", "With another ANSI Like \033[30m");
    TestAnsiGoodWithTail("\033[30m", "Or with out of ASCII like 한글?");

    // Bad
    TestAnsiBad("Just Bad");
    TestAnsiBad("\033Test");
    TestAnsiBad("\033[HasNoM_SMALL");
    TestAnsiBad("\033NoOpeningSquare");

    // Pad
    TestAnsiPad("\033[30m", "Would work with ANSI");

    puts("Test went all good!");
    return 0;
}