# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "arrayUtil.h"

int areEqual(ArrayUtil array1, ArrayUtil array2){
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

ArrayUtil create(int typeSize, int length){
	int *array = calloc(length,sizeof(typeSize));
	ArrayUtil array1;
	array1.base = array;
	array1.typeSize = typeSize;
	array1.length = length;
	return array1;
};

ArrayUtil resize(ArrayUtil util, int length){
	int i;
	int *array= (int *)(util.base);
	int *util_1 = calloc(length,sizeof(util.typeSize));

	for(i=0;i<length;i++){
		if(i<=util.length)
			util_1[i]=array[i];
	};
	util.length = length;
	util.base = util_1;
	return util;
};

int findIndex(ArrayUtil util, void *element){
	int i,j=0;
	char *array= (char *)(util.base);
	char * ele = (char *)element ;

	int memoryLength =util.length*util.typeSize;

	for(i=0;i<memoryLength;i++){
		if(array[i]==*ele)
			return i/util.typeSize;
	}
	return -1;
};
























// int findIn(ArrayUtil util, void* element){
// 	int i;
// 	int sub_i =0;
// 	int subByteLength =util.typeSize/(int)sizeof(char); 
// 	char * bytes = (char *)util.base;
// 	char * subByte =(char *)element;
// 	int byteLength =util.length*util.typeSize;
// 	for (i=0;i<(byteLength);i++){
// 		if(sub_i>0&&bytes[i]!=subByte[sub_i]){
// 			sub_i =0;
// 		}
// 		if(bytes[i]==subByte[sub_i]){
// 			sub_i++;
// 			if(sub_i==subByteLength){
// 				return (i/util.typeSize);
// 			}
// 		}
		
// 	}
// 	return -1;
// }