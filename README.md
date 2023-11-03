# PPP-code
《C++程序设计原理与实践》书中代码和习题解答

本书网站：https://www.stroustrup.com/programming.html

笔记：https://zzy979.github.io/posts/ppp-note-index/

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
[std_lib_facilities.h](https://www.stroustrup.com/Programming/std_lib_facilities.h)

## 第2章 Hello, World!
* [Hello world](ch02/hello_world.cpp)

### 习题
* [2-1](ch02/exec2-1.cpp)

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
* [5-7](ch05/solve_quadratic_equation.cpp)
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

### 简单练习
* [绘制函数图像练习](ch15/function_graphing_drill.cpp)
* [类定义练习](ch15/person.h)

### 习题
* [15-1](ch15/factorial.cpp)
* [15-2](ch15/exec15-2.cpp)
* [15-4](ch15/exec15-4.cpp)
* [15-5](ch15/exec15-5.cpp)
* [15-6~15-9](ch15/exec15-8.cpp)
* [15-11](ch15/exec15-11.cpp)

## 第16章 图形用户界面
### 16.5 一个实例
* [Lines_window](ch16/lines_window.h)
* [主程序](ch16/draw_lines.cpp)

### 16.7 添加菜单
* [Lines_window](ch16/lines_window.h)

### 简单练习
* [Lines_window](ch16/lines_window.h)

### 习题
* [16-3](ch16/exec16-3.cpp)
* [16-4](ch16/exec16-4.cpp)
* [16-6](ch16/exec16-6.cpp)
* [16-9](ch16/exec16-9.cpp)
* [16-10](ch16/exec16-10.cpp)

## 第17章 向量和自由空间
### 17.3 内存、地址和指针
#### 17.3.1 sizeof运算符
* [试一试](ch17/sizeof_example.cpp)

### 17.5 析构函数
#### 17.5.2 析构函数和自由存储
* [试一试](ch17/destructor_example.cpp)

### 17.6 访问元素
* [简单向量v1](ch17/simple_vector.h)

### 17.9 指针和引用
#### 17.9.3 示例：链表
* [双向链表](ch17/doubly_linked_list.h)

#### 17.9.5 链表的应用
* [链表的应用](ch17/linked_list_use.cpp)

### 17.10 this指针
* [双向链表v2](ch17/doubly_linked_list_v2.h)

#### 17.10.1 链表的应用
* [链表的应用v2](ch17/linked_list_use_v2.cpp)

### 简单练习
* [drill17](ch17/drill17.cpp)

### 习题
* [17-2](ch17/exec17-2.cpp)
* [17-3~17-5](ch17/string_algorithm_exec17.cpp)
* [17-7~17-8](ch17/exec17-7.cpp)
* [17-9](ch17/exec17-9.cpp)
* [17-11](ch17/linked_list_use_v2.cpp)
* [17-13](ch17/exec17-13.cpp)

## 第18章 向量和数组
* [简单向量v2](ch18/simple_vector.h)

### 18.4 基本操作
#### 18.4.2 调试构造函数和析构函数
* [试一试](ch18/debug_ctor_dtor.cpp)

### 18.7 实例：回文
* [is_palindrome函数](ch18/palindrome.cpp)

### 简单练习
* [drill18](ch18/drill18.cpp)

### 习题
* [18-1~18-7](ch18/string_algorithm_exec18.cpp)
* [18-8](ch18/palindrome.cpp)
* [18-9](ch17/exec17-9.cpp)

## 第19章 向量、模板和异常
* [简单向量v3](ch19/simple_vector.h) （简化的`std::vector`）

### 19.3 模板
#### 19.3.5 整数作为模板参数
* [简单数组](ch19/simple_array.h) （简化的`std::array`）

### 简单练习
* [drill19](ch19/drill19.cpp)

### 习题
* [19-1](ch19/vector_add.h) （实现`std::valarray`的`operator+`）
* [19-2](ch19/inner_product.h) （实现`std::inner_product()`）
* 19-3 （实现`std::pair`）
  * [Pair](ch19/pair.h)
  * [Symbol_table](ch19/symbol_table.h)
* 19-4
  * [双向链表v3](ch19/doubly_linked_list_v3.h)
  * [链表的应用v3](ch19/exec19-4.cpp)
* [19-5~19-7](ch19/number.h)
* [19-8~19-9](ch19/simple_allocator.h) （简化的`std::allocator`）
* [19-10](ch19/unique_ptr.h) （简化的`std::unique_ptr`）
* [19-11](ch19/counted_ptr.h) （简化的`std::shared_ptr`）

## 第20章
### 20.1 存储和处理数据
#### 20.1.1 使用数据
* [Jack-and-Jill](ch20/jack_and_jill_v1.cpp)

#### 20.1.2 一般化代码
* [Jack-and-Jill v2](ch20/jack_and_jill_v2.cpp)

### 20.3 序列和迭代器
* [试一试](ch20/copy.cpp)

#### 20.3.1 回到示例
* [Jack-and-Jill v3](ch20/jack_and_jill_v3.cpp)

### 20.4 链表
* [双向链表v4](ch20/doubly_linked_list_v4.h) （简化的`std::list`）[WIP]

### 20.5 再次一般化vector
* [简单向量v3](ch19/simple_vector.h)

### 20.6 示例：简单文本编辑器
* [简单文本编辑器](ch20/simple_text_editor.h)

### 20.8 使我们的vector适配STL
* [简单向量v3](ch19/simple_vector.h)

### 20.9 使内置数组适配STL
* [简单数组](ch19/simple_array.h)

### 简单练习
* [drill20](ch20/drill20.cpp)

### 习题
* [20-2](ch20/jack_and_jill_v2.cpp)
* [20-4](ch20/jack_and_jill_v4.cpp)
* [20-5](ch19/drill19.cpp)
* [20-6](ch20/simple_text_editor.cpp)
* [20-7](ch20/high.h)
* [20-8~20-10](ch20/simple_text_editor.cpp)
* [20-12](ch20/exec20-12.cpp)
* [20-13](ch20/doubly_linked_list_v4.h)
* [20-14](ch20/singly_linked_list.h) （简化的`std::forward_list`）[WIP]
* [20-15](ch20/pvector.h)
* [20-16](ch20/ovector.h)
* [20-17](ch20/ownership_vector.h)
* [20-18~20-19](ch20/range_checked_iterator.h)
* [20-20](ch20/exec20-20.cpp)
  * 编译命令：`g++ -std=c++14 -O2 -o exec20-20 exec20-20.cpp`
  * [测试结果](ch20/exec20-20_result.csv)（看起来似乎不存在`list`比`vector`快的可能性）

## 第21章 算法和映射
### 21.4 函数对象
* [Larger_than函数对象](ch21/larger_than.h)

### 21.5 数值算法
#### 21.5.2 一般化accumulate()
* [计算物品总价](ch21/calculate_total_cost.cpp)

#### 21.5.3 inner_product()
* [计算股票市场指数](ch21/calculate_stock_market_index.cpp)

### 21.6 关联容器
#### 21.6.1 map
* [统计单词出现次数](ch21/word_frequency.cpp)

#### 21.6.3 另一个map示例
* [计算股票市场指数v2](ch21/calculate_stock_market_index_v2.cpp)

### 21.7 拷贝操作
#### 21.7.2 流迭代器
* [简单字典v2](ch21/simple_dictionary_v2.cpp)

### 21.8 排序和搜索
* [排序字符串（不区分大小写）](ch21/sort_strings_ignore_case.cpp)

### 简单练习
* [21-1](ch21/drill21-1.cpp)
* [21-2](ch21/drill21-2.cpp)
* [21-3](ch21/drill21-3.cpp)

### 习题
* [21-3~21-4](ch21/count.h)
* [21-6](ch21/exec21-6.cpp)
* [21-7](ch21/binary_search.h)
* [21-8](ch21/exec21-8.cpp)
* 21-9~21-10
  * [Order类](ch21/order.h)
  * [主程序](ch21/exec21-9.cpp)
* 21-11~21-12
  * [Order_list_window](ch21/order_list_window.h)
  * [Order_list_table](ch21/order_list_table.h)
  * [Order_edit_window](ch21/order_edit_window.h)
  * [Purchase_list_table](ch21/purchase_list_table.h)
  * [主程序](ch21/exec21-11.cpp)
* 21-13~21-15
  * [Word_query](ch21/word_query.h)
  * [Word_query_window](ch21/word_query_window.h)
  * [主程序](ch21/exec21-15.cpp)

## 第23章 文本处理
### 23.2 字符串
* [字符串转换函数](ch23/string_convert.h)

### 23.4 映射
* 查找邮件
  * [Message_file](ch23/email_message.h)
  * [主程序](ch23/find_email.cpp)

### 23.7 使用正则表达式搜索
* [查找邮政编码](ch23/find_postal_codes.cpp)

### 23.8 正则表达式语法
#### 23.8.7 正则表达式错误
* [测试正则表达式](ch23/test_regex.cpp)

### 23.9 使用正则表达式匹配
* [验证表格](ch23/verify_table.cpp)

### 简单练习
* [查找邮政编码](ch23/find_postal_codes.cpp)

### 习题
* [23-1](ch23/testdata/test.eml)
* [23-2~23-4](ch23/find_email_v2.cpp)
* [23-6](ch23/exec23-6.cpp)
* [23-8](ch23/exec23-8.cpp)
* [23-10](ch23/exec23-10.cpp)
* [23-12](ch23/exec23-12.cpp)
* [23-13](ch23/exec23-13.cpp)
* [23-15~23-16](ch23/exec23-15.txt)

## 第24章 数值计算
### 24.2 大小、精度和溢出
* [溢出和截断](ch24/overflow_and_truncation.cpp)

#### 24.2.1 数值限制
* [数值限制](ch24/numeric_limits.cpp)

### 24.5 Matrix库
* [矩阵示例](ch24/matrix_example.cpp)

#### 24.5.1 维度和访问
* [二维矩阵](ch24/two_dim_matrix.cpp)

### 24.6 示例：解线性方程组
* [高斯消元法](ch24/gaussian_elimination.cpp)
* [主程序](ch24/solve_linear_equations.cpp)

#### 24.6.3 测试
* [解随机线性方程组](ch24/solve_random_system.cpp)

### 24.7 随机数
* [生成正态分布直方图](ch24/generate_normal_dist_histogram.cpp)

### 简单练习
* [24-1~24-3](ch24/drill24-1.cpp)
* [24-4](ch24/drill24-4.cpp)
* [24-5, 24-8](ch24/drill24-5.cpp)
* [24-6](ch24/drill24-6.cpp)
* [24-7](ch24/drill24-7.cpp)

### 习题
* [24-1~24-2](ch24/drill24-1.cpp)
* [24-4](ch24/solve_linear_equations.cpp)
* [24-5](ch24/testdata/solve_linear_equations_input6.txt)
* [24-8](ch24/exec24-8.cpp)
* [24-10](ch24/exec24-10.cpp)
* [24-11](ch24/exec24-11.cpp)
* [24-12](ch24/matrix_operation.h)

# 术语
[术语](terms.md)

参考：[Bjarne Stroustrup's C++ Glossary](https://www.stroustrup.com/glossary.html)
