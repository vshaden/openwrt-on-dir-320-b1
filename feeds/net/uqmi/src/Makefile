#CROSS=mipsel-uclibc-
CC ?= $(CROSS)gcc
LD ?= $(CROSS)ld

CFLAGS  := --std=gnu99 -g -Os -I. $(EXTRACFLAGS)
#CFLAGS  += -Wall -Werror -Wmissing-declarations
CFLAGS  += -ffunction-sections -fdata-sections
#CFLAGS += -DDEBUG_PACKET -DDEBUG -g3
LDFLAGS += -Wl,--gc-sections -Llibuboxm -Wl,-Bstatic -luboxm -Wl,-Bdynamic

TARGET = uqmi
SOURCES = main.c dev.c commands.c qmi-message.c 

service_sources = $(foreach service,ctl dms nas pds wds wms,qmi-message-$(service).c)
service_headers = $(service_sources:.c=.h)

SOURCES += $(service_sources)
OBJS=$(SOURCES:.c=.o)


PREFIX=/usr

default_target: all
.PHONY : default_target

install: all
	$(INSTALL) -D $(TARGET) $(INSTALLDIR)/$(PREFIX)/sbin/$(TARGET)
.PHONY : install

clean:
	@rm -f $(OBJS) $(TARGET) $(service_sources) $(service_headers) qmi-errors.c
.PHONY : clean

# The main all target
all: $(TARGET)
.PHONY : all

qmi-message-%.o: CFLAGS += -Wno-unused

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

.c.o::
	$(CC) $(CFLAGS) -c $<

# Dependencies
main.o: main.c uqmi.h commands.h
dev.o: dev.c qmi-errors.c qmi-errors.h uqmi.h $(service_headers)
commands.o: commands.c uqmi.h commands.h $(service_sources) $(service_headers)
qmi-message.o: qmi-message.c qmi-message.h $(service_headers)
