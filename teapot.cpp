//这是茶壶实验

#include<glut.h>
void init(void) {

	//一、启动深度测试，位场景添加一个光源
	//glEnable(GL_LIGHTING);表示启动光照的总开关 
	//glEnable(GL_LIGHT0);//打开0号光源
	//glEnable(GL_DEPTH_TEST);//打开深度缓冲区，绘制3D图像时候使用

	glEnable(GL_DEPTH_TEST);//用来开启更新深度缓冲区的功能
	GLfloat position[] = { 1.0,1.0,1.0,1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, position);//创建光源
	glEnable(GL_LIGHTING);//表示启动光照的总开关
	glEnable(GL_LIGHT0);//打开0号光源

	//定义物体的材质属性
	GLfloat ambient[] = { 0.0,0.0,0.0,1.0 };
	GLfloat diffuse[] = { 0.5,0.5,0.5,1.0 };
	GLfloat specular[] = { 1.0,1.0,1.0,1.0 };
	//【指定材质】 glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse); GL_FRONT 正面
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);//材料对环境光的反射情况
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);//散射光的反射情况
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);//镜面光的反射情况
	glMaterialf(GL_FRONT, GL_SHININESS, 50.0); // 镜面光的聚焦情况
}
void display(void) {
	//示要清除颜色缓冲以及深度缓冲
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//创建显示列表
	glNewList(1, GL_COMPILE);//GL_COMPILE，则表示以下的内容只是装入到显示列表，但现在不执行它们；
	glutSolidTeapot(0.5);
	glEndList();
	//调用显示列表
	glCallList(1);
	glFlush();
	/*
	分配显示列表编号glGenLists();
	创建显示列表
	glNewList(装入的显示列表,GL_COMPILE);
	//GL_COMPILE，则表示以下的内容只是装入到显示列表，但现在不执行它们；
	//GL_COMPILE_AND_EXECUTE，表示在装入的同时，把装入的内容执行一遍。
	glEndList();

	调用显示列表
	glCallList();
	glCallLists();

	销毁显示列表
	glDeletelists();
	*/


}
void reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);//x，y 以像素为单位，指定了视口的左下角位 width，height 表示这个视口矩形的宽度和高度，根据窗口的实时变化重绘窗口
	glMatrixMode(GL_PROJECTION);//将当前矩阵指定为投影矩阵
	glLoadIdentity();//任何一个模型、视图变换，如translate、scale、lookAt等，计算后都会影响当前栈顶矩阵的值！若每次变换完毕后不去归位（glLoadIdentity）
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);//正射投影：glOrtho
	glMatrixMode(GL_MODELVIEW);//GL_MODELVIEW是对模型视景矩阵操作
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);//初始化
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);// 指定RGB颜色模式的窗口 创建及使用模板缓存 窗口使用深度缓存
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);//调整窗口大小
	glutDisplayFunc(display);//显示函数
	glutMainLoop();//循环
	return 0;
}

//一、启动深度测试，位场景添加一个光源
//glEnable(GL_LIGHTING);表示启动光照的总开关 
//glEnable(GL_LIGHT0);//打开0号光源
//glEnable(GL_DEPTH_TEST);//打开深度缓冲区，绘制3D图像时候使用

//二、定义物体的材质属性
//【指定材质】 glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
//glMatrixMode()函数的参数，这个函数其实就是对接下来要做什么进行一下声明，也就是在要做下一步之前告诉计算机我要对“什么”进行操作了，
//这个“什么”在glMa