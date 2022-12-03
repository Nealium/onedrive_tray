#ifndef MORECOLORS_H
#define MORECOLORS_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QColorDialog;
class QToolButton;
QT_END_NAMESPACE

class MoreColorsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MoreColorsDialog(const QColor &defaultColor, const bool &rainIcon);
    QColor colorValidated();

protected:

private slots:
    void currentColorChanged(const QColor &color, const bool &rainIcon);

private:
  QColorDialog *colorDlg;
  QToolButton *iconButton;
};

#endif
