#ifndef SETTINGS_H
#define SETTINGS_H

#include "ui_Settings.h"

#include <QDialog>
#include <QSettings>
#include <iostream>

//Min and max zoom ratio (relative)
const float GL_MAX_ZOOM = 50.f;
const float GL_MIN_ZOOM = 0.01f;

float zoomClip(float val);

class cParameters
{
public:
    cParameters();
    ~cParameters(){}

    //sets
    void setFullScreen(bool aBool)      { _fullScreen = aBool;   }
    void setPosition(QPoint pos)        { _position = pos;       }
    void setNbFen(QPoint const &aNbFen) { _nbFen = aNbFen;       }
    void setSzFen(QSize aSzFen)         { _szFen = aSzFen;       }

    void setZoomWindowValue(int aZoom)  { _zoomWindow = aZoom;   }
    void setDefPtName(QString name)     { _ptName  = name;       }
    void setPostFix(QString name)       { _postFix = name;       }

    void setLineThickness(float val)    { _linethickness = val;  }
    void setPointDiameter(float val)    { _pointDiameter = val;  }
    void setPointSize(float val)        { _pointSize = val;      }
    void setGamma(float val)            { _gamma = val;          }

    void setSelectionRadius(int val)    { _radius = val;         }

    //get
    bool    getFullScreen()             { return _fullScreen;    }
    QPoint  getPosition()               { return _position;      }
    QPoint  getNbFen()                  { return _nbFen;         }
    QSize   getSzFen()                  { return _szFen;         }

    float   getZoomWindowValue()        { return _zoomWindow;    }
    QString getDefPtName()              { return _ptName;        }
    QString getPostFix()                { return _postFix;       }

    float getLineThickness()            { return _linethickness; }
    float getPointDiameter()            { return _pointDiameter; }
    float getPointSize()                { return _pointSize;     }
    float getGamma()                    { return _gamma;         }

    int   getSelectionRadius()          { return _radius;        }

    //! Copy operator
    cParameters& operator =(const cParameters& params);

    void    read();
    void    write();

private:
    //main window parameters
    bool        _fullScreen;
    QPoint      _position;
    QPoint      _nbFen;
    QSize       _szFen;

    //drawing settings
    float       _linethickness;
    float       _pointDiameter;
    float       _pointSize;
    float       _gamma;

    //other parameters
    float       _zoomWindow;
    QString     _ptName;
    QString     _postFix;
    int         _radius;
};

//! Dialog to setup display settings
class cSettingsDlg : public QDialog, public Ui::settingsDialog
{
    Q_OBJECT

public:

    //! Default constructor
    cSettingsDlg(QWidget* parent, cParameters *params);
    ~cSettingsDlg();

    void setParameters(cParameters &params);

signals:
    void hasChanged(bool closeWidgets);

protected slots:

    void on_okButton_clicked();
    void on_applyButton_clicked();
    void on_resetButton_clicked();
    void on_cancelButton_clicked();

    void on_NBF_x_spinBox_valueChanged(int);
    void on_NBF_y_spinBox_valueChanged(int);

    void on_WindowWidth_spinBox_valueChanged(int);
    void on_WindowHeight_spinBox_valueChanged(int);

    void on_LineThickness_doubleSpinBox_valueChanged(double);
    void on_PointDiameter_doubleSpinBox_valueChanged(double);
    void on_PointSize_doubleSpinBox_valueChanged(double);
    void on_GammaDoubleSpinBox_valueChanged(double);

    void on_zoomWin_spinBox_valueChanged(int);
    void on_RadiusSpinBox_valueChanged(int);

protected:

    //! Refreshes dialog to reflect new settings values
    void refresh();

    //! settings
    cParameters *_parameters;

    //! settings copy
    cParameters  _oldParameters;
};


#endif