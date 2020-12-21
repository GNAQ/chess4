// Natsu 是负责提供简便工具函数、协调各库、环境和 OS 的「胶水库」

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

// 阻塞式等待键盘输入字符，即时响应
// 并匹配 req 中的字符
// 匹配成功则返回其在 req 中的下标，从 0 开始
// 如果传入 _ 代表一个通配符，匹配除其余指明字符外的所有字符。
int Get_single_key_input(char *req);

void Change_window_size(int height, int width);

void HelloNatsu();