# Compiler settings
CXX = g++
VCPKG_ROOT = C:/vcpkg
CXXFLAGS = -std=c++17 -I"$(VCPKG_ROOT)/installed/x64-mingw-dynamic/include"
LDFLAGS = -L"$(VCPKG_ROOT)/installed/x64-mingw-dynamic/lib"
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lgdi32 -lwinmm

# Files
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
EXE = FlappyBird.exe

# Targets
all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@
	mv $(EXE) bin/

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del src\*.o
	del bin\$(EXE)

run:
	bin\$(EXE)