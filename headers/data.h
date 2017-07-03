/*Declaring all functions which are defined in data.c*/
#include<stdint.h>

typedef enum {DATA_SUCCESS, DATA_NULL_POINTER, DATA_BAD_DATA} data_error_code;

/*								                
 * Function:     my_itoa 
 * -----------------------------------------------------------------------------
 * Description:  Takes an integer type and converts every digit to 1-byte 
 *               ASCII format resulting in a string containing the number, with
 *               respect to the base specified. 
 * 
 * Usage:        Pass a uint8 type pointer, int32_t type containing the number,
 *               and a uint8 type containing the base of the number in that 
 *               order as arguments to this function.
 *
 *               The uint8 type pointer needs to have access to n-bytes, where
 *               'n' is the number of digits in the number for a positive 
 *               number. And 'n+1' bytes, to accomodate the negative sign in 
 *               case the number input is negative.
 *              
 *               Collect the ASCII string containing the number in this pointer.
 *        
 * returns:      Error codes:     
 *               DATA_NULL_POINTER: This is returned when a NULL pointer is 
 *               detected for the string which would contain the number in ASCII
 *               format.
 *               
 *               DATA_BAD_DATA: This code is returned when the base is detected 
 *               to be negative or 0.
 *               
 *               DATA_SUCCESS: This is returned when the function executes
 *               successfully.    
 * ----------------------------------------------------------------------------
 */
data_error_code my_itoa( uint8_t *str, int32_t data, uint8_t base);




/*								                
 * Function:     my_atoi(uint8_t *str, int32_t result) 
 * -----------------------------------------------------------------------------
 * Description:  Converts an ASCII string containing a decimal number to an 
 *               int32_t type containing the decimal.
 *               
 * Usage:        Pass a uint8 type pointer containing the number in ASCII form, 
 *               and an int32_t type to store the conversion of the number.
 *              
 * returns:      Error codes:     
 *
 *               DATA_NULL_POINTER: This is returned when a NULL pointer is 
 *               detected for the string which would contain the number in ASCII
 *               format.
 *               
 *               DATA_BAD_DATA: This code is returned when the string contains
 *               non-numeric data. This is also returned when the string contains
 *               decimals (fractions).
 *
 *               DATA_SUCCESS: This is returned when the function executes
 *               successfully. 
 * ----------------------------------------------------------------------------
 */
data_error_code my_atoi(int8_t *str, int32_t result);


/*								                
 * Function:     dump_memory(uint8_t* start, int32_t length) 
 * -----------------------------------------------------------------------------
 * Description:  Dumps 'length' bytes of memory pointed to by start.
 *               
 * Usage:        Pass a uint8 type pointer, and a int32_t type in that order.
 *
 *               The pointer must point to the address of the 1st byte of data
 *               to be printed. The int32_t type must contain the length of
 *               the memory dump requred.
 *
 *
 * returns:      Error codes:     
 *
 *               DATA_NULL_POINTER: This is returned when a NULL pointer is 
 *               detected for the pointer which should be pointing to the first
 *               byte of the memory to be dumped.
 *               
 *               DATA_BAD_DATA: This code is returned when the length is 
 *               detected to be less than or equal to zero. 
 *
 *               DATA_SUCCESS: This is returned when the function executes
 *               successfully. 
 * ----------------------------------------------------------------------------
 */
data_error_code dump_memory(uint8_t *start,uint32_t length);

/*								                
 * Function:     change_endianness(uint32_t data) 
 * -----------------------------------------------------------------------------
 * Description:  Changes endianness of the input simply by reversing the order
 *               of the bytes stored. 
 *               
 * Usage:        Pass a uint32_t type that needs its endianness changed.
 *
 * returns:      A uint32 type of the which has its bytes ordered the other way.
 *               It will have its data stored as per the endian alternate.
 *
 *               This function always returns successfully.
 *                   
 * ----------------------------------------------------------------------------
 */
uint32_t change_endianness(uint32_t data);


