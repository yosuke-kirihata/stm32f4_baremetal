@
@   Startup script
@

@ Text Section
.text
	.align 2 @セクションの4バイト境界
	.code 16 @thumb命令の使用宣言
	.syntax unified @統合アセンブラ構文の使用宣言
	.global _startup @外部公開(他のオブジェクトファイルから使用可能)
	.type _startup, function @明示しなくても関数として認識されるらしい情報あり

_startup:

	cpsid f @ Disable FIQ intr

	bl startup
