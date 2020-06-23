/*
-------------------------------------
File:    My_Definitions.h
Project: CP264
file description
-------------------------------------
Author:  Rick Magnotta
ID:      xxxxxxxxx
Email:   rmagnotta@wlu.ca
Version  2019-11-08
-------------------------------------
 */
#ifndef MY_DEFINITIONS_H_
#define MY_DEFINITIONS_H_

#ifdef TRUE
   #undef TRUE
   #undef FALSE
#endif
#define TRUE  (1==1)
#define FALSE (0==1)

typedef unsigned int bool;

#define SUCCESS TRUE
#define FAILURE FALSE

#endif /* MY_DEFINITIONS_H_ */
