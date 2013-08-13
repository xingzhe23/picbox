#include "RawPicLabelWidget.h"
#include "Logger.h"

RawPicLabelWidget::RawPicLabelWidget(const QString& imageFile)
{
    m_imageFile = imageFile;
    m_pPixMap = new QPixmap(m_imageFile);

    setGeometry(0, 0, 300, 300);
}
RawPicLabelWidget::~RawPicLabelWidget()
{
    if(m_pPixMap)
        delete m_pPixMap;
}

QString RawPicLabelWidget::imageFile()
{
    return m_imageFile;
}

bool    RawPicLabelWidget::valid()
{
    return !m_pPixMap->isNull();
}

QPixmap* RawPicLabelWidget::pixMap()
{
    return m_pPixMap;
}


PicListWidget::PicListWidget()
{
    m_pLayout = new QGraphicsLinearLayout(Qt::Horizontal);
    setLayout(m_pLayout);
}

PicListWidget::~PicListWidget()
{
    QMap<QString, RawPicLabelWidget*>::iterator it = m_pics.begin();
    for(; it != m_pics.end(); ++it)
    {
        delete it.value();
    }

    if(m_pLayout)
        delete m_pLayout;
}

void PicListWidget::addItem(const QString& imageFile)
{
    Logger("PicListWidget::addItem, image=", imageFile.toStdString());
    QMap<QString, RawPicLabelWidget*>::iterator it = m_pics.find(imageFile);
    if(it == m_pics.end())
    {
        RawPicLabelWidget* pic = new RawPicLabelWidget(imageFile);
        if(pic->valid())
        {
            Logger("PicListWidget::addItem VALIID");
        }
        m_pLayout->addItem(pic);
        m_pics[imageFile] = pic;

        drawItem(imageFile);

        refresh();
    }
}

RawPicLabelWidget*  PicListWidget::PicFromImageFile(const QString& imageFile)
{
    QMap<QString, RawPicLabelWidget*>::iterator it = m_pics.find(imageFile);
    if(it != m_pics.end())
    {
        return it.value();
    }

    return NULL;
}


void PicListWidget::delItem(const QString& imageFile)
{
    Logger("PicListWidget::delItem, image=", imageFile.toStdString());
    QMap<QString, RawPicLabelWidget*>::iterator it = m_pics.find(imageFile);
    if(it != m_pics.end())
    {
        delete it.value();
        m_pics.erase(it);
        refresh();
    }
}
void PicListWidget::refresh()
{
    update();
}

void PicListWidget::drawItem(const QString& imageFile)
{
    RawPicLabelWidget* pic = PicFromImageFile(imageFile);
    if(pic != NULL)
    {
        Logger("PicListWidget::drawItem");
        QPixmap* pImage = pic->pixMap();
        Logger("PicListWidget::drawItem, image width/height", pImage->width(), pImage->height());

        QPixmap image = pImage->scaled(rect().width(), rect().height());
        if(!image.isNull())
        {
            Logger("PicListWidget::drawItem, image width/height", image.width(), image.height());
        }
        QPainter painter;
        painter.drawPixmap(this->rect().topLeft(), image);
    }
}


