# BlueLeopard：蓝豹子

主要记录课本例题以及课后习题中光看不是很好理解的代码

翁惠玉版C++教材，封面是蓝色的并且有一只豹子，简称蓝豹子.

[TOC]

## 关于用RAND_MAX生成随机整数、随机实数

rand()来自cstdlib库

RAND_MAX也是来自cstdlib库的一个常量

rand()产生随机数范围是[0, RAND_MAX]中的整数

srand(time(NULL))设置随机数的种子

---

生成[0, 1]区间的随机实数：(doube)rand() / RAND_MAX

假设RAND_MAX=10，显然[0, 10]区间会对应这[0, 1.0]区间

---

生成[low, high]区间的整数： low + （high - low + 1)*rand() / (RAND_MAX + 1)

为什么后面要加1呢？

比如生成[0, 10]区间的整数

最大值 = 0 + ( 10 - 0 + 1 ) * 10 / ( 10 + 1) = 110 / 11 = 10

---

生成[low, high]区间的实数： low + （high - low + 1)*(double)rand() / (RAND_MAX + 1)

根据上面的铺垫，这个就很好理解了

上述内容对应蓝豹子page-211

