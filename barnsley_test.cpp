/*
	Poject:branley
	@Author:Tong
	Time:2023/2/21
	���ڸ��ʵ�����û��ʹ����ȷ������0.07�Ŀ���
	2/22
	����֮ǰ�����⣺
		���ڸ��ʵ����� 1-0.07=0.93
		��������Barnsley�ĵ�󵽴��ڵ��ӳ������==>ת�����⣿δѧ
*/
//����BarnsleyҶʵ��
#include<iostream>
#include<random>
#include<cstdlib>
#include<glut.h>
using namespace std;

void Barnsley() {
	GLfloat nextx, nexty;
	glClear(GL_COLOR_BUFFER_BIT);//ʾҪ�����ɫ�����Լ���Ȼ���
	glColor3f(0.4f, 0.8f, 0.4f);
	glBegin(GL_POINTS);
	GLfloat x = 0, y = 0;
	srand((unsigned)time(0));//Ϊ�˳���ÿ�����з��ز�ͬ����������������ÿ�β�һ��

	for (int i = 0; i < 40000; i++) {
	//���� rand_max �������С����double x = ��double)(rand()) / rand_max;
	//[a,b]��rand()1.0/RAND_MAX(b-a)+a
	//p Ϊ����
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

		glVertex2f(nextx/10,nexty/10-0.3);//����Barnskey��Ӧ��������  ����
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
1.��д�����鹫ʽ
2.���ݸ���p���з���
3.ѭ����� ��glBegin()��glEnd()֮����л滭
*/
/*
��2����
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
glutPostRedisplay ��ǵ�ǰ������Ҫ���»��ơ�ͨ��glutMainLoop��һ��ѭ��ʱ��������ʾ�����ص���������ʾ���ڵ�������塣
��ε���glutPostRedisplay������һ����ʾ�ص�ֻ������һ��������ʾ�ص���
����glutPostRedisplay��������mainloop����ᷴ������glutDisplayFunc(display);
*/
