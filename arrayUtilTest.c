# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "expr_assert.h"
# include "arrayUtil.h"
# define STRING char* 
#define SIZEOF_INT sizeof(int)
#define SIZEOF_FLOAT sizeof(float)
#define SIZEOF_CHAR sizeof(char)
#define SIZEOF_DOUBLE sizeof(double)

#define INT_SIZE sizeof(int)
#define CHAR_SIZE sizeof(char)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)

#define SIZEOF_INT sizeof(int)

#define CHAR_SIZE sizeof(char)
#define INT_SIZE sizeof(int)

#define INT_SIZE sizeof(int)
#define CHAR_SIZE sizeof(char)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)

ArrayUtil util,expectedUtil;
typedef char*  String;
ArrayUtil util, resultUtil, expectedUtil;
int sample[] = {1,2,3,4,5};

ArrayUtil util1,util2;
typedef struct Student{
    int rollno;
    float age;
} student;

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
	assertEqual(strcmp(((STRING*)result.base)[2],"hiiii"),0);
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

void test_for_findFirst_return_NULL_if_no_element_match(){
	int a[]={1,5,3,7,9},hint=3,*result;

	ArrayUtil array = { a,sizeof(int),5};
	assertEqual((int)(findFirst(array,isEven,&hint)),(int)NULL);
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

int compare(void* hint, void* item){
	if(*(char *)item=='g')
		return 1;
	return 0;
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

//..................................................................................

void test_for_filter_that_return_the_num_of_ele_that_match_the_criteria(){
	int a[]={1,4,3,4,4},hint=3;
	void *destination; 
	int resultCount;
	ArrayUtil array = { a,sizeof(int),5};
	resultCount = filter(array,isEven,&hint,&destination,2);
	assertEqual(resultCount,2);
	// assertEqual(((int *)destination)[0],4);
};

// ..................................................................................

int isEqual(void* hint, void* item){
	if(*(int*)item==8 ||*(float*)item == 9.0 || *(double*)item==8.9)
		return 1;
	return 0;
}

void test_filter_will_return_the_array_of_8_8_8(){
	int a[]={1,8,8,7,8,9},hint=3,count;
	void* result;
	ArrayUtil array = {a, sizeof(int), 6};
	count = filter(array,isEqual,&hint,&result,5);

	assertEqual(((int*)result)[0],8);
	assertEqual(count,3);
};


void test_filter_will_return_the_array_of_only_two_8(){
	int a[]={1,8,8,7,8,9},hint=3,count;
	void* result;
	ArrayUtil array = {a, sizeof(int), 6};
	count = filter(array,isEqual,&hint,&result,2);

	assertEqual(((int*)result)[1],8);
	assertEqual(count,2);
};

void test_filter_will_return_the_array_of_only_two_8_point_7_in_float(){
	float a[]={1.4,8.4,8.9,7,8,9.0},hint=3;
	int count;
	void* result;
	ArrayUtil array = {a, sizeof(float), 6};
	count = filter(array,isEqual,&hint,&result,2);

	assertEqual(((float*)result)[0],9.0);
	assertEqual(count,1);
};

void test_filter_will_return_the_array_g_g_g(){
	char a[]={'g','g','g','b','d'},hint=3;
	int count;
	void* result;
	ArrayUtil array = {a, sizeof(char), 5};
	count = filter(array,compare,&hint,&result,5);

	assertEqual(((char*)result)[1],'g');
	assertEqual(count,3);
};

int stringCompare(void* hint, void* item){
	STRING aa= "gg";
	if(*(char **)item==aa)
		return 1;
	return 0;
};

void test_filter_will_return_the_array_of_gg_gg_gg(){
	void *result;
	int hint=3,count;
	STRING aa = "gg";
	ArrayUtil array = create(sizeof(char*),4);
	((char **)array.base)[0] = "gg";
	((char **)array.base)[1] = "gg";
	((char **)array.base)[2] = "gg";
	((char **)array.base)[3] = "bg";
	count = filter(array,stringCompare,&hint,&result,5);
	assertEqual(count,3);
	assertEqual(strcmp(((STRING*)result)[1],"gg"),0);
};

void addFiveInEachNumber(void* hint, void* sourceItem, void* destinationItem){
	int srcItem = *(int *)sourceItem;
	*(int *)destinationItem = srcItem +5;
};

void test_map_will_return_a_convert_ele_array(){
	// ArrayUtil destination;
	int hint=3;
	ArrayUtil array = {(int []){1,2,3,4,5},sizeof(int),5};
	ArrayUtil expected = {(int []){6,7,8,9,10},sizeof(int),5};
	ArrayUtil destination = create(sizeof(int),5);
	map(array,destination,addFiveInEachNumber,&hint);
	assert(areEqual(expected,destination));
};

void addFloatNumberInEachNumber(void* hint, void* sourceItem, void* destinationItem){
	// printf("------------------%f\n", );
	float srcItem = *(float *)sourceItem;
	*(float *)destinationItem = srcItem + 5.1;
};

void intMultiplyBy2(void* hint, void* item){
	*(int *)*(&item) = *(int *)item * *(int *)hint;
};

void test_forEach_gives_2_4_6_8_10_for_1_2_3_4_5_in_same_array(){
	ArrayUtil src = create(sizeof(int),5);
	int *arr,i,hint = 2,*list;
	arr = (int*)src.base;
	for(i=0;i<5;i++){
		arr[i] = i+1;
	}
	list = ((int*)src.base);
	forEach(src,intMultiplyBy2,&hint);
	assertEqual(list[0],2);
	assertEqual(list[1],4);
	assertEqual(list[2],6);
	assertEqual(list[3],8);
	assertEqual(list[4],10);
	dispose(src);
}

void floatAddOnePointThree(void* hint, void* item){
	float *result = malloc(sizeof(float));
	*result = *(float *)item + *(float *)hint;
	printf("%f\n",*result );
	result = realloc(result,4);
};

void test_forEach_gives_2p8_3p8_for_1p5_2p5_in_diff_array(){
	ArrayUtil src = { (float []){1.5,2.5},sizeof(float),2};
	float hint = 1.3;
	forEach(src,floatAddOnePointThree,&hint);
}

void charReturn(void* hint, void* item){
	*(char *)*(&item) = *(char *)item;
}

void test_forEach_gives_a_b_c_for_a_b_c_in_same_array(){
	ArrayUtil src = create(sizeof(char),5);
	char *arr,*list;
	int hint=2,i;
	arr = (char*)src.base;
	for(i=0;i<101;i++){
		arr[i] = i+'a';
	}
	list = ((char*)src.base);
	forEach(src,charReturn,&hint);
	assertEqual(list[0],'a');
	assertEqual(list[1],'b');
	assertEqual(list[2],'c');
	dispose(src);
}


void *add_all(void* hint, void* previousItem, void* item){
	*((int*)item)= *((int*)previousItem) + *((int*)item);
	return ((int*)item);
}


void test_reduce_gives_15_when_elements_are_1_2_3_4_5_and_initial_value_is_0(){
	void *hint;
	int intialValue=0;
	int array[]={1,2,3,4,5};
	ArrayUtil util={array,sizeof(int),5};
	void *return_value=reduce(util,add_all,&hint,&intialValue);
	assertEqual(*((int*)return_value),15);
}

void test_reduce_gives_30_when_elements_are_1_2_3_4_5_and_initial_value_is_15(){
	void *hint;
	int intialValue=15;
	int array[]={1,2,3,4,5};
	ArrayUtil util={array,INT_SIZE,5};
	void *return_value=reduce(util,add_all,&hint,&intialValue);
	assertEqual(*((int*)return_value),30);
}

void element_into_element_plus_one(void* hint, void* item){
	*((int *)item)= *((int *)item) * ((*((int *)item))+1);
}


void test_forEach_does_multiplication_of_item_with_item_plus_one(){
	void *hint;
	int array[]={1,2,3,4,5};
	int incremented[]={2,6,12,20,30};
	ArrayUtil util={array,INT_SIZE,5};
	ArrayUtil expected={incremented,INT_SIZE,5};
	forEach(util,element_into_element_plus_one,&hint);
	assert(areEqual(util,expected));
}

void* add(void* hint, void* previousItem, void* item){
	*((int*)item)= *((int*)previousItem) + *((int*)item);
	return ((int*)item);
}

void test_reduce_returns_add_of_all_integers_of_array (){
	int hint = 2,initial_value = 0;
	int array[] = {0,0,0,1,0};
	ArrayUtil util = create(sizeof(int),5);
	util.base = array;
	initial_value = *(int*)(reduce(util,add,&hint,&initial_value));
	assertEqual(initial_value,1);
};

void* sum (void* hint, void* pv, void* cv){
	int* _pv = (int*)pv;
	int* _cv = (int*)cv;
	int* result = (int*)malloc(INT_SIZE); 
	*result = *_pv + *_cv;
	return result;
}

void test_reduce_returns_sum_of_all_integers_of_array (){
	int hint = 2,result;
	int initial_value = 0;
	int array[] = {1,2,3};
	void* (*fn_ptr)(void*,void*,void*) = &sum;
	ArrayUtil util = create(INT_SIZE,3);
	util.base = (void*)array;
	result = *(int*)reduce(util,fn_ptr,(void*)&hint,(void*)&initial_value);
	assertEqual(result,6);
};

//---------------------------------------------------------------------------------------------------------------------------
