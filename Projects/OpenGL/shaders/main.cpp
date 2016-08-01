#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

void key_callback(GLFWwindow* window,int key,int scancode,int action,int mode)
{
    if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS)
        glfwSetWindowShouldClose(window,GL_TRUE);
}

// vertex shader
const GLchar* vertex_shader_source="# version 330 core\n"
        "layout (location=0) in vec3 position;\n"
        "void main()\n"
        "{\n"
        "gl_Position = vec4(position.x,position.y,position.z,1.0);\n"
        "}\0";

// fragment shader
const GLchar* fragment_shader_source="# version 330 core\n"
        "out vec4 color;\n"
        "uniform vec4 our_color;\n"
        "void main()\n"
        "{\n"
        "color=our_color;\n"
        "}\0";

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);

    GLFWwindow *window=glfwCreateWindow(800,600,"Learn OpenGL",nullptr,nullptr);
    if(window==nullptr)
    {
        std::cout<<"Failed to create GLFW window!"<<std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glewExperimental=GL_TRUE;
    if(glewInit()!=GLEW_OK)
    {
        std::cout<<"Failed to initialize GLEW!"<<std::endl;
        return -1;
    }

    int width,height;
    glfwGetFramebufferSize(window,&width,&height);
    glViewport(0,0,width,height);

    glfwSetKeyCallback(window,key_callback);

    GLfloat vertices[]={
        -0.5f,-0.5f,0.0f,
        0.5f,-0.5f,0.0f,
        0.0f,0.5f,0.0f};

    GLuint VBO;
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

    // vertex shader
    GLuint vertex_shader=glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader,1,&vertex_shader_source,NULL);
    glCompileShader(vertex_shader);

    GLint success;
    GLchar info_log[512];
    glGetShaderiv(vertex_shader,GL_COMPILE_STATUS,&success);
    if(!success)
    {
        glGetShaderInfoLog(vertex_shader,512,NULL,info_log);
        std::cout<<"Error! Vertex Shader::Compilation Failed!"<<std::endl<<info_log<<std::endl;
    }

    // fragment shader
    GLuint fragment_shader=glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader,1,&fragment_shader_source,NULL);
    glCompileShader(fragment_shader);

    glGetShaderiv(fragment_shader,GL_COMPILE_STATUS,&success);
    if(!success)
    {
        glGetShaderInfoLog(fragment_shader,512,NULL,info_log);
        std::cout<<"Error! Fragment Shader::Compilation Failed!"<<std::endl<<info_log<<std::endl;
    }

    // shader program
    GLuint shader_program=glCreateProgram();
    glAttachShader(shader_program,vertex_shader);
    glAttachShader(shader_program,fragment_shader);
    glLinkProgram(shader_program);

    glGetProgramiv(shader_program,GL_LINK_STATUS,&success);
    if(!success)
    {
        glGetProgramInfoLog(shader_program,512,NULL,info_log);
        std::cout<<"Error! Shader Program::Linking Failed!"<<std::endl<<info_log<<std::endl;
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    GLuint VAO;
    glGenVertexArrays(1,&VAO);
    // bind vertex array object
    glBindVertexArray(VAO);
    // copy the vertices in a buffer
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    // set vertex attribute pointers
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(GL_FLOAT),(GLvoid*)0);
    glEnableVertexAttribArray(0);
    // unbind the vertex array object
    glBindVertexArray(0);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(.2f,.3f,.3f,1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        // use shader program
        glUseProgram(shader_program);

        GLfloat time_value=glfwGetTime();
        GLfloat green_value=(sin(time_value)/2)+0.5;
        GLint vertex_color_location=glGetUniformLocation(shader_program,"our_color");
        glUniform4f(vertex_color_location,0.0f,green_value,0.0f,1.0f);

        // draw
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES,0,3);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    // deallocate all resources
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    // terminate GLFW
    glfwTerminate();

    return 0;
}
