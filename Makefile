CC=gcc
CFLAGS=`xml2-config --cflags`
LIBS=`xml2-config --libs`

TARGET=readxml
SOURCE=readxml.c

all:
	$(CC) $(SOURCE) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)
