CC = g++

CPPFLAG = -Wall -g -w -fPIC -DWITH_NONAMESPACES -fno-use-cxa-atexit -fexceptions -DWITH_DOM \
          -DWITH_OPENSSL -std=c++0x -static-libstdc++

INCLUDE += -I./deps/

LIB= -lssl -lcrypto -lcurl

PROXYSOURCE = deps

ProxyOBJ = $(PROXYSOURCE)/soapDeviceBindingProxy.o $(PROXYSOURCE)/soapMediaBindingProxy.o \
           $(PROXYSOURCE)/soapPTZBindingProxy.o \
           $(PROXYSOURCE)/soapPullPointSubscriptionBindingProxy.o \
           $(PROXYSOURCE)/soapRemoteDiscoveryBindingProxy.o

PluginSOURCE = plugin

PluginOBJ = $(PluginSOURCE)/wsaapi.o $(PluginSOURCE)/wsseapi.o $(PluginSOURCE)/threads.o \
            $(PluginSOURCE)/duration.o $(PluginSOURCE)/smdevp.o $(PluginSOURCE)/mecevp.o \
            $(PluginSOURCE)/dom.o

SRC = ./deps/stdsoap2.o ./deps/soapC.o ./deps/soapClient.o ./Media.o ./Snapshot.o ./main.o \
      $(PluginOBJ) $(ProxyOBJ)

OBJECTS = $(patsubst %.cpp,%.o,$(SRC))

TARGET = ipconvif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo link $(TARGET)
	@$(CC) $(CPPFLAG) $(OBJECTS) $(INCLUDE) $(LIB) -o $(TARGET)

$(OBJECTS):%.o: %.cpp
	@echo cc $<
	@$(CC) -c $(CPPFLAG) $(INCLUDE) $< -o $@

clean:
	rm -rf  $(OBJECTS)

