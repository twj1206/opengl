//���ǲ��ʵ��

#include<glut.h>
void init(void) {

	//һ��������Ȳ��ԣ�λ�������һ����Դ
	//glEnable(GL_LIGHTING);��ʾ�������յ��ܿ��� 
	//glEnable(GL_LIGHT0);//��0�Ź�Դ
	//glEnable(GL_DEPTH_TEST);//����Ȼ�����������3Dͼ��ʱ��ʹ��

	glEnable(GL_DEPTH_TEST);//��������������Ȼ������Ĺ���
	GLfloat position[] = { 1.0,1.0,1.0,1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, position);//������Դ
	glEnable(GL_LIGHTING);//��ʾ�������յ��ܿ���
	glEnable(GL_LIGHT0);//��0�Ź�Դ

	//��������Ĳ�������
	GLfloat ambient[] = { 0.0,0.0,0.0,1.0 };
	GLfloat diffuse[] = { 0.5,0.5,0.5,1.0 };
	GLfloat specular[] = { 1.0,1.0,1.0,1.0 };
	//��ָ�����ʡ� glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse); GL_FRONT ����
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);//���϶Ի�����ķ������
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);//ɢ���ķ������
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);//�����ķ������
	glMaterialf(GL_FRONT, GL_SHININESS, 50.0); // �����ľ۽����
}
void display(void) {
	//ʾҪ�����ɫ�����Լ���Ȼ���
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//������ʾ�б�
	glNewList(1, GL_COMPILE);//GL_COMPILE�����ʾ���µ�����ֻ��װ�뵽��ʾ�б������ڲ�ִ�����ǣ�
	glutSolidTeapot(0.5);
	glEndList();
	//������ʾ�б�
	glCallList(1);
	glFlush();
	/*
	������ʾ�б���glGenLists();
	������ʾ�б�
	glNewList(װ�����ʾ�б�,GL_COMPILE);
	//GL_COMPILE�����ʾ���µ�����ֻ��װ�뵽��ʾ�б������ڲ�ִ�����ǣ�
	//GL_COMPILE_AND_EXECUTE����ʾ��װ���ͬʱ����װ�������ִ��һ�顣
	glEndList();

	������ʾ�б�
	glCallList();
	glCallLists();

	������ʾ�б�
	glDeletelists();
	*/


}
void reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);//x��y ������Ϊ��λ��ָ�����ӿڵ����½�λ width��height ��ʾ����ӿھ��εĿ�Ⱥ͸߶ȣ����ݴ��ڵ�ʵʱ�仯�ػ洰��
	glMatrixMode(GL_PROJECTION);//����ǰ����ָ��ΪͶӰ����
	glLoadIdentity();//�κ�һ��ģ�͡���ͼ�任����translate��scale��lookAt�ȣ�����󶼻�Ӱ�쵱ǰջ�������ֵ����ÿ�α任��Ϻ�ȥ��λ��glLoadIdentity��
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);//����ͶӰ��glOrtho
	glMatrixMode(GL_MODELVIEW);//GL_MODELVIEW�Ƕ�ģ���Ӿ��������
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);//��ʼ��
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);// ָ��RGB��ɫģʽ�Ĵ��� ������ʹ��ģ�建�� ����ʹ����Ȼ���
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);//�������ڴ�С
	glutDisplayFunc(display);//��ʾ����
	glutMainLoop();//ѭ��
	return 0;
}

//һ��������Ȳ��ԣ�λ�������һ����Դ
//glEnable(GL_LIGHTING);��ʾ�������յ��ܿ��� 
//glEnable(GL_LIGHT0);//��0�Ź�Դ
//glEnable(GL_DEPTH_TEST);//����Ȼ�����������3Dͼ��ʱ��ʹ��

//������������Ĳ�������
//��ָ�����ʡ� glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
//glMatrixMode()�����Ĳ��������������ʵ���ǶԽ�����Ҫ��ʲô����һ��������Ҳ������Ҫ����һ��֮ǰ���߼������Ҫ�ԡ�ʲô�����в����ˣ�
//�����ʲô����glMa