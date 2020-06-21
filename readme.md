# STM32 Baremetal

## 開発環境
* コンパイラ arm-none-eabi-gcc (GNU Tools for Arm Embedded Processors 9-2019-q4-major) 9.2.1
* デバッガ OpenOCD v0.10.0
* エディタ VSCode
* エディタプラグイン Cortex-Debug, C/C++

## 実行環境
* STMicro STM32F4

## 開発環境の構築
### Mac

動作確認済みOS macOS Catalina 10.15.5

1. xcodeのインストール
```sh
$ xcode-select --install
```
2. ARM GCCのインストール
```sh
$ brew tap ArmMbed/homebrew-formulae
$ brew install arm-none-eabi-gcc
$ arm-none-eabi-gcc --version
arm-none-eabi-gcc (GNU Tools for Arm Embedded Processors 9-2019-q4-major) 9.2.1 20191025 (release) [ARM/arm-9-branch revision 277599]
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

3. OpenOCDのインストール
```sh
$ brew install openocd
$ openocd --version
Open On-Chip Debugger 0.10.0
Licensed under GNU GPL v2
For bug reports, read
	http://openocd.org/doc/doxygen/bugs.html
```

4. VSCode,プラグインのインストール
