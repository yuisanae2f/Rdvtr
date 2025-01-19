#if __cplusplus
#include "Rndr.hpp"
#endif

#ifndef Rdvtr_Rnder_h
#define Rdvtr_Rnder_h

#include <ae2f/Call.h>
#include <ae2f/Cast.h>
#include <stdint.h>
#include <ae2f/Ds/Alloc.h>

/// @brief 
/// Element of insert queue so you don't need to 
typedef struct Rdvtr_RndrQueryEl {
    /// @brief 
    /// String you want to insert.
    const char* Str;

    /// @brief 
    /// The byte-count before the Rdvtr_RndrQueryEl::Str comes.
    size_t Pad;
} Rdvtr_RndrQueryEl;

/// @brief
/// # It does not own the memory. 
/// List type for Rndr Query.
/// For a handler, see @see ae2f::Ds::Arr::cRefer \n 
/// For an element, see @see Rdvtr_RndrQueryEl
typedef 
    ae2f_WhenC(ae2f_struct ae2f_cDsAllocRef)
    ae2f_WhenCXX(ae2f::Ds::Arr::cRefer<Rdvtr_RndrQueryEl>)
Rdvtr_RndrQuery;

/// @brief
/// # This type is already specified.
/// List type for Rndr Query.
/// For a handler, see @see ae2f::Ds::Arr::cRefer \n 
/// For an element, see @see Rdvtr_RndrQueryEl
typedef 
    ae2f_WhenC(ae2f_struct ae2f_cDsAllocRef)
    ae2f_WhenCXX(ae2f::Ds::Arr::cOwner::Linear_t<Rdvtr_RndrQueryEl>)
Rdvtr_RndrQueryOwnLinear;

/// @brief
/// # You will need to specify(implement) the methods.
/// List type for Rndr Query.
/// For a handler, see @see ae2f::Ds::Arr::cRefer \n 
/// For an element, see @see Rdvtr_RndrQueryEl
typedef 
    ae2f_WhenC(ae2f_struct ae2f_cDsAllocRef)
    ae2f_WhenCXX(ae2f::Ds::Arr::xrOwner<Rdvtr_RndrQueryEl>)
Rdvtr_RndrQueryOwnInterface;

/// @warning
/// This function does not consider the param [in]'s length.
/// Inputs of query must be well-sanitised.
/// 
/// This function will consider the parameter [out]'s length is already more than its return value.
/// 
/// parameter [out] and [in] must not overlap each other.
/// @brief
/// Copies the data that [in] with the contents of [queries] inserted to parameter [out].
/// @param[out] out
/// Destination. needs to be allocated. \n
/// When passed 0, no data will be passed via [out].
/// @param[in] in 
/// Host source.
/// @param queries
/// Could pass 0.
/// @return
/// The count of bytes written to [out]... 
/// Which means [out] needs to be longer than the function's return value.
ae2f_extern ae2f_SHAREDCALL
size_t Rdvtr_RndrGen(
    char* out,
    const char* in,
    Rdvtr_RndrQuery* queries
);

#include <ae2f/Bmp/Idx.h>

typedef struct Rdvtr_Rndr {
    ae2f_struct ae2f_rBmpIdx mIdx;
    int8_t* mField;
    Rdvtr_RndrQuery mQuery;
} Rdvtr_Rndr;

#endif