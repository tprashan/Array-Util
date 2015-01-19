# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "arrayUtil.h"

int areEqual(Array_util array1, Array_util array2){
	int i,length;
	int *arr1= (int *)(array1.base);
	int *arr2= (int *)array2.base;

	if(array1.length!=array2.length || array1.typeSize!=array2.typeSize)
		return 0;
	for(i=0;i<array1.length;i++){
		if(arr1[i]!=arr2[i])
			return 0;
	};
	return 1;
};

Array_util create(int typeSize, int length){
	int *array = (int *)calloc(length,sizeof(typeSize));
	Array_util array1;
	array1.base = array;
	array1.typeSize = typeSize;
	array1.length = length;
	return array1;
};