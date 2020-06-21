MEMORY {
	ROM (rx) : ORIGIN = 0x08000000, LENGTH = 256K
	RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 30K
}

SECTIONS {
	.text :
	{
		KEEP(*(.vector)) /*KEEPは最適化による消去抑制*/
		*(.text)
	} > ROM /*MEMORYで定義したROM領域に配置*/

	.data :
	{
		__data_start__ = .;
		*(.data)
		__data_end__ = .;
	} > RAM AT > ROM /*リンクはRAMでロードはROM(アドレスはRAMでオブジェクト配置がROM領域)*/

	__idata_start__ = LOADADDR(.data); /*.dataのROM上での配置アドレスを返す*/
	_data_size = SIZEOF(.data);

	.bss :
	{
		__bss_start__ = .;
		*(.bss)
		__bss_end__ = .;
	} > RAM
	_bss_size = SIZEOF(.bss);

	_estack = 0x2000fffc;
}
