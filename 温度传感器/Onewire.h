#include <reg52.h>

unsigned char onewire_Init();  // ��ʼ��

//����һλ
void onewire_sendbit(unsigned char b);

//����һλ
unsigned char onewire_rb();


//����һ���ֽ�
void onewire_sendbyte(unsigned char byte);


//����һ���ֽ�
unsigned char onewire_rbyte();