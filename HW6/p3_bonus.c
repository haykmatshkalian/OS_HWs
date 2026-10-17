#include <stdio.h>

struct NormalStruct {
    	char a;
    	int b;
    	double c;
};

#pragma pack(1)
struct Packed1 {
    	char a;
    	int b;
    	double c;
};
#pragma pack()

#pragma pack(2)
struct Packed2 {
    	char a;
	int b;
    	double c;
};
#pragma pack()

#pragma pack(4)
struct Packed4 {
    	char a;
    	int b;
    	double c;
};
#pragma pack()

#define PRINT_INFO(type, obj) \
    	printf("\n%s size: %zu bytes\n", type, sizeof(obj)); \
    	printf("a: %p\n", (void *)&(obj).a); \
    	printf("b: %p\n", (void *)&(obj).b); \
    	printf("c: %p\n", (void *)&(obj).c)

int main(void) {
    	struct NormalStruct normal;
    	struct Packed1 p1;
    	struct Packed2 p2;
    	struct Packed4 p4;

    	PRINT_INFO("Normal struct", normal);
    	PRINT_INFO("Pack(1)", p1);
    	PRINT_INFO("Pack(2)", p2);
    	PRINT_INFO("Pack(4)", p4);

    	return 0;
}
