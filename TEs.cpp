@@ -1,496 +0,0 @@
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float angle=0.0, deltaAngle = 0.0, ratio;
float x=0.0f, y=5.0f, z=25.0f; // posisi awal kamera
float lx=0.0f, ly=0.0f, lz=-1.0f;
int deltaMove = 0,h,w;
int deltaZ = 0;
int bitmapHeight=12;

void Reshape(int w1, int h1){
	// Fungsi reshape
	if(h1 == 0) h1 = 1;
	w = w1;
	h = h1;
	ratio = 1.0f * w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45,ratio,0.1,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx,y + ly,z + lz, 0.0f,1.0f,0.0f);
}

void orientMe(float ang){
	// Fungsi ini untuk memutar arah kamera (tengok kiri/kanan)
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f,1.0f,0.0f);
}

void moveMeFlat(int i){
	// Fungsi ini untuk maju mundur kamera
	x = x + i*(lx)*0.05;
	z = z + i*(lz)*0.05;

	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f,1.0f,0.0f);
}

void moveVertical(int i){
//	x = x + i*(lx)*0.1;
	y = y + i*0.01;
//	z = z + i*(lz)*0.1;
	
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f,1.0f,0.0f);
}

void Grid() {
	// Fungsi untuk membuat grid di "lantai"
	double i;
	const float Z_MIN = -80, Z_MAX = 80;
	const float X_MIN = -80, X_MAX = 80;
	const float gap = 1.5;
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
	for(i=Z_MIN;i<Z_MAX;i+=gap){
		glVertex3f(i, 0, Z_MIN);
		glVertex3f(i, 0, Z_MAX);
	}
	for(i=X_MIN;i<X_MAX;i+=gap){
		glVertex3f(X_MIN, 0, i);
		glVertex3f(X_MAX, 0, i);
	}
	glEnd();
}

void Kapal(){
	//Kapal 1
	glPushMatrix();
		glTranslatef(0.0f,-1.0f,0.0f);
		// body
		// depan kanan
		glPushMatrix();
			glBegin(GL_TRIANGLE_STRIP);
			glColor3f(0.34f,0.17f,0.03f);
			glVertex3f(-2.0f,0.0f,0.0f);
			glVertex3f(-3.6f,3.0f,0.0f);
			glVertex3f(-1.9f,0.0f,2.0f);
			glVertex3f(-3.5f,3.0f,2.0f);
			glVertex3f(-1.7f,0.0f,4.0f);
			glVertex3f(-3.3f,3.0f,4.0f);
			glVertex3f(-1.4f,0.0f,6.0f);
			glVertex3f(-3.0f,3.5f,6.0f);
			glVertex3f(0.0f,0.0f,8.0f);
			glVertex3f(0.0f,3.8f,12.0f);
			glEnd();
		glPopMatrix();
		// depan kiri
		glPushMatrix();
			glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(2.0f,0.0f,0.0f);
			glVertex3f(3.6f,3.0f,0.0f);
			glVertex3f(1.9f,0.0f,2.0f);
			glVertex3f(3.5f,3.0f,2.0f);
			glVertex3f(1.7f,0.0f,4.0f);
			glVertex3f(3.3f,3.0f,4.0f);
			glVertex3f(1.4f,0.0f,6.0f);
			glVertex3f(3.0f,3.5f,6.0f);
			glVertex3f(0.0f,0.0f,8.0f);
			glVertex3f(0.0f,3.8f,12.0f);
			glEnd();
		glPopMatrix();
		// belakang kanan
		glPushMatrix();
			glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(-2.0f,0.0f,0.0f);
			glVertex3f(-3.6f,3.0f,0.0f);
			glVertex3f(-1.9f,0.0f,-2.0f);
			glVertex3f(-3.5f,3.0f,-2.0f);
			glVertex3f(-1.7f,0.0f,-4.0f);
			glVertex3f(-3.3f,3.0f,-4.0f);
			glVertex3f(-1.4f,0.0f,-6.0f);
			glVertex3f(-3.0f,3.9f,-6.0f);
			glVertex3f(0.0f,0.0f,-8.0f);
			glVertex3f(0.0f,4.0f,-10.0f);
			glEnd();
		glPopMatrix();
		//belakang kiri
		glPushMatrix();
			glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(2.0f,0.0f,0.0f);
			glVertex3f(3.6f,3.0f,0.0f);
			glVertex3f(1.9f,0.0f,-2.0f);
			glVertex3f(3.5f,3.0f,-2.0f);
			glVertex3f(1.7f,0.0f,-4.0f);
			glVertex3f(3.3f,3.0f,-4.0f);
			glVertex3f(1.4f,0.0f,-6.0f);
			glVertex3f(3.0f,3.9f,-6.0f);
			glVertex3f(0.0f,0.0f,-8.0f);
			glVertex3f(0.0f,4.0f,-10.0f);
			glEnd();
		glPopMatrix();
		
		//deck
		glPushMatrix();
			glBegin(GL_TRIANGLE_STRIP);
			glColor3f(0.65f,0.39f,0.03f);
			glVertex3f(0.0f,4.0f,-10.0f);
			glVertex3f(3.0f,3.9f,-6.0f);
			glVertex3f(-3.0f,3.9f,-6.0f);
			glVertex3f(3.3f,3.0f,-4.0f);
			glVertex3f(-3.3f,3.0f,-4.0f);
			glVertex3f(3.5f,3.0f,-2.0f);
			glVertex3f(-3.5f,3.0f,-2.0f);
			glVertex3f(3.6f,3.0f,0.0f);
			glVertex3f(-3.6f,3.0f,0.0f);
			glVertex3f(3.5f,3.0f,2.0f);
			glVertex3f(-3.5f,3.0f,2.0f);
			glVertex3f(3.3f,3.0f,4.0f);
			glVertex3f(-3.3f,3.0f,4.0f);
			glVertex3f(3.0f,3.5f,6.0f);
			glVertex3f(-3.0f,3.5f,6.0f);
			glVertex3f(0.0f,3.8f,12.0f);
			glEnd();
		glPopMatrix();
		
		//tiang
		//tengah
		glPushMatrix();
			glColor3f(0.34f,0.17f,0.03f);
			glBegin(GL_QUAD_STRIP);
			glVertex3f(-0.1f,0.0f,0.0f);
			glVertex3f(-0.1f,18.0f,0.0f);
			glVertex3f(0.0f,0.0f,0.1f);
			glVertex3f(0.0f,18.0f,0.1f);
			glVertex3f(0.1f,0.0f,0.0f);
			glVertex3f(0.1f,18.0f,0.0f);
			glVertex3f(0.0f,0.0f,-0.1f);
			glVertex3f(0.0f,18.0f,-0.1f);
			glEnd();
		glPopMatrix();
			//tengah atas
			glPushMatrix();
				glTranslatef(0.0f,16.0f,0.0f);
				glRotatef(90,0,0,1);
				glBegin(GL_QUAD_STRIP);
				glVertex3f(-0.1f,-3.0f,0.0f);
				glVertex3f(-0.1f,3.0f,0.0f);
				glVertex3f(0.0f,-3.0f,0.1f);
				glVertex3f(0.0f,3.0f,0.1f);
				glVertex3f(0.1f,-3.0f,0.0f);
				glVertex3f(0.1f,3.0f,0.0f);
				glVertex3f(0.0f,-3.0f,-0.1f);
				glVertex3f(0.0f,3.0f,-0.1f);
				glEnd();
			glPopMatrix();
			//tengah tengah
			glPushMatrix();
				glTranslatef(0.0f,12.0f,0.0f);
				glRotatef(90,0,0,1);
				glBegin(GL_QUAD_STRIP);
				glVertex3f(-0.1f,-3.5f,0.0f);
				glVertex3f(-0.1f,3.5f,0.0f);
				glVertex3f(0.0f,-3.5f,0.1f);
				glVertex3f(0.0f,3.5f,0.1f);
				glVertex3f(0.1f,-3.5f,0.0f);
				glVertex3f(0.1f,3.5f,0.0f);
				glVertex3f(0.0f,-3.5f,-0.1f);
				glVertex3f(0.0f,3.5f,-0.1f);
				glEnd();
			glPopMatrix();
			//tengah bawah
			glPushMatrix();
				glTranslatef(0.0f,8.0f,0.0f);
				glRotatef(90,0,0,1);
				glBegin(GL_QUAD_STRIP);
				glVertex3f(-0.1f,-4.0f,0.0f);
				glVertex3f(-0.1f,4.0f,0.0f);
				glVertex3f(0.0f,-4.0f,0.1f);
				glVertex3f(0.0f,4.0f,0.1f);
				glVertex3f(0.1f,-4.0f,0.0f);
				glVertex3f(0.1f,4.0f,0.0f);
				glVertex3f(0.0f,-4.0f,-0.1f);
				glVertex3f(0.0f,4.0f,-0.1f);
				glEnd();
			glPopMatrix();
		//depan
		glPushMatrix();
			glTranslatef(0.0f,0.0f,6.0f);
			glBegin(GL_QUAD_STRIP);
			glVertex3f(-0.1f,0.0f,0.0f);
			glVertex3f(-0.1f,13.0f,0.0f);
			glVertex3f(0.0f,0.0f,0.1f);
			glVertex3f(0.0f,13.0f,0.1f);
			glVertex3f(0.1f,0.0f,0.0f);
			glVertex3f(0.1f,13.0f,0.0f);
			glVertex3f(0.0f,0.0f,-0.1f);
			glVertex3f(0.0f,13.0f,-0.1f);
			glEnd();
		glPopMatrix();
			//depan atas
			glPushMatrix();
				glTranslatef(0.0f,12.0f,6.0f);
				glRotatef(90,0,0,1);
				glBegin(GL_QUAD_STRIP);
				glVertex3f(-0.1f,-3.0f,0.0f);
				glVertex3f(-0.1f,3.0f,0.0f);
				glVertex3f(0.0f,-3.0f,0.1f);
				glVertex3f(0.0f,3.0f,0.1f);
				glVertex3f(0.1f,-3.0f,0.0f);
				glVertex3f(0.1f,3.0f,0.0f);
				glVertex3f(0.0f,-3.0f,-0.1f);
				glVertex3f(0.0f,3.0f,-0.1f);
				glEnd();
			glPopMatrix();
			//depan tengah
			glPushMatrix();
				glTranslatef(0.0f,9.0f,6.0f);
				glRotatef(90,0,0,1);
				glBegin(GL_QUAD_STRIP);
				glVertex3f(-0.1f,-3.5f,0.0f);
				glVertex3f(-0.1f,3.5f,0.0f);
				glVertex3f(0.0f,-3.5f,0.1f);
				glVertex3f(0.0f,3.5f,0.1f);
				glVertex3f(0.1f,-3.5f,0.0f);
				glVertex3f(0.1f,3.5f,0.0f);
				glVertex3f(0.0f,-3.5f,-0.1f);
				glVertex3f(0.0f,3.5f,-0.1f);
				glEnd();
			glPopMatrix();
			//depan bawah
			glPushMatrix();
				glTranslatef(0.0f,6.0f,6.0f);
				glRotatef(90,0,0,1);
				glBegin(GL_QUAD_STRIP);
				glVertex3f(-0.1f,-4.0f,0.0f);
				glVertex3f(-0.1f,4.0f,0.0f);
				glVertex3f(0.0f,-4.0f,0.1f);
				glVertex3f(0.0f,4.0f,0.1f);
				glVertex3f(0.1f,-4.0f,0.0f);
				glVertex3f(0.1f,4.0f,0.0f);
				glVertex3f(0.0f,-4.0f,-0.1f);
				glVertex3f(0.0f,4.0f,-0.1f);
				glEnd();
			glPopMatrix();
		//belakang
		glPushMatrix();
			glTranslatef(0.0f,0.0f,-5.0f);
			glBegin(GL_QUAD_STRIP);
			glVertex3f(-0.1f,0.0f,0.0f);
			glVertex3f(-0.1f,16.0f,0.0f);
			glVertex3f(0.0f,0.0f,0.1f);
			glVertex3f(0.0f,16.0f,0.1f);
			glVertex3f(0.1f,0.0f,0.0f);
			glVertex3f(0.1f,16.0f,0.0f);
			glVertex3f(0.0f,0.0f,-0.1f);
			glVertex3f(0.0f,16.0f,-0.1f);
			glEnd();
		glPopMatrix();
			//belakang atas
			glPushMatrix();
				glTranslatef(0.0f,15.0f,-5.0f);
				glRotatef(90,0,0,1);
				glBegin(GL_QUAD_STRIP);
				glVertex3f(-0.1f,-3.0f,0.0f);
				glVertex3f(-0.1f,3.0f,0.0f);
				glVertex3f(0.0f,-3.0f,0.1f);
				glVertex3f(0.0f,3.0f,0.1f);
				glVertex3f(0.1f,-3.0f,0.0f);
				glVertex3f(0.1f,3.0f,0.0f);
				glVertex3f(0.0f,-3.0f,-0.1f);
				glVertex3f(0.0f,3.0f,-0.1f);
				glEnd();
			glPopMatrix();
			//belakang tengah
			glPushMatrix();
				glTranslatef(0.0f,12.0f,-5.0f);
				glRotatef(90,0,0,1);
				glBegin(GL_QUAD_STRIP);
				glVertex3f(-0.1f,-3.5f,0.0f);
				glVertex3f(-0.1f,3.5f,0.0f);
				glVertex3f(0.0f,-3.5f,0.1f);
				glVertex3f(0.0f,3.5f,0.1f);
				glVertex3f(0.1f,-3.5f,0.0f);
				glVertex3f(0.1f,3.5f,0.0f);
				glVertex3f(0.0f,-3.5f,-0.1f);
				glVertex3f(0.0f,3.5f,-0.1f);
				glEnd();
			glPopMatrix();
			//belakang bawah
			glPushMatrix();
				glTranslatef(0.0f,8.0f,-5.0f);
				glRotatef(90,0,0,1);
				glBegin(GL_QUAD_STRIP);
				glVertex3f(-0.1f,-4.0f,0.0f);
				glVertex3f(-0.1f,4.0f,0.0f);
				glVertex3f(0.0f,-4.0f,0.1f);
				glVertex3f(0.0f,4.0f,0.1f);
				glVertex3f(0.1f,-4.0f,0.0f);
				glVertex3f(0.1f,4.0f,0.0f);
				glVertex3f(0.0f,-4.0f,-0.1f);
				glVertex3f(0.0f,4.0f,-0.1f);
				glEnd();
			glPopMatrix();
		//ujung
		/* glPushMatrix();
			glTranslatef(0.0f,0.0f,7.0f);
			glRotatef(50,1,0,0);
			glBegin(GL_QUAD_STRIP);
			glVertex3f(-0.1f,0.0f,0.0f);
			glVertex3f(-0.1f,12.0f,0.0f);
			glVertex3f(0.0f,0.0f,0.1f);
			glVertex3f(0.0f,12.0f,0.1f);
			glVertex3f(0.1f,0.0f,0.0f);
			glVertex3f(0.1f,12.0f,0.0f);
			glVertex3f(0.0f,0.0f,-0.1f);
			glVertex3f(0.0f,12.0f,-0.1f);
			glEnd();
		glPopMatrix();
		*/
		
		//layar
		//depan
		glPushMatrix();
			glColor3f(1.0f,1.0f,1.0f);
			glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(0.0f,13.0f,6.0f);
			glVertex3f(0.0f,4.0f,9.0f);
			glVertex3f(0.0f,6.8f,14.0f);
			glEnd();
		glPopMatrix();
		//belakang
		glPushMatrix();
			glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(0.0f,4.0f,-5.0f);
			glVertex3f(0.0f,11.0f,-5.0f);
			glVertex3f(0.0f,5.0f,-9.0f);
			glVertex3f(0.0f,9.0f,-7.0f);
			glEnd();
		glPopMatrix();
		
	glPopMatrix();
	
}

void display(){
	// Kalau move dan angle tidak nol, gerakkan kamera...
	if (deltaMove){
		moveMeFlat(deltaMove);
	}
	if (deltaZ){
		moveVertical(deltaZ);
	}
	if (deltaAngle){
		angle += deltaAngle;
		orientMe(angle);
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Gambar grid
	Grid();
	// Gambar objek di sini...
	Kapal();
	glutSwapBuffers();
	glFlush();
}

void pressKey(int key, int x, int y) {
	// Fungsi ini akan dijalankan saat tombol keyboard ditekan dan belum dilepas
	// Selama tombol ditekan, variabel angle dan move diubah => kamera bergerak
	switch (key){
		case GLUT_KEY_LEFT : deltaAngle = -0.001f;break;
		case GLUT_KEY_RIGHT : deltaAngle = 0.001f;break;
		case GLUT_KEY_UP : deltaMove = 1;break;
		case GLUT_KEY_DOWN : deltaMove = -1;break;
		case GLUT_KEY_PAGE_UP : deltaZ = 1;break;
		case GLUT_KEY_PAGE_DOWN : deltaZ = -1;break;
	}
}

void releaseKey(int key, int x, int y) {
	// Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas
	// Saat tombol dilepas, variabel angle dan move diset nol => kamera berhenti
	switch (key){
		case GLUT_KEY_LEFT:
			if (deltaAngle < 0.0f)
			deltaAngle = 0.0f;
			break;
		case GLUT_KEY_RIGHT :
			if (deltaAngle > 0.0f)
			deltaAngle = 0.0f;
			break;
		case GLUT_KEY_UP:
			if (deltaMove > 0)
			deltaMove = 0;
			break;
		case GLUT_KEY_DOWN :
			if (deltaMove < 0)
			deltaMove = 0;
			break;
		case GLUT_KEY_PAGE_UP :
			if (deltaZ > 0)
			deltaZ = 0;
			break;
		case GLUT_KEY_PAGE_DOWN :
			if (deltaZ < 0)
			deltaZ = 0;
			break;
	}
}

// Variable untuk pencahayaan
const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { -15.0f, 15.0f, 1.0f, 1.0f };
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void lighting(){
	// Fungsi mengaktifkan pencahayaan
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void init(void){
	glEnable (GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Kapal 3D");
	glutIgnoreKeyRepeat(1); // Mengabaikan key repeat (saat tombol keyboard dipencet terus)
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);
	glutDisplayFunc(display);
	glutIdleFunc(display); // Fungsi display-nya dipanggil terus- menerus
	glutReshapeFunc(Reshape);
	init();
	lighting();
	glutMainLoop();
	return(0);
}
