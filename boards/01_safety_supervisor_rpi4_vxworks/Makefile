APP_NAME := supervisor
BUILD_DIR := build
PROJECT_ROOT := ../..
GENERATED_DIR := $(PROJECT_ROOT)/v_model/05_mbd_state_machine/generated_c

CC ?= cc
RM ?= rm -f
MKDIR_P ?= mkdir -p

TARGET := $(BUILD_DIR)/$(APP_NAME).vxe

SRCS := \
	src/main.c \
	src/SupervisorApp.c \
	src/SupervisorMbd_Port.c \
	$(GENERATED_DIR)/FailoverSupervisor.c

CPPFLAGS += -Iinclude -I$(GENERATED_DIR)
CFLAGS ?= -rtp -static -std=c99 -Wall -Wextra -O2
LDFLAGS ?=
LDLIBS ?=

.PHONY: all clean print-env

all: $(TARGET)

$(TARGET): $(SRCS)
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(SRCS) $(LDLIBS) -o $@

print-env:
	@echo "CC=$(CC)"
	@echo "TARGET=$(TARGET)"
	@echo "GENERATED_DIR=$(GENERATED_DIR)"

clean:
	$(RM) -r $(BUILD_DIR)
