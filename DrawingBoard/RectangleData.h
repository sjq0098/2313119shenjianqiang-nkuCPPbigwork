#ifndef RECTANGLEDATA_H
#define RECTANGLEDATA_H

#include<shapedata.h>
class RectangleData:public ShapeData{
public:
    /*
     * 接口说明：公共接口，无参构造函数
     * 参数说明：无
     * 返回值说明：无
     */
    RectangleData();
    /*
     * 接口说明：公共接口，有参构造函数
     * 参数说明： [in]   dPosX起点横坐标
     *          [in]    dPosY起点纵坐标
     *          [in]    dWidth宽度
     *          [in]    dHeight高度
     * 返回值说明：无
     */
    RectangleData(const double& dPosX,const double&dPosY,const double &dWidth,const double &dHeight);
    /*
     * 接口说明：公共接口，析构函数
     * 参数说明：无
     * 返回值说明：无
     */
    ~RectangleData();
    //设置矩形参数
    inline void SetStartPosX(const double &dPosX){m_dStartPosX=dPosX;};
    inline void SetStartPosY(const double &dPosY){m_dStartPosY=dPosY;};
    inline void SetWidth(const double &dWigth){m_dWidth=dWigth;};
    inline void SetHeight(const double &dHeight){m_dHeight=dHeight;};


    //获取矩形参数
    inline const double &GetStartPosX()const {return m_dStartPosX;};
    inline const double &GetStartPosY()const {return m_dStartPosY;};
    inline const double &GetWidth()const {return m_dWidth;};
    inline const double &GetHeight()const {return m_dHeight;};

private:
    double m_dStartPosX;
    double m_dStartPosY;
    double m_dWidth;
    double m_dHeight;
    //边框颜色和填充颜色设置将在2.0版本写出

};

#endif // RECTANGLEDATA_H
