#include <reg52.h>
#include "Public.h"

void Time0Init();//初始化定时器

void Time0set(uint value);//设置时间

uint Gettime();//获取时间数值

void Time0run(uchar run);//启动定时器