  void render() {
    //GRAFICAR una region
    glBegin(GL_LINE_LOOP);    
    glColor3f(1, 1, 1);//COLOR REGION
    for(auto punto:regions) {
      glVertex2f(p.x, p.y);
    }
    glEnd();
    // El punto que le corresponde
    glBegin(GL_POINTS);
    for(auto &p:points) {
      glColor3f(1, 1, 1);
      glVertex2f(p.x, p.y);
    }
    glEnd();
    if(iteration < width)
      update();
  }
