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


class PicListWidget;
class MainFrame : public QGraphicsView
{
    Q_OBJECT

public:
    MainFrame();
    ~MainFrame();

public:
    BackGroundItem*  backgroudItem() { return m_pBackgroundItem;}
    QRegion calcFrameClipRegion( const QRect &rect );

public:
    virtual void drawBackground(QPainter *painter, const QRectF &rect);

protected:
    virtual void resizeEvent( QGraphicsSceneResizeEvent *event );
    virtual bool event(QEvent* event);

private:
    void init();

public slots:
    void onHeartBeat();

private:
    QGraphicsScene*     m_pSence;
    BackGroundItem*     m_pBackgroundItem;
    PicListWidget*      m_picList;
    QTimer              m_Timer;

};

#endif