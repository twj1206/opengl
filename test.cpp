#include<glut.h>
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<vector>
#include<glm/glm.hpp>
using namespace std;

float Vertex[5051][3];
int Face[9999][3];

void readOff(string filepath) {
    FILE* fp;
    if (!fp) {
        cout << "文件" << filepath << "打开失败" << endl;
    }
    
}
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);// glut初始化
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("bunny");
    init();
    glutDisplayFunc(display);// 设置显示回调函数 -- 每帧执行
    glutMainLoop(); // 进入主循环
    return 0;
}
