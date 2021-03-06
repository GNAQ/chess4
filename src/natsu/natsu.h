// Natsu 负责提供简便工具函数、协调各库、环境和 OS。
// “胶水库”
#pragma once

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

typedef struct tm __Sys_time;
// 棋盘类 struct 声明
// 历史记录
struct _HistoryA
{
	int winner;
	int tot_steps, height, width;
	int *posx, *posy;
	char *userA, *userB;
	__Sys_time *game_time;
	time_t std_fmt_time;
};
typedef struct _HistoryA HisA;
// 盘面
struct _Board
{
	int **mat;
	int height, width;
	// 对弈
	char *userA, *userB; // 用户名
	int idA, idB; // 用户 Hash
	int winner; // .. 0 / 1 / 2 / -1[平局]
	// 历史
	HisA *his;
};
typedef struct _Board Board;
// 创建 CBoard 的结果
struct _CreateResult
{
	// 创建成功返回 1
	// 内存空间不足返回 -1
	int result;
	Board bd;
};
typedef struct _CreateResult CreateResult;
// 创建历史记录的结果
struct _CreateHisA
{
	int result;
	HisA his;
};
typedef struct _CreateHisA CreateHisA;
// 文件链表
struct _FileLL
{
	int id;
	FILE *fp;
	struct _FileLL *prev, *next;
};
typedef struct _FileLL FileLL;

// 函数如下

void HelloNatsu(void);

// 手写的读 int
void ReadInt(int *x);

// 阻塞式等待键盘输入字符，即时响应
// 并匹配 req 中的字符
// 匹配成功则返回其在 req 中的下标，从 0 开始
// 如果传入 _ 代表一个通配符，匹配除其余指明字符外的所有字符。
int Get_single_key_input(char *req);

// 改变命令行的窗口大小。
void Change_window_size(int height, int width);

// 检查历史记录的目录结构.
void Check_file_dir(void);

// 保存历史记录到文件。
void Save_his(HisA* his);

// 链表的添加操作
FileLL* Add_filell(FileLL *last, FILE *addfp);

// 链表的初始化操作
FileLL* Init_filell(void);

// 解析文件树到链表
FileLL* Resolute_logtree(FileLL* head);

// 销毁链表和其内存
void Destroy_filelog(FileLL *head);

// 从文件读历史记录到 HisA 结构体。
void Read_his(FileLL *logid, HisA *his);