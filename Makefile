CC       := clang
CFLAGS   := -Wall -Wextra -std=c17 -O2
LDFLAGS  :=

SRC_DIR  := src
BIN_DIR  := dist

SRCS     := $(SRC_DIR)/main.c $(SRC_DIR)/image.c $(SRC_DIR)/filters.c
OBJS     := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRCS))
TARGET   := $(BIN_DIR)/edge_detector

.PHONY: all clean run help

# Create output directory
$(BIN_DIR):
	@mkdir -p $@

# Compile source files into object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

# Build target (display result)
all: $(TARGET)
	@echo "✓ Build complete: $(TARGET)"

clean:
	@rm -rf $(BIN_DIR)
	@rm -f output.ppm
	@echo "✓ Cleaned build artifacts"

run: all
	@echo "✓ Running edge detector..."
	@./$(TARGET)

help:
	@echo "Available targets:"
	@echo "  make all     - Build the edge detector (default)"
	@echo "  make run     - Build and run the edge detector"
	@echo "  make clean   - Remove build artifacts"
	@echo "  make help    - Show this help message"