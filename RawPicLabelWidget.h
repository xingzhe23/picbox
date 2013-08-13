#ifndef _RAWPICLABELWIDGET_H
#define _RAWPICLABELWIDGET_H
#include "stables.h"

class RawPicLabelWidget : public QGraphicsWidget
{
public:
   RawPicLabelWidget(const QString& imageFile);
   ~RawPicLabelWidget();

    QString     imageFile();
    bool        valid(); 
    QPixmap*    pixMap();
    
private:
    QString     m_imageFile;
    QPixmap*    m_pPixMap;
};

class PicListWidget : public QGraphicsWidget
{
public:
    PicListWidget();
    ~PicListWidget();

    void addItem(const QString& imageFile);
    void delItem(const QString& imageFile);
    
    RawPicLabelWidget*  PicFromImageFile(const QString& imageFile);
    void refresh();

    void drawItem(const QString& imageFile);

private:
    QGraphicsLinearLayout*        m_pLayout;
    QMap<QString, RawPicLabelWidget*> m_pics;
};

#endif