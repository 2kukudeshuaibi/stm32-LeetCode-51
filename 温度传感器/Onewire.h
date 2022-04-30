#include <reg52.h>

unsigned char onewire_Init();  // 初始化

//发送一位
void onewire_sendbit(unsigned char b);

//接受一位
unsigned char onewire_rb();


//发送一个字节
void onewire_sendbyte(unsigned char byte);


//接受一个字节
unsigned char onewire_rbyte();