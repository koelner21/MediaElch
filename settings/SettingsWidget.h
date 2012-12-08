#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QComboBox>
#include <QFileDialog>
#include <QSettings>
#include <QTableWidgetItem>
#include <QWidget>

#include "data/ScraperInterface.h"
#include "globals/Globals.h"
#include "settings/DataFile.h"
#include "settings/Settings.h"

namespace Ui {
class SettingsWidget;
}

/**
 * @brief The Settings class stores all MediaElch settings and displays the settings widget.
 */
class SettingsWidget : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWidget(QWidget *parent = 0);
    ~SettingsWidget();

    void loadSettings();

public slots:
    int exec();
    void saveSettings();
    void accept();
    void reject();

private slots:
    void chooseDirToAdd();
    void addDir(QString dir, QString mediaCenterPath = QString(), bool separateFolders = false, bool autoReload = false, SettingsDirType dirType = DirTypeMovies);
    void removeDir();
    void organize();
    void dirListRowChanged(int currentRow);

    void onDebugLogPathChosen(QString file);
    void onActivateDebugMode();
    void onSetDebugLogPath(QString path);
    void onUseProxy();
    void onAutoLoadStreamDetails();

private:
    Ui::SettingsWidget *ui;
    Settings *m_settings;
    QFileDialog *m_logFileDialog;
    QMap<ScraperInterface*, QComboBox*> m_scraperCombos;
    QMap<TvScraperInterface*, QComboBox*> m_tvScraperCombos;
    QMap<ConcertScraperInterface*, QComboBox*> m_concertScraperCombos;
};

#endif // SETTINGSWIDGET_H
