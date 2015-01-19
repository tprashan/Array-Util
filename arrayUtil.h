typedef struct ArrayUtil
{
	void *base;
	int typeSize;
	int length;
} Array_util;

int areEqual(Array_util array1, Array_util array2);
// ArrayUtil create(int typeSize, int length);
 