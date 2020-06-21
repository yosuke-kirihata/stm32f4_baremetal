TCPREFIX	= arm-none-eabi-

CC			= $(TCPREFIX)gcc
OBJCOPY		= $(TCPREFIX)objcopy
SIZE		= $(TCPREFIX)size
OBJDUMP		= $(TCPREFIX)objdump
NM			= $(TCPREFIX)nm

CFLAGS		= -O0 -g -Wall -mthumb -mcpu=cortex-m4 --specs=nosys.specs#-Wl,--gc-sections
TARGET		= rom
SRCS		= $(wildcard *.c)
OBJS		= startup.o $(SRCS:.c=.o)
LSCRIPT		= linker.ld

.c.o:
	$(CC) $(CFLAGS) -c $*.c

.S.o:
	$(CC) $(CFLAGS) -c $*.S

$(TARGET).bin:$(TARGET).elf
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin

$(TARGET).elf:$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -T $(LSCRIPT) -o $(TARGET).elf
	$(SIZE) $(TARGET).elf

.PHONY:clean
.PHONY:disasm
.PHONY:nm

clean:
	@rm $(OBJS) $(TARGET).elf $(TARGET).bin

disasm:$(TARGET).elf
	$(OBJDUMP) -SDl $(TARGET).elf

nm:$(TARGET).elf
	$(NM) $(TARGET).elf
