# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "expr_assert.h"
# include "arrayUtil.h"

void test_array_util(){
	int a[]={1,2,3,4,5};
	int b[]={1,2,3,4,5,6};

	ArrayUtil array1;
	ArrayUtil array2;

	array1.base = a;
	array1.typeSize = sizeof(int);
	array1.length = 5;

	array2.base = b;
	array2.typeSize = sizeof(int);
	array2.length = 6;

	assertEqual(areEqual(array1, array2),0);

};

void test_ArrayUtil_same_array_return_1(){
	int a[]={1,2,3,4,5};
	int b[]={1,2,3,4,5};

	ArrayUtil array1;
	ArrayUtil array2;

	array1.base = a;
	array1.typeSize = sizeof(int);
	array1.length = 5;

	array2.base = b;
	array2.typeSize = sizeof(int);
	array2.length = 5;

	assertEqual(areEqual(array1, array2),1);

};

void test_ArrayUtil_same_float_array_return_1(){
	float a[]={1,2.1,3,4,5};
	float b[]={1,2.1,3,4,5};

	ArrayUtil array1;
	ArrayUtil array2;

	array1.base = a;
	array1.typeSize = sizeof(float);
	array1.length = 5;

	array2.base = b;
	array2.typeSize = sizeof(float);
	array2.length = 5;

	assertEqual(areEqual(array1, array2),1);

};


void test_ArrayUtil_diff_char_array_return_0(){
	float a[]={1,2.1,3,4,5};
	char b[]={'c','b','r','s','x','\0'};

	ArrayUtil array1;
	ArrayUtil array2;

	array1.base = a;
	array1.typeSize = sizeof(float);
	array1.length = 5;

	array2.base = b;
	array2.typeSize = sizeof(char);
	array2.length = 5;

	assertEqual(areEqual(array1, array2),0);

};

void test_ArrayUtil_create(){
	ArrayUtil array;
	int *a;
	array = create(4,3);
	a = array.base;
	assertEqual(a[0],0);
	assertEqual(sizeof(a),4);
};

void test_ArrayUtil_create_array_length_is_7(){
	ArrayUtil array;
	array = create(4,7);
	assertEqual(array.length,7);
};

void test_ArrayUtil_create_array_typeSize_is_4(){
	ArrayUtil array;
	array = create(4,7); 
	assertEqual(array.typeSize,4);
};

void test_ArrayUtil_resize_array(){
	int a[]={1,2,3,4,5};
	int *resArray;
	ArrayUtil array;
	ArrayUtil resizeArray;
	array.base = a;
	array.typeSize = sizeof(int);
	array.length = 5;
	resizeArray=resize(array,7); 
	resArray = resizeArray.base;
	assertEqual(resizeArray.typeSize,4);
	assertEqual(resizeArray.length,7);
};

void test_ArrayUtil_resize_array_shoud_give_0_at_index_6(){
	int a[]={1,2,3,4,5};
	int *resArray;
	ArrayUtil array;
	ArrayUtil resizeArray;
	array.base = a;
	array.typeSize = sizeof(int);
	array.length = 5;
	resizeArray=resize(array,7); 
	resArray = resizeArray.base;
	assertEqual(resArray[6],0);
};

void test_ArrayUtil_resize_array_shoud_give_0_at_index_5(){
	int a[]={1,2,3,4,5};
	int *resArray;
	ArrayUtil array;
	ArrayUtil resizeArray;
	array.base = a;
	array.typeSize = sizeof(int);
	array.length = 5;
	resizeArray=resize(array,4); 
	resArray = resizeArray.base;
	assertEqual(resArray[3],4);
};