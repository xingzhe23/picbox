#include "MainFrame.h"
#include "WinUtil.h"
#include "Logger.h"
#include "duidrawutil.h"

MainFrame::MainFrame(): QGraphicsView()
{
    m_pSence = new QGraphicsScene(this);
    m_pBackgroundItem = new BackGroundItem;
    init();
}
   
MainFrame::~MainFrame()
{
    if(m_pSence)
        delete m_pSence;
    if(m_pBackgroundItem)
        delete m_pBackgroundItem;
}


QRegion MainFrame::calcFrameClipRegion( const QRect &rect )
{
    QRect rects[5] = 
    {
        QRect(2, 0, rect.width() - 4, 1),
        QRect(1, 1, rect.width() - 2, 1),

        QRect(0, 2, rect.width(), rect.height() - 4),

        QRect(1, rect.bottom()-1, rect.width() - 2, 1),
        QRect(2,rect.bottom()-0, rect.width() - 4, 1)
    };

    int x = rect.left();
    int y = rect.top();
    for(int i = 0; i < sizeof(rects) / sizeof(QRect); i++)
    {
        rects[i].adjust(x, y, x, y);
    }

    QRegion rgn;
    rgn.setRects(rects, sizeof(rects)/sizeof(rects[0]));

    return rgn;
}



void MainFrame::drawBackground(QPainter *painter, const QRectF &rect)
{
    //
    QPixmap image(tr("tree.png"));

    Logger("tree.png, width/height=", image.width(), image.height());
    Logger("frame,  width/height=", this->rect().width(), this->rect().height());
    image = image.scaled(this->rect().width(), this->rect().height());
    Logger("tree.png, width/height=", image.width(), image.height());

    //DuiDrawUtil::drawPixmap(painter, this->rect(), image);

    //painter->setClipRegion(this->rect());
    painter->drawPixmap(rect.topLeft(), image);

}

void MainFrame::init()
{
    //init Sence;
    setScene(m_pSence);

    //init size:
    setMinimumWidth(100);
    setMaximumWidth(1000);

    QBrush brush;
    brush.setColor(Qt::gray);
    setBackgroundBrush(brush);
    //foreground

    //set auto prefer size


    //font

    //window Title
    setWindowTitle(tr("hello world"));
   
    //custom title bar
    //custom button
    UINT32 winStyle = 0;
    winStyle |= WS_MINIMIZEBOX;
    WinUtil::addWindowStyle((UINT32)winId(), WS_SYSMENU | winStyle );

    //frame style;
    setFrameShadow(QFrame::Plain);
    Shadow sha = frameShadow();
    Logger("Frame shadow =", sha);
    setLineWidth(0);
    setMidLineWidth(0);
    setFrameStyle(QFrame::StyledPanel);

    //this->setPreferredHeight(400.0);
    //this->setPreferredWidth(400.0);
    //Frame Margin
}

