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
        cout << "�ļ�" << filepath << "��ʧ��" << endl;
    }
    
}
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);// glut��ʼ��
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("bunny");
    init();
    glutDisplayFunc(display);// ������ʾ�ص����� -- ÿִ֡��
    glutMainLoop(); // ������ѭ��
    return 0;
}
