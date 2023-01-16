# PPP-code
《C++程序设计原理与实践》书中代码和习题解答

本书网站：https://www.stroustrup.com/programming.html

笔记：https://blog.csdn.net/zzy979481894/article/details/125922900

# 运行方式
本项目使用CMake构建，通过IDE或命令行的方式编译并运行其中的代码示例。

## IDE
直接使用支持CMake的IDE（如CLion, Visual Studio或Visual Studio Code）打开即可。

## 命令行
以Linux系统为例，使用Unix Makefiles生成器：
```bash
$ cmake -G "Unix Makefiles" -B cmake-build
$ cmake --build cmake-build
$ cmake-build/ch02/hello_world 
Hello, World!
```

# 单元测试
使用CTest运行单元测试：
```bash
$ cd cmake-build/
$ ctest
```

# 代码目录
## 第2章 Hello, World!
* [Hello world](ch02/hello_world.cpp)

### 习题
* [习题1](ch02/exec2-1.cpp)

## 第3章 对象、类型和值
### 3.1 输入
* [读取并打印名字](ch03/read_and_write_first_name.cpp)

### 3.3 输入和类型
* [读取名字和年龄](ch03/read_name_and_age.cpp)
* [读取名字和年龄（版本2）](ch03/read_name_and_age_v2.cpp)
* [读取全名](ch03/read_full_name.cpp)
* [试一试](ch03/read_name_and_age_v3.cpp)

### 3.4 运算和运算符
* [练习运算符](ch03/double_operators.cpp)
* [试一试](ch03/integer_operators.cpp)
* [读取全名（版本2）](ch03/read_full_name_v2.cpp)
* [读取并比较名字](ch03/read_and_compare_names.cpp)

### 3.5 赋值和初始化
* [检测重复单词](ch03/detect_repeated_words.cpp)

### 3.6 组合赋值运算符
* [查找重复单词](ch03/find_repeated_words.cpp)

### 3.9 类型安全
* [试一试](ch03/unsafe_conversions.cpp)

### 简单练习
* [信件生成器](ch03/letter_generator.cpp)

### 习题
* [3-2](ch03/exec3-2.cpp)
* [3-4](ch03/exec3-4.cpp)
* [3-5](ch03/exec3-5.cpp)
* [3-6](ch03/exec3-6.cpp)
* [3-7](ch03/exec3-7.cpp)
* [3-8](ch03/exec3-8.cpp)
* [3-9](ch03/exec3-9.cpp)
* [3-10](ch03/exec3-10.cpp)
* [3-11](ch03/exec3-11.cpp)

## 第4章 计算
### 4.4 语句
#### 4.4.1 选择语句
##### 4.4.1.1 if语句
* [厘米-英寸转换](ch04/convert_length_unit.cpp)
* [试一试](ch04/convert_currency.cpp)

##### 4.4.1.2 switch语句
* [厘米-英寸转换(switch)](ch04/convert_length_unit_v2.cpp)

##### 4.4.1.3 switch技术细节
* [试一试](ch04/convert_currency_v2.cpp)

#### 4.4.2 循环语句
##### 4.4.2.1 while语句
* [打印平方数表(while)](ch04/print_squares_table.cpp)
* [试一试](ch04/print_character_table.cpp)

##### 4.4.2.3 for语句
* [打印平方数表(for)](ch04/print_squares_table_v2.cpp)
* [试一试](ch04/print_character_table_v2.cpp)

### 4.6 向量
#### 4.6.3 一个数值计算的例子
* [计算温度的平均值和中位数](ch04/mean_median_temperature.cpp)

#### 4.6.4 一个文本处理的例子
* [简单字典](ch04/simple_dictionary.cpp)
* [试一试](ch04/bleep_disliked_words.cpp)

### 简单练习
* [长度统计](ch04/length_statistics.cpp)

### 习题
* [4-2](ch04/mean_median_temperature.cpp)
* [4-3](ch04/exec4-3.cpp)
* [4-4](ch04/exec4-4.cpp)
* [4-5](ch04/exec4-5.cpp)
* [4-6](ch04/exec4-6.cpp)
* [4-9](ch04/exec4-9.cpp)
* [4-10](ch04/exec4-10.cpp)
* [4-12](ch04/exec4-12.cpp)
* [4-14](ch04/exec4-14.cpp)
* [4-16](ch04/exec4-16.cpp)
* [4-17](ch04/exec4-17.cpp)
* [4-18](ch04/exec4-18.cpp)
* [4-19~4-21](ch04/exec4-21.cpp)

## 第5章 错误
### 5.6 异常
#### 5.6.1 参数错误
* [计算面积](ch05/area.cpp)

### 5.7 逻辑错误
* [统计温度(bug)](ch05/temperature_stats_buggy.cpp)
* [试一试](ch05/temperature_stats_fixed.cpp)

### 习题
* [5-2~5-6](ch05/temperature_converters.cpp)
* [5-7](ch05/solve_equation.cpp)
* [5-8](ch05/sum_n_integers.cpp)
* [5-11](ch05/fibonacci_series.cpp)
* [5-12~5-13](ch05/bulls_and_cows.cpp)

## 第6章 编写一个程序
* [简单计算器v0](ch06/calculator_v0.cpp)
* [简单计算器v1](ch06/calculator_v1)
  * [词法分析器](ch06/calculator_v1/lexer.h)
  * [语法分析器](ch06/calculator_v1/parser.h)
  * [主程序](ch06/calculator_v1/main.cpp)

### 习题
* [6-4](ch06/exec6-4.cpp)
* [6-5](ch06/exec6-5.txt)
* [6-7](ch06/exec6-7.txt)
* [6-9](ch06/exec6-9.cpp)
* [6-10](ch06/exec6-10.cpp)

## 第7章 完成一个程序
* [简单计算器v1](ch07/calculator_v2)
  * [符号表](ch07/calculator_v2/variable.h)
  * [词法分析器](ch07/calculator_v2/lexer.h)
  * [语法分析器](ch07/calculator_v2/parser.h)
  * [主程序](ch07/calculator_v2/main.cpp)

## 第8章 函数相关的技术细节
### 简单练习
* [8-1](ch08/use.cpp)
* [8-2](ch08/swaps.cpp)
* [8-3](ch08/drill8-3.cpp)

### 习题
* [8-2](ch08/print_vector.cpp)
* [8-3](ch08/fibonacci.cpp)
* [8-4](ch08/fibonacci_test.cpp)
* [8-5~8-6](ch08/reverse_vector.cpp)
* [8-7](ch08/exec8-7.cpp)
* [8-10](ch08/inner_product.cpp)
* [8-11~8-12](ch08/describe_vector.cpp)
* [8-13](ch08/print_until.cpp)
* [8-14](ch08/describe_vector.cpp)

## 第9章 类相关的技术细节
### 9.8 Date类
* [Date类](ch09/Chrono.h)

### 简单练习
* [测试Date类](ch09/Chrono_test.cpp)

### 习题
* [9-2~9-3](ch09/name_pairs.h)
* [9-4](ch09/nesting_example.cpp)
* [9-5~9-7](ch09/book.h)
* [9-8](ch09/patron.h)
* [9-9](ch09/library.h)
* [9-10~9-11](ch09/Chrono.cpp)
* [9-13](ch09/relational.h)

## 第10章 输入/输出流
### 10.5 读写文件
* [读取温度数据文件](ch10/read_temperatures.cpp)

### 10.6 I/O错误处理
* [读取整数向量](ch10/fill_vector.cpp)

### 10.7 读取单个值
* 读取一个指定范围内的整数
  * [get_int函数](ch10/get_int.cpp)
  * [主程序](ch10/read_integer_in_range.cpp)

### 10.11 读取结构化的文件
* 读取结构化的温度数据文件
  * [温度读数数据结构](ch10/temperature_reading.h)
  * [主程序](ch10/read_structured_temperatures.cpp)

# 术语
[术语](terms.txt)

参考：[Bjarne Stroustrup's C++ Glossary](https://www.stroustrup.com/glossary.html)
