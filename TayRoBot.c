#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

GLfloat spin = 0.0;
GLfloat spinBapTayX = 0.0;
GLfloat spinBapTayZ = 0.0;
GLfloat spinKhuyuTayY = 0.0;
GLfloat spinKhuyuTayZ = 0.0;
GLfloat spinCoTay = 0.0;
GLfloat spinBanTay = 0.0;
GLfloat spinNgonTay = 0.0;
GLfloat spinDotNgon = 0.0;
void tayTren() {
	glPushMatrix();
		glPushMatrix();		
			glColor3f(0.12, 0.56, 1.0);
			glScalef(1.0, 1.2 , 1.0);	
			glTranslatef(0.0, 2.0, 0.0);
			glutSolidSphere (0.8, 20, 15);
		glPopMatrix();
		glPushMatrix();			
			glColor3f(1.0, 0.85, 0.73);
			glTranslatef(0.0, 0.3, 0.0);
			glScalef(0.7, 1.4 , 1.0);	
			glutSolidSphere (1.0, 20, 15);
		glPopMatrix();
	glPopMatrix();	
}

void tayDuoi() {
		glPushMatrix();
			glColor3f(1.0, 0.85, 0.73);	
			glTranslatef(0.0, -2.8, 0.0);	
			glScalef(0.6, 2.0 , 1.0);				
			glutSolidSphere (1.0, 20, 15);
		glPopMatrix();	
}
void dotNgonTay() {
	glPushMatrix();
		glTranslatef(0.0, -0.5, 0.0);
		glTranslatef(0.0, +0.2, 0.0);
		glRotatef(spinDotNgon, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.2, 0.0);
		glScalef(1.0, 3.0, 1.0);
		glutSolidCube(0.2);
	glPopMatrix();
}
void ngonTay(GLfloat doLech) {
	glPushMatrix();
		glTranslatef(doLech, 0.0, 0.0);					
		glPushMatrix();										
			glScalef(1.0, 3.0, 1.0);
			glutSolidCube(0.2);
		glPopMatrix();				
		dotNgonTay();
	glPopMatrix();
}

void canhTayPhai() {
	glPushMatrix();
		glRotatef(spin, 1.0, 1.0, 1.0);
		glPushMatrix();
			glTranslatef(0.0, 3.0, 0.0);
			glRotatef(spinBapTayZ, 0.0, 0.0, 1.0);
			glRotatef(spinBapTayX, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -3.0, 0.0);
			tayTren();			
			glPushMatrix();				
				glTranslatef(0.0, -1.0, 0.0);
				glRotatef(spinKhuyuTayZ, 0.0, 0.0, 1.0);
				glTranslatef(0.0, 1.0, 0.0);
				glRotatef(spinKhuyuTayY, 0.0, 1.0, 0.0);
				tayDuoi();			
				glPushMatrix();	
					glTranslatef(0.0, -0.5, 0.0);
					glTranslatef(0.0, -4.3, 0.0);
					glRotatef(spinBanTay, 1.0, 0.0, 0.0);	
					glTranslatef(0.0, 4.3, 0.0);		
					glPushMatrix();
						glColor3f(0.12, 0.56, 1.0);
						glTranslatef(0.0, -4.8, 0.0);	
						glScalef(2.8, 2.8, 1.0);
						glutSolidSphere(0.2, 15, 15);
					glPopMatrix();		
					glTranslatef(0.0, -5.5, 0.0);	
					glTranslatef(0.0, 0.2, 0.0);
					glRotatef(spinNgonTay, 1.0, 0.0, 0.0);
					glTranslatef(0.0, -0.2, 0.0);	
					ngonTay(0.3);
					ngonTay(0.0);
					ngonTay(-0.3);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}
void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	canhTayPhai();
	glutSwapBuffers();
}
void reshape (int w, int h)
{	
	glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -20.0, 40.0);
	glMatrixMode(GL_MODELVIEW);
}
void keyboard (unsigned char key, int x, int y)
{	
	switch (key) {
		case 's': 			
			if (spinKhuyuTayZ > 0.0)
				spinKhuyuTayZ -= 2.0;											
			break;
		case 'q': 			
			if (spinNgonTay < 90.0)
				spinNgonTay += 2.0;		
			break;
		case 'e': 			
			if (spinNgonTay > 0)
				spinNgonTay -= 2.0;	
			break;
		case 'z': 			
			if (spinDotNgon < 90)
				spinDotNgon += 2.0;		
			break;
		case 'c': 			
			if (spinDotNgon > 0)
				spinDotNgon -= 2.0;	
			break;
		case 'x':
			spin += 5.0;
			break;			
		case 'w': 
			if (spinKhuyuTayZ < 120.0)			
				spinKhuyuTayZ += 2.0;		
			break;
		case '1': 
			if (spinBanTay < 90)			
				spinBanTay += 2.0;	
			break;
		case '2': 
			if (spinBanTay > -90)			
				spinBanTay -= 2.0;	
			break;
		case 'd': 
			if (spinKhuyuTayY > -180)			
				spinKhuyuTayY -= 2.0;
			break;
		case 'a': 
			if (spinKhuyuTayY < 180)			
				spinKhuyuTayY += 2.0;
			break;
		default:
			break;
	}
	glutPostRedisplay();
}
void specKey(int key, int x, int y) {
	switch(key) {
		case GLUT_KEY_RIGHT :
			if (spinBapTayX > - 180)	
				spinBapTayX -= 2.0;					
			break;
		case GLUT_KEY_LEFT:
			if (spinBapTayX < 0)	
				spinBapTayX += 2.0;	
			break;
		case GLUT_KEY_UP :
			if (spinBapTayZ - spinBapTayX < 180.0)	
				spinBapTayZ += 2.0;	
			break;
		case GLUT_KEY_DOWN :
			if (spinBapTayZ - spinBapTayX > -90.0)	
				spinBapTayZ -= 2.0;	
			break;
	}
	glutPostRedisplay();
}
void init(void) 
{	
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat mat_shininess[] = { 80.0 };
	glShadeModel (GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_specular);
   	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_specular);
   	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   	glEnable(GL_LIGHTING);
   	glEnable(GL_LIGHT0);
   	glEnable(GL_DEPTH_TEST);
   	glEnable(GL_COLOR_MATERIAL);
}

int main(int argc, char** argv)
{	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (800, 800); 
	glutInitWindowPosition (0, 0);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutSpecialFunc(specKey);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}



