// 313531113 Dvir Asaf
#include "ex1.h"
/***************************************************************************************************
 Function Name: is_big_endian.
 Function input:none.
 Function Action:this func check if the machine Endianness is Big endian or Little endian.
 Function output:return 1 if the machine Endianness is Big endian, else return 0.
 **************************************************************************************************/
int is_big_endian() {
    // create new number to check if the machine is represented as little or big endian.
    int num = 1;
    char *c = (char*)&num;
    if(*c) {
        //pointer to x of type char (one byte)
        //if the LSB stored first the machine Endianness is Little endian.
        return 0;
    }
    else {
   //if the MSB stored first the machine Endianness is Big endian.
        return 1;}
}
/***************************************************************************************************
 Function Name: merge_bytes
 Function input:two inputs of type unsigned long.
 Function Action:return unsigned long that merge the given x and y. the left half of x and the right half of y.
 Function output:unsigned long.
 **************************************************************************************************/
unsigned long merge_bytes(unsigned long x,unsigned long y)
{
    int i; //index variable for for loop
    unsigned char *bytesY = (unsigned char *)(&y);//typecast to char pointer which is only one byte
    unsigned char *bytesX = (unsigned char *)(&x);
    unsigned long result;//the result
    unsigned char* resultBytes =(unsigned char *)(&result);//typecast to char pointer which is only one byte
    //first check Endianness
    if (is_big_endian()) {
        //if your machine is Big endian so the LSB is stored last
        unsigned char lsb = bytesY[sizeof(y)-1];
        resultBytes[sizeof(y)-1] = lsb;//store LSB last
        for (i = (sizeof(y)-1); i >=((sizeof(y))/2); i--)//assign the left bytes of X
        {
            resultBytes[i] = bytesY[i];
        }
        for(int j = 0; j < (sizeof(x)/2); j++) {
            resultBytes[j] = bytesX[j];
        }
    }
    else {
        //if your machine is Little endian so the LSB is stored first.
        unsigned char lsb = bytesY[0];
        resultBytes[0] = lsb;
        for(int j = 0; j < (sizeof(y)/2); j++) {
            resultBytes[j] = bytesY[j];
        }
        for (i = (sizeof(x)-1); i >=((sizeof(x))/2); i--)//assign the left bytes of X
        {
            resultBytes[i] = bytesX[i];
        }
    }
    return result;
}
/***************************************************************************************************
 Function Name: put_byte
 Function input:unsigned long x, unsigned char b, int i
 Function Action: replace the byte with the index of i in the x variable with a given char b.
 Function output: the result after replacement of unsigned long type
 **************************************************************************************************/
unsigned long put_byte(unsigned long x, unsigned char b, int i) {
    unsigned long result = x;//the final result
    //typecast to char pointer which is only one byte= 8 bits
    unsigned char* resultBytes =(unsigned char *)(&result);//typecast to char pointer which is only one byte
    //first check Endianness
    if (is_big_endian()) {
        resultBytes[i] = b;
    }
    else {
        resultBytes[sizeof(x)-1-i] = b;
    }
    return result;
}