/*
	Poject:branley
	@Author:Tong
	Time:2023/2/21
	对于概率的运用没有使用正确，两个0.07的考虑
	2/22
	修正之前的问题：
		对于概率的运用 1-0.07=0.93
		四组计算出Barnsley的点后到窗口点的映射问题==>转化问题？未学
*/
//这是Barnsley叶实验
#include<iostream>
#include<random>
#include<cstdlib>
#include<glut.h>
using namespace std;

void Barnsley() {
	GLfloat nextx, nexty;
	glClear(GL_COLOR_BUFFER_BIT);//示要清除颜色缓冲以及深度缓冲
	glColor3f(0.4f, 0.8f, 0.4f);
	glBegin(GL_POINTS);
	GLfloat x = 0, y = 0;
	srand((unsigned)time(0));//为了程序每次运行返回不同的随机数，种子最好每次不一样

	for (int i = 0; i < 40000; i++) {
	//利用 rand_max 产生随机小数：double x = （double)(rand()) / rand_max;
	//[a,b]—rand()1.0/RAND_MAX(b-a)+a
	//p 为概率
		//int p = (int)100 * rand() /(RAND_MAX+1);//[1,100]
		double p = (double)rand() / RAND_MAX;
		if (p < 0.1) {	//1%change
			nextx = 0;
			nexty = 0.16 * y;
		}
		else if (p < 0.85) {// 85% chance
			nextx = 0.85 * x + 0.04 * y;
			nexty = -0.04 * x + 0.85 * y + 1.6;
		}
		else if (p < 0.93)//7%change
		{
			nextx = 0.2 * x - 0.26 * y;
			nexty = 0.23 * x + 0.22 * y + 1.6;
		}
		else //7%change
		{
			nextx = -0.15 * x + 0.28 * y;
			nexty = 0.26 * x + 0.24 * y + 0.44;
		}
		x = nextx;
		y = nexty;

		glVertex2f(nextx/10,nexty/10-0.3);//调整Barnskey对应窗口坐标  比例
		glFlush();
	}
	glEnd();
	glFlush();
}
int main(int argc,char* argv[]) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Barnsley");
	glutDisplayFunc(&Barnsley);
	glutMainLoop();
	return 0;
}

//static_cast
/*
1.编写出四组公式
2.根据概率p进行分类
3.循环描点 在glBegin()和glEnd()之间进行绘画
*/
/*
花2个点
glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.5f, 0.0f);
	glEnd();
	glFlush();
*/
/*
/*
glutPostRedisplay
glutPostRedisplay 标记当前窗口需要重新绘制。通过glutMainLoop下一次循环时，窗口显示将被回调以重新显示窗口的正常面板。
多次调用glutPostRedisplay，在下一个显示回调只产生单一的重新显示回调。
有了glutPostRedisplay函数，和mainloop，则会反复调用glutDisplayFunc(display);
*/
