/**
 * @file  memory_util.h
 *
 * @brief Provides memory utility functions for Kmyth applications
 *        using TPM 2.0
 */

#ifndef _KMYTH_ENCLAVE_MEMORY_UTIL_H_
#define _KMYTH_ENCLAVE_MEMORY_UTIL_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Wipes the memory in a designated pointer. If the size is incorrectly
 *        specified, behavior can be unpredictable. If a NULL pointer is
 *        handled, the function simply returns.
 *
 *        Based on SEI Cert C Coding Standard miscellaneous recommendation
 *        MSC06-C
 *
 *        https://wiki.sei.cmu.edu/confluence/display/c/MSC06-C.+Beware+of+compiler+optimizations
 *
 * @param[in,out] v         The pointer to memory to be cleared
 *
 * @param[in]     size      The size of the block to be cleared
 *
 * @return                  None. The memory for the passed in pointer (v) is
 *                          cleared upon return from this function.
 */
  void kmyth_enclave_clear(void *v, size_t size);

/**
 * @brief Wipes the memory in a designated pointer, then frees the pointer.
 *        Utilizes kmyth_clear. If the size is incorrectly specified, behavior
 *        can be unpredictable. If a NULL pointer is handled, the function
 *        simply returns.
 *
 * @param[in,out] v         The pointer to memory to be cleared then freed
 *
 * @param[in]     size      The size of the block to be cleared then freed
 * 
 * @return                  None. The memory for the passed in pointer (v) is
 *                          cleared and the pointer is freed upon return.
 */
  void kmyth_enclave_clear_and_free(void *v, size_t size);

/**
 * Clears the contents of a pointer, without running into issues of gcc
 * optimizing around memset. Implementation obtained from:
 *    open-std WG 15 Document: N1381
 *    http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1381.pdf
 *    
 * @param[in,out] v         The pointer containing contents to clear
 *
 * @param[in] c             The value to fill the array with
 *
 * @param[in] n             The size of the array
 *
 * @return                  The function itself has no return value.
 *                          The passed in pointer (v) is returned
 *                          pointing to a cleared block of memory
 */
  void *kmyth_enclave_secure_memset(void *v, int c, size_t n);

#ifdef __cplusplus
}
#endif

#endif                          /* MEMORY_UTIL_H */
