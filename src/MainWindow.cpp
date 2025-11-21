//[]---------------------------------------------------------------[]
//|                                                                 |
//| Copyright (C) 2022 Paulo Pagliosa.                              |
//|                                                                 |
//| This software is provided 'as-is', without any express or       |
//| implied warranty. In no event will the authors be held liable   |
//| for any damages arising from the use of this software.          |
//|                                                                 |
//| Permission is granted to anyone to use this software for any    |
//| purpose, including commercial applications, and to alter it and |
//| redistribute it freely, subject to the following restrictions:  |
//|                                                                 |
//| 1. The origin of this software must not be misrepresented; you  |
//| must not claim that you wrote the original software. If you use |
//| this software in a product, an acknowledgment in the product    |
//| documentation would be appreciated but is not required.         |
//|                                                                 |
//| 2. Altered source versions must be plainly marked as such, and  |
//| must not be misrepresented as being the original software.      |
//|                                                                 |
//| 3. This notice may not be removed or altered from any source    |
//| distribution.                                                   |
//|                                                                 |
//[]---------------------------------------------------------------[]
//
// OVERVIEW: MainWindow.cpp
// ========
// Source file for cg template window.
//
// Author: Paulo Pagliosa
// Last revision: 07/11/2022

#include "MainWindow.h"
#include "CentralSphere.h"
#include "GoldSphere.h"
#include "Ground.h"

/////////////////////////////////////////////////////////////////////
//
// MainWindow implementation
// ==========
MainWindow::MainWindow(int width, int height):
  Base{"P2 Wilker e José", width, height}
{

}

void
MainWindow::initialize()
{
  Base::initialize();

  raycaster = std::make_unique<Raycaster>(width(), height());

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_POLYGON_OFFSET_FILL);
  glPolygonOffset(1.0f, 1.0f);

  sceneManager.createScene("main",
    new CentralSphere(),
    new Ground(),
    new GoldSphere()
  );

  sceneManager.addLight("main", { 6, -4, 1}, cg::Color::red);
  sceneManager.addLight("main", { 10, 25, 10}, cg::Color::magenta * 0.7f);

  sceneManager.setActiveScene("main");

  if (auto* scene = sceneManager.getActiveScene()) 
    raycaster->render(*scene);

}

void
MainWindow::update()
{
  
  sceneManager.update(deltaTime());

}

void
MainWindow::renderScene()
{
  
  using namespace cg;

  auto g3 = this->g3();
    
  if (raycaster && raycaster->getImage())
    raycaster->getImage()->draw(0, 0);
    
}

bool
MainWindow::keyInputEvent(int key, int action, int mods)
{
  return Base::keyInputEvent(key, action, mods);
}

void
MainWindow::gui()
{
}