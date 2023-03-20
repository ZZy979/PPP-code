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

### 简单练习
* [读写Point](ch10/read_write_points.cpp)

### 习题
* [10-1](ch10/exec10-1.cpp)
* [10-2](ch10/store_temps.cpp)
* [10-3~10-4](ch10/temp_stats.cpp)
* [10-5](ch10/temperature_reading.cpp)
* [10-6](ch10/roman_int.h)
* [10-8](ch10/exec10-8.cpp)
* [10-9](ch10/exec10-9.cpp)
* [10-11](ch10/exec10-11.cpp)

## 第11章 定制输入/输出
### 11.2 输出格式化
#### 11.2.1 整数输出
* [使用不同进制输出整数](ch11/output_integer_in_different_bases.cpp)

#### 11.2.2 整数输入
* [使用不同进制输入整数](ch11/input_integer_in_different_bases.cpp)

#### 11.2.4 精度
* [使用不同格式输出浮点数](ch11/output_float_in_different_formats.cpp)
* [设置精度](ch11/set_precision.cpp)

#### 11.2.5 域
* [设置域宽度](ch11/set_field_width.cpp)
* [打印联系方式表格](ch11/print_contact_table.cpp)

### 11.3 文件打开和定位
#### 11.3.2 二进制文件
* [读写二进制整数文件](ch11/read_write_binary_file.cpp)

### 11.4 字符串流
* [字符串转浮点数](ch11/str_to_double.cpp)

### 11.7 使用非标准分隔符
* [Punct_stream类](ch11/punct_stream.h)
* [自定义分隔符的字典](ch11/custom_separator_dictionary.cpp)

### 简单练习
* [11-1~11-7](ch11/output_integer_in_different_bases.cpp)
* [11-8](ch11/input_integer_in_different_bases.cpp)
* [11-9](ch11/output_float_in_different_formats.cpp)
* [11-10](ch11/print_contact_table.cpp)

### 习题
* [11-1](ch11/exec11-1.cpp)
* [11-2](ch11/exec11-2.cpp)
* [11-3](ch11/exec11-3.cpp)
* [11-4](ch11/exec11-4.cpp)
* [11-5](ch11/exec11-5.cpp)
* 11-6~11-8
  * [Punct_stream_v2](ch11/punct_stream_v2.h)
  * [主程序](ch11/custom_separator_dictionary_v2.cpp)
* [11-10~11-11](ch11/split.cpp)
* [11-12](ch11/exec11-12.cpp)
* [11-13](ch11/exec11-13.cpp)
* [11-14](ch11/exec11-14.cpp)
* [11-15](ch11/exec11-15.cpp)
* [11-16](ch11/exec11-16.cpp)

## 第12章 一个显示模型
### 12.3 第一个例子
* [绘制三角形](ch12/draw_triangle.cpp)

### 12.7 使用形状类
* [基本形状](ch12/shape_primitives.cpp)

### 简单练习
* [基本形状](ch12/shape_primitives.cpp)

### 习题
* [12-1](ch12/exec12-1.cpp)
* [12-2](ch12/exec12-2.cpp)
* [12-3](ch12/exec12-3.cpp)
* [12-4](ch12/exec12-4.cpp)
* [12-7](ch12/exec12-7.cpp)
* [12-8](ch12/exec12-8.cpp)
* [12-11](ch12/exec12-11.cpp)
* [12-12](ch12/exec12-12.cpp)

## 第13章 图形类
### 13.2 Point和Line
* [绘制线段](ch13/draw_two_lines.cpp)

### 13.3 Lines
* [绘制线段2](ch13/draw_two_lines2.cpp)
* [绘制网格](ch13/draw_grid.cpp)

### 13.4 Color
* [绘制红色网格](ch13/draw_grid.cpp)

### 13.5 Line_style
* [绘制红色点线网格](ch13/draw_grid.cpp)
* [绘制红色加粗虚线网格](ch13/draw_grid.cpp)
* [绘制有颜色的线段](ch13/draw_two_lines.cpp)

### 13.6 Open_polyline
* [绘制Open_polyline](ch13/draw_open_polyline.cpp)

### 13.7 Closed_polyline
* [绘制Closed_polyline](ch13/draw_closed_polyline.cpp)

### 13.8 Polygon
* [绘制多边形](ch13/draw_polygon.cpp)

### 13.9 Rectangle
* [绘制矩形](ch13/draw_rectangles.cpp)

### 13.10 管理未命名对象
* [绘制16×16颜色表](ch13/draw_color_matrix.cpp)

### 13.11 Text
* [显示文本](ch13/draw_closed_polyline.cpp)

### 13.12 Circle
* [绘制圆](ch13/draw_circles.cpp)

### 13.13 Ellipse
* [绘制椭圆](ch13/draw_ellipses.cpp)

### 13.14 Marked_polyline
* [绘制Marked_polyline](ch13/draw_marked_polyline.cpp)

### 13.15 Marks
* [绘制Marks](ch13/draw_marks.cpp)

### 13.16 Mark
* [绘制标记圆心的圆](ch13/draw_circles.cpp)

### 13.17 Image
* [绘制图像](ch13/draw_images.cpp)

### 简单练习
* [魔塔](ch13/magic_tower.cpp)

### 习题
* [13-1](ch13/exec13-1.cpp)
* [13-2](ch13/exec13-2.cpp)
* [13-3](ch13/exec13-3.cpp)
* [13-4](ch13/exec13-4.cpp)
* [13-5](ch13/exec13-5.cpp)
* [13-6](ch13/exec13-6.cpp)
* [13-8~13-10](ch13/exec13-9.cpp)
* [13-11](ch13/exec13-11.cpp)
* [13-12](ch13/exec13-12.cpp)
* [13-13](ch13/draw_color_matrix.cpp)

## 第14章 设计图形类
### 14.3 基类和派生类
#### 14.3.3 覆盖
* [覆盖的例子](ch14/overriding_example.cpp)

### 简单练习
* [drill14](ch14/drill14.cpp)

### 习题
* [14-1](ch14/exec14-1.cpp)
* [14-11~14-13](ch14/exec14-11.cpp)
* [14-15](ch14/iterator.h)
* [14-16](ch14/controller.h)
* [14-17](ch14/standard_exception_class_hierarchy.png)

## 第15章 绘制函数图和数据图
### 15.2 绘制简单函数图
* [绘制简单函数图](ch15/graphing_functions.cpp)

### 15.3 Function
#### 15.3.2 更多例子
* [绘制简单函数图](ch15/graphing_functions.cpp)

### 15.5 近似
* [指数函数近似](ch15/exp_approximation.cpp)

### 15.6 绘制数据图
* [绘制日本人年龄构成](ch15/graphing_japanese_age.cpp)

# 术语
[术语](terms.md)

参考：[Bjarne Stroustrup's C++ Glossary](https://www.stroustrup.com/glossary.html)
