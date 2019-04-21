/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Preforms statistical analysis on a dataset. 
 *
 * @author vtotient
 * @date April 7, 2019
 *
 */

#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void print_statistics(unsigned char array[], unsigned int length){
	PRINTF("The original array:\n\n");
	print_array(array, length);
	sort_array(array, length);
	PRINTF("The Sorted array:\n");
	print_array(array, length);
	PRINTF("The Median is: %d\n", find_median(array, length));
	PRINTF("The Mean is: %d\n", find_mean(array, length));
	PRINTF("The Max is: %d\n", find_max(array, length));
	PRINTF("The Min is: %d\n\n", find_min(array, length));	
	return;
}

void print_array(unsigned char array[], unsigned int length){
	#ifdef VERBOSE
	for(int i = 0; i < length/8; i++){
		for(int j = 0; j < length/5; j++){
		       PRINTF("%3d  ", array[8*i+j]);
		}
 		PRINTF("\n");
	}
	
	PRINTF("\n");	
	
	#endif

	return;
}

unsigned char find_median(unsigned char array[], unsigned int length){
	return array[(length-1)/2];
}

unsigned char find_mean(unsigned char array[], unsigned int length){
	unsigned int sum = 0;
	for(int i = 0; i < length; i++){
		sum += array[i];	
	}

	return (unsigned char)( sum / length );
}

unsigned char find_max(unsigned char array[], unsigned int length){
	return array[length-1];
}

unsigned char find_min(unsigned char array[], unsigned int length){
	return array[0];
}

void sort_array(unsigned char array[], unsigned int length){
	unsigned char tmp;
	for(int i = 0; i < length; i++){
		for(int j = i; j < length; j++){
			if(array[j] < array[i]){
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
			}
		}
	}
	return;
}
