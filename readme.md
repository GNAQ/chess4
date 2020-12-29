# C 语言实验课 - 四子棋

· GNAQ ·

平台：Windows 10 + Visual Studio Code + Windows Terminal

工具：MinGW-W64 + CMake + git + Powershell 7

技术：C

**CLI 四子棋游戏。**

Let's Go!

## 碎碎念 && 四子棋规则介绍

第一次完整使用 CMake、git 等成熟开发工具和 C 语言的 little attampt~

四子棋其实是受了一个视频的启发（Switch 上有这款游戏）。

希望慢慢进步吧……

-----------------

## Flags

### 2020/12/21

计划了两个库

一个是账号库，记录对战数据，提供注册功能和登入功能，数据库用加密存储。

为此我估计还得写个简易数据库出来。不过这个不难做。

字符串加密手段还没想好。账号密码就只支持可见 ASCII 字符集的常用子集算了。

上述这些都丢到一个库里。

~~一个是专门处理各种零碎功能的库。~~

~~今天写 `Welcome` 页面的时候发现了一个问题，我想用一个即时相应的键盘输入方式~~

~~这样就来一个函数专门处理他。具体写在代码注释里了。~~

今晚我就写完 `CBoard` 棋盘处理。 

-----------------

## Daily Logs

### 2020/12/21

初始化 git repo。初始化 `CMakeLists`。

第一行 `Hello World`。

创建 github repo。编写本 readme 并上传 remote。

添加 gitignore。

-

开始写 Natsu 库。

> [15:07]
> 
> Natsu 作为胶水库会被多方调用，目录关系还是同层的，现> 在 CMake 开始玩我了。
> 
> 试试把 natsu 单独分离出来编译行不行。
> 
> [15:14]
> 
> 开始魔改……
> 
> [15:38] 
> 
> ld 一直报错 ` undefined reference to > 'Get_single_key_input'`，搞不明白。
> 
> [16:08]
> 
> 生命在于折腾。。。
> 终于搞明白了
> 
> 翻了一篇奇怪的博客 ([URL Here](https://www.> cnblogs.com/oldBook/archive/2004/01/13/> 11884212.html))
> 
> 他说要加这三行
> 
> ```plain
> add_library(natsu STATIC IMPORTED)
> set_property(TARGET natsu PROPERTY > IMPORTED_LOCATION ./src/natsu/libnatsu.a)
> target_link_libraries(chess4 natsu)
> ```
> 
> 然后就行了……我也不知道为什么……
> 
> [16:15]
> 
> 现在又不行了。现在是 `add_subdirectory` 的 CBoard > 出问题了
> 
> md, 怎么回事
> 
> [16:28]
> 
> 瞎整了一顿，现在差不多了。
> 
> 现在最关键的问题是
> 
> [16:30]
> 
> 得了，没有最关键的问题了，好像都搞定了。
> 
> `add_subdirectory()` 一定程度上真是好文明（共享变量> 方面）
> 
> [16:35]
> 
> 好耶！！！！
> 
> 现在完全完美了

完成了所有依赖和库的配置。

现在是 Natsu 库单独用 CMake 编译，其他库和 `main.c` 放一起用 CMake 编译。

添加了库检查。

现在可以开始实现具体功能了！

-

> [22:13]
> 睡了一觉起来轻松多了
> 开始写点 CBoard，然后就写线代作业

### 2020/12/29

我回来了。

这次事态紧急，干他妈的。

不多说了，写功能了。

> [1:44]
>
> 写完了 `CBoard` 的功能
> 
> 发现所有结构体定义都该丢到 `Natsu` 里去，要么就完蛋了。
>
> 趁着睡觉前 `cli` 撸一半出来。（其实也就对弈主界面显示）

得了，现在写好倒是写好了，给我整出 redef 来了……

天杀的各种库依赖

学会了，直接 `#pragma once`

呃，测试挂了，为什么……

草，我 `strcpy` 了个寂寞，这 `(char*)CBoard->usrA` 根本就没分配空间……

> [14:54]
>
> 加把劲，今天就把对局做出来，然后搞定账号系统就完工了。。
> 
> 对弈机器人不做了，md。
>
> 哦还有对弈历史
>
> 哦豁，完蛋