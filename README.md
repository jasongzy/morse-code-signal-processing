# 基于STC89C52 单片机的灯光摩尔斯码收发装置

利用 STC89C52 单片机建立一种简易的摩尔斯码光信号发送和解译半双工通信装置。

## 原理

采用光敏电阻接收光信号，利用 XPT2046 芯片采集光敏电阻的 AD 值，通过其阈值判断灯光的亮灭。经单片机处理后将翻译出的摩尔斯码在 LCD1602 液晶显示屏上输出。

## Android app

[MorseFlashlight](https://github.com/jasongzy/MorseFlashlight)

可在界面输入信息，应用会自动将其编码为摩尔斯码并调用手机闪光灯发出光信号。电码单位时长可调节，默认与单片机接收端匹配。


![国际摩尔斯电码](assets/国际摩尔斯电码.svg)

![Morse-code-tree](assets/Morse-code-tree.svg)