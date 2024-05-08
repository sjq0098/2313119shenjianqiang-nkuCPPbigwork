#include<DrawWidget.h>

DrawWidget::DrawWidget(QWidget*parent):QWidget(parent){


    m_openButton.setParent(this);
    m_openButton.setText(QString("打开"));
    m_openButton.setIcon(QIcon(QString(":/icon/recourse/icon/open.png")));
    m_openButton.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    m_openButton.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);


    m_keepButton.setParent(this);
    m_keepButton.setText(QString("保存"));
    m_keepButton.setIcon(QIcon(QString(":/icon/recourse/icon/keep.png")));
    m_keepButton.setIconSize(QSize(ICON_SIZE,ICON_SIZE));
    m_keepButton.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    m_pSystemData=SystemData::GetSystemData();

    m_bLBtnClicked=false;
    m_Shapetype=ShapeType::Shape_Unknow;
    m_RotateType=Rotatetype::Rotate_0;
    m_isdraw=0;

    m_NullBrush.setStyle(Qt::BrushStyle::NoBrush);
    m_BlackPen.setColor(QColor(0,0,0));
    m_BlackPen.setWidth(5);





    m_TextFont.setFamily(QString::fromUtf8("华文行楷"));
    m_TextFont.setPixelSize(30);
    m_ContentEdit.setParent(this);
    m_ContentEdit.hide();
    _openflag=0;

   QObject::connect(&m_ContentEdit,&TextcontentEdit::Signal_GetContent,this,&DrawWidget::fn_Recv_ContentEdit_GetContent,Qt::DirectConnection);
   QObject::connect(&m_openButton, &QToolButton::clicked, this, &DrawWidget::OpenPic, Qt::DirectConnection);
   QObject::connect(&m_keepButton, &QToolButton::clicked, this, &DrawWidget::SavePic, Qt::DirectConnection);

}
DrawWidget::~DrawWidget(){

};
void DrawWidget::paintEvent(QPaintEvent *event){

    if(_openflag == 0)//不是打开图片的，每一次新建一个空白的画布
    {

        _pixmap = QPixmap(size());//新建pixmap
        _pixmap.fill(Qt::white);//背景色填充为白色
    }

    QPixmap pix = _pixmap;//以_pixmap作为画布
    QPainter painter(&pix);//将_pixmap作为画布
    QPainter pw(&pix);
    pw.setPen(m_WhitePen);
    painter.setPen(m_BlackPen);
    painter.setFont(m_TextFont);
    painter.setBrush(m_NullBrush);

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
            break;
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
        case ShapeType::Shape_Pencil:{
        PencilData *pPencil=static_cast< PencilData*>(pShape);

        painter.drawPath(pPencil->Getdrawpath());
        break;
        }

        default:{break;};
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
        case ShapeType::Shape_Pencil:{
        painter.drawPath(drawingPath1);
        break;
        }
        default:{break;};
        }

    }
    painter.end();
    painter.begin(this);
    painter.drawPixmap(0,0, pix);//将pixmap画到窗体
}
void DrawWidget::resizeEvent(QResizeEvent *event){
     m_openButton.setGeometry(width()-ICON_SIZE,0,ICON_SIZE,ICON_SIZE);
     m_keepButton.setGeometry(width()-2*ICON_SIZE,0,ICON_SIZE,ICON_SIZE);
    QWidget::resizeEvent(event);
    //
}



void DrawWidget:: mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::MouseButton::LeftButton){
        m_bLBtnClicked=true;
        m_ClickedPoint=event->pos();
        m_MovePoint=m_ClickedPoint;
        if(m_isdraw){
            drawingPath1.moveTo(event->pos());
        }

    }
    QWidget::mousePressEvent(event);
} ;


void DrawWidget:: mouseReleaseEvent(QMouseEvent*event){
    QWidget::mouseReleaseEvent(event);
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
         }
        case ShapeType::Shape_Pencil:{
            PencilData* pPencilData= new PencilData(drawingPath1);
            m_pSystemData->m_ShapeVec.push_back(pPencilData);
            update();
        }
         default:{break;};
        }

    }

}

void DrawWidget:: mouseMoveEvent(QMouseEvent*event){
    if(m_bLBtnClicked){
        m_MovePoint=event->pos();
        if(m_isdraw){
            drawingPath1.lineTo(event->pos());
        }
    }
    update();

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
int DrawWidget::SavePic(){
    //弹出文件保存对话框
    QString fileName = QFileDialog::getSaveFileName(this, tr("保存"), "new.jpg", "Image (*.jpg *.png *.bmp)");

    if (fileName.length() > 0)
    {
        m_ContentEdit.hide();//防止文本输入框显示时，将文本框保存到图片
        QPixmap pixmap(size());//新建窗体大小的pixmap
        QPainter painter(&pixmap);//将pixmap作为画布
        painter.fillRect(QRect(0, 0, size().width(), size().height()), Qt::white);//设置绘画区域、画布颜色
        this->render(&painter);//将窗体渲染到painter，再由painter画到画布
        pixmap.copy(QRect(0,30,size().width(),size().height()-30)).save(fileName);//不包含工具栏
    }
    return NORMAL_RETURN;
}
//保存图片


int DrawWidget::OpenPic(){
    //弹出文件打开对话框
    QString picPath = QFileDialog::getOpenFileName(this,tr("打开"),"","Image Files(*.jpg *.png)");
    if(!picPath.isEmpty())//用户选择了文件
    {
        QPixmap pix;
        pix.load(picPath);//加载图片
        QPainter p(&_pixmap);
        p.drawPixmap(0,0,pix);//添加工具栏的空间
        _openflag = 1;//设置文件打开标志
        update();//触发窗体重绘，将图片画到窗体
    }
    return NORMAL_RETURN;
}//打开图片

