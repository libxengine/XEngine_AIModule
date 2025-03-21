[中文](README.md) ||  [English](README.en.md)  
# XEngine_ServiceFramework
As long as the repository is not in suspended state, we will maintain and develop it all the time, please use it with confidence  

## Introduction
C c++ ai module collection. By collecting various Ai open source libraries to become unified modules, which is convenient for use  
The code has detailed comments, and you can easily understand how it works

## Software feature
Support the following technologies  
1. AI voice to text

## install

#### XEngine Evn
you must install XEngine,need V9 or above,install XEngine can be refer to xengine Readme docment  
GITEE:https://gitee.com/libxengine/libxengine  
GITHUB:https://github.com/libxengine/libxengine

##### fast to deployment 
git clone https://gitee.com/libxengine/libxengine.git or git clone https://github.com/libxengine/libxengine.git  
window Exection XEngine_WINEnv.bat   
Linux Exection:sudo ./XEngine_LINEnv.sh -i 3  
Macos Exection:./XEngine_LINEnv.sh -i 3

#### Windows
use vs open and compile,suport windows 7sp1 and above  
Just Run it

#### Linux
use makefile compile,UBUNTU22.04 x64 or RockyLinux9 x64  
Run it on the terminal

#### Macos
use makefile compile,mac 13 and above  
Run it on the terminal

##### Screenshot of the program
execute command in XEngine_Source path   
make complie  
make FLAGS=InstallAll Install File  
make FLAGS=CleanAll Clear Complie  

## How to develop
#### How to deploy
Audio to text requires support from whisper.cpp library. We compiled win64 and win32. Win64 uses cuda.win32 is a CPU. There is no ARM because the graphics card does not support it.  
The XEngine_Release directory has modules. After compiling the API module yourself, copy the modules in this directory to the program for use.

## Participate in contribution

1.  Fork this code
2.  Create new Feat_xxx branch
3.  Submit the code
4.  New Pull Request

## Follow us
If you think this software is helpful to you, please give us a START

## post issues

if you have eny quest.post issues...

## Acknowledgements
Since the module relies on other third-party library modules, the copyright information of each third-party library module may be different. Please refer to the copyright of the third-party library module.
1. [whisper.cpp](https://github.com/ggerganov/whisper.cpp)