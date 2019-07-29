//
//  main.c
//  C_ArrayTest
//
//  Created by jiahui on 2019/7/20.
//  Copyright © 2019 JH. All rights reserved.
//

#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>

void createArr(void);

void modifyArray (int *p) {
    p[0] = -2;//p[0]等价于 *p。 p[3]等价于 main里的 a[3]
    ///p[i] 即 main 函数里的 a[i];
}

////指针和数组
int main() {
    int a[5] = {1,2,3,4,5};///a表示第一个元素的地址（指针）相当于int *a; 这句里的a;
    char ch = 'A';
    int i = 99;
    double x = 66.6;
    char * p = &ch;
    int * q = &i;
    double * r = &x;
    printf("p的地址是0x%x, p占%d个字节, ch占%d个字节\n",p,sizeof(p), sizeof(ch));
    printf("q的地址是0x%x, q占%d个字节, int占%d个字节\n",q,sizeof(q), sizeof(i));
    printf("r的地址是0x%x, r占%d个字节, double占%d个字节\n\n",r,sizeof(r), sizeof(x));
    ///
    
    printf("a的第一个元素为：%d ，a的第二个元素为：%d ,a的第三个元素为：%d, a的第四个元素为：%d, a的第五个元素为：%d\n",a[0],a[1],a[2],a[3],a[4]);
   
    modifyArray(a);
    printf("a的第一个元素为：%d ，a的第二个元素为：%d ,a的第三个元素为：%d, a的第四个元素为：%d, a的第五个元素为：%d\n",*a,*(a+1),*(a+2),*(a+3),*(a+4));
    
    return 0;
}


void createArr() {
    ///静态创建
//    int a[5] = {1,2,3,4,5};///
    
    //动态创建 （用户输入要创建的大小
    int length ;
    printf("请输入需要分配的数组长度: ");
    scanf("%d",&length);
    
    /////因为malloc返回的是字节的地址（都是8个字节64位 64位机上），但无法推测出后面的字节区间故前面要强转（int *）
    int *arry = (int *)malloc(sizeof(int) *length);
    
    ///赋值
    *arry = 4;//等价于 a[0] = 4
    arry[1] = 10;
    
    printf("arry的第一个元素为：%d ,%d\n",*arry,arry[1]);
    free(arry);
}
