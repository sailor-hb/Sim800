#ifndef MAINUNT_H
#define MAINUNT_H

#include <QtGui/QMainWindow>
#include <QtGui/QFileDialog>
#include <QtCore/QMimeData>
#include <QtCore/QDateTime>
#include <QtGui/QTreeWidgetItem>
#include "Common.h"
#include <QtGui/QLabel>
#include <QtGui/QProgressbar>
#include <QtCore/QTranslator>


namespace Ui {
    class TMainFrm;
}


class TMainFrm : public QMainWindow {
    Q_OBJECT
public:
    explicit TMainFrm(QWidget *parent = 0);
    ~TMainFrm();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::TMainFrm *ui;
    QFileDialog OpenSaveFileDialog;
    QString fLastSavedProjectFilename;
    QLabel *action;
    QProgressBar *progress;
    QTime fPrepareBufferStartTime;
    bool fDiscardRenameCheck;
    QString fBookfilename;
    QTranslator* fTranslator;
    QString fLastLangCode;
    QSet<Qt::Key> fPressedKeys;
private:
    //void TryAcceptDrop( QFileInfo &info, int maxdepth, int &bypasscount, int &acceptcount );
    //void TryAcceptPages( QFileInfo &info, int maxdepth, int chapterindex, int &bypasscount, int &acceptcount );
    //void TryAcceptXmlFolder( QFileInfo &info, OpenBookWriter* writer, int baselen, int maxdepth, int &bypasscount, int &acceptcount );
protected:
    virtual bool eventFilter(QObject*, QEvent*);
    virtual void keyPressEvent(QKeyEvent *);
    virtual void keyReleaseEvent(QKeyEvent *);
public:
    void StoreTranslator( QTranslator* translator );
private slots:
    void onEmulationStartClicked();
    void onEmulationRestartClicked();
    void onEmulationTestClicked();
    void onBenchmarkClicked();
    void onLanguageEnglishClicked();
    void onLanguageChineseClicked();
    //void onToolsOptionsClicked();
    void onHelpContentsClicked();
public slots:
    void writeLog(QString content, TLogType logtype = ltMessage);
    void onReadyBuildBook();
    void onStepFinished(quint16 pc);
    void onLCDBufferChanged(QByteArray* buffer);
};

QString LogTypeToString( TLogType logtype );
QString localLanguage();
#endif // MAINUNT_H