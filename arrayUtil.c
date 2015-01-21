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

ArrayUtil resize(ArrayUtil util, int length){
	int i,newIndex;
	int resizeLength = length*util.typeSize;
	int byteLength =util.length*util.typeSize;	
	int resizeByte = (length-util.length)*util.typeSize;

	util.base = realloc(util.base,resizeLength);
	util.length = length;
	for(i = 0;i < resizeByte;i++){
		newIndex = byteLength + i;
		((char*)util.base)[newIndex] = 0;
	}
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
  // memcpy((destination),&(util.base[i]),j+util.typeSize);
  // *destination = realloc(*destination,util.typeSize*j);
// int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
// 	int i,count=0,j=0;
// 	int bytelength= util.typeSize*util.length;
// 	*destination  = malloc(bytelength);
//     printf("%d\n",util.typeSize );
//     for(i=0;i<bytelength;){
//       if(match(hint,&(util.base[i]))){
//         *(char *)(destination)[j]=*(char *)&(util.base[i]);
//         printf("%d\n",*(char *)(destination)[j] );
//         count++;
//         j=j+util.typeSize;
//         printf("%d\n",*(char *)(destination)[j] );
//       };
//       if(count==maxItems)
//       	break;
//       i = i+util.typeSize;
//    }
//    return count;
// };

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
	int i,count=0;
	int bytelength= util.typeSize*util.length;
   	*destination  = malloc(util.typeSize);
   	for(i=0;i<bytelength;i++){
    	if(match(hint,&util.base[i])){
	  		memcpy(&((*destination)[count*util.typeSize]),&(util.base[i]),util.typeSize);
	        count++;
  			*destination = realloc(*destination,util.typeSize*count+1);
      	};
      	if(count==maxItems)
      		break;
   	}
   return count;
};

// int filter(ArrayUtil array, MatchFunc* match, void* hint, void** destination, int maxItems ){
// 	int i,length=0;
// 	*destination = malloc(array.typeSize);
// 	for(i=0;i<array.length*array.typeSize;i++){
// 		if(match(hint,&array.base[i])){
// 			memcpy(&((*destination)[length*array.typeSize]),&(array.base[i]),array.typeSize);
// 			length++;
// 			*destination = realloc(*destination,array.typeSize*length+1);
// 		}  
// 		if(maxItems==(length))
// 			return maxItems;
// 	};
// 	return length;
// };