#include <reg52.h>
#include "Public.h"
#include "INT0.h"
#include "Time0.h"

void IR_Init();//红外初始化

uchar IR_getdateflag();//数据标志位
uchar IR_getrepeat();//重复信号标志位


uchar IR_getadd();//获取红外地址
uchar IR_getcommand();//获取键码值