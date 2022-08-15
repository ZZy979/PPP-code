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

# 术语
[术语](terms.txt)

参考：[Bjarne Stroustrup's C++ Glossary](https://www.stroustrup.com/glossary.html)
