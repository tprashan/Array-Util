# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "expr_assert.h"
# include "arrayUtil.h"

void test_array_util_equal(){
	int a[]={1,2,3,4,5};
	int b[]={1,2,3,4,5,6};

	ArrayUtil array1 = { a,sizeof(int),5};
	ArrayUtil array2 = { b,sizeof(int),6};

	assertEqual(areEqual(array1, array2),0);

};

void test_ArrayUtil_same_array_return_1(){
	int a[]={1,2,3,4,5};
	int b[]={1,2,3,4,5};

	ArrayUtil array1 = { a,sizeof(int),5};
	ArrayUtil array2 = { b,sizeof(int),5};

	assertEqual(areEqual(array1, array2),1);

};

void test_ArrayUtil_same_float_array_return_1(){
	float a[]={1,2.1,3,4,5};
	float b[]={1,2.1,3,4,5};

	ArrayUtil array1 = { a,sizeof(float),5};
	ArrayUtil array2 = { b,sizeof(float),5};

	assertEqual(areEqual(array1, array2),1);

};


void test_ArrayUtil_diff_char_array_return_0(){
	float a[]={1,2.1,3,4,5};
	char b[]={'c','b','r','s','x','\0'};

	ArrayUtil array1 = { a,sizeof(float),5};
	ArrayUtil array2 = { b,sizeof(char),5};

	assertEqual(areEqual(array1, array2),0);

};

void test_ArrayUtil_create(){
	int *a;
	ArrayUtil array = create(4,3);
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
	ArrayUtil result;
	ArrayUtil array = create(4,4);
	((int *)array.base)[0] = 1;
	((int *)array.base)[1] = 2;
	((int *)array.base)[2] = 4;
	((int *)array.base)[3] = 5;
	result = resize(array,3);
	assertEqual(result.typeSize,4);
	assertEqual(result.length,3);
};

void test_ArrayUtil_resize_array_shoud_give_4_at_index_3(){
	ArrayUtil result;
	ArrayUtil array = create(4,4);
	((int *)array.base)[0] = 1;
	((int *)array.base)[1] = 2;
	((int *)array.base)[2] = 5;
	((int *)array.base)[3] = 4;
	result = resize(array,6);
	assertEqual(result.typeSize,4);
	assertEqual(((int *)result.base)[3],4);
};

void test_ArrayUtil_resize_array_shoud_give_8_at_index_2(){
	ArrayUtil result;
	ArrayUtil array = create(4,4);
	((int *)array.base)[0] = 1;
	((int *)array.base)[1] = 2;
	((int *)array.base)[2] = 8;
	((int *)array.base)[3] = 4;
	result = resize(array,6);
	assertEqual(result.typeSize,4);
	assertEqual(((int *)result.base)[2],8);
};


void test_ArrayUtil_resize_array_shoud_give_0_at_index_6(){
	ArrayUtil result;
	ArrayUtil array = create(4,4);
	((int *)array.base)[0] = 1;
	((int *)array.base)[1] = 2;
	((int *)array.base)[2] = 5;
	((int *)array.base)[3] = 4;
	result = resize(array,7);
	assertEqual(result.typeSize,4);
	assertEqual(((int *)result.base)[6],0);
};


void test_ArrayUtil_resize_array_shoud_give_c_at_index_3(){
	ArrayUtil result;
	ArrayUtil array = create(4,4);
	((char *)array.base)[0] = 'a';
	((char *)array.base)[1] = 'b';
	((char *)array.base)[2] = 'g';
	((char *)array.base)[3] = 'c';
	result = resize(array,6);
	assertEqual(result.typeSize,4);
	assertEqual(((char*)result.base)[3] ,'c');
};

void test_ArrayUtil_resize_array_shoud_give_df_at_index_1(){
	ArrayUtil result;
	ArrayUtil array = create(4,4);
	((char **)array.base)[0] = "hiiii";
	((char **)array.base)[1] = "guys";
	((char **)array.base)[2] = "hiiii";
	((char **)array.base)[3] = "guys";
	result = resize(array,5);
	assertEqual(result.length, 5);
	assertEqual(((char **)result.base)[2],"hiiii");
	assertEqual(((int *)result.base)[4],0);
};

void test_ArrayUtil_indexOf_int(){
	int a[]={1,2,3,4,5};
	int Index,ele =3;

	ArrayUtil array = { a,sizeof(int),5};
	Index = findIndex(array,&ele);
	assertEqual(Index,2); 
};


void test_ArrayUtil_indexOf_int_return_minus_1(){
	int a[]={1,2,3,4,5};
	int Index,ele =8;
	
	ArrayUtil array = { a,sizeof(int),5};
	Index = findIndex(array,&ele);
	assertEqual(Index,-1); 
};

void test_ArrayUtil_indexOf_char(){
	char a[]={'a','c','h','w','d','r','j','\0'};
	int  Index;
	char ele ='r';

	ArrayUtil array = { a,sizeof(char),7};
	Index = findIndex(array,&ele);
	assertEqual(Index,5); 
};

void test_ArrayUtil_indexOf_char_return_minus_1(){
	char a[]={'a','c','h','w','d','r','j','\0'};
	int  Index;
	char ele ='b';

	ArrayUtil array = { a,sizeof(char),7};
	Index = findIndex(array,&ele);
	assertEqual(Index,-1); 
};

void test_ArrayUtil_indexOf_float(){
	float a[]={1.7,2.8,3.1,4,5.3};
	int Index;
	float ele =3.1;

	ArrayUtil array = { a,sizeof(float),5};
	Index = findIndex(array,&ele);
	assertEqual(Index,2); 
};

void test_ArrayUtil_indexOf_float_return_minus_1(){
	float a[]={1.7,2.8,3.1,4,5.3};
	int Index;
	float ele =3.2;

	ArrayUtil array = { a,sizeof(float),5};
	Index = findIndex(array,&ele);
	assertEqual(Index,-1); 
};

void test_ArrayUtil_indexOf_float_return_0(){
	float a[]={1.7,2.8,3.1,4,5.3};
	int Index;
	float ele =1.7;

	ArrayUtil array = { a,sizeof(float),5};
	Index = findIndex(array,&ele);
	assertEqual(Index,0); 
};

void test_ArrayUtil_indexOf__return_minus_1(){
	float a[]={1.7,2.8,3.1,4,5.3};
	int Index;	
	float ele =2.1;
	
	ArrayUtil array = { a,sizeof(float),5};
	Index = findIndex(array,&ele);
	assertEqual(Index,-1); 
};

void test_dispose_array_memory(){
	ArrayUtil array;
	array = create(4,7);
	dispose(array);
	// after dispose there will be no index.
};

int isEven(void* hint, void* item){
	if(*(int *)item % 2==0)
		return 1;
	return 0;
};

void test_for_findFirst(){
	int a[]={1,5,3,4,9},hint=3,*result;

	ArrayUtil array = { a,sizeof(int),5};
	result = findFirst(array,isEven,&hint);
	assertEqual(*result,4);
};

void test_for_findFirst_return_NULL(){
	int a[]={1,5,3,7,9},hint=3,*result;

	ArrayUtil array = { a,sizeof(int),5};
	assertEqual(findFirst(array,isEven,&hint),(int)NULL);
};

void test_for_findFirst_return_6(){
	int a[]={1,5,6,4,9},hint=3,*result;

	ArrayUtil array = { a,sizeof(int),5};
	result = findFirst(array,isEven,&hint);
	assertEqual(*result,6);
};


void test_for_findLast_return_4(){
	int a[]={1,5,6,4,9},hint=3,*result;

	ArrayUtil array = { a,sizeof(int),5};
	result = findLast(array,isEven,&hint);
	assertEqual(*result,4);
};

void test_for_findLast_should_return_8(){
	int a[]={1,8,5,3,9},hint=3,*result;

	ArrayUtil array = { a,sizeof(int),5};
	result = findLast(array,isEven,&hint);
	assertEqual(*result,8);
};

int compare1(void *hint,void* item){
	if(*(char*)item=='a')
		return 1;
	return 0;
};

void test_findfirst_will_return_a(){
	char a[]={'b','a','b','b'},hint=3,*result;
	ArrayUtil array = {a, sizeof(char), 3};
	result = findFirst(array,compare1,&hint);

	assertEqual((char)*result,'a');
};

int compare(void* hint, void* item){
	if(*(char *)item=='g')
		return 1;
	return 0;
};

void test_for_findFirst_return_g(){
	char a[]={'a','v','g','h','g'},hint=3,*result;

	ArrayUtil array = { a,sizeof(char),5};
	result = findFirst(array,compare,&hint);
	assertEqual((char)*result,'g');
};

void test_for_count_return_3_num_of_g(){
	char a[]={'a','g','g','h','g'},hint=3;
	int result;

	ArrayUtil array = { a,sizeof(char),5};
	result = count(array,compare,&hint);
	assertEqual(result,3);
};


void test_for_count_return_2_num_of_4(){
	int a[]={1,4,3,4,9},hint=3;
	int result;

	ArrayUtil array = { a,sizeof(int),5};
	result = count(array,isEven,&hint);
	assertEqual(result,2);
};

//-----------------------------------------------------------------------------------------------------------------

void test_for_filter_that_return_the_num_of_ele_that_match_the_criteria(){
	int a[]={1,4,3,4,4},hint=3;
	void *destination; 
	int resultCount;
	ArrayUtil array = { a,sizeof(int),5};
	resultCount = filter(array,isEven,&hint,&destination,2);
	assertEqual(resultCount,2);
	// assertEqual(((int *)destination)[0],4);
};

// ----------------------------------------------------------------------------------------------------------------

int isEqual(void* hint, void* item){
	if(*(int*)item==8 ||*(float*)item == 9.0 || *(double*)item==8.9)
		return 1;
	return 0;
}

void test_filter_will_return_the_array_of_8_8_8(){
	int a[]={1,8,8,7,8,9},hint=3,length;
	void* result;
	ArrayUtil array = {a, sizeof(int), 6};
	length = filter(array,isEqual,&hint,&result,5);

	assertEqual(((int*)result)[0],8);
	assertEqual(length,3);
};


void test_filter_will_return_the_array_of_only_two_8(){
	int a[]={1,8,8,7,8,9},hint=3,length;
	void* result;
	ArrayUtil array = {a, sizeof(int), 6};
	length = filter(array,isEqual,&hint,&result,2);

	assertEqual(((int*)result)[1],8);
	assertEqual(length,2);
};

void test_filter_will_return_the_array_of_only_two_8_point_7_in_float(){
	float a[]={1.4,8.4,8.9,7,8,9.0},hint=3;
	int length;
	void* result;
	ArrayUtil array = {a, sizeof(float), 6};
	length = filter(array,isEqual,&hint,&result,2);

	assertEqual(((float*)result)[0],9.0);
	assertEqual(length,1);
};

void test_filter_will_return_the_array_a_a_a(){
	char a[]={'g','g','g','b','d'},hint=3;
	int length;
	void* result;
	ArrayUtil array = {a, sizeof(char), 5};
	length = filter(array,compare,&hint,&result,5);

	assertEqual(((char*)result)[1],'g');
	assertEqual(length,3);
};