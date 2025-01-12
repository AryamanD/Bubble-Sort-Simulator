#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>
#include <windows.h>
using namespace std;
int width = 800;
int height = 640;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 500;
int whichwindow = 0;
std::vector<int> inputArray;
std::string userInput = "";
bool inputComplete = false;
void startProgram()
{
    whichwindow = 1;
    glutPostRedisplay();
}
void drawText(const char* text, float x, float y) {
    glRasterPos2f(x, y);
    for (int i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
    }
}
void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GLUT_SINGLE | GLUT_RGB);
    glLoadIdentity();
    glViewport(0, 0, 800, 500);
    glOrtho(-90.0, 100.0, -15.0, 100.0, 0.0, 1.0);
}
void renderbitmap(float x, float y, void* font, char* string)
{
    char* c;
    glRasterPos2f(x, y);

    for (c = string; *c != '\0'; c++)
    {
        if (*c == '\n')
        {
            y -= 5.0;
            glRasterPos2f(x, y);
            continue;
        }
        glutBitmapCharacter(font, *c);
    }
}
void introscreen()
{
    glColor3f(1.f, 1.f, 1.f);
    char buf[500] = { 0 };
    sprintf_s(buf, "Bubble Sort Algorithm");
    renderbitmap(-30, 90, GLUT_BITMAP_TIMES_ROMAN_24, buf);
    sprintf_s(buf, "Bubble sort, sometimes referred to as sinking sort,is a simple sorting\nalgorithm that repeatedly steps through the input list element by element,\ncomparing the current element with the one after it, swapping their values\nif needed. These passes through the list are repeated until no swaps had to\nbe performed during a pass, meaning that the list has become fully sorted.\nThe algorithm, which is a comparison sort, is named for the way the larger\nelements bubble up to the top of the list.");
    renderbitmap(-80, 80, GLUT_BITMAP_TIMES_ROMAN_24, buf);
    sprintf_s(buf, "Time-Complexity");
    renderbitmap(-80, 40, GLUT_BITMAP_TIMES_ROMAN_24, buf);
    sprintf_s(buf, "Best-case: O(n)\nAverage-case: O(n^2)\nWorst-case: O(n^2)");
    renderbitmap(-80, 33, GLUT_BITMAP_TIMES_ROMAN_24, buf);
    sprintf_s(buf, "Space-Complexity");
    renderbitmap(-80, 10, GLUT_BITMAP_TIMES_ROMAN_24, buf);
    sprintf_s(buf, "Auxiliary space: O(1)");
    renderbitmap(-80, 3, GLUT_BITMAP_TIMES_ROMAN_24, buf);
}

int selectedOption = 0;
const int MENU_START = 0;
const int MENU_ABOUT = 1;
const int MENU_CREDITS = 2;

void aboutProgram()
{
    whichwindow = 2;
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutPostRedisplay();
}

void creditsProgram()
{
    whichwindow = 3;
    glutPostRedisplay();
}

void drawMenuItem(const char* text, int y)
{
    int textWidth = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)text);
    int screenWidth = 550;
    int x = (screenWidth - textWidth) / 2;

    if (selectedOption == MENU_START && strcmp(text, "Start") == 0)
    {
        glRasterPos2i(x - 20, y);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '>');
    }
    else if (selectedOption == MENU_ABOUT && strcmp(text, "About") == 0)
    {
        glRasterPos2i(x - 20, y);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '>');
    }
    else if (selectedOption == MENU_CREDITS && strcmp(text, "Credits") == 0)
    {
        glRasterPos2i(x - 20, y);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '>');
    }

    glRasterPos2i(x, y);
    glColor3f(1.0, 1.0, 1.0);

    while (*text)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text++);
    }
}
void writeArrayToFile(const std::vector<int>& inputArray, const std::string& filename) {
    std::ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (int num : inputArray) {
            outputFile << num << " ";
        }
        outputFile.close();
    }
    else {
    }
}

void draw()
{
    if (whichwindow == 0)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        int screenWidth = 550;
        int screenHeight = 388;
        glViewport((glutGet(GLUT_WINDOW_WIDTH) - screenWidth) / 2, (glutGet(GLUT_WINDOW_HEIGHT) - screenHeight) / 2, screenWidth, screenHeight);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, screenWidth, 0, screenHeight);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        int menuItemHeight = 30;
        int menuTop = (screenHeight - (menuItemHeight * 3)) / 2;
        int menuItemPadding = 11;

        const char* heading = "   Bubble Sort Simulator";
        int headingTextWidth = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)heading);
        int headingX = (screenWidth - headingTextWidth) / 2;
        int headingY = menuTop + (menuItemHeight + menuItemPadding) * 3 + 90;
        int boxWidth = headingTextWidth + 20;
        int boxHeight = 60;

        glColor3f(1.0, 1.0, 1.0);
        glLineWidth(2);
        glBegin(GL_LINE_LOOP);
        glVertex2i(headingX - 10, headingY + boxHeight);
        glVertex2i(headingX + boxWidth + 10, headingY + boxHeight);
        glVertex2i(headingX + boxWidth + 10, headingY - 10);
        glVertex2i(headingX - 10, headingY - 10);
        glEnd();

        glLineWidth(2);
        glBegin(GL_LINES);
        glVertex2i(headingX - 10, headingY + boxHeight - 35);
        glVertex2i(headingX + boxWidth + 10, headingY + boxHeight - 35);
        glEnd();

        glRasterPos2i(headingX, headingY);
        glColor3f(1.0, 1.0, 1.0);
        while (*heading)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *heading++);
        }

        drawMenuItem("Start", menuTop + (menuItemHeight + menuItemPadding) * 2);
        drawMenuItem("About", menuTop + menuItemHeight + menuItemPadding);
        drawMenuItem("Credits", menuTop);

        glFlush();
    }
    else if (whichwindow == 1)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        int centerX = WINDOW_WIDTH / 2;
        int centerY = WINDOW_HEIGHT / 2;

        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(WINDOW_WIDTH, 0);
        glVertex2f(WINDOW_WIDTH, WINDOW_HEIGHT);
        glVertex2f(0, WINDOW_HEIGHT);
        glEnd();

        glColor3f(0.0, 0.0, 0.0);
        int instructionsBoxWidth = 400;
        int instructionsBoxHeight = 50;
        int instructionsBoxX = centerX - instructionsBoxWidth / 2;
        int instructionsBoxY = centerY + 170;
        glRecti(instructionsBoxX, instructionsBoxY, instructionsBoxX + instructionsBoxWidth, instructionsBoxY - instructionsBoxHeight);

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2i(centerX - 180, centerY + 200);
        std::string instructions = "Enter 7 one digit numbers and press Enter. Backspace to delete.";
        for (char c : instructions)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
        }

        glRasterPos2i(centerX - 150, centerY + 150);
        std::string inputLabel = "Enter number " + std::to_string(inputArray.size() + 1);
        for (char c : inputLabel)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }

        glRasterPos2i(centerX - 150, centerY + 120);
        for (char c : userInput)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }

        glColor3f(1.0, 1.0, 1.0);
        glLineWidth(2.0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        int boxWidth = 80;
        int boxHeight = 80;
        int startX = centerX - (inputArray.size() * (boxWidth + 10)) / 2;
        int startY = centerY - boxHeight / 2;

        for (size_t i = 0; i < inputArray.size(); ++i)
        {
            glRecti(startX + i * (boxWidth + 10), startY, startX + i * (boxWidth + 10) + boxWidth, startY + boxHeight);

            glColor3f(1.0, 1.0, 1.0);
            std::stringstream ss;
            ss << inputArray[i];
            std::string numStr = ss.str();
            glRasterPos2i(startX + i * (boxWidth + 10) + 15, startY + 25);
            for (char c : numStr)
            {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
            }
        }

        if (inputComplete)
        {
            glColor3f(0.0, 1.0, 0.0);
            std::string completeMessage = "Input complete!";
            int messageWidth = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<const unsigned char*>(completeMessage.c_str()));
            glRasterPos2i(centerX - messageWidth / 2, centerY - 200);
            for (char c : completeMessage)
            {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
            }
            glutPostRedisplay();
            writeArrayToFile(inputArray, "array.txt");
            whichwindow = 4;
        }

        glFlush();

    }
    else if (whichwindow == 2)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glMatrixMode(GL_PROJECTION | GLUT_RGB);
        glLoadIdentity();
        glViewport(0, 0, 800, 500);
        glOrtho(-90.0, 100.0, -15.0, 100.0, 0.0, 1.0);

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(-88.0f, -13.0f);
        glVertex2f(98.0f, -13.0f);
        glVertex2f(98.0f, 98.0f);
        glVertex2f(-88.0f, 98.0f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex2f(30.0f, 87.0f);
        glVertex2f(-38.0f, 87.0f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex2f(-80.0f, 39.0f);
        glVertex2f(-37.0f, 39.0f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex2f(-80.0f, 9.0f);
        glVertex2f(-37.0f, 9.0f);
        glEnd();

        introscreen();

        glFlush();
        glutPostRedisplay();
    }
    else if (whichwindow == 3)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0, 1.0, 1.0);
        const char* CreditText = "Credits";
        int textWidth1 = glutBitmapLength(GLUT_BITMAP_9_BY_15, (const unsigned char*)CreditText);
        float xPos1 = -0.15;
        float yPos1 = 1.0;

        drawText(CreditText, xPos1, yPos1);

        drawText("Aryaman Datta            gingeraryaman@gmail.com", -0.75, 0.5);

        drawText("Abdul Rab", -0.75, 0.3);

        drawText("Hajira Zuha", -0.75, 0.1);

        const char* instituteText = "Atria Institute of Technology, 2023";
        int textWidth = glutBitmapLength(GLUT_BITMAP_9_BY_15, (const unsigned char*)instituteText);
        float xPos = -0.6;
        float yPos = -0.7;

        drawText(instituteText, xPos, yPos);

        glFlush();

    }
    else if (whichwindow == 4)
    {
        const wchar_t* exePath = L"BSS.exe";

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
        glutDestroyWindow(glutGetWindow());
        system("cls");
        exit(0);
    }
}

void handleKeypress(unsigned char key, int x, int y)
{
    if (whichwindow == 0)
    {
        switch (key)
        {
        case 13:
            switch (selectedOption)
            {
            case MENU_START:
                startProgram();
                break;
            case MENU_ABOUT:
                aboutProgram();
                break;
            case MENU_CREDITS:
                creditsProgram();
                break;
            }
            break;
        default:
            break;
        }
    }
    else if (whichwindow == 1)
    {
        if (inputComplete)
        {
            return;
        }

        if (isdigit(key))
        {
            userInput += key;
        }
        else if (key == '\r')
        {
            if (!userInput.empty())
            {
                int num = std::atoi(userInput.c_str());
                inputArray.push_back(num);
                userInput = "";
                if (inputArray.size() >= 7)
                {
                    inputComplete = true;
                }
            }
        }
        else if (key == '\b')
        {
            if (!userInput.empty())
            {
                userInput.pop_back();
            }
        }
        else if (key == 109)
        {
            whichwindow = 0;
            inputArray.clear();
            glutPostRedisplay();
        }

        glutPostRedisplay();
    }
    else if (whichwindow > 1 && whichwindow < 4)
    {
        if (key == 13 || key == 109)
        {
            whichwindow = 0;
            glutPostRedisplay();
        }
    }
    else
    {

    }
}

void handleSpecialKeypress(int key, int x, int y)
{
    if (whichwindow == 0)
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            selectedOption = (selectedOption - 1 + 3) % 3;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            selectedOption = (selectedOption + 1) % 3;
            glutPostRedisplay();
            break;
        default:
            break;
        }
    }
}
void handleReshape(int w, int h)
{
    glutReshapeWindow(800, 500);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    int argc = 1;
    char* argv[1] = { (char*)"BubbleSortSimulator" };
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Bubble Sort Simulator");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutDisplayFunc(draw);
    glutReshapeFunc(handleReshape);
    glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(handleSpecialKeypress);
    glutMainLoop();
    return 0;
}