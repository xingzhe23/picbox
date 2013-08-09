#ifndef _MAINFRAME_H
#define _MAINFRAME_H

#include "stables.h"

class BackGroundItem 
{
public:
    BackGroundItem()
    {
        m_pBrush = new QBrush;
        m_pImage = new QPixmap;
    }

    ~BackGroundItem()
    {
        delete m_pBrush;
        delete m_pImage;
    }

    QBrush* brush() { return m_pBrush;}
    
    void setImage(QString& file)
    {
        m_pImage->load(file);
    }

private:
    QBrush*     m_pBrush;
    QPixmap*    m_pImage;
};


class MainFrame : public QGraphicsView
{
public:
    MainFrame();
    ~MainFrame();

public:
    BackGroundItem*  backgroudItem() { return m_pBackgroundItem;}
    QRegion calcFrameClipRegion( const QRect &rect );

public:
    virtual void drawBackground(QPainter *painter, const QRectF &rect);

private:
    void init();

private:
    QGraphicsScene*     m_pSence;
    BackGroundItem*     m_pBackgroundItem;
};

#endif