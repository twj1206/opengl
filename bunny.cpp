/*
 * @Author: twj
 * @Date: 2023-02-24 至 2023-02-25
 * @question：glBegin(GL_POINTS)用别参数不行  总是多出一条斜线 已经解决 是因为写出参数Vertex[index1][1]
 *            网格和实体的关系
 */
//这是兔子bunny模型实验
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

//读取文件
void readOff(string filepath) {
    ifstream fin(filepath);
    if (!fin.is_open()) {
        cout << "文件" << filepath << "打开失败" << endl;
    }
    string line;
    int vertexNum, faceNum, edgeNum;     //顶点的个数 面的个数  边的个数
    fin >> line;                         //读入OFF字符串，无用，不处理
    fin >> vertexNum >> faceNum >> edgeNum;//顶点数 面数 边数
    for (int i = 0; i < vertexNum; i++) {   //读取顶点的位置
        float x, y, z;
        fin >> x >> y >> z; //读入
        Vertex[i][0] = x;
        Vertex[i][1] = y;
        Vertex[i][2] = z;
    }
    for (int i = 0; i < faceNum; i++) {
        int n, index1, index2, index3;//面的顶点个数 顶点1的索引号 顶点2的索引号 顶点3的索引号
        fin >> n >> index1 >> index2 >> index3;
        Face[i][0] = index1;
        Face[i][1] = index2;
        Face[i][2] = index3;
    }
    fin.close();
}
//初始化
void init() {
    //调用readOff 读取off模型并生成顶点
    readOff("bunny.off");
    glEnable(GL_DEPTH_TEST);//用来开启更新深度缓冲区的功能 
}

void display() {
    // 示要清除颜色缓冲以及深度缓冲
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glColor3f(1.0f, .0f, .0f);

    for (int i = 0; i <9999; i++) {
        glBegin(GL_LINE_LOOP);
        int index1 = Face[i][0];
        int index2 = Face[i][1];
        int index3 = Face[i][2];
        //调整大小
        glVertex3f(Vertex[index1][0]/15, Vertex[index1][1]/15 -0.5, Vertex[index1][2]/15 -0.3);
        glVertex3f(Vertex[index2][0]/15, Vertex[index2][1]/15 -0.5, Vertex[index2][2]/15 -0.3);
        glVertex3f(Vertex[index3][0]/15, Vertex[index3][1]/15 -0.5, Vertex[index3][2]/15-0.3);
        glEnd();
        glFlush();  
    }
    //glutSwapBuffers();//交换缓冲区
}

int main(int argc,char *argv[]) {
    glutInit(&argc, argv);// glut初始化
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("bunny");
    init();
    glutDisplayFunc(display);   // 设置显示回调函数 -- 每帧执行
    glutMainLoop(); // 进入主循环
    return 0;
}


/*
* 
* //vector<glm::vec3> face;//丢掉数字3 找到每个三角形的3个顶点的索引号对于的xyz坐标
//vector<glm::vec3> Vertex;
//读取索引号到3维数组
        /*face.push_back(Vertex[index1]);
        face.push_back(Vertex[index2]);
        face.push_back(Vertex[index3]);*/

/*
* 
* //Vertex.push_back(glm::vec3(x, y, z));
//打印 输出 即x,y,z坐标
    for (int i = 0; i < 5; i++) {
       glm::vec3 p = Vertex[i];
        cout << "p[0]="<<p[0]<< " p[1]=" << p[1]<< " p[2]=" << p[2] << endl;
   }

*/

/*
glm库，看成一个矩阵，x y z
*/
/*
    void glDrawArrays(GLenum mode, GLint first, GLsizei count);
    first
    从数组缓存中的哪一位开始绘制，一般为0.
    count
    数组中顶点的数量.
*/
/*
**glFlush()和glutSwapBuffers()**都是用于将渲染结果显示到屏幕上的函数。

glFlush()是OpenGL内置函数，它的作用是强制执行缓冲区中的所有指令。
它会立即执行缓冲区中的所有指令，但是它不会交换前后缓存。
因此，如果使用glFlush()来更新屏幕，那么绘制的图形可能会有闪烁，因为它不会做到双缓存。

glutSwapBuffers()是FreeGLUT库中的函数，它的作用是交换前后缓存。
它会在后台缓冲区中绘制图形，当调用glutSwapBuffers()时，
会将后台缓冲区中的图形拷贝到前台缓冲区中，并显示在屏幕上。这样做可以避免闪烁的问题，因为图形在后台缓冲区中被绘制完成之后再显示。

*/
