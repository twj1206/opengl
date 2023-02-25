/*
 * @Author: twj
 * @Date: 2023-02-24 �� 2023-02-25
 * @question��glBegin(GL_POINTS)�ñ��������  ���Ƕ��һ��б�� �Ѿ���� ����Ϊд������Vertex[index1][1]
 *            �����ʵ��Ĺ�ϵ
 */
//��������bunnyģ��ʵ��
#include<glut.h>
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<fstream>
#include<string>
#include<vector>
#include<glm/glm.hpp>
using namespace std;

float Vertex[5051][3];
int Face[9999][3];

//��ȡ�ļ�
void readOff(string filepath) {
    ifstream fin(filepath);
    if (!fin.is_open()) {
        cout << "�ļ�" << filepath << "��ʧ��" << endl;
    }
    string line;
    int vertexNum, faceNum, edgeNum;     //����ĸ��� ��ĸ���  �ߵĸ���
    fin >> line;                         //����OFF�ַ��������ã�������
    fin >> vertexNum >> faceNum >> edgeNum;//������ ���� ����
    for (int i = 0; i < vertexNum; i++) {   //��ȡ�����λ��
        float x, y, z;
        fin >> x >> y >> z; //����
        Vertex[i][0] = x;
        Vertex[i][1] = y;
        Vertex[i][2] = z;
    }
    for (int i = 0; i < faceNum; i++) {
        int n, index1, index2, index3;//��Ķ������ ����1�������� ����2�������� ����3��������
        fin >> n >> index1 >> index2 >> index3;
        Face[i][0] = index1;
        Face[i][1] = index2;
        Face[i][2] = index3;
    }
    fin.close();
}
//��ʼ��
void init() {
    //����readOff ��ȡoffģ�Ͳ����ɶ���
    readOff("bunny.off");
    glEnable(GL_DEPTH_TEST);//��������������Ȼ������Ĺ��� 
}

void display() {
    // ʾҪ�����ɫ�����Լ���Ȼ���
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glColor3f(1.0f, .0f, .0f);

    for (int i = 0; i <9999; i++) {
        glBegin(GL_LINE_LOOP);
        int index1 = Face[i][0];
        int index2 = Face[i][1];
        int index3 = Face[i][2];
        //������С
        glVertex3f(Vertex[index1][0]/15, Vertex[index1][1]/15 -0.5, Vertex[index1][2]/15 -0.3);
        glVertex3f(Vertex[index2][0]/15, Vertex[index2][1]/15 -0.5, Vertex[index2][2]/15 -0.3);
        glVertex3f(Vertex[index3][0]/15, Vertex[index3][1]/15 -0.5, Vertex[index3][2]/15-0.3);
        glEnd();
        glFlush();  
    }
    //glutSwapBuffers();//����������
}

int main(int argc,char *argv[]) {
    glutInit(&argc, argv);// glut��ʼ��
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("bunny");
    init();
    glutDisplayFunc(display);   // ������ʾ�ص����� -- ÿִ֡��
    glutMainLoop(); // ������ѭ��
    return 0;
}


/*
* 
* //vector<glm::vec3> face;//��������3 �ҵ�ÿ�������ε�3������������Ŷ��ڵ�xyz����
//vector<glm::vec3> Vertex;
//��ȡ�����ŵ�3ά����
        /*face.push_back(Vertex[index1]);
        face.push_back(Vertex[index2]);
        face.push_back(Vertex[index3]);*/

/*
* 
* //Vertex.push_back(glm::vec3(x, y, z));
//��ӡ ��� ��x,y,z����
    for (int i = 0; i < 5; i++) {
       glm::vec3 p = Vertex[i];
        cout << "p[0]="<<p[0]<< " p[1]=" << p[1]<< " p[2]=" << p[2] << endl;
   }

*/

/*
glm�⣬����һ������x y z
*/
/*
    void glDrawArrays(GLenum mode, GLint first, GLsizei count);
    first
    �����黺���е���һλ��ʼ���ƣ�һ��Ϊ0.
    count
    �����ж��������.
*/
/*
**glFlush()��glutSwapBuffers()**�������ڽ���Ⱦ�����ʾ����Ļ�ϵĺ�����

glFlush()��OpenGL���ú���������������ǿ��ִ�л������е�����ָ�
��������ִ�л������е�����ָ����������ύ��ǰ�󻺴档
��ˣ����ʹ��glFlush()��������Ļ����ô���Ƶ�ͼ�ο��ܻ�����˸����Ϊ����������˫���档

glutSwapBuffers()��FreeGLUT���еĺ��������������ǽ���ǰ�󻺴档
�����ں�̨�������л���ͼ�Σ�������glutSwapBuffers()ʱ��
�Ὣ��̨�������е�ͼ�ο�����ǰ̨�������У�����ʾ����Ļ�ϡ����������Ա�����˸�����⣬��Ϊͼ���ں�̨�������б��������֮������ʾ��

*/
