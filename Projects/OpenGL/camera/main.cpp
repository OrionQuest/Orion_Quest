#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <SOIL.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"

GLfloat mix_value=0.2f;
bool keys[1024];
GLfloat delta_time=0.0f;    // time between current frame and last frame
GLfloat last_frame=0.0f;    // time of last frame

glm::vec3 camera_position=glm::vec3(0.0f,0.0f,3.0f);
glm::vec3 camera_front=glm::vec3(0.0f,0.0f,-1.0f);
glm::vec3 camera_up=glm::vec3(0.0f,1.0f,0.0f);

void do_movement()
{
    // camera controls
    GLfloat camera_speed=5.0f*delta_time;
    if(keys[GLFW_KEY_W]) camera_position+=camera_speed*camera_front;
    if(keys[GLFW_KEY_S]) camera_position-=camera_speed*camera_front;
    if(keys[GLFW_KEY_A]) camera_position-=glm::normalize(glm::cross(camera_front,camera_up))*camera_speed;
    if(keys[GLFW_KEY_D]) camera_position+=glm::normalize(glm::cross(camera_front,camera_up))*camera_speed;
}

void key_callback(GLFWwindow* window,int key,int scancode,int action,int mode)
{
    if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS)
        glfwSetWindowShouldClose(window,GL_TRUE);

    if(key==GLFW_KEY_UP && action==GLFW_PRESS)
    {
        mix_value+=0.1f;
        if(mix_value>1.0f) mix_value=1.0f;
    }

    if(key==GLFW_KEY_DOWN && action==GLFW_PRESS)
    {
        mix_value-=0.1f;
        if(mix_value<0.0f) mix_value=0.0f;
    }

    if(action==GLFW_PRESS) keys[key]=true;
    else if(action==GLFW_RELEASE) keys[key]=false;
}

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

    // projection matrix
    glm::mat4 projection;
    projection=glm::perspective(glm::radians(45.0f),(float)width/height,0.1f,100.0f);

    glfwSetKeyCallback(window,key_callback);

    Shader our_shader("shader.vs","shader.frag");

    GLuint texture1,texture2;

    // generate texture 1
    glGenTextures(1,&texture1);
    glBindTexture(GL_TEXTURE_2D,texture1);
    // set texture parameters
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    // set texture filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    // load, create and generate mipmaps
    unsigned char* image=SOIL_load_image("container.jpg",&width,&height,0,SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    glGenerateMipmap(GL_TEXTURE_2D);
    // free image data
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D,0);

    // generate texture 2
    glGenTextures(1,&texture2);
    glBindTexture(GL_TEXTURE_2D,texture2);
    // set texture parameters
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    // set texture filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    // load, create and generate mipmaps
    image=SOIL_load_image("awesomeface.png",&width,&height,0,SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    glGenerateMipmap(GL_TEXTURE_2D);
    // free image data
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D,0);

    GLfloat vertices[]={
        // positions        // textures
        -0.5f,-0.5f,-0.5f,  0.0f,0.0f,
         0.5f,-0.5f,-0.5f,  1.0f,0.0f,
         0.5f, 0.5f,-0.5f,  1.0f,1.0f,
         0.5f, 0.5f,-0.5f,  1.0f,1.0f,
        -0.5f, 0.5f,-0.5f,  0.0f,1.0f,
        -0.5f,-0.5f,-0.5f,  0.0f,0.0f,

        -0.5f,-0.5f, 0.5f,  0.0f,0.0f,
         0.5f,-0.5f, 0.5f,  1.0f,0.0f,
         0.5f, 0.5f, 0.5f,  1.0f,1.0f,
         0.5f, 0.5f, 0.5f,  1.0f,1.0f,
        -0.5f, 0.5f, 0.5f,  0.0f,1.0f,
        -0.5f,-0.5f, 0.5f,  0.0f,0.0f,

        -0.5f, 0.5f, 0.5f,  1.0f,0.0f,
        -0.5f, 0.5f,-0.5f,  1.0f,1.0f,
        -0.5f,-0.5f,-0.5f,  0.0f,1.0f,
        -0.5f,-0.5f,-0.5f,  0.0f,1.0f,
        -0.5f,-0.5f, 0.5f,  0.0f,0.0f,
        -0.5f, 0.5f, 0.5f,  1.0f,0.0f,

         0.5f, 0.5f, 0.5f,  1.0f,0.0f,
         0.5f, 0.5f,-0.5f,  1.0f,1.0f,
         0.5f,-0.5f,-0.5f,  0.0f,1.0f,
         0.5f,-0.5f,-0.5f,  0.0f,1.0f,
         0.5f,-0.5f, 0.5f,  0.0f,0.0f,
         0.5f, 0.5f, 0.5f,  1.0f,0.0f,

        -0.5f,-0.5f,-0.5f,  0.0f,1.0f,
         0.5f,-0.5f,-0.5f,  1.0f,1.0f,
         0.5f,-0.5f, 0.5f,  1.0f,0.0f,
         0.5f,-0.5f, 0.5f,  1.0f,0.0f,
        -0.5f,-0.5f, 0.5f,  0.0f,0.0f,
        -0.5f,-0.5f,-0.5f,  0.0f,1.0f,

        -0.5f, 0.5f,-0.5f,  0.0f,1.0f,
         0.5f, 0.5f,-0.5f,  1.0f,1.0f,
         0.5f, 0.5f, 0.5f,  1.0f,0.0f,
         0.5f, 0.5f, 0.5f,  1.0f,0.0f,
        -0.5f, 0.5f, 0.5f,  0.0f,0.0f,
        -0.5f, 0.5f,-0.5f,  0.0f,1.0f
    };

    glm::vec3 cube_positions[]={
        glm::vec3( 0.0f, 0.0f, 0.0f), 
        glm::vec3( 2.0f, 5.0f,-15.0f), 
        glm::vec3(-1.5f,-2.2f,-2.5f),  
        glm::vec3(-3.8f,-2.0f,-12.3f),  
        glm::vec3( 2.4f,-0.4f,-3.5f),  
        glm::vec3(-1.7f, 3.0f,-7.5f),  
        glm::vec3( 1.3f,-2.0f,-2.5f),  
        glm::vec3( 1.5f, 2.0f,-2.5f), 
        glm::vec3( 1.5f, 0.2f,-1.5f), 
        glm::vec3(-1.3f, 1.0f,-1.5f)
    };

    GLuint VAO,VBO;
    glGenBuffers(1,&VBO);
    glGenVertexArrays(1,&VAO);

    // bind vertex array object
    glBindVertexArray(VAO);

    // copy the vertices in a buffer
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

    // set position attribute pointers
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,5*sizeof(GL_FLOAT),(GLvoid*)0);
    glEnableVertexAttribArray(0);
    // set texture attribute pointers
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,5*sizeof(GL_FLOAT),(GLvoid*)(3*sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    // unbind the vertex array object
    glBindVertexArray(0);

    glEnable(GL_DEPTH_TEST);

    GLfloat radius=10.0f;

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        do_movement();
        glClearColor(.2f,.3f,.3f,1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        GLfloat current_frame=glfwGetTime();
        delta_time=current_frame-last_frame;
        last_frame=current_frame;

        // use shader program
        our_shader.Use();

        // bind textures
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,texture1);
        glUniform1i(glGetUniformLocation(our_shader.program,"our_texture1"),0);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D,texture2);
        glUniform1i(glGetUniformLocation(our_shader.program,"our_texture2"),1);

        glUniform1f(glGetUniformLocation(our_shader.program,"mix_value"),mix_value);

        // view space transform
        glm::mat4 view=glm::lookAt(camera_position,camera_position+camera_front,camera_up);

        GLuint model_location=glGetUniformLocation(our_shader.program,"model");
        GLuint view_location=glGetUniformLocation(our_shader.program,"view");
        glUniformMatrix4fv(view_location,1,GL_FALSE,glm::value_ptr(view));
        GLuint projection_location=glGetUniformLocation(our_shader.program,"projection");
        glUniformMatrix4fv(projection_location,1,GL_FALSE,glm::value_ptr(projection));

        // draw
        glBindVertexArray(VAO);
        for(GLuint i=0;i<10;++i)
        {
            // world space transform
            glm::mat4 model;
            model=glm::translate(model,cube_positions[i]);
            model=glm::rotate(model,glm::radians((GLfloat)glfwGetTime()*50.0f),glm::vec3(0.5f,1.0f,0.0f));
            GLfloat angle=glm::radians(20.0f*i);
            model=glm::rotate(model,angle,glm::vec3(1.0f,0.3f,0.5f));
            glUniformMatrix4fv(model_location,1,GL_FALSE,glm::value_ptr(model));

            glDrawArrays(GL_TRIANGLES,0,36);
        }
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
