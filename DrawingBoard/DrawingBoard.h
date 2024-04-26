#ifndef DRAWINGBOARD_H
#define DRAWINGBOARD_H

#include <QWidget>
#include<QPainter>
#include<QToolButton>
#include<DrawWidget.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class DrawingboardWidget : public QWidget
{
    Q_OBJECT

public:
    DrawingboardWidget(QWidget *parent = nullptr);
    ~DrawingboardWidget();
    void resizeEvent(QResizeEvent *event) override;

protected slots:
    int fn_Recv_RectangleButton_Clicked();
     int fn_Recv_EllipseButton_Clicked();
     int fn_Recv_trangleButton_Clicked();
     int fn_Recv_lineButton_Clicked();
     int fn_Recv_TextButton_Clicked();
    int  fn_Recv_rotateLeftButton_Clicked();
     int  fn_Recv_rotateRightButton_Clicked();

private:
    QToolButton m_RectangleButton;//矩形按钮
    QToolButton m_EllipseButton;//椭圆按钮
    QToolButton m_trangleButton;//等边三角形按钮
    QToolButton m_lineButton;//直线按钮
    QToolButton m_TextButton;//文本框
    QToolButton m_resetZoomButton;//重置缩放按钮
    QToolButton m_rotateLeftButton;//左旋转
    QToolButton m_rotateRightButton;//右旋转


    DrawWidget m_DrawWidget;//绘画窗体
 } ;
#endif // DRAWINGBOARD_H
