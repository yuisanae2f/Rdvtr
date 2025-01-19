#ifndef Rdvtr_Ansi_h
#define Rdvtr_Ansi_h

#include <ae2f/Call.h>
#include <ae2f/Cast.h>
#include <stdint.h>

/// @brief Not found
#define Rdvtr_AnsiMeasureNFOUND ((int32_t)0)

/// @warning
/// Notice this code will find only one ANSI code.
/// @brief
/// Try to find one ANSI code. \n
/// If found, count the characters until it ends.
/// @param[in] prm_string
/// @param[out] firstpadret_optional
/// Returns the index where the ANSI code starts. 
/// @return 
/// The width of the ANSI Code found.
ae2f_extern ae2f_SHAREDCALL int32_t Rdvtr_AnsiMeasure(
    const char* prm_string, 
    int32_t* firstpadret_optional
);

#endif