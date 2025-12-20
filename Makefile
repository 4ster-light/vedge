CC       := clang
CFLAGS   := -Wall -Wextra -std=c17 -O2
LDFLAGS  :=

SRC_DIR  := src
DIST_DIR := dist

SRCS     := $(SRC_DIR)/main.c $(SRC_DIR)/image.c $(SRC_DIR)/filters.c $(SRC_DIR)/cli.c
OBJS     := $(patsubst $(SRC_DIR)/%.c, $(DIST_DIR)/%.o, $(SRCS))
TARGET   := $(DIST_DIR)/vedge

# Build target (display result)
all: $(TARGET)
	@echo "✓ Build complete: $(TARGET)"

clean:
	@rm -rf $(DIST_DIR)
	@echo "✓ Cleaned build artifacts and output"

run: all
	@echo "✓ Running edge detector..."
	@echo ""
	@./$(TARGET)

help:
	@echo "Available targets:"
	@echo "  make all     - Build the edge detector (default)"
	@echo "  make run     - Build and run the edge detector"
	@echo "  make clean   - Remove build artifacts"
	@echo "  make help    - Show this help message"

.PHONY: all clean run help

# Create output directory
$(DIST_DIR):
	@mkdir -p $@

# Compile source files into object files
$(DIST_DIR)/%.o: $(SRC_DIR)/%.c | $(DIST_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(TARGET): $(OBJS) | $(DIST_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)
