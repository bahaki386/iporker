#-------------------------------------------------------
# BCC Developer 1.2.21
# Copyright (C) 2003 jun_miura@hi-ho.ne.jp
#-------------------------------------------------------
.autodepend
CC=bcc32
RC=brc32
CFLAG=-W  -3 -Od -w -AT -pc -H- -k -b -v -y  -DDEBUG
OUTDIR=-nDebug
CINCS=
TARGET=Debug\iporker.exe
SRC1=C:\Users\haruki-baba\iporker\exam.cpp
OBJ1=Debug\exam.obj
SRC2=C:\Users\haruki-baba\iporker\main.cpp
OBJ2=Debug\main.obj
SRC3=C:\Users\haruki-baba\iporker\GetCard.cpp
OBJ3=Debug\GetCard.obj

TARGET: $(TARGET)

$(TARGET): $(OBJ1) $(OBJ2) $(OBJ3)
    $(CC) $(CFLAG) -e$(TARGET) $(OBJ1) $(OBJ2) $(OBJ3)

$(OBJ1): $(SRC1)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC1)

$(OBJ2): $(SRC2)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC2)

$(OBJ3): $(SRC3)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC3)
