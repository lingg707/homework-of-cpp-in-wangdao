CC := g++
CPPFLAGS:= -g -Wall 
#LIBS这个不能写错，写错一个字母都不行,倒是空格可以随便加，应该是类似于命令行的用法
LIBS  := -lpthread
#下面的地址一定要写，要不然会报错,但是好像是填什么都可以。。。
#只要填一个东西就可以了，应该是这个表达式需要一个形参
#SRCS的命名好像是可以随便修改的，我现在改了也没事
SRCS:=$(wildcard *.cc) 
#%是通配符，表示所有的,OBJS是.o文件，只是.cc文件的重新命名，生成.o文件的代码在16行
OBJS := $(patsubst %.cc,%.o,$(SRCS))
#下面的代码是用来查看生成的文件是什么的
#test:
#	echo $(SRCS)
#	echo $(OBJS)
#	echo $(TARGET)
#依赖项是SR，把所有的cc文件转化为o文件
TARGET := oothreadpool.exe
$(TARGET):$(OBJS)
	$(CC) $^ -o $@ $(CPPFLAGS)$(LIBS)
#上面的-o后面跟着生成文件.所依赖文件的$^的位置好像可以随便换
%.o:%.cc
	$(CC) -c $< -o $@ $(CPPFLAGS)$(LIBS)
#-c生成目标文件.o
clean:
	rm -rf $(TARGET) $(OBJS)

