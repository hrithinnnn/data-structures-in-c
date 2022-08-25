#include <stdio.h>
#include<malloc.h>

typedef struct Temp {

    int a;
} Temp;

// class Temp {

//     public: int a;
// };

void fn(Temp* ob) {
    
    ob->a = 5;
}

int main() {

    Temp* ob = (Temp*)(malloc(sizeof(Temp)));

    ob->a = 10;
    printf("%d",ob->a);
    fn(ob);
    printf(" %d",ob->a);
   // std::cout<<ob.a;
}