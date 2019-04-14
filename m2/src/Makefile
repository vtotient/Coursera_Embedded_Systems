#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# General flags for both platforms
GEN_FLAGS = \
	    -Wall \
	    -Werror \
	    -g \
	    -O0 \
	    -std=c99

TARGET = c1m2

ifeq ($(PLATFORM), MSP432)
	# Architectures Specific Flags
	LINKER_FILE = -T ../msp432p401r.lds 
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	EXTRA = -mthumb \
		-mfloat-abi=hard \
		-mfpu=fpv4-sp-d16

	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	CFLAGS = $(GEN_FLAGS) $(EXTRA) -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS)
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CPPFLAGS = -DMSP432 $(INCLUDES)

	# Architecture specific source codes
	SOURCE = \
		 main.c \
		 memory.c \
		 interrupts_msp432p401r_gcc.c \
		 startup_msp432p401r_gcc.c \
		 system_msp432p401r.c

else
	# Complier Flags and Defines
	CC = gcc
	CFLAGS = $(GEN_FLAGS)
	CPPFLAGS = -DHOST $(INCLUDES)
	LDFLAGS = -Wl,-Map=$(TARGET).map
endif

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
ASMS = $(SRCS:.c=.asm)
PREP = $(SRCS:.c=.i)

%o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

%asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

%i: %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: Build
build: $(DEPS)
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@

.PHONY: Clean
clean:
	rm -f $(OBJS) $(DEPS) $(ASMS) $(PREP) $(TARGET).out $(TARGET).map 
