#define uchar unsigned char
#define uint  unsigned int

void DS1302_init();//初始化
void DS1302_WriteByte(uchar command,uchar date);//写一个字节
uchar DS1302_ReadByte(uchar command);//读一个字节


