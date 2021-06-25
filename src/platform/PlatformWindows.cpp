#include "PlatformWindows.h"
#include <iostream>
#include <fstream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

std::string WindowsResLoader::buildFilePath(std::string path){
    return ASSETS_DIR + path;
}

unsigned char* WindowsResLoader::loadAssetsFile(std::string path , long &filesize){
    return nullptr;
}

unsigned char* WindowsResLoader::loadAssetsImage(std::string path, 
                            int &imageWidth , 
                            int &imageHeight , 
                            int &channels){
    std::string absolutePath = buildFilePath(path);
    unsigned char *imageData = nullptr;
    imageData = stbi_load(absolutePath.c_str() , &imageWidth , &imageHeight , &channels , 0);
    return imageData;
}

std::string WindowsResLoader::loadAssetsText(std::string path){
    std::string absolutePath = buildFilePath(path);
    std::string content;
	std::ifstream infile(absolutePath);
	if(infile.is_open()){
		std::string line;
		while(std::getline(infile , line)){
			line += "\n";
			content += line;
		}//end while
	}else{
		std::cout << "open file : " << path << " error "<<std::endl;
	}
	infile.close();
    return content;
}

int WindowsInput::getKeyState(int key){
    return glfwGetKey(window , key);
}

