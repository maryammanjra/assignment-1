CC = gcc
CFLAGS = -Wall -Wextra -g
SRC_DIR = src
BUILD_DIR = build
INPUT_DIR = input
EXPECTED_DIR = expected
OUTPUT_DIR = $(BUILD_DIR)/outputs

PROGS = polling interrupts multiprogrammed
INPUTS = $(wildcard $(INPUT_DIR)/*.txt)

# Executables are built into build/
all: $(PROGS:%=$(BUILD_DIR)/%)

$(BUILD_DIR)/polling: $(SRC_DIR)/polling.c $(BUILD_DIR)/helper_functions.o
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/interrupts: $(SRC_DIR)/interrupts.c $(BUILD_DIR)/helper_functions.o
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/multiprogrammed: $(SRC_DIR)/multiprogrammed.c $(BUILD_DIR)/helper_functions.o
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/helper_functions.o: $(SRC_DIR)/helper_functions.c $(SRC_DIR)/data_structures.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*

# Test harness: run each scheduler against each input and diff results
test: all
	@mkdir -p $(OUTPUT_DIR)
	@for prog in $(PROGS); do \
	    for f in $(INPUTS); do \
	        base=$$(basename $$f); \
	        echo "Running $$prog on $$base"; \
	        $(BUILD_DIR)/$$prog $$f > $(OUTPUT_DIR)/$$prog\_$$base; \
	        if diff -q $(OUTPUT_DIR)/$$prog\_$$base $(EXPECTED_DIR)/$$prog\_$$base >/dev/null; then \
	            echo "  [PASS]"; \
	        else \
	            echo "  [FAIL] (see $(OUTPUT_DIR)/$$prog\_$$base)"; \
	        fi \
	    done \
	done

# Update expected outputs with current program outputs
update-expected: all
	@mkdir -p $(EXPECTED_DIR)
	@for prog in $(PROGS); do \
	    for f in $(INPUTS); do \
	        base=$$(basename $$f); \
	        echo "Updating expected output for $$prog on $$base"; \
	        $(BUILD_DIR)/$$prog $$f > $(EXPECTED_DIR)/$$prog\_$$base; \
	    done \
	done
