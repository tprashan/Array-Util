# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "arrayUtil.h"

int areEqual(ArrayUtil array1, ArrayUtil array2){
	int i,length;
	char *arr1= (char *)(array1.base);
	char *arr2= (char *)array2.base;
	length = array1.length*array1.typeSize;

	if(array1.length!=array2.length || array1.typeSize!=array2.typeSize)
		return 0;
	for(i=0;i<length;i++){
		if(arr1[i]!=arr2[i])
			return 0;
	};
	return 1;
};

ArrayUtil create(int typeSize, int length){
	ArrayUtil array1;
	array1.base = calloc(length,typeSize);;
	array1.typeSize = typeSize;
	array1.length = length;
	return array1;
};

ArrayUtil resize(ArrayUtil array,int length){
	int i,copyLength;
	void *newArray;
	int byteLength = array.length*array.typeSize;
	copyLength = (length<=array.length?length:array.length)*array.typeSize;
	newArray = calloc(length,length*array.typeSize); 
	memcpy(newArray,array.base,copyLength);
	// newArray = calloc(length,array.typeSize); 
	// memcpy(&((*destination)[count*util.typeSize]),&(util.base[i]),util.typeSize);
	// for(i=0;i<byteLength;){
	// 	memcpy(&((newArray)[i*array.typeSize]),&(array.base[i*array.typeSize]),array.typeSize);
	// 	i = i + array.typeSize;
	// }
	array.base = newArray;
	array.length = length;
	return array;
};

int findIndex(ArrayUtil util, void* element){
	int i,count=0;
	char *array= (char *)(util.base);
	char * ele = (char *)element ;
	int memoryLength =util.length*util.typeSize;
	for(i=0;i<memoryLength;i++){
		if(count > 0 && array[i]!=ele[count])
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
	int memoryLength =util.length*util.typeSize;
	for (i=0;i<memoryLength;){
		result = match(hint,&(util.base[i]));
		if(result==1){
			return &(util.base[i]);
		}
		i = i + util.typeSize;
	};
	return NULL;
};

void* findLast(ArrayUtil util, MatchFunc* match, void* hint){
	int i,count=0,j=0,result;
	int memoryLength =util.length*util.typeSize;
	int lastPosition = memoryLength-util.typeSize;
	for (i=lastPosition;i>=0;){
		result = match(hint,&(util.base[i]));
		if(result==1)
			return &(util.base[i]);
		i=i-util.typeSize;
	};
	return NULL;
};

int count(ArrayUtil util, MatchFunc* match, void* hint){
	int i,count=0,result;
	int memoryLength =util.length*util.typeSize;
	for (i=0;i<memoryLength;){
		result = match(hint,&(util.base[i]));
		if(result==1)
			count++;
		i = i + util.typeSize;
	};
	return count;
};

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
	int i,count=0;
	int bytelength= util.typeSize*util.length;
   	*destination  = malloc(util.typeSize);
   	for(i=0;i<bytelength;){
    	if(match(hint,&util.base[i])){
	  		memcpy(&((*destination)[count*util.typeSize]),&(util.base[i]),util.typeSize);
	        count++;
  			*destination = realloc(*destination,util.typeSize*count+1);
      	};
      	i = i+util.typeSize;
      	if(count==maxItems)
      		break;
   	}
   return count;
};


void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
	int i,j,address;
	int bytelength= source.typeSize*source.length;
	for(i=0;i<source.length;i++){
		j = i*source.typeSize;
		convert(hint,&(source.base[j]),&destination.base[j]);
	};
};

void forEach(ArrayUtil util, OperationFunc* operation, void* hint){
	int i;
	int byteLength = util.length*util.typeSize;
	for(i=0;i<byteLength;){
		operation(hint,&util.base[i]);
		i = i + util.typeSize;
	}
};

void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue){
	int i;
	char* result = intialValue;
	int byteLength = util.length*util.typeSize;
	for(i=0;i<byteLength;){
		result = reducer(hint,result,&util.base[i]);
		i = i + util.typeSize;
	}
	return result;
};
