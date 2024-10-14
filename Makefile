# 使用的编译器
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I. # 使用 C++11 标准并显示所有警告
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system  # SFML 库链接选项

# 源文件列表
SOURCES = main.cpp Enemy.cpp EasyEnemy.cpp MediumEnemy.cpp HardEnemy.cpp Projectile.cpp Object.cpp
OBJECTS = $(SOURCES:.cpp=.o)  # 将 .cpp 文件编译为 .o 文件

# 测试文件
TEST_SOURCES = test.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
TEST_EXECUTABLE = test_program

# 生成的可执行文件
EXECUTABLE = game

# 默认目标：编译主程序
all: $(EXECUTABLE)

# 生成主程序
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

# 编译并运行测试程序
test: $(TEST_OBJECTS) $(OBJECTS)
	$(CXX) $(TEST_OBJECTS) $(OBJECTS) -o $(TEST_EXECUTABLE) $(LDFLAGS)
	./$(TEST_EXECUTABLE)  # 运行测试程序

# 运行主程序
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# 编译所有源文件为对象文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理编译生成的文件
clean:
	rm -f $(EXECUTABLE) $(TEST_EXECUTABLE) *.o