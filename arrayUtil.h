typedef struct ArrayUtil
{
	void *base;
	int typeSize;
	int length;
} ArrayUtil;

int areEqual(ArrayUtil array1, ArrayUtil array2);
ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil util, int length);
int findIndex(ArrayUtil util, void *element);