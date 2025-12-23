CC       := clang
CFLAGS   := -Wall -Wextra -std=c17 -O2
LDFLAGS  :=

SRC_DIR  := src
DIST_DIR := dist

SRCS     := $(wildcard $(SRC_DIR)/*.c)
OBJS     := $(patsubst $(SRC_DIR)/%.c, $(DIST_DIR)/%.o, $(SRCS))
TARGET   := $(DIST_DIR)/vedge

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(DIST_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(DIST_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(DIST_DIR)

run: all
	@$(TARGET)

help:
	@echo "Available targets:"
	@echo "  make all     - Build the edge detector (default)"
	@echo "  make run     - Build and run the edge detector"
	@echo "  make clean   - Remove build artifacts"
	@echo "  make help    - Show this help message"

.PHONY: all clean run help
