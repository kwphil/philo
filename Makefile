CC := gcc

SRCDIRS := srcc srcp cmplr
OBJDIR := obj
BINDIR := bin

CFLAGS := -Wall -Wextra $(foreach dir,$(SRCDIRS), -I$(dir))
LDFLAGS := -lm

SOURCES := $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
OBJ := $(patsyubset %.c, $(OBJDIR)/%.o, %(notdir $(SOURCES)))
TARGET := build.elf

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
    @mkdir -p $(@D)
    $(CC) -o $@ $^ $(LDFLAGS)

$OBJDIR/%.o: $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
    @mkdir -p $(@D)
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -rf $(OBJDIR) $(BINDIR)

install:
    chmod +x script.sh
    make