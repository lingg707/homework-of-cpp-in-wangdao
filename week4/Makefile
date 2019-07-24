CC := g++
CPPFLAGS := -std=c++11 -g 
LIBS := -lpthread
#下面的地址一定要写，要不然会报错,但是好像是填什么都可以。。。
#只要填一个东西就可以了，应该是这个表达式需要一个形参
INC_FILE := $(addprefix -I,)
CPP_FILE :=  $(wildcard *.cc) 
#%是通配符，表示所有的
OBJS := $(patsubst %.cc,%.o,$(CPP_FILE))#依赖项是CPP_FILE，把所有的cc文件转化为o文件
TARGET := threadpool.exe
$(TARGET):$(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^ $(INC_FILE) $(LIBS)
%.o:%.cc
	$(CC) $(CPPFLAGS) -o $@ -c $< $(INC_FILE) $(LIBS)
object:
	@echo $(objs)
clean:
	rm -rf $(TARGET) $(OBJS)

