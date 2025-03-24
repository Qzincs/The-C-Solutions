CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
BUILD_DIR = build

# 查找所有章节目录和源文件
CHAPTERS := $(wildcard ch*)
SOURCES := $(foreach ch,$(CHAPTERS),$(wildcard $(ch)/*.c))
EXECUTABLES := $(patsubst %.c,$(BUILD_DIR)/%,$(SOURCES))

.PHONY: all clean help $(CHAPTERS)

all: setup $(EXECUTABLES)

# 为每个章节创建build子目录
setup:
	@mkdir -p $(BUILD_DIR)
	@for ch in $(CHAPTERS); do \
		mkdir -p $(BUILD_DIR)/$$ch; \
	done

# 分章节编译的目标
$(CHAPTERS): setup
	@echo "编译 $@ 章节..."
	@mkdir -p $(BUILD_DIR)/$@
	$(foreach src,$(wildcard $@/*.c),$(CC) $(CFLAGS) $(src) -o $(BUILD_DIR)/$(src:.c=) && echo "Compiled: $(BUILD_DIR)/$(src:.c=)";)

# 编译规则
$(BUILD_DIR)/%: %.c
	$(CC) $(CFLAGS) $< -o $@
	@echo "Compiled: $@"

clean:
	rm -rf $(BUILD_DIR)

help:
	@echo "K&R C语言练习题解 Makefile"
	@echo ""
	@echo "使用说明:"
	@echo "  make	   - 编译所有章节的所有C文件"
	@echo "  make ch1   - 仅编译第1章的C文件"
	@echo "  make ch2   - 仅编译第2章的C文件"
	@echo "  make clean - 删除所有编译生成的文件"
	@echo "  make help  - 显示此帮助信息"
	@echo ""
	@echo "编译后的可执行文件将位于 $(BUILD_DIR) 目录下，保持与源文件相同的目录结构"
	@echo "例如: ch1/1-1.c 将编译为 $(BUILD_DIR)/ch1/1-1"