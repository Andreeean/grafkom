#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <GL/glew.h>
#include <glfw3.h>
#include <common/controls.hpp>
#include <common/shader.hpp>
#include <customs/shapes.hpp>
#include <customs/things.hpp>

using namespace glm;
GLFWwindow* window;

GLfloat random (GLfloat min, GLfloat max) {
    return min + (GLfloat) rand () / (GLfloat (RAND_MAX / (max-min)));
}

void generateRandomTree (int n, GLfloat height, GLfloat planeSize, std::vector<Object*> &objects) {
    GLfloat space[] = {-planeSize/2, 5};
    for (int i = 0; i < n; i++) {
        GLfloat x, z;
        x = random (-planeSize/2, planeSize/2);

        GLfloat s = space[rand () % 2];
        z = random (s, s+(planeSize/2)-5);

        int size = 5 + rand () % (10-5+1);
        objects.push_back (new Tree (x, height, z, size));
    }
}

int initGL () {
    // initialize GLFW
    if (!glfwInit ()) {
        fprintf (stderr, "Failed to initialize GLFW\n");
        getchar ();
        return -1;
    }

    glfwWindowHint (GLFW_SAMPLES, 4);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    window = glfwCreateWindow (800, 600, "FP", nullptr, nullptr);
    if (window == nullptr) {
        getchar ();
        glfwTerminate ();
        return -1;
    }
    glfwMakeContextCurrent (window);

    // Initialize GLEW
    glewExperimental = true;
    if (glewInit () != GLEW_OK) {
        fprintf (stderr, "Failed to initialize GLEW\n");
        getchar ();
        glfwTerminate ();
        return -1;
    }

    glfwSetInputMode (window, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSetInputMode (window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwPollEvents ();
    glfwSetCursorPos (window, 1024/2, 768/2);
    glClearColor (0.4f, 0.6f, 0.9f, 0.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LESS);
    glEnable (GL_CULL_FACE);
    return 0;
}

int main () {
    srand (static_cast <unsigned> (time (0)));
    if (initGL () == -1)
        return -1;

    GLuint programID = LoadShaders ("TransformVertexShader.vertexshader", "ColorFragmentShader.fragmentshader");
    GLuint MatrixID = glGetUniformLocation (programID, "MVP");

    /* define all the objects here. */
    std::vector<Object*> objects;
    //kepala
    objects.push_back(((Object*)((new Box (-6,-5,0,1,0,1,true))->setFaceColor(Box::FRONT, Color (67, 70,75, true)))));
    objects.push_back(((Object*)((new Box(-7,-6,0,0.5,0,1, true))->setFaceColor(Box::FRONT, Color(160,0,0, true)))));
    objects.push_back(((Object*)((new Cylinder(-6.5,0.5,0.5,0.25,0.75, true))->setSideColor (Color(67,70,75, true)))));
    //gerbong 1
    objects.push_back(((Object*)((new Box(-5,-4.75,0.25,0.5,0.35,0.65, true))->setFaceColor (Box::FRONT, Color(160,0,0, true)))));
    objects.push_back(((Object*)((new Cube(-4.25,0,0.5,1, true))->setFaceColor(Box::FRONT,Color(67,70,75,true)))));
    //gerbong 2
    objects.push_back (((Object*)((new Box(-3.75,-3.55,0.25,0.5,0.35,0.65, true))->setFaceColor(Box::FRONT, Color(160,0,0,true)))));
    objects.push_back (((Object*)((new Cube(-3.05,0,0.5,1, true))->setFaceColor(Box::FRONT, Color(67,70,75,true)))));
    //gerbong 3
    objects.push_back (((Object*)((new Box(-2.55,-2.3,0.25,0.5,0.35,0.65, true))->setFaceColor(Box::FRONT,Color(160,0,0,true)))));
    objects.push_back (((Object*)((new Cube(-1.8,0,0.5,1, true))->setFaceColor(Box::FRONT,Color(67,70,75,true)))));
    //gerbong 4
    objects.push_back (((Object*)((new Box(-1.3,-1,0.25,0.5,0.35,0.65, true))->setFaceColor(Box::FRONT,Color(160,0,0,true)))));
    objects.push_back (((Object*)((new Cube(-0.5,0,0.5,1, true))->setFaceColor(Box::FRONT,Color(67,70,75,true)))));
    //gerbong 5
    objects.push_back (((Object*)((new Box(0,0.25,0.25,0.5,0.35,0.65, true))->setFaceColor(Box::FRONT, Color(160,0,0,true)))));
    objects.push_back (((Object*)((new Cube(0.75,0,0.5,1, true))->setFaceColor(Box::FRONT,Color(67,70,75,true)))));
    //danau
    objects.push_back (((Object*)((new Cylinder(-6,-0.25,6,3,0.01, false))->setCoverColor (Color(0,102,255,true)))));
    //pohon
    objects.push_back (new Tree(-4,-0.25,-6, 5));
    objects.push_back (new Tree(-6,-0.25,-9, 5));
    objects.push_back (new Tree(5,-0.25,-10, 5));
    objects.push_back (new Tree(7,-0.25,8, 5));
    objects.push_back (new Tree(10,-0.25,7, 5));
    objects.push_back (new Tree(-11,-0.25,3, 5));
    objects.push_back (new Tree(3,-0.25,2, 6));
    objects.push_back (new Tree(9,-0.25,5, 5));
    objects.push_back (new Tree(5,-0.25,8, 5));
    objects.push_back (new Tree(7,-0.25,9, 7));
    objects.push_back (new Tree(-9,-0.25,7, 5));
    objects.push_back (new Tree(-10,-0.25,8, 5));
    objects.push_back (new Tree(-4,-0.25,-6, 5));
    objects.push_back (new Tree(1,-0.25,8, 5));
    objects.push_back (new Tree(0,-0.25,-6, 5));
    objects.push_back (new Tree(4,-0.25,-4, 5));
    objects.push_back (new Tree(6,-0.25,-9, 6));
    objects.push_back (new Tree(7,-0.25,-11, 5));
    objects.push_back (new Tree(10,-0.25,-3, 5));
    objects.push_back (new Tree(-10,-0.26,-11,8));
    objects.push_back (new Tree(-9,-0.26,-11.5,8));
    objects.push_back (new Tree(-8,-0.26,-10,8));




    // earth
    objects.push_back (new Plane (0, -0.25f, 0, 25));

    // rail
    objects.push_back (((Object*)((new Box (-12.5, 12.5, -0.25f, 0, 0, 1))->setFaceColor (Box::LEFT,Color (0,0,0, 1))->setFaceColor(Box::RIGHT,Color(0,0,0,1))->setFaceColor (Box::TOP, Color (0, 0, 0, 1)))));


    do {

        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram (programID);

        // Compute the MVP matrix from keyboard and mouse input
        computeMatricesFromInputs ();
        glm::mat4 ProjectionMatrix = getProjectionMatrix ();
        glm::mat4 ViewMatrix = getViewMatrix ();
        glm::mat4 ModelMatrix = glm::mat4 (1.0);
        glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

        glUniformMatrix4fv (MatrixID, 1, GL_FALSE, &MVP[0][0]);
        for (int i = 0; i < objects.size (); i++)
            // render all objects defined
            objects[i]->render ();

        glfwSwapBuffers (window);
        glfwPollEvents ();
    }
    while (glfwGetKey (window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose (window) == 0);

    for (int i = 0; i < objects.size (); i++)
        objects[i]->clean ();
    glDeleteProgram (programID);

    // Close OpenGL window and terminate GLFW
    glfwTerminate ();

    return 0;
}