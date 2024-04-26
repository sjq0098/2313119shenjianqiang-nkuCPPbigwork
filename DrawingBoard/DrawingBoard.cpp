#include "DrawingBoard.h"
#include"sizestandard.h"


DrawingboardWidget::DrawingboardWidget(QWidget *parent)
    : QWidget(parent)
{//笔刷和橡皮擦将再2.0版本写出
    setWindowTitle(QStringLiteral("qtnote1.0"));
    setWindowIcon(QIcon(QString(":/icon/recourse/icon/note1.png")));



    m_RectangleButton.setParent(this);
    m_EllipseButton.setParent(this);
    m_trangleButton.setParent(this);
    m_lineButton.setParent(this);
    m_TextButton.setParent(this);
    m_resetZoomButton.setParent(this);
    m_rotateLeftButton.setParent(this);
    m_rotateRightButton.setParent(this);//设置父类
    m_DrawWidget.setParent(this);

    m_RectangleButton.setText(QString("矩形"));
    m_EllipseButton.setText(QString("椭圆"));
    m_trangleButton.setText(QString("三角形"));
    m_lineButton.setText(QString("直线"));
    m_TextButton.setText(QString("文本"));
    m_resetZoomButton.setText(QString("重置缩放"));
    m_rotateLeftButton.setText(QString("左旋转"));
    m_rotateRightButton.setText(QString("右旋转"));//设置文字


    m_RectangleButton.setIcon(QIcon(QString(":/icon/recourse/icon/rectangle.png")));
    m_RectangleButton.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    m_RectangleButton.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    m_EllipseButton.setIcon(QIcon(QString(":/icon/recourse/icon/Ellipse.png")));
    m_EllipseButton.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    m_EllipseButton.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    m_trangleButton.setIcon(QIcon(QString(":/icon/recourse/icon/triangle.png")));
    m_trangleButton.setIconSize(QSize(ICON_SIZE/2,ICON_SIZE/2));
    m_trangleButton.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    m_lineButton.setIcon(QIcon(QString(":/icon/recourse/icon/Line.png")));
    m_lineButton.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    m_lineButton.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    m_TextButton.setIcon(QIcon(QString(":/icon/recourse/icon/text.png")));
    m_TextButton.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    m_TextButton.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    m_resetZoomButton.setIcon(QIcon(QString(":/icon/recourse/icon/redo.png")));
    m_resetZoomButton.setIconSize(QSize(ICON_SIZE/2,ICON_SIZE/2));
    m_resetZoomButton.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    m_rotateLeftButton.setIcon(QIcon(QString(":/icon/recourse/icon/LeftRotate.png")));
    m_rotateLeftButton.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    m_rotateLeftButton.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    m_rotateRightButton.setIcon(QIcon(QString(":/icon/recourse/icon/RightRotate.png")));
    m_rotateRightButton.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    m_rotateRightButton.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QObject::connect(&m_RectangleButton, &QToolButton::clicked, this, &DrawingboardWidget::fn_Recv_RectangleButton_Clicked, Qt::DirectConnection);
    QObject::connect(&m_EllipseButton, &QToolButton::clicked, this, &DrawingboardWidget::fn_Recv_EllipseButton_Clicked, Qt::DirectConnection);
    QObject::connect(&m_trangleButton, &QToolButton::clicked, this, &DrawingboardWidget::fn_Recv_trangleButton_Clicked, Qt::DirectConnection);
    QObject::connect(&m_lineButton, &QToolButton::clicked, this, &DrawingboardWidget::fn_Recv_lineButton_Clicked, Qt::DirectConnection);
    QObject::connect(&m_TextButton, &QToolButton::clicked, this, &DrawingboardWidget::fn_Recv_TextButton_Clicked, Qt::DirectConnection);
    QObject::connect(&m_rotateLeftButton, &QToolButton::clicked, this, &DrawingboardWidget::fn_Recv_rotateLeftButton_Clicked, Qt::DirectConnection);
     QObject::connect(&m_rotateRightButton, &QToolButton::clicked, this, &DrawingboardWidget::fn_Recv_rotateRightButton_Clicked, Qt::DirectConnection);
}


DrawingboardWidget::~DrawingboardWidget()
{

}
void DrawingboardWidget::resizeEvent(QResizeEvent *event)
{
    m_RectangleButton.setGeometry(0,0,ICON_SIZE,ICON_SIZE);
    m_EllipseButton.setGeometry(0,1*ICON_SIZE,ICON_SIZE,ICON_SIZE);
    m_trangleButton.setGeometry(0,2*ICON_SIZE,ICON_SIZE,ICON_SIZE);
    m_lineButton.setGeometry(0,3*ICON_SIZE,ICON_SIZE,ICON_SIZE);
    m_TextButton.setGeometry(0,4*ICON_SIZE,ICON_SIZE,ICON_SIZE);
    m_resetZoomButton.setGeometry(0,5*ICON_SIZE,ICON_SIZE,ICON_SIZE);
    m_rotateLeftButton.setGeometry(0,6*ICON_SIZE,ICON_SIZE,ICON_SIZE);
    m_rotateRightButton.setGeometry(0,7*ICON_SIZE,ICON_SIZE,ICON_SIZE);
    m_DrawWidget.setGeometry(ICON_SIZE,5,width()-ICON_SIZE-5,height()-5);
    QWidget::resizeEvent(event);
}


int DrawingboardWidget::fn_Recv_RectangleButton_Clicked(){
    m_DrawWidget.SetShapeType(ShapeType::Shape_Rectangle);
    return NORMAL_RETURN;
}
int DrawingboardWidget::fn_Recv_EllipseButton_Clicked(){
    m_DrawWidget.SetShapeType(ShapeType::Shape_Ellipse);
    return NORMAL_RETURN;
}
int DrawingboardWidget::fn_Recv_trangleButton_Clicked(){
    m_DrawWidget.SetShapeType(ShapeType::Shape_Triangle);
    return NORMAL_RETURN;
}
int DrawingboardWidget::fn_Recv_lineButton_Clicked(){
    m_DrawWidget.SetShapeType(ShapeType::Shape_Line);
    return NORMAL_RETURN;
}
int DrawingboardWidget::fn_Recv_TextButton_Clicked(){
    m_DrawWidget.SetShapeType(ShapeType::Shape_Text);
    return NORMAL_RETURN;
}
int DrawingboardWidget::fn_Recv_rotateLeftButton_Clicked(){
    m_DrawWidget.RotateLeft();
    return NORMAL_RETURN;
}
int DrawingboardWidget::fn_Recv_rotateRightButton_Clicked(){
    m_DrawWidget.RotateRight();
    return NORMAL_RETURN;
}
