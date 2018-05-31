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

void pulau1(){
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

}
