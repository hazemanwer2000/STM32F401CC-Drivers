/*************************************************************
 * 
 * Filename: Std_Types.h
 * Description: Standard type-definitions file, relevant to the STM32F401CC MCU.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __STD_TYPES_H__
#define __STD_TYPES_H__

/*************************************************************
 * Description: Type-definitions of unsigned integral types.
 * 
 *************************************************************/
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long long int u64;


/*************************************************************
 * Description: Type-definitions of signed integral types.
 * 
 *************************************************************/
typedef signed char s8;
typedef signed short int s16;
typedef signed int s32;
typedef signed long long int s64;


/*************************************************************
 * Description: Type-definitions of floating-point types.
 * 
 *************************************************************/
typedef float f32;
typedef double f64;


/*************************************************************
 * Description: Macro-definition of what it means to be false (boolean).
 * 
 *************************************************************/
#define FALSE 			0
#define TRUE 			1


/*************************************************************
 * Description: Macro-definition of what it means to be a NULL pointer.
 * 
 *************************************************************/
#define NULL            ((void *) 0)


#endif /* __STD_TYPES_H__ */
