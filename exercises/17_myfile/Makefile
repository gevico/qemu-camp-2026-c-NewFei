CC = gcc
CFLAGS = -Wall -g -O2 -fPIE

TARGET := 17_myfile
SRCS := 17_myfile.c
OBJS := $(SRCS:.c=.o)

all: $(TARGET) 17_myfile.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

17_myfile.o: 17_myfile.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean