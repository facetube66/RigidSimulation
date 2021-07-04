// RigidSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Inventor/Win/SoWin.h>
#include <Inventor/Win/viewers/SoWinExaminerViewer.h>
#include <Inventor/nodes/SoCube.h>

#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/nodes/SoSphere.h>
#include <iostream>
using namespace std;

int main(int, char** argv)
{
    // Draw the object read from the file
    HWND window = SoWin::init(argv[0]);
    if (window == NULL)
        exit(1);

    SoWinExaminerViewer* viewer = new SoWinExaminerViewer(window);
    SoSeparator* root = new SoSeparator;;
    SoSeparator* sphereSep = new SoSeparator;
    SoSphere* sphere = new SoSphere;
    sphere->radius = 0.00001;
    SoSeparator* object = new SoSeparator;
    SoTransform* trans = new SoTransform;
    SoCube* cube = new SoCube;

    SoInput sceneInput;
    if (!sceneInput.openFile("jackbox.iv")) {
        cout << "Cannot open input file, displaying empty scene" << endl;
    }
    else
    {
        object = SoDB::readAll(&sceneInput);
    }

    //root->addChild(object);
    root->addChild(trans);
    //root->addChild(sphere);
    cube->width = 2;
    cube->height = 1;
    cube->depth = 0.5;

    root->addChild(cube);

    viewer->setSceneGraph(root);
    viewer->setTitle("RIGId BODY SIMULATION");
    viewer->show();

    SoWin::show(window);
    SoWin::mainLoop();

    return 0;
}
