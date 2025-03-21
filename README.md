[中文](README.md) ||  [English](README.en.md)  
# XEngine_ServiceFramework
只要仓库不是在暂停状态,那么就会有人一直维护和开发,请放心使用  

## 介绍
c c++ ai模块集合.通过收集各种ai开源库集成为统一模块,方便使用  
代码拥有详细的注释,你可以非常方便的了解它是如何运作的  

## 软件特性
支持以下技术  
1. AI声音转文本

## 安装教程

#### XEngine环境
必须安装XEngine,版本需要V9或者以上版本,安装XEngine可以参考其Readme文档  
GITEE:https://gitee.com/libxengine/libxengine  
GITHUB:https://github.com/libxengine/libxengine

###### 快速部署
git clone https://gitee.com/libxengine/libxengine.git 或者 git clone https://github.com/libxengine/libxengine.git  
window执行XEngine_WINEnv.bat 脚本.  
Linux执行:sudo ./XEngine_LINEnv.sh -i 3  
macos执行:./XEngine_LINEnv.sh -i 3  

#### Windows
使用VS打开并且编译,支持WINDOWS 10以及以上系统  
直接运行即可

#### Linux
Linux使用Makefile编译,UBUNTU22.04 x64或者RockyLinux9 x64  
在控制台运行

#### Macos
使用makefile编译,控制台运行,需要mac 13以及以上版本  
在控制台运行

##### 编译命令
在XEngine_Source目录下执行命令  
make 编译  
make FLAGS=InstallAll 安装库程序  
make FLAGS=CleanAll 清理编译  

## 如何开发
#### 如何部署
音频转文本需要whisper.cpp库支持,我们编译了win64和win32,win64使用了cuda.win32是CPU.没有ARM,因为显卡不支持.  
XEngine_Release目录有模块,自己编译API模块后把这个目录的模块一起拷贝到程序下使用  

## 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request 

## 关注我们
如果你觉得这个软件对你有帮助,请你给我们一个START吧

## 提交问题

如果你有问题,可以在issues中提交