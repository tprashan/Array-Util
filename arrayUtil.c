# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "arrayUtil.h"

int areEqual(ArrayUtil array1, ArrayUtil array2){
	int i,length;
	char *arr1= (char *)(array1.base);
	char *arr2= (char *)array2.base;
	length = array1.length<=array2.length?(array2.length*array1.typeSize):(array1.length*array1.typeSize);

	if(array1.length!=array2.length || array1.typeSize!=array2.typeSize)
		return 0;
	for(i=0;i<length;i++){
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

int findIndex(ArrayUtil util, void* element){
	int i,count=0;
	char *array= (char *)(util.base);
	char * ele = (char *)element ;
	int memoryLength =util.length*util.typeSize;
	for(i=0;i<memoryLength;i++){
		if(array[i]!=ele[count])
			count=0;
		if(array[i]==ele[count]){
			count++;
			if(count==util.typeSize){
				return i/util.typeSize;
			}
		}
	}
	return -1;
};

void dispose(ArrayUtil util){
	free(util.base);
	util.length=0;
	util.typeSize=0;
};

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
	int i,count=0,j=0,result;
	char *array= (char *)(util.base);
	int memoryLength =util.length*util.typeSize;
	for (i=0;i<memoryLength;i++){
		if(count!=(util.typeSize)*j)
			count++;
		if(count==(util.typeSize)*j){
			j++;
			result = match(hint,&array[count]);
			if(result==1){
				return &array[i];
			}
		};
	};
	return NULL;
};