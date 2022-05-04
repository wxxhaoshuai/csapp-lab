/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  //化简异或表达式
  return (~(~x&~y))&(~(x&y));
}

/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  //最小的整形二进制补码为0x10000000
  return 1<<31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {
  //如果x是二进制补码的最大值返回1
  //和其异或，返回0取反则得到一
  return !(x^0x7fffffff);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  //如果奇位的数字为1返回1
  //A = 1010
  //用掩码的方式
  /*
  int mask = 0xAA+(0xAA<<8);
  mask = mask+(mask<<16);
  return !((mask&x)^mask);*/
  int mask = 0xaaaaaaaa;
  return !((mask&x)^mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  //返回补码
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  //返回特定范围的数
  int min = 0x2F+(~x+1);
  int max = 0x39+(~x+1);
  min = min>>31;
  max = !(max>>31);
  return min&max;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  //实现一个三目表达式：x是否不为零返回y或z
  //！：逻辑非
  x = !!x;//此炒作返回一个0或1的数
  x = ~x+1;//0的补码为全0,1的补码为全1，根据这个特性实现选择
  return (y&x)|(z&(~x));

}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  //实现小于等于操作符;
  int negX=~x+1;//-x,
  int addX=negX+y;//y-x补码加法=原码减法
  int checkSign = addX>>31&1; //y-x的符号
  int leftBit = 1<<31;//最大位为1的32位有符号数
  int xLeft = x&leftBit;//x的符号
  int yLeft = y&leftBit;//y的符号
  int bitXor = xLeft ^ yLeft;//x和y符号相同标志位，相同为0不同为1
  bitXor = (bitXor>>31)&1;//符号相同标志位格式化为0或1
  return ((!bitXor)&(!checkSign))|(bitXor&(xLeft>>31));

}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  //实现逻辑非
  //x sign is -    x sign is + 
  //如果是负数，直接返回1
  //如果是正数，符号位为零，判断是否为0
  return ~(x>>31)&(((~x+1)>>31)+1);
  
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int b16,b8,b4,b2,b1,b0;
  int mask = x>>31;
  x = ((~mask)&x)|(mask&(~x));

  b16 = !!(x>>16)<<4; //如果高16为有1,则b16 = 16，否则为0
  x>>=b16;//如果高16为有1,x右移16位舍弃低16位,在新的低16位继续查找；否则保持不变

  b8 = !!(x>>8)<<3;
  x>>=b8;

  b4 = !!(x>>4)<<2;
  x>>=b4;
  
  b2 = !!(x>>2)<<1;
  x>>=b2;
  
  b1 = !!(x>>1);
  x>>=b1;
  
  b0 = x;

  
  return b16+b8+b4+b2+b1+b0+1;
}
//float
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
    unsigned s = uf & 0x80000000;
    unsigned exp = (uf & 0x7f800000)>>23;
    unsigned frac = uf & 0x7fffff;
    unsigned ans = 0;
    unsigned inf = s|(0xff<<23);
    if(exp==0xff) return uf;
    if(exp==0){
        frac = frac<<1;
	ans = s|(exp<<23)|frac;
	return ans;
    }
    	 
    exp ++;
    if(exp==0xff)return inf;
   
    ans = s|(exp<<23)|frac;
    return ans;
    

}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  /*例：float f=15213.0 ，其二进制值为0011 1011 0110 1101. 在IEEE 754中
其位表示为：(-1)^0 * (1.1101101101101) * 2^13
exp=13+bias(在float中为127)=1000 1100（二进制）
frac=1101101101101…0(小数去掉1，共23位)
s=0

向偶舍入：（四舍六入五成双）
即规定的位后面>100,则进1
若<100,则舍去
若等于100，若此位为1,则进1；此位为0，则舍去。*/
  
    unsigned temp,result;
    //符号位，阶码，尾数长度，补零数，进位标志
    int s,exp,fracbit,highbit,flag;
    if(!x)return x;//0直接返回
    s = (x>>31)&0x01;
    if(s){//int中存储的负数是补码，要转化为正的
	x = ~x+1;
    }
    highbit = 0;
    temp = x;
    while(!(temp&0x80000000)){//找到最高位的一前面有几个零，这几个零待会要舍去
	temp<<=1;
	highbit++;
    }	
    //根据规格数的规则，最高位的1要隐藏
    temp=temp<<1;
    //根据单精度浮点数规则计算出exp，和frac位数
    fracbit = 31-highbit;
    exp = 127+fracbit;
    flag=0;
    //此处需要舍去9位因为frac：23位,int:32位
    if((temp&0x1ff)>0x100){//对应大于5
	flag =1;	 
    }
    if((temp&0x3ff)==0x300){//对应该位为1
	flag =1;	 
    }
    result=(s<<31)+(exp<<23)+(temp>>9)+flag;
    return result;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  //规格化的：尾数：M=1+f
  //非规格化的 尾数：M = f
  int sign = uf>>31;
  int exp = (uf>>23)&0xff;
  int frac = uf&0x007fffff;
  //E = e-bias
  int E = exp - 127;
  //阶码小于零，2的负次方，乘与尾数的1.x，结果一定小于零，作归零处理.
  if(E<0)return 0;
  //exp-127>=31如果E >= 31，小数点右移31位，此时隐含的1和frac占32位，另外还需要一个符号位，超出了int型范围
  else if(E>=31) return 0x80000000;
  else {
    frac = frac|0x00800000;//加上隐含的1
    if(E<23){
      //阶码小于23,相当于要在尾数左边补零
      frac >>= (23-E);
    }
    else{
      //阶码大于23,相当于要在尾数右边补零
      frac <<= (E-23);
    }
    if (sign)
      //根据符号位确定正负
      return -frac;
    else
      return frac;
  }
 
}
