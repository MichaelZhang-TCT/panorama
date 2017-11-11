PROJECT_DIR = blenders
BUILD_DIR = _build

all:
	g++ -o $(BUILD_DIR)/blenders $(PROJECT_DIR)/blenders.cpp -I/usr/local/include/ -L/usr/local/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs 
