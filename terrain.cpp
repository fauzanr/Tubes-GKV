void grid(){
	glPushMatrix();
		glColor3f(0.5,0.5,1.0);
		glBegin(GL_QUADS);
			glVertex3f(-90.0,0,-90.0);
			glVertex3f(90.0,0,-90.0);
			glVertex3f(90.0,0,90.0);
			glVertex3f(-90.0,0,90.0);
		glEnd();
	glPopMatrix();
}

void Balok(float panjang,float lebar,float tinggi){
	glPushMatrix();
	float p=panjang/2;
	float l=lebar/2;
	float t=tinggi/2;
	//depan
	glBegin(GL_QUADS);
	glVertex3f(-p,0,l);
	glVertex3f(p,0,l);
	glVertex3f(p,-t*2,l);
	glVertex3f(-p,- t*2,l);
	glEnd();
	// belakang
	glBegin(GL_QUADS);
	glVertex3f(-p,0,- l);
	glVertex3f(p,0,-l);
	glVertex3f(p,-t*2,- l);
	glVertex3f(-p,- t*2,-l);
	glEnd();
	// atas
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-p,0,- l);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(p,0,-l);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(p,0,l);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-p,0,l);
	glEnd();

	// bawah
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-p,- t*2,-l);
	glTexCoord2f(0.0f, 1.0f);

	glVertex3f(p,-t*2,- l);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(p,-t*2,l);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-p,- t*2,l);
	glEnd();
	// kanan
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-p,- t*2,-l);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-p,- t*2,l);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-p,0,l);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-p,0,- l);
	glEnd();

	// kiri
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(p,-t*2,- l);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(p,-t*2,l);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(p,0,l);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(p,0,-l);
	glEnd();
	glPopMatrix();
}

void jembatan(float rotJembatan) {
	glPushMatrix();
		glPushMatrix();
			glTranslatef(-30,3,-36);
			glRotatef(rotJembatan,0,0,1);
			glTranslatef(7.0,0.0,0.0);
			glColor3f(1,0,0);
			Balok(14,25,1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-2,3,-36);
			glRotatef(-1*rotJembatan,0,0,1);
			glTranslatef(-7.0,0.0,0.0);
			glColor3f(1,0,1);
			Balok(14,25,1);
		glPopMatrix();
	glPopMatrix();
}

void terrain(){
	//dock
	glPushMatrix();
		glTranslatef(-45,0,35);
		glRotatef(180,0,1,0);

		glPushMatrix();
			glTranslatef(-5,0,-13);
			//papan dock
			glPushMatrix();
				glColor3f(0.0,0.0,0.3);
				glTranslatef(21.5,3,0);
				Balok(25,15,1.5);
			glPopMatrix();

			//tiang papan 1
			glPushMatrix();
				glColor3f(1,0.1,0.2);
				glTranslatef(16,4,7.8);
				Balok(2,2,4);
			glPopMatrix();

			//tiang papan 2
			glPushMatrix();
				glColor3f(1,0.1,0.2);
				glTranslatef(28,4,7.8);
				Balok(2,2,4);
			glPopMatrix();
			//tiang papan 3
			glPushMatrix();
				glColor3f(1,0.1,0.2);
				glTranslatef(16,4,-7.8);
				Balok(2,2,4);
			glPopMatrix();
			//tiang papan 4
			glPushMatrix();
				glColor3f(1,0.1,0.2);
				glTranslatef(28,4,-7.8);
				Balok(2,2,4);
			glPopMatrix();
		glPopMatrix();
		//daratan dock
		glPushMatrix();
			glColor3f(0,1,0);
			glTranslatef(42,3,0);
			Balok(26,53,3);
		glPopMatrix();
		glPopMatrix();

	//daratan 1
	glPushMatrix();
		glColor3f(0,0,1);
		glTranslatef(-65,3,-46);
		Balok(70,109,3);
	glPopMatrix();

	//daratan2
	glPushMatrix();
		glPushMatrix();
			glColor3f(0,0.88,1);
			glTranslatef(20,3,26);
			Balok(44,168,3);
		glPopMatrix();

		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(40,0,0);
			glBegin(GL_POLYGON);
			glVertex3f(2.0f,3.0f,0.0f);
			glVertex3f(2.0f,3.0f,110.0f);
			glVertex3f(25.0f,3.0f,110.0f);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(40,0,0);
			glBegin(GL_POLYGON);
			glVertex3f(2.0f,3.0f,110.0f);
			glVertex3f(2.0f,0.0f,110.0f);
			glVertex3f(25.0f,0.0f,110.0f);
			glVertex3f(25.0f,3.0f,110.0f);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(40,0,0);
			glBegin(GL_POLYGON);
			glVertex3f(2.0f,3.0f,0.0f);
			glVertex3f(2.0f,0.0f,0.0f);
			glVertex3f(25.0f,0.0f,110.0f);
			glVertex3f(25.0f,3.0f,110.0f);
			glEnd();
		glPopMatrix();
	glPopMatrix();

	//daratan 3
	glPushMatrix();
		glPushMatrix();
			glColor3f(0,0,1);
			glTranslatef(82.5,3,-50);
			Balok(25,100,3);
		glPopMatrix();

		glPushMatrix();
				glColor3f(1,1,1);
				glTranslatef(68,0,0);
				glBegin(GL_POLYGON);
				glVertex3f(2.0f,3.0f,0.0f);
				glVertex3f(2.0f,0.0f,0.0f);
				glVertex3f(27.0f,0.0f,50.0f);
				glVertex3f(27.0f,3.0f,50.0f);
				glEnd();
		glPopMatrix();

		glPushMatrix();
				glColor3f(1,1,1);
				glTranslatef(68,0,0);
				glBegin(GL_POLYGON);
				glVertex3f(27.0f,3.0f,0.0f);
				glVertex3f(27.0f,0.0f,0.0f);
				glVertex3f(27.0f,0.0f,50.0f);
				glVertex3f(27.0f,3.0f,50.0f);
				glEnd();
		glPopMatrix();

		glPushMatrix();
				glColor3f(1,1,1);
				glTranslatef(68,0,0);
				glBegin(GL_POLYGON);
				glVertex3f(2.0f,3.0f,0.0f);
				glVertex3f(27.0f,3.0f,0.0f);
				glVertex3f(27.0f,3.0f,50.0f);
				glEnd();
		glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}
