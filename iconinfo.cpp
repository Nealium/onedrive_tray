#include <QVector>
#include <QColor>
#include <QPixmap>
#include <QPainter>
#include <iconinfo.h>

IconInfo::IconInfo(QObject* parent) : QObject(parent) {}

IconInfo::~IconInfo(){}

const QString IconInfo::m_onedriveIconPathName = QString(":/images/OneDrive.svg");

const QString IconInfo::m_syncingOnedriveIconPathName = QString(":/images/OneDrive-sync.svg");

QStringList IconInfo::defaultColorsText()
{
    static const QStringList result = { tr("OneNote Darker"), tr("OneNote Lighter"),  tr("White"), tr("Blue"), tr("Red"), tr("Green"), tr("Black")};
    return result;
}

QVector<QColor> IconInfo::defaultColors()
{
    QVector<QColor> result {"#094ab2", "#23aaeb", Qt::white, Qt::blue , Qt::red, Qt::green, Qt::black};
    return result;
}

QString IconInfo::onedriveIconPathName()
{
    return m_onedriveIconPathName;
}

QString IconInfo::syncingOnedriveIconPathName(const bool &rainIcon)
{
    if (rainIcon)
    {
      return m_syncingOnedriveIconPathName;
    }
    return m_onedriveIconPathName;
}

QPixmap IconInfo::changeColorIcon(const QString &imageName, const QColor &color)
{
    QPixmap pixmap(imageName);
    QPainter painter(&pixmap);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(pixmap.rect(), color);
    painter.end();
    return pixmap;
}

