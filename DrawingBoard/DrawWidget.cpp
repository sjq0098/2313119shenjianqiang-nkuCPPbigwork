#include<DrawWidget.h>

DrawWidget::DrawWidget(QWidget*parent):QOpenGLWidget(parent){
    m_pSystemData=SystemData::GetSystemData();

    m_bLBtnClicked=false;
    m_Shapetype=ShapeType::Shape_Unknow;
    m_RotateType=Rotatetype::Rotate_0;
    m_BlackPen.setColor(QColor(0,0,0));

    m_NullBrush.setStyle(Qt::BrushStyle::NoBrush);
    m_WhiteBrush.setColor(QColor(255,255,255));
    m_WhiteBrush.setStyle(Qt::BrushStyle::SolidPattern);

    m_TextFont.setFamily(QString::fromUtf8("楷体"));
    m_TextFont.setPixelSize(30);
    m_ContentEdit.setParent(this);
    m_ContentEdit.hide();
   QObject::connect(&m_ContentEdit,&TextcontentEdit::Signal_GetContent,this,&DrawWidget::fn_Recv_ContentEdit_GetContent,Qt::DirectConnection);
}
DrawWidget::~DrawWidget(){

}
void DrawWidget::paintEvent(QPaintEvent *event){

    QOpenGLWidget::paintEvent(event);
    QPainter painter(this);
    painter.setPen(m_BlackPen);
    painter.setFont(m_TextFont);
    painter.setBrush(m_NullBrush);
    painter.setBrush(m_WhiteBrush);
    painter.drawRect(rect());



    switch (m_RotateType) {
    case(Rotatetype::Rotate_90):{
        painter.translate(width(),0);
        painter.rotate(90);
        break;

    }
    case(Rotatetype::Rotate_180):{
        painter.translate(width(),height());
        painter.rotate(180);
        break;
    }
    case(Rotatetype::Rotate_270):{
        painter.translate(0,height());
        painter.rotate(270);
        break;
    }
    default:{
        break;
    }
    }

    int iSize=m_pSystemData->m_ShapeVec.size();
    for(int i=0;i<iSize;i++){
        ShapeData* pShape=m_pSystemData->m_ShapeVec.at(i);
        switch (pShape->GetShapeType()) {
        case ShapeType::Shape_Rectangle: {
            RectangleData* pRectangle=static_cast<RectangleData *>(pShape);
            painter.drawRect(QRect(pRectangle->GetStartPosX(),pRectangle->GetStartPosY(),pRectangle->GetWidth(),pRectangle->GetHeight()));
            break;//shift修正将在2.0版本写出
            }
        case ShapeType::Shape_Ellipse:{
            EllipseData* pEllipse=static_cast< EllipseData*>(pShape);
            painter.drawEllipse(QRectF(pEllipse->GetStartPosX(),pEllipse->GetStartPosY(),pEllipse->GetRadiusW(),pEllipse->GetRadiusH()));
            break;
            }
        case ShapeType::Shape_Triangle:{
             TriangleData* pTriangle=static_cast< TriangleData*>(pShape);

            QPoint point1(pTriangle->GetStartPosX(),pTriangle->GetStartPosY());
            QPoint point2(pTriangle->GetStartPosX()+qAbs(pTriangle->GetTriangleW()/2),pTriangle->GetStartPosY()-qAbs(pTriangle->GetTriangleH()));
            QPoint point3(pTriangle->GetStartPosX()+qAbs(pTriangle->GetTriangleW()),pTriangle->GetStartPosY());
            painter.drawLine(point1,point2);
            painter.drawLine(point1,point3);
            painter.drawLine(point2,point3);
            break;
            }
        case ShapeType::Shape_Line:{
            LineData* pLineData=static_cast< LineData*>(pShape);
           QPoint point1(pLineData->GetStartPosX(),pLineData->GetStartPosY());
           QPoint point2(pLineData->GetEndPosX(),pLineData->GetEndPosY());
           painter.drawLine(point1,point2);
           break;
            }
        case ShapeType::Shape_Text:{
         Textdata* pTextData=static_cast<Textdata*>(pShape);
         painter.drawText(QPointF(pTextData->GetStartPosX(),pTextData->GetStartPosY()),pTextData->GetQstr_content());
         break;
         }
        default:{};
        }
    //进行数据渲染、绘画
    }


    if(m_bLBtnClicked){
        switch (m_Shapetype) {
        case ShapeType::Shape_Rectangle: {
            painter.drawRect(QRectF(m_ClickedPoint,m_MovePoint));
            break;
            }
        case ShapeType::Shape_Ellipse:{
            painter.drawEllipse(QRectF(m_ClickedPoint,m_MovePoint));
            break;
            }
        case ShapeType::Shape_Triangle:{
            double iX1=m_ClickedPoint.x()<m_MovePoint.x()?m_ClickedPoint.x():m_MovePoint.x();
            double iY1=m_ClickedPoint.y()>m_MovePoint.y()?m_ClickedPoint.y():m_MovePoint.y();
            QPoint dis=m_MovePoint-m_ClickedPoint;

            QPoint point1(iX1,iY1);
            QPoint point2(iX1+qAbs(dis.x()/2),iY1-qAbs(dis.y()));
            QPoint point3(iX1+qAbs(dis.x()),iY1);
            painter.drawLine(point1,point2);
            painter.drawLine(point1,point3);
            painter.drawLine(point2,point3);
            break;
            }
        case ShapeType::Shape_Line:{
            double iX1=m_ClickedPoint.x();
            double iY1=m_ClickedPoint.y();
            double iX2=m_MovePoint.x();
            double iY2=m_MovePoint.y();
            QPoint point1(iX1,iY1);
             QPoint point2(iX2,iY2);
              painter.drawLine(point1,point2);
            break;
            }
        case ShapeType::Shape_Text:{

            break;
        }
        default:{};
        }
    }


}
void DrawWidget::resizeEvent(QResizeEvent *event){
    QOpenGLWidget::resizeEvent(event);
    //
}



void DrawWidget:: mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::MouseButton::LeftButton){
        m_bLBtnClicked=true;
        m_ClickedPoint=event->pos();
        m_MovePoint=m_ClickedPoint;
    }
    QOpenGLWidget::mousePressEvent(event);
} ;


void DrawWidget:: mouseReleaseEvent(QMouseEvent*event){
    QOpenGLWidget::mouseReleaseEvent(event);
     if(event->button()==Qt::MouseButton::LeftButton){
         m_bLBtnClicked=false;
         m_MovePoint=event->pos();
         switch(m_Shapetype){
         case ShapeType::Shape_Rectangle: {
             double iX1=m_ClickedPoint.x()<m_MovePoint.x()?m_ClickedPoint.x():m_MovePoint.x();
             double iY1=m_ClickedPoint.y()<m_MovePoint.y()?m_ClickedPoint.y():m_MovePoint.y();


             QPoint dis=m_MovePoint-m_ClickedPoint;
             RectangleData* pRectangle= new RectangleData(double(iX1),double(iY1),qAbs(double(dis.x())),qAbs(double(dis.y())));
            m_pSystemData->m_ShapeVec.push_back(pRectangle);
            update();
            break;
                }
         case ShapeType::Shape_Ellipse:{
                 double iX1=m_ClickedPoint.x()<m_MovePoint.x()?m_ClickedPoint.x():m_MovePoint.x();
                 double iY1=m_ClickedPoint.y()<m_MovePoint.y()?m_ClickedPoint.y():m_MovePoint.y();

                 QPoint dis=m_MovePoint-m_ClickedPoint;
                 EllipseData* pEllipse= new EllipseData(double(iX1),double(iY1),qAbs(double(dis.x())),qAbs(double(dis.y())));
                m_pSystemData->m_ShapeVec.push_back(pEllipse);
                update();
                break;
                }
         case ShapeType::Shape_Triangle:{
             double iX1=m_ClickedPoint.x()<m_MovePoint.x()?m_ClickedPoint.x():m_MovePoint.x();
             double iY1=m_ClickedPoint.y()>m_MovePoint.y()?m_ClickedPoint.y():m_MovePoint.y();

            QPoint dis=m_MovePoint-m_ClickedPoint;
            TriangleData* pTriangle= new TriangleData(double(iX1),double(iY1),qAbs(double(dis.x())),qAbs(double(dis.y())));
            m_pSystemData->m_ShapeVec.push_back(pTriangle);
            update();
            break;

         }
         case ShapeType::Shape_Line:{
             double iX1=m_ClickedPoint.x();
             double iY1=m_ClickedPoint.y();
             double iX2=m_MovePoint.x();
             double iY2=m_MovePoint.y();

            LineData* pLineData= new LineData(double(iX1),double(iY1),iX2,iY2);
            m_pSystemData->m_ShapeVec.push_back(pLineData);
            update();
            break;
            }
         case ShapeType::Shape_Text:{
             if(m_ContentEdit.isHidden()){
                 m_TextPoint=m_MovePoint;
                 m_ContentEdit.clear();
                 m_ContentEdit.show();
                 m_ContentEdit.setGeometry(m_TextPoint.x(),m_TextPoint.y()-50,400,50);//记得回来调参数
                 m_ContentEdit.setFocus();
             }
             else{
                 m_ContentEdit.hide();
             }
             break;
            }
         default:{};

     }
};

}

void DrawWidget:: mouseMoveEvent(QMouseEvent*event){
    if(m_bLBtnClicked){
        m_MovePoint=event->pos();
        update();
    }
};



int DrawWidget::fn_Recv_ContentEdit_GetContent(const QString &qstrContent){
    Textdata*pText=new Textdata(double(m_TextPoint.x()),double(m_TextPoint.y()),qstrContent);
    m_pSystemData->m_ShapeVec.push_back(pText);
    update();
    return NORMAL_RETURN;
}
int DrawWidget:: RotateLeft(){
    switch (m_RotateType) {
    case(Rotatetype::Rotate_90):{
        m_RotateType=Rotatetype::Rotate_0;
        break;
    }
    case(Rotatetype::Rotate_180):{
        m_RotateType=Rotatetype::Rotate_90;
        break;
    }
    case(Rotatetype::Rotate_270):{
        m_RotateType=Rotatetype::Rotate_180;
        break;
    }
    case(Rotatetype::Rotate_0):{
        m_RotateType=Rotatetype::Rotate_270;
        break;
    }

    }
    update();
    return NORMAL_RETURN;

}

int DrawWidget::RotateRight(){
    switch (m_RotateType) {
    case(Rotatetype::Rotate_90):{
        m_RotateType=Rotatetype::Rotate_180;
        break;
    }
    case(Rotatetype::Rotate_180):{
        m_RotateType=Rotatetype::Rotate_270;
        break;
    }
    case(Rotatetype::Rotate_270):{
        m_RotateType=Rotatetype::Rotate_0;
        break;
    }
    case(Rotatetype::Rotate_0):{
        m_RotateType=Rotatetype::Rotate_90;
        break;
    }

    }
    update();
    return NORMAL_RETURN;

}
