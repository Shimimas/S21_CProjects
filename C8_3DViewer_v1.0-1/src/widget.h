#ifndef WIDGET_H
#define WIDGET_H

#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QQuaternion>
#include <QTimer>
#include <QWidget>

#include "geometry.h"

class GeometryEngine;


class Widget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  using QOpenGLWidget::QOpenGLWidget;
  QColor *color = new QColor(0, 0, 0, 255);
  QColor *color_back = new QColor(255, 255, 255, 255);
  QColor *color_ver = new QColor(17, 242, 0, 255);

  ~Widget();
  GeometryEngine *geometries = nullptr;
  QOpenGLShaderProgram program;
  void initColors();
  void initColorsVer();
  void updating();
  void paintGL() override;
  void resizeGL(int w, int h) override;



 protected:
  void initShaders();

  void initializeGL() override;

 private:
  QMatrix4x4 projection;
  QQuaternion rotation;

  QVector2D mousePressPosition;
  qreal angularSpeed = 0;
};

#endif  // WIDGET_H
