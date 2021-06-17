CC := g++

SRC_DIR := ../src
BUILD_DIR := build
STD := c++11
OUTPUT := output 
INCLUDE_DIR := ../src/include

build_dir:
	mkdir -p ${BUILD_DIR}

compile: build_dir \
		${BUILD_DIR}/glad.o \
		${BUILD_DIR}/WinApp.o \
		${BUILD_DIR}/Shader.o \
		${BUILD_DIR}/Camera.o \
		${BUILD_DIR}/Shape.o \
		${BUILD_DIR}/TriangleApp.o \
		${BUILD_DIR}/CubeApp.o \
		${BUILD_DIR}/PlatformWindows.o \
		${BUILD_DIR}/App.o \ 


${BUILD_DIR}/glad.o:glad.cpp
	${CC} -std=${STD} -c glad.cpp -o ${BUILD_DIR}/glad.o -Iinclude

${BUILD_DIR}/WinApp.o:${SRC_DIR}/platform/WinApp.cpp
	${CC} -std=${STD} -c ${SRC_DIR}/platform/WinApp.cpp -o ${BUILD_DIR}/WinApp.o -Iinclude -I${INCLUDE_DIR}

${BUILD_DIR}/Shader.o:${SRC_DIR}/core/Shader.cpp
	${CC} -std=${STD} -c ${SRC_DIR}/core/Shader.cpp -o ${BUILD_DIR}/Shader.o -Iinclude -I${INCLUDE_DIR}

${BUILD_DIR}/Camera.o:${SRC_DIR}/core/Camera.cpp
	${CC} -std=${STD} -c ${SRC_DIR}/core/Camera.cpp -o ${BUILD_DIR}/Camera.o -Iinclude -I${INCLUDE_DIR}

${BUILD_DIR}/PlatformWindows.o:${SRC_DIR}/platform/PlatformWindows.cpp
	${CC} -std=${STD} -c ${SRC_DIR}/platform/PlatformWindows.cpp -o ${BUILD_DIR}/PlatformWindows.o -Iinclude -I${INCLUDE_DIR}

${BUILD_DIR}/App.o:${SRC_DIR}/core/App.cpp
	${CC} -std=${STD} -c ${SRC_DIR}/core/App.cpp -o ${BUILD_DIR}/App.o -Iinclude -I${INCLUDE_DIR}

${BUILD_DIR}/Shape.o:${SRC_DIR}/core/Shape.cpp
	${CC} -std=${STD} -c ${SRC_DIR}/core/Shape.cpp -o ${BUILD_DIR}/Shape.o -Iinclude -I${INCLUDE_DIR}

${BUILD_DIR}/TriangleApp.o:${SRC_DIR}/example/TriangleApp.cpp
	${CC} -std=${STD} -c ${SRC_DIR}/example/TriangleApp.cpp -o ${BUILD_DIR}/TriangleApp.o -Iinclude -I${INCLUDE_DIR}

${BUILD_DIR}/CubeApp.o:${SRC_DIR}/example/CubeApp.cpp
	${CC} -std=${STD} -c ${SRC_DIR}/example/CubeApp.cpp -o ${BUILD_DIR}/CubeApp.o -Iinclude -I${INCLUDE_DIR}

link:compile
	${CC} ${BUILD_DIR}/*.o -o ${BUILD_DIR}/app.exe -Llib -lglfw3dll -lopengl32 
	
run:link
	${BUILD_DIR}/app

assemble:link
	mkdir -p ${BUILD_DIR}/${OUTPUT}
	cp -r assets ${BUILD_DIR}/${OUTPUT}
	cp -r shader ${BUILD_DIR}/${OUTPUT}
	cp -r ${BUILD_DIR}/main.exe ${BUILD_DIR}/${OUTPUT}
	cp -r glfw3.dll ${BUILD_DIR}/${OUTPUT}

clean:
	rm -f ${BUILD_DIR}/*.o 
	rm -f ${BUILD_DIR}/app.exe
	rm -rf ${BUILD_DIR}/${OUTPUT}