#include <glad/glad.h>
#define GLFW_STATIC
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stb_image.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
float h = 0.0f;
float g = 0.0f;
float c = 0.0f;
float d = 0.21f;
int comparisonu = 0;
int comparisont = 0;
int swapu = 0;
int swapt = 0;
int m = 0;
int y = 0;
int s = 0;
int u = 0;
int last = 0;
int last1 = 0;
int redblue = 1;
float distance = 1.25f;
float delay = 0.0f;
float delay1 = 0.0f;
float temporary;
float temporary1;
int reverse = 0;
int reverse1 = 0;
int value = -1;
float am = 0.0f;
float bm = 0.0f;
float drift = 0.0f;
float wait = 0.0f;
float drift1 = 0.0f;
float wait1 = 0.0f;
int start = 0;
int glag = 1;
int hlag = 1;
int back = 0;
int front = 0;
int passno = 1;
int flag = 0;
int frontarrow = 1;
int backarrow = 0;
int array[7] = { 0 }, sorted[7] = { 0 }, swap[50] = { 0 };
float vertices[500] = { 0.0f };
const unsigned int SCR_WIDTH = 930;
const unsigned int SCR_HEIGHT = 900;
const char* vertexShaderSource2 = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 2) in vec2 aTexCoord;\n"
"uniform mat4 transform;\n"
"out vec2 TexCoord;\n"
"void main()\n"
"{\n"
"   gl_Position = transform * vec4(aPos, 1.0);\n"
"   TexCoord = aTexCoord;\n"
"}\0";
const char* fragmentShaderSource2 = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec2 TexCoord;\n"
"uniform sampler2D ourTexture;\n"
"void main()\n"
"{\n"
"   FragColor = texture(ourTexture, TexCoord);\n"
"}\n\0";
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"uniform float offsetx;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f - offsetx, 0.0f + offsetx, 0.2f, 1.0f);\n"
"}\n\0";
void draw(unsigned int shaderProgram2, unsigned int VAO, float offset, unsigned int off, int a, int b)
{
    char number;
    if (y != 7)
    {
        number = array[y++] + 48;
    }
    else
    {
        y = 0;
        number = array[y++] + 48;
    }
    char str1[7] = "10.jpg";
    if (y % 2 != 0)
    {
        str1[0] = number;
        str1[1] = '0';
    }
    else
    {
        str1[0] = number;
        str1[1] = 'f';
    }
    str1[0] = number;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    unsigned int texture1;
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    float borderColor[] = { 0.2f, 0.3f, 0.3f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(str1, &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glUseProgram(shaderProgram2);
    glBindVertexArray(VAO);
    if (redblue == 0)
    {
        if (y == b && h < 0.21f && y == frontarrow)
        {
            glm::mat4 transform;
            transform = glm::translate(transform, glm::vec3(0.0f, h = h + 0.01f, 0.0f));
            unsigned int transformLoc = glGetUniformLocation(shaderProgram2, "transform");
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(off * sizeof(unsigned int)));
            transform = glm::mat4(1.0f);
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        }
        else if (y == b && h >= 0.21f && g > -0.25f && y == frontarrow)
        {
            glm::mat4 transform;
            transform = glm::translate(transform, glm::vec3(g = g - 0.01f, 0.21f, 0.0f));
            unsigned int transformLoc = glGetUniformLocation(shaderProgram2, "transform");
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(off * sizeof(unsigned int)));
            transform = glm::mat4(1.0f);
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

        }
        else if (y == b && g <= -0.25 && c < 0.25f && y == frontarrow)
        {
            glm::mat4 transform;
            transform = glm::translate(transform, glm::vec3(-0.25f, 0.21f, 0.0f));
            unsigned int transformLoc = glGetUniformLocation(shaderProgram2, "transform");
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(off * sizeof(unsigned int)));
            transform = glm::mat4(1.0f);
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        }
        else if (y == a && g <= -0.25f && c < 0.25f && y == frontarrow - 1)
        {
            glm::mat4 transform;
            transform = glm::translate(transform, glm::vec3(c = c + 0.01f, 0.0f, 0.0f));
            unsigned int transformLoc = glGetUniformLocation(shaderProgram2, "transform");
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(off * sizeof(unsigned int)));
            transform = glm::mat4(1.0f);
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

        }
        else if (y == a && c >= 0.25f && y == frontarrow - 1)
        {
            glm::mat4 transform;
            transform = glm::translate(transform, glm::vec3(0.25f, 0.0f, 0.0f));
            unsigned int transformLoc = glGetUniformLocation(shaderProgram2, "transform");
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(off * sizeof(unsigned int)));
            transform = glm::mat4(1.0f);
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        }
        else if (y == b && c >= 0.25f && d > 0.0f && y == frontarrow)
        {
            glm::mat4 transform;
            transform = glm::translate(transform, glm::vec3(-0.25f, d = d - 0.01f, 0.0f));
            unsigned int transformLoc = glGetUniformLocation(shaderProgram2, "transform");
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(off * sizeof(unsigned int)));
            transform = glm::mat4(1.0f);
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        }
        else if (y == b && d <= 0.0f && y == frontarrow)
        {
            glm::mat4 transform;
            transform = glm::translate(transform, glm::vec3(-0.25f, 0.0f, 0.0f));
            unsigned int transformLoc = glGetUniformLocation(shaderProgram2, "transform");
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(off * sizeof(unsigned int)));
            transform = glm::mat4(1.0f);
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
            flag = 1;
            std::swap(array[a - 1], array[b - 1]);
        }
        else
        {
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(off * sizeof(unsigned int)));
        }
    }
    else
    {
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(off * sizeof(unsigned int)));
    }
    glDeleteTextures(1, &texture1);
    free(data);
}
void Title(int j, unsigned int shaderProgram2)
{
    unsigned int texture;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    float borderColor[] = { 0.2f, 0.3f, 0.3f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("BSS.jpg", &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glUseProgram(shaderProgram2);
    int b = j;
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(b * sizeof(unsigned int)));
    glDeleteTextures(1, &texture);
    free(data);
}
void Pass(int j, unsigned int shaderProgram2)
{
    unsigned int texture;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    float borderColor[] = { 0.2f, 0.3f, 0.3f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("Pass.jpg", &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glUseProgram(shaderProgram2);
    int b = j;
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(b * sizeof(unsigned int)));
    glDeleteTextures(1, &texture);
    free(data);
}
void NoC(int j, unsigned int shaderProgram2)
{
    unsigned int texture;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    float borderColor[] = { 0.2f, 0.3f, 0.3f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("comparisons.jpg", &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glUseProgram(shaderProgram2);
    int b = j;
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(b * sizeof(unsigned int)));
    glDeleteTextures(1, &texture);
    free(data);
}
void NoCt(int j, unsigned int shaderProgram2)
{
    unsigned int texture;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    float borderColor[] = { 0.2f, 0.3f, 0.3f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    char str1[7] = "1p.jpg";
    str1[0] = comparisont + 48;
    unsigned char* data = stbi_load(str1, &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glUseProgram(shaderProgram2);
    int b = j;
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(b * sizeof(unsigned int)));
    glDeleteTextures(1, &texture);
    free(data);
}
void NoCu(int j, unsigned int shaderProgram2)
{
    unsigned int texture;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    float borderColor[] = { 0.2f, 0.3f, 0.3f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    char str1[7] = "1p.jpg";
    str1[0] = comparisonu + 48;
    unsigned char* data = stbi_load(str1, &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glUseProgram(shaderProgram2);
    int b = j;
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(b * sizeof(unsigned int)));
    glDeleteTextures(1, &texture);
    free(data);
}
void NoS(int j, unsigned int shaderProgram2)
{
    unsigned int texture;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    float borderColor[] = { 0.2f, 0.3f, 0.3f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("swaps.jpg", &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glUseProgram(shaderProgram2);
    int b = j;
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(b * sizeof(unsigned int)));
    glDeleteTextures(1, &texture);
    free(data);
}
void NoSt(int j, unsigned int shaderProgram2)
{
    unsigned int texture;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    float borderColor[] = { 0.2f, 0.3f, 0.3f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    char str1[7] = "1p.jpg";
    str1[0] = swapt + 48;
    unsigned char* data = stbi_load(str1, &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glUseProgram(shaderProgram2);
    int b = j;
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(b * sizeof(unsigned int)));
    glDeleteTextures(1, &texture);
    free(data);
}
void NoSu(int j, unsigned int shaderProgram2)
{
    unsigned int texture;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    float borderColor[] = { 0.2f, 0.3f, 0.3f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    char str1[7] = "1p.jpg";
    str1[0] = swapu + 48;
    unsigned char* data = stbi_load(str1, &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glUseProgram(shaderProgram2);
    int b = j;
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(b * sizeof(unsigned int)));
    glDeleteTextures(1, &texture);
    free(data);
}
void unsorted(int j, unsigned int shaderProgram2)
{
    unsigned int texture;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    float borderColor[] = { 0.2f, 0.3f, 0.3f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    char str1[13] = "unsorted.jpg";
    if (distance <= 0.0f || last1 >= 2)
    {
        str1[0] = 'i';
        str1[1] = 's';
    }
    unsigned char* data = stbi_load(str1, &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glUseProgram(shaderProgram2);
    int b = j;
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(b * sizeof(unsigned int)));
    glDeleteTextures(1, &texture);
    free(data);
}
void Passvalue(int j, unsigned int shaderProgram2)
{
    unsigned int texture;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    float borderColor[] = { 0.2f, 0.3f, 0.3f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    int width, height, nrChannels;
    char str1[7] = "1p.jpg";
    str1[0] = passno + 48;
    str1[1] = 'p';
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(str1, &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glUseProgram(shaderProgram2);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(j * sizeof(unsigned int)));
    glDeleteTextures(1, &texture);
    free(data);
}
void slidingarrow2(int j, unsigned int shaderProgram2)
{
    unsigned int texture;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    float borderColor[] = { 0.2f, 0.3f, 0.3f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    char str[] = "bluarrow.jpg";
    if (redblue == 0)
    {
        if (frontarrow != 7 - (passno - 2))
        {
            if ((delay > 0.25 && delay < 0.5 && (swap[u + 1] + 1 == frontarrow + 1)) || ((delay >= 0.5f && wait == 0.0f) && (swap[u + 1] + 1 == frontarrow)) || ((delay >= 0.5f && wait >= 0.0f && wait < 0.25f) && (swap[u - 1] + 1 == frontarrow)))
            {
                str[0] = 'g';
                str[1] = 'r';
                str[2] = 'e';
                stbi_set_flip_vertically_on_load(false);
            }
            else if ((delay > 0.25 && delay < 0.5 && (swap[u + 1] + 1 != frontarrow + 1)) || ((delay >= 0.5f && wait >= 0.0f && wait < 0.25f) && (swap[u + 1] + 1 != frontarrow)))
            {
                str[0] = 'r';
                str[1] = 'e';
                str[2] = 'd';
                stbi_set_flip_vertically_on_load(true);
            }
            else
            {
                str[0] = 'b';
                str[1] = 'l';
                str[2] = 'u';
                stbi_set_flip_vertically_on_load(true);
            }
        }
        else
        {
            if ((delay > 0.25 && delay < 0.5 && (swap[u + 1] + 1 == 2)) || ((delay >= 0.5f && wait == 0.0f) && (swap[u + 1] + 1 == frontarrow)) || ((delay >= 0.5f && wait >= 0.0f && wait < 0.25f) && (swap[u - 1] + 1 == frontarrow)))
            {
                str[0] = 'g';
                str[1] = 'r';
                str[2] = 'e';
                stbi_set_flip_vertically_on_load(false);
            }
            else if ((delay > 0.25 && delay < 0.5 && (swap[u + 1] + 1 != 2)) || ((delay >= 0.5f && wait >= 0.0f && wait < 0.25f) && (swap[u + 1] + 1 != frontarrow)))
            {
                str[0] = 'r';
                str[1] = 'e';
                str[2] = 'd';
                stbi_set_flip_vertically_on_load(true);
            }
            else
            {
                str[0] = 'b';
                str[1] = 'l';
                str[2] = 'u';
                stbi_set_flip_vertically_on_load(true);
            }
        }
    }
    else if (redblue == 1)
    {
        if ((delay > 0.25 && delay < 0.5) || (delay >= 0.5f && wait >= 0.0f && wait < 0.25f))
        {
            str[0] = 'r';
            str[1] = 'e';
            str[2] = 'd';
            stbi_set_flip_vertically_on_load(true);
        }
        else
        {
            str[0] = 'b';
            str[1] = 'l';
            str[2] = 'u';
            stbi_set_flip_vertically_on_load(true);
        }

    }
    /*if (issorted == 1)
    {
        str[0] = 'b';
        str[1] = 'l';
        str[2] = 'u';
        stbi_set_flip_vertically_on_load(true);
    }*/
    int width, height, nrChannels;
    unsigned char* data = stbi_load(str, &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glUseProgram(shaderProgram2);
    if (am < drift  && last1 < 2)
    {
        if (temporary == am)
        {
            if (reverse == 1)
            {
                reverse = 0;
                glag = 1;
                start = 1;
                passno++;
                distance = distance - 0.25f;
            }
            else
            {
                glag = 1;
            }
        }
        glm::mat4 transform;
        transform = glm::translate(transform, glm::vec3(am = am + 0.01f, 0.0f, 0.0f));
        unsigned int transformLoc = glGetUniformLocation(shaderProgram2, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(j * sizeof(unsigned int)));
        transform = glm::mat4(1.0f);
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
    }
    else if (reverse == 1 && am > drift && last1 < 2)
    {
        glm::mat4 transform;
        transform = glm::translate(transform, glm::vec3(am = am - distance / 20.833, 0.0f, 0.0f));
        unsigned int transformLoc = glGetUniformLocation(shaderProgram2, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(j * sizeof(unsigned int)));
        transform = glm::mat4(1.0f);
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        temporary = am;
    }
    else
    {
        if (reverse == 1)
        {
            delay = delay + 0.01f;
            if (delay >= 0.5f)
            {
                start = 1;
                reverse = 0;
                frontarrow = 2;
                if (last1 < 2)
                {
                    comparisonu++;
                    if (comparisonu >= 10)
                    {
                        comparisonu = 0;
                        comparisont++;
                    }
                }
            }
        }
        else if (wait == 0.0f && glag == 1)
        {
            delay = delay + 0.01f;
            if (delay >= 0.5f)
            {
                if (frontarrow == (7 - (passno - 2)))
                {
                    frontarrow = 2;
                    if (last1 < 2)
                    {
                        comparisonu++;
                        if (comparisonu >= 10)
                        {
                            comparisonu = 0;
                            comparisont++;
                        }
                    }
                }
                else
                {
                    frontarrow++;
                    if (last1 < 2)
                    {
                        comparisonu++;
                        if (comparisonu >= 10)
                        {
                            comparisonu = 0;
                            comparisont++;
                        }
                    }
                }
                glag = 0;
            }
        }
        glm::mat4 transform;
        transform = glm::translate(transform, glm::vec3(am, 0.0f, 0.0f));
        unsigned int transformLoc = glGetUniformLocation(shaderProgram2, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(j * sizeof(unsigned int)));
        transform = glm::mat4(1.0f);
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        if (swap[u + 1] + 1 != frontarrow && swap[u] != 8 && delay >= 0.5f)
        {
            wait = wait + 0.01f;
        }
        if (swap[u] == 8 && delay >= 0.5f)
        {
            wait = wait + 0.01f;
        }
        if (am >= distance && wait >= 0.5f)
        {
            reverse = 1;
            wait = 0.0f;
            drift = 0.0f;
            delay = 0.0f;
            if (swap[u] == 8)
            {
                last1++;
                if (last1 > 3)
                {
                    last1 = 3;
                }
            }
        }
        else if (wait >= 0.5f)
        {
            drift = drift + 0.25f;
            wait = 0.0f;
            temporary = am;
            delay = 0.0f;
        }
    }

    glDeleteTextures(1, &texture);
    free(data);
}
void slidingarrow1(int j, unsigned int shaderProgram2)
{
    unsigned int texture;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    float borderColor[] = { 0.2f, 0.3f, 0.3f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    char str[] = "bluarrow.jpg";
    if (u == 0)
    {
        value = -1;
    }
    else
    {
        value = swap[u - 2];
    }
    if (redblue == 0)
    {
        if (backarrow != 6 - (passno - 2))
        {
            if ((delay1 > 0.25f && delay1 < 0.5f && (swap[u] + 1 == backarrow + 1)) || ((delay1 >= 0.5f && wait1 == 0.0f) && (swap[u] + 1 == backarrow)) || ((delay1 >= 0.5f && wait1 >= 0.0f && wait1 < 0.25f) && (value + 1 == backarrow)))
            {
                str[0] = 'g';
                str[1] = 'r';
                str[2] = 'e';
                stbi_set_flip_vertically_on_load(false);
            }
            else if ((delay1 > 0.25f && delay1 < 0.5f && (swap[u] + 1 != backarrow + 1)) || ((delay1 >= 0.5f && wait1 >= 0.0f && wait1 < 0.25f) && (swap[u] + 1 != backarrow)))
            {
                str[0] = 'r';
                str[1] = 'e';
                str[2] = 'd';
                stbi_set_flip_vertically_on_load(true);
            }
            else
            {
                str[0] = 'b';
                str[1] = 'l';
                str[2] = 'u';
                stbi_set_flip_vertically_on_load(true);
            }
        }
        else
        {
            if ((delay1 > 0.25 && delay1 < 0.5 && (swap[u] + 1 == 1)) || ((delay1 >= 0.5f && wait1 == 0.0f) && (swap[u] + 1 == backarrow)) || ((delay1 >= 0.5f && wait1 >= 0.0f && wait1 < 0.25f) && (swap[u - 2] + 1 == backarrow)))
            {
                str[0] = 'g';
                str[1] = 'r';
                str[2] = 'e';
                stbi_set_flip_vertically_on_load(false);
            }
            else if ((delay1 > 0.25 && delay1 < 0.5 && (swap[u] + 1 != 1)) || ((delay1 >= 0.5f && wait1 >= 0.0f && wait1 < 0.25f) && (swap[u] + 1 != backarrow)))
            {
                str[0] = 'r';
                str[1] = 'e';
                str[2] = 'd';
                stbi_set_flip_vertically_on_load(true);
            }
            else
            {
                str[0] = 'b';
                str[1] = 'l';
                str[2] = 'u';
                stbi_set_flip_vertically_on_load(true);
            }

        }
    }
    else if (redblue == 1)
    {
        if ((delay1 > 0.25 && delay1 < 0.5) || (delay1 >= 0.5f && wait1 >= 0.0f && wait1 < 0.25f))
        {
            str[0] = 'r';
            str[1] = 'e';
            str[2] = 'd';
            stbi_set_flip_vertically_on_load(true);
        }
        else
        {
            str[0] = 'b';
            str[1] = 'l';
            str[2] = 'u';
            stbi_set_flip_vertically_on_load(true);
        }

    }

    int width, height, nrChannels;
    unsigned char* data = stbi_load(str, &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glUseProgram(shaderProgram2);
    if (bm < drift1 && last < 2)
    {
        if (temporary1 == bm)
        {
            if (reverse1 == 1)
            {
                reverse1 = 0;
                hlag = 1;
            }
            else
            {
                hlag = 1;
            }
        }
        glm::mat4 transform;
        transform = glm::translate(transform, glm::vec3(bm = bm + 0.01f, 0.0f, 0.0f));
        unsigned int transformLoc = glGetUniformLocation(shaderProgram2, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(j * sizeof(unsigned int)));
        transform = glm::mat4(1.0f);
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
    }
    else if (reverse1 == 1 && bm > drift1 && last < 2)
    {
        glm::mat4 transform;
        transform = glm::translate(transform, glm::vec3(bm = bm - distance / 20.833, 0.0f, 0.0f));
        unsigned int transformLoc = glGetUniformLocation(shaderProgram2, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(j * sizeof(unsigned int)));
        transform = glm::mat4(1.0f);
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        temporary1 = bm;
    }
    else
    {
        if (reverse1 == 1)
        {
            delay1 = delay1 + 0.01f;
            if (delay1 >= 0.5f)
            {
                start = 1;
                reverse1 = 0;
                backarrow = 1;
            }
        }
        else if (wait1 == 0.0f && hlag == 1)
        {
            delay1 = delay1 + 0.01f;
            if (delay1 >= 0.5f)
            {
                if (backarrow == (6 - (passno - 2)))
                {
                    backarrow = 1;
                }
                else
                {
                    backarrow++;
                }
                hlag = 0;
            }
        }
        glm::mat4 transform;
        transform = glm::translate(transform, glm::vec3(bm, 0.0f, 0.0f));
        unsigned int transformLoc = glGetUniformLocation(shaderProgram2, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(j * sizeof(unsigned int)));
        transform = glm::mat4(1.0f);
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        if (swap[u] != 8)
        {
            if (swap[u] + 1 != backarrow && delay1 >= 0.5f)
            {
                wait1 = wait1 + 0.01f;
            }
        }
        else if (swap[u] == 8 && delay1 >= 0.5f)
        {
            wait1 = wait1 + 0.01f;
        }
        if (bm >= distance && wait1 >= 0.5f)
        {
            reverse1 = 1;
            wait1 = 0.0f;
            drift1 = 0.0f;
            delay1 = 0.0f;
            if (swap[u] == 8)
            {
                last++;
                if (last == 3)
                {
                    last = 3;
                }
            }
        }
        else if (wait1 >= 0.5f)
        {
            if (swap[u] == 8)
            {
                redblue = 1;
            }
            drift1 = drift1 + 0.25f;
            wait1 = 0.0f;
            temporary1 = bm;
            delay1 = 0.0f;
        }
    }

    glDeleteTextures(1, &texture);
    free(data);
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        const wchar_t* exePath = L"Bubble Sort Simulator.exe";

        STARTUPINFO si = {};
        PROCESS_INFORMATION pi = {};

        int bufferSize = lstrlenW(exePath) + 1;
        LPWSTR writableExePath = new wchar_t[bufferSize];
        wcscpy_s(writableExePath, bufferSize, exePath);

        BOOL success = CreateProcess(
            NULL,
            writableExePath,
            NULL,
            NULL,
            FALSE,
            CREATE_NEW_PROCESS_GROUP,
            NULL,
            NULL,
            &si,
            &pi
        );

        if (success) {

            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
        else {

        }

        delete[] writableExePath;
    }
}
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    std::string filename = "array.txt";
    std::vector<int> inputVector;

    std::ifstream inputFile(filename);
    if (inputFile.is_open())
    {
        int num;
        while (inputFile >> num)
        {
            inputVector.push_back(num);
        }
        inputFile.close();
        for (size_t i = 0; i < inputVector.size(); ++i)
        {
            array[i] = inputVector[i];
            sorted[i] = inputVector[i];
        }
    }
    int size = sizeof(sorted) / sizeof(sorted[0]);
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < size; ++i)
        {
            if (sorted[i - 1] > sorted[i])
            {
                redblue = 0;
                std::swap(sorted[i - 1], sorted[i]);
                swap[s++] = i - 1;
                swap[s++] = i;
                swapped = true;
            }
        }
    } while (swapped);
    if (redblue == 1)
    {
        swap[u] = 8;
        last1++;
        last++;
    }
    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Bubble Sort Simulator", NULL, NULL);
    glfwMakeContextCurrent(window);
    int wi, he, cha;
    unsigned char* da = stbi_load("icon.png", &wi, &he, &cha, 4);
    GLFWimage icon[1];
    icon[0].width = wi;
    icon[0].height = he;
    icon[0].pixels = da;
    glfwSetWindowIcon(window, 1, icon);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSetKeyCallback(window, key_callback);
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    unsigned int vertexShader2 = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader2, 1, &vertexShaderSource2, NULL);
    glCompileShader(vertexShader2);
    unsigned int fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader2, 1, &fragmentShaderSource2, NULL);
    glCompileShader(fragmentShader2);
    unsigned int shaderProgram2 = glCreateProgram();
    glAttachShader(shaderProgram2, vertexShader2);
    glAttachShader(shaderProgram2, fragmentShader2);
    glLinkProgram(shaderProgram2);
    vertices[80] = -0.875f; vertices[81] = 0.875f; vertices[82] = 0.0f; vertices[83] = 0.0f; vertices[84] = 1.0f;
    vertices[85] = -0.875f; vertices[86] = 0.750f; vertices[87] = 0.0f; vertices[88] = 0.0f; vertices[89] = 0.0f;
    vertices[90] = 0.875f; vertices[91] = 0.875f; vertices[92] = 0.0f; vertices[93] = 1.0f; vertices[94] = 1.0f;
    vertices[95] = 0.875f; vertices[96] = 0.750f; vertices[97] = 0.0f; vertices[98] = 1.0f; vertices[99] = 0.0f;
    vertices[0] = -0.875f; vertices[1] = 0.0f; vertices[2] = 0.0f;
    vertices[5] = -0.875f; vertices[6] = 0.25f; vertices[7] = 0.0f; vertices[8] = 0.0f; vertices[9] = 1.0f;
    vertices[13] = 1.0f; vertices[14] = 0.0f;
    vertices[18] = 1.0f; vertices[19] = 1.0f;
    vertices[28] = 0.0f; vertices[29] = 1.0f;
    vertices[33] = 1.0f; vertices[34] = 0.0f;
    vertices[38] = 1.0f; vertices[39] = 1.0f;
    vertices[48] = 0.0f; vertices[49] = 1.0f;
    vertices[53] = 1.0f; vertices[54] = 0.0f;
    vertices[58] = 1.0f; vertices[59] = 1.0f;
    vertices[68] = 0.0f; vertices[69] = 1.0f;
    vertices[73] = 1.0f; vertices[74] = 0.0f;
    vertices[78] = 1.0f; vertices[79] = 1.0f;
    vertices[100] = -0.875f; vertices[101] = 0.46f; vertices[102] = 0.0f; vertices[103] = 0.0f; vertices[104] = 0.0f;
    vertices[105] = -0.875f; vertices[106] = 0.55f; vertices[107] = 0.0f; vertices[108] = 0.0f; vertices[109] = 1.0f;
    vertices[110] = -0.575f; vertices[111] = 0.46f; vertices[112] = 0.0f; vertices[113] = 1.0f; vertices[114] = 0.0f;
    vertices[115] = -0.575f; vertices[116] = 0.55f; vertices[117] = 0.0f; vertices[118] = 1.0f; vertices[119] = 1.0f;
    vertices[120] = -0.550f; vertices[121] = 0.465f; vertices[122] = 0.0f; vertices[123] = 0.0f; vertices[124] = 0.0f;
    vertices[125] = -0.550f; vertices[126] = 0.555f; vertices[127] = 0.0f; vertices[128] = 0.0f; vertices[129] = 1.0f;
    vertices[130] = -0.460f; vertices[131] = 0.465f; vertices[132] = 0.0f; vertices[133] = 1.0f; vertices[134] = 0.0f;
    vertices[135] = -0.460f; vertices[136] = 0.555f; vertices[137] = 0.0f; vertices[138] = 1.0f; vertices[139] = 1.0f;
    vertices[140] = -0.875f; vertices[141] = -0.25f; vertices[142] = 0.0f; vertices[143] = 0.0f; vertices[144] = 0.0f;
    vertices[145] = -0.875f; vertices[146] = 0.0f; vertices[147] = 0.0f; vertices[148] = 0.0f; vertices[149] = 1.0f;
    vertices[150] = -0.625f; vertices[151] = -0.25f; vertices[152] = 0.0f; vertices[153] = 1.0f; vertices[154] = 0.0f;
    vertices[155] = -0.625f; vertices[156] = 0.0f; vertices[157] = 0.0f; vertices[158] = 1.0f; vertices[159] = 1.0f;
    vertices[160] = -0.625f; vertices[161] = -0.25f; vertices[162] = 0.0f; vertices[163] = 0.0f; vertices[164] = 0.0f;
    vertices[165] = -0.625f; vertices[166] = 0.0f; vertices[167] = 0.0f; vertices[168] = 0.0f; vertices[169] = 1.0f;
    vertices[170] = -0.375f; vertices[171] = -0.25f; vertices[172] = 0.0f; vertices[173] = 1.0f; vertices[174] = 0.0f;
    vertices[175] = -0.375f; vertices[176] = 0.0f; vertices[177] = 0.0f; vertices[178] = 1.0f; vertices[179] = 1.0f;
    vertices[180] = -0.875f; vertices[181] = -0.50f; vertices[182] = 0.0f; vertices[183] = 0.0f; vertices[184] = 0.0f;
    vertices[185] = -0.875f; vertices[186] = -0.41f; vertices[187] = 0.0f; vertices[188] = 0.0f; vertices[189] = 1.0f;
    vertices[190] = 0.265f; vertices[191] = -0.50f; vertices[192] = 0.0f; vertices[193] = 1.0f; vertices[194] = 0.0f;
    vertices[195] = 0.265f; vertices[196] = -0.41f; vertices[197] = 0.0f; vertices[198] = 1.0f; vertices[199] = 1.0f;
    vertices[200] = 0.365f; vertices[201] = -0.50f; vertices[202] = 0.0f; vertices[203] = 0.0f; vertices[204] = 0.0f;
    vertices[205] = 0.365f; vertices[206] = -0.41f; vertices[207] = 0.0f; vertices[208] = 0.0f; vertices[209] = 1.0f;
    vertices[210] = 0.455f; vertices[211] = -0.50f; vertices[212] = 0.0f; vertices[213] = 1.0f; vertices[214] = 0.0f;
    vertices[215] = 0.455f; vertices[216] = -0.41f; vertices[217] = 0.0f; vertices[218] = 1.0f; vertices[219] = 1.0f;
    vertices[220] = 0.455f; vertices[221] = -0.50f; vertices[222] = 0.0f; vertices[223] = 0.0f; vertices[224] = 0.0f;
    vertices[225] = 0.455f; vertices[226] = -0.41f; vertices[227] = 0.0f; vertices[228] = 0.0f; vertices[229] = 1.0f;
    vertices[230] = 0.545f; vertices[231] = -0.50f; vertices[232] = 0.0f; vertices[233] = 1.0f; vertices[234] = 0.0f;
    vertices[235] = 0.545f; vertices[236] = -0.41f; vertices[237] = 0.0f; vertices[238] = 1.0f; vertices[239] = 1.0f;
    vertices[240] = -0.875f; vertices[241] = -0.75f; vertices[242] = 0.0f; vertices[243] = 0.0f; vertices[244] = 0.0f;
    vertices[245] = -0.875f; vertices[246] = -0.66f; vertices[247] = 0.0f; vertices[248] = 0.0f; vertices[249] = 1.0f;
    vertices[250] = -0.155f; vertices[251] = -0.75f; vertices[252] = 0.0f; vertices[253] = 1.0f; vertices[254] = 0.0f;
    vertices[255] = -0.155f; vertices[256] = -0.66f; vertices[257] = 0.0f; vertices[258] = 1.0f; vertices[259] = 1.0f;
    vertices[260] = 0.365f; vertices[261] = -0.75f; vertices[262] = 0.0f; vertices[263] = 0.0f; vertices[264] = 0.0f;
    vertices[265] = 0.365f; vertices[266] = -0.66f; vertices[267] = 0.0f; vertices[268] = 0.0f; vertices[269] = 1.0f;
    vertices[270] = 0.455f; vertices[271] = -0.75f; vertices[272] = 0.0f; vertices[273] = 1.0f; vertices[274] = 0.0f;
    vertices[275] = 0.455f; vertices[276] = -0.66f; vertices[277] = 0.0f; vertices[278] = 1.0f; vertices[279] = 1.0f;
    vertices[280] = 0.455f; vertices[281] = -0.75f; vertices[282] = 0.0f; vertices[283] = 0.0f; vertices[284] = 0.0f;
    vertices[285] = 0.455f; vertices[286] = -0.66f; vertices[287] = 0.0f; vertices[288] = 0.0f; vertices[289] = 1.0f;
    vertices[290] = 0.545f; vertices[291] = -0.75f; vertices[292] = 0.0f; vertices[293] = 1.0f; vertices[294] = 0.0f;
    vertices[295] = 0.545f; vertices[296] = -0.66f; vertices[297] = 0.0f; vertices[298] = 1.0f; vertices[299] = 1.0f;
    vertices[300] = 0.345f; vertices[301] = 0.46f; vertices[302] = 0.0f; vertices[303] = 0.0f; vertices[304] = 0.0f;
    vertices[305] = 0.345f; vertices[306] = 0.55f; vertices[307] = 0.0f; vertices[308] = 0.0f; vertices[309] = 1.0f;
    vertices[310] = 0.875f; vertices[311] = 0.46f; vertices[312] = 0.0f; vertices[313] = 1.0f; vertices[314] = 0.0f;
    vertices[315] = 0.875f; vertices[316] = 0.55f; vertices[317] = 0.0f; vertices[318] = 1.0f; vertices[319] = 1.0f;
    int i = 10;
    int n = 7;
    for (; i <= (((n + 1) * 2 - 1) * 5); i = i + 5)
    {
        vertices[i] = vertices[i - 10] + 0.25f;
        vertices[i + 1] = vertices[i - 9];
        vertices[i + 2] = vertices[i - 8];
    }
    i = i - 5;
    unsigned int indices[200] = { 0 };
    indices[0] = 0; indices[1] = 1; indices[2] = 2;
    int j = 3;
    for (; j < ((i / 5) - 1) * 3; j++)
    {
        indices[j] = indices[j - 3] + 1;
    }
    indices[j] = (n + 1) * 2;
    indices[j + 1] = (n + 1) * 2 + 1;
    indices[j + 2] = (n + 1) * 2 + 2;
    indices[j + 3] = (n + 1) * 2 + 1;
    indices[j + 4] = (n + 1) * 2 + 2;
    indices[j + 5] = (n + 1) * 2 + 3;
    indices[j + 6] = (n + 1) * 2 + 4;
    indices[j + 7] = (n + 1) * 2 + 5;
    indices[j + 8] = (n + 1) * 2 + 6;
    indices[j + 9] = (n + 1) * 2 + 5;
    indices[j + 10] = (n + 1) * 2 + 6;
    indices[j + 11] = (n + 1) * 2 + 7;
    indices[j + 12] = (n + 1) * 2 + 8;
    indices[j + 13] = (n + 1) * 2 + 9;
    indices[j + 14] = (n + 1) * 2 + 10;
    indices[j + 15] = (n + 1) * 2 + 9;
    indices[j + 16] = (n + 1) * 2 + 10;
    indices[j + 17] = (n + 1) * 2 + 11;
    indices[j + 18] = (n + 1) * 2 + 12;
    indices[j + 19] = (n + 1) * 2 + 13;
    indices[j + 20] = (n + 1) * 2 + 14;
    indices[j + 21] = (n + 1) * 2 + 13;
    indices[j + 22] = (n + 1) * 2 + 14;
    indices[j + 23] = (n + 1) * 2 + 15;
    indices[j + 24] = (n + 1) * 2 + 16;
    indices[j + 25] = (n + 1) * 2 + 17;
    indices[j + 26] = (n + 1) * 2 + 18;
    indices[j + 27] = (n + 1) * 2 + 17;
    indices[j + 28] = (n + 1) * 2 + 18;
    indices[j + 29] = (n + 1) * 2 + 19;
    indices[j + 30] = (n + 1) * 2 + 20;
    indices[j + 31] = (n + 1) * 2 + 21;
    indices[j + 32] = (n + 1) * 2 + 22;
    indices[j + 33] = (n + 1) * 2 + 21;
    indices[j + 34] = (n + 1) * 2 + 22;
    indices[j + 35] = (n + 1) * 2 + 23;
    indices[j + 36] = (n + 1) * 2 + 24;
    indices[j + 37] = (n + 1) * 2 + 25;
    indices[j + 38] = (n + 1) * 2 + 26;
    indices[j + 39] = (n + 1) * 2 + 25;
    indices[j + 40] = (n + 1) * 2 + 26;
    indices[j + 41] = (n + 1) * 2 + 27;
    indices[j + 42] = (n + 1) * 2 + 28;
    indices[j + 43] = (n + 1) * 2 + 29;
    indices[j + 44] = (n + 1) * 2 + 30;
    indices[j + 45] = (n + 1) * 2 + 29;
    indices[j + 46] = (n + 1) * 2 + 30;
    indices[j + 47] = (n + 1) * 2 + 31;
    indices[j + 48] = (n + 1) * 2 + 32;
    indices[j + 49] = (n + 1) * 2 + 33;
    indices[j + 50] = (n + 1) * 2 + 34;
    indices[j + 51] = (n + 1) * 2 + 33;
    indices[j + 52] = (n + 1) * 2 + 34;
    indices[j + 53] = (n + 1) * 2 + 35;
    indices[j + 54] = (n + 1) * 2 + 36;
    indices[j + 55] = (n + 1) * 2 + 37;
    indices[j + 56] = (n + 1) * 2 + 38;
    indices[j + 57] = (n + 1) * 2 + 37;
    indices[j + 58] = (n + 1) * 2 + 38;
    indices[j + 59] = (n + 1) * 2 + 39;
    indices[j + 60] = (n + 1) * 2 + 40;
    indices[j + 61] = (n + 1) * 2 + 41;
    indices[j + 62] = (n + 1) * 2 + 42;
    indices[j + 63] = (n + 1) * 2 + 41;
    indices[j + 64] = (n + 1) * 2 + 42;
    indices[j + 65] = (n + 1) * 2 + 43;
    indices[j + 66] = (n + 1) * 2 + 44;
    indices[j + 67] = (n + 1) * 2 + 45;
    indices[j + 68] = (n + 1) * 2 + 46;
    indices[j + 69] = (n + 1) * 2 + 45;
    indices[j + 70] = (n + 1) * 2 + 46;
    indices[j + 71] = (n + 1) * 2 + 47;
    unsigned int texture;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    float borderColor[] = { 0.2f, 0.3f, 0.3f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("BSS.jpg", &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(2);
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glBindVertexArray(VAO);
        if (flag == 1)
        {
            swapu++;
            if (swapu >= 10)
            {
                swapu = 0;
                swapt++;
            }
            back = swap[u];
            u = u + 2;
            front = swap[u];
            if (u == s)
            {
                swap[u] = 8;
                swap[u + 1] = 9;
            }
            flag = 0;
            h = 0.0f;
            g = 0.0f;
            c = 0.0f;
            d = 0.21f;
        }
        Title(j, shaderProgram2);
        Pass(j + 6, shaderProgram2);
        Passvalue(j + 12, shaderProgram2);
        slidingarrow1(j + 18, shaderProgram2);
        slidingarrow2(j + 24, shaderProgram2);
        NoC(j + 30, shaderProgram2);
        NoCt(j + 36, shaderProgram2);
        NoCu(j + 42, shaderProgram2);
        NoS(j + 48, shaderProgram2);
        NoSt(j + 54, shaderProgram2);
        NoSu(j + 60, shaderProgram2);
        unsorted(j + 66, shaderProgram2);
        for (int k = 0; k < n; k++)
        {
            if (k % 2 == 0)
            {
                draw(shaderProgram2, VAO, -1.0f, k * 6, swap[u] + 1, swap[u + 1] + 1);
            }
            else
            {
                draw(shaderProgram2, VAO, 1.0f, k * 6, swap[u] + 1, swap[u + 1] + 1);
            }
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    stbi_image_free(da);
    glfwTerminate();
    return 0;
}

